#include "GerenciadorGrafico.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// CONSTRUTORA DA CLASSE GERENCIADORGRAFICO
GerenciadorGrafico::GerenciadorGrafico()
{

}

void GerenciadorGrafico::Init(){

    FilaEventos = NULL;
    display = NULL;
    timer = NULL;
    fonte = NULL;

    InitAllegro(); // INICIALIZACAO DO ALLEGRO
    CriaDisplay(); // CRIA O DISPLAY
    TestaDisplay(); // VERIFICA SE O DISPLAY FOI CRIADO CORRETAMENTE
    InstalaHardwares(); // INSTALA OS AGENTES EXTERNOS
    InitAddons(); // INICIALIZACAO DOS ADDONS DO ALLEGRO
    CriaFilaEventos(); // CRIA A FILA DE EVENTOS
    CriaTimer(); // CRIA O TEMPORIZADOR
    RegistraSources(); // REGISTRA OS SOURCES DO ALLEGRO NA FILA DE EVENTOS
    CriaFonte(); // CRIA A FONTE PADRAO DO JOGO

}
// DESTRUTORA DA CLASSE GERENCIADORGRAFICO
GerenciadorGrafico::~GerenciadorGrafico()
{
    /*al_destroy_display(display); // LIBERA A MEMORIA ALOCADA
    al_destroy_event_queue(FilaEventos); // LIBERA A MEMORIA ALOCADA
    al_destroy_timer(timer); // LIBERA A MEMORIA ALOCADA
    al_destroy_font(fonte); // LIBERA A MEMORIA ALOCADA
    al_destroy_bitmap(tela_inicial); // LIBERA A MEMORIA ALOCADA*/
}

// METODO PARA UTILIZAR O PONTEIRO DA FILA DE EVENTOS
ALLEGRO_EVENT_QUEUE* GerenciadorGrafico::GetFilaEventos()
{
    return FilaEventos;
}

// METODO PARA UTILIZAR O PONTEIRO DO DISPLAY
ALLEGRO_DISPLAY* GerenciadorGrafico::GetDisplay()
{
    return display;
}

// METODO PARA UTILIZAR O PONTEIRO DO TEMPORIZADOR
ALLEGRO_TIMER* GerenciadorGrafico::GetTimer()
{
    return timer;
}

// METODO PARA INICIALIZAR O ALLEGRO
int GerenciadorGrafico::InitAllegro()
{
    // MOSTRA MENSAGEM DE ERRO CASO O ALLEGRO NAO SE INICIALIZE CORRETAMENTE
    if(!al_init())
    {
        al_show_native_message_box(NULL, "AVISO!", "ERRO:",
        "ALLEGRO NAO PODE SER INICIALIZADO!", NULL, ALLEGRO_MESSAGEBOX_ERROR);

        return -1;
    }
}

// METODO PARA CRIAR O DISPLAY
void GerenciadorGrafico::CriaDisplay()
{
    display = al_create_display(LarguraTela, AlturaTela);
}

// METODO PARA VERIFICAR SE O DISPLAY FOI CRIADO CORRETAMENTE
int GerenciadorGrafico::TestaDisplay()
{
    // MOSTRA MENSAGEM DE ERRO CASO O DISPLAY NAO SE INICIALIZE CORRETAMENTE
    if(!display)
    {
        al_show_native_message_box(NULL, "AVISO!", "ERRO:",
        "O DISPLAY NAO PODE SER CRIADO!", NULL, ALLEGRO_MESSAGEBOX_ERROR);

        return -1;
    }
}

// METODO PARA INSTALAR OS AGENTES EXTERNOS
void GerenciadorGrafico::InstalaHardwares()
{
    al_install_keyboard(); // INSTALANDO O TECLADO
    al_install_mouse(); // INSTALANDO O MOUSE
}

// METODO PARA INICIALIZAR OS ADDONS DO ALLEGRO
void GerenciadorGrafico::InitAddons()
{
    al_init_primitives_addon(); // ADDON REFERENTE AS FIGURAS PRIMITIVAS
    al_init_image_addon(); // ADDON REFERENTE AS IMAGENS CARREGADAS
    al_init_font_addon(); // ADDON REFERENTE A FONTE PADRAO
}

// METODO PARA CRIAR A FILA DE EVENTOS
void GerenciadorGrafico::CriaFilaEventos()
{
    FilaEventos = al_create_event_queue();
}

// METODO PARA CRIAR A FONTE PADRAO
void GerenciadorGrafico::CriaFonte()
{
    if (!al_init_ttf_addon())
    {
        //fprintf(stderr, "Falha ao inicializar add-on allegro_ttf.\n");
    }
    fonte = al_load_font("/home/thiago/allegro/examples/data/DejaVuSans.ttf",30, 0);
}

// METODO PARA CRIAR O TEMPORIZADOR
void GerenciadorGrafico::CriaTimer()
{
    timer = al_create_timer(1.0 / FPS);
}

// METODO PARA REGISTRAR OS SOURCES DO ALLEGRO NA FILA DE EVENTOS
void GerenciadorGrafico::RegistraSources()
{
    // EVENTOS RELACIONADOS AO TECLADO
    al_register_event_source(FilaEventos, al_get_keyboard_event_source());

    // EVENTOS RELACIONADOS AO DISPLAY
    al_register_event_source(FilaEventos, al_get_display_event_source(display));

    // EVENTOS RELACIONADOS AO MOUSE
    al_register_event_source(FilaEventos, al_get_mouse_event_source());

    // EVENTOS RELACIONADOS AO TEMPORIZADOR
    al_register_event_source(FilaEventos, al_get_timer_event_source(timer));
}

// PERGUNTAR AO PROFESSOR
void GerenciadorGrafico::DestroiTudo()
{
    al_destroy_bitmap(tela_inicial); // LIBERA A MEMORIA ALOCADA
    al_destroy_display(display); // LIBERA A MEMORIA ALOCADA
    al_destroy_event_queue(FilaEventos); // LIBERA A MEMORIA ALOCADA
    al_destroy_timer(timer); // LIBERA A MEMORIA ALOCADA
    al_destroy_font(fonte); // LIBERA A MEMORIA ALOCADA
    estado=0;
}

void GerenciadorGrafico::Pause(int o){

    al_clear_to_color(al_map_rgb(0,0,0));
    switch(o){
    case 0:
    al_draw_text(fonte, al_map_rgb(255, 255, 255), 150 , 150, ALLEGRO_ALIGN_CENTRE,"Continuar");
    break;
    case 1:
    al_draw_text(fonte, al_map_rgb(255, 255, 255), 150 , 150, ALLEGRO_ALIGN_CENTRE,"Salvar Jogo");
    break;
    case 2:
    al_draw_text(fonte, al_map_rgb(255, 255, 255), 150 , 150, ALLEGRO_ALIGN_CENTRE,"Sair do jogo");
    break;
    }
    al_flip_display();
}

void GerenciadorGrafico::Tela_inicial(int o){

    tela_inicial=al_load_bitmap("/home/thiago/TeM/Jogo07/Imagens/Abertura2.bmp");

    al_draw_bitmap(tela_inicial,0,0,0);

    switch(o){
    case 0:
    al_draw_text(fonte, al_map_rgb(255, 255, 255), 130 , 130, ALLEGRO_ALIGN_CENTRE,"Novo jogo");
    break;
    case 1:
    al_draw_text(fonte, al_map_rgb(255, 255, 255), 130 , 130, ALLEGRO_ALIGN_CENTRE,"Continuar");
    break;
    case 2:
    al_draw_text(fonte, al_map_rgb(255, 255, 255), 130 , 130, ALLEGRO_ALIGN_CENTRE,"Sair");
    break;
    }
    al_flip_display();
}


void GerenciadorGrafico::EscolhaJogadores(int o){

    tela_inicial=al_load_bitmap("/home/thiago/TeM/Jogo07/Imagens/Abertura2.bmp");

    al_draw_bitmap(tela_inicial,0,0,0);

    switch(o){
    case 0:
    al_draw_text(fonte, al_map_rgb(0, 255, 255), 130 , 130, ALLEGRO_ALIGN_CENTRE,"1-jogador");
    break;
    case 1:
    al_draw_text(fonte, al_map_rgb(0, 0, 255), 130 , 130, ALLEGRO_ALIGN_CENTRE,"2-jogadores");
    break;
    case 2:
    al_draw_text(fonte, al_map_rgb(255, 255, 0), 130 , 130, ALLEGRO_ALIGN_CENTRE,"Sair");
    break;
    }
    al_flip_display();
}


void GerenciadorGrafico::EscolheFase (int o){

    tela_inicial=al_load_bitmap("/home/thiago/TeM/Jogo07/Imagens/Abertura2.bmp");

    al_draw_bitmap(tela_inicial,0,0,0);

    switch(o){
    case 0:
    al_draw_text(fonte, al_map_rgb(0, 0, 0), 130 , 130, ALLEGRO_ALIGN_CENTRE,"1-Fase");
    break;
    case 1:
    al_draw_text(fonte, al_map_rgb(255, 255, 255), 130 , 130, ALLEGRO_ALIGN_CENTRE,"2-Fase");
    break;
    case 2:
    al_draw_text(fonte, al_map_rgb(255, 0, 255), 130 , 130, ALLEGRO_ALIGN_CENTRE,"3-Fase");
    break;
    }
    al_flip_display();
}

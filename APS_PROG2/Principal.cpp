#include "Principal.h"

#define SAIR 'S'
#define Opcoes_jogo 'A'
#define Escolhe_1player 'B'
#define Escolhe_multiplayer 'D'
#define Comeco 'C'

Principal::Principal(){

    janelas=NULL;
    fila_eventos=NULL;
    fonte=NULL;

}

Principal::~Principal(){


}

int Principal::Executar(){

 int i;
 int ACK_L=0;
 char Estado=Comeco;
  ACK_L=Cria_Janela();
  if (ACK_L==-1)
  {
    return-1;
  }
  ACK_L=Cria_Mouse();
  if (ACK_L==-1)
  {
    return-1;
  }
 ACK_L=Cria_Evento();
  if (ACK_L==-1)
  {
    return-1;
  }
 ACK_L=Cria_Font();
  if (ACK_L==-1)
  {
    return-1;
  }
  gerenciador_tela.Init(janelas,fila_eventos,fonte);
  while(Estado!=SAIR)
  {
    switch(Estado)
    {
    case Comeco:
    ACK_L=gerenciador_tela.Mostrar_tela_principal(640,480,20);
    if (ACK_L==0)
    {
        Estado=Opcoes_jogo;
    }
    else if(ACK_L==1)
    {
     // Estado=;
    }
    else if(ACK_L==2)
    {
      Estado=SAIR;
    }
    break;
    case Opcoes_jogo:
    ACK_L=gerenciador_tela.Mostrar_tela_opcoes_jogo(640,480,20);
    if(ACK_L==0)
    {
      Estado=Escolhe_1player;
    }
    else if(ACK_L==1)
    {
      Estado=Escolhe_multiplayer;
    }
    else if(ACK_L==2)
    {
      Estado=Comeco;
    }
    break;
    case Escolhe_1player:
    ACK_L=gerenciador_tela.Mostrar_tela_escolhe_jogador(640,480,20,1);
    if(ACK_L==0){
        Estado=SAIR;

    }
    else if (ACK_L==1){

        Estado=SAIR;
    }
    else if (ACK_L==2){

        Estado=SAIR;
    }
    break;
    case Escolhe_multiplayer:
    ACK_L=gerenciador_tela.Mostrar_tela_escolhe_jogador(640,480,20,2);
    if(ACK_L==0){
        Estado=SAIR;
    }
    else if (ACK_L==1){
        Estado=SAIR;

    }
    else if (ACK_L==2){
        Estado=SAIR;

    }
    break;
    default:
        printf("Default da maquina de estado\n");
        Estado=Comeco;
    break;
    }
  }
 return 1;

}

void Principal::Destroi_Tela(){

   al_destroy_display(janelas);
   al_destroy_event_queue(fila_eventos);
   al_destroy_font(fonte);


}

int Principal::Cria_Janela(){

 Largura_tela=640;
 Altura_tela=480;
 if (!al_init())
 {
     fprintf(stderr, "Falha ao inicializar a Allegro.\n");
     return -1;
  }
 janelas = al_create_display(Largura_tela, Altura_tela);
 if (!janelas)
    {
        fprintf(stderr, "Falha ao criar janela.\n");
        return -1;
    }
 else
 al_set_window_title(janelas, "Batalha Naval - Pincinato");
 return 1;
}

int Principal::Cria_Mouse()
{
 if (!al_install_mouse())
    {
        fprintf(stderr, "Falha ao inicializar o mouse.\n");
        al_destroy_display(janelas);
        return -1;
    }
 if (!al_set_system_mouse_cursor(janelas, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT))
    {
        fprintf(stderr, "Falha ao atribuir ponteiro do mouse.\n");
        return -1;
    }
 return 1;

}

int Principal::Cria_Evento(){


    fila_eventos = al_create_event_queue();
    if (!fila_eventos)
    {
        fprintf(stderr, "Falha ao inicializar o fila de eventos.\n");
        al_destroy_display(janelas);
        return -1;
    }
    al_register_event_source(fila_eventos, al_get_mouse_event_source());
 return 1;
}

int Principal::Cria_Font(){

    tamanho_fonte = 20;
    al_init_font_addon();
    if (!al_init_ttf_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_ttf.\n");
        return -1;
    }
    fonte = al_load_font("/home/thiago/allegro/examples/data/DejaVuSans.ttf",tamanho_fonte, 0);
    if (!fonte)
    {
        al_destroy_display(janelas);
        al_destroy_event_queue(fila_eventos);
        fprintf(stderr, "Falha ao carregar fonte.\n");
        return -1;
    }
    return 1;
}

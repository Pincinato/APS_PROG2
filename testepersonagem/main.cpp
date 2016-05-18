#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <iostream>

using namespace std;

enum TECLAS{CIMA, BAIXO, DIREITA, ESQUERDA};

int main()
{
    /// ----------VARIÁVEIS DO JOGO----------
    const int Largura_Tela = 800;
    const int Altura_Tela = 600;

    ALLEGRO_BITMAP *sonic[] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

    int posx = 100;
    int posy = 100;

    int i = 0;

    // VARIAVEL REFERENTE AO LOOP PRINCIPAL DO JOGO
    bool fim = false;

    // VETOR COM AS TECLAS DIRECIONAIS
    bool direcao[] = {false, false, false, false};

    // DECLARANDO A FILA DE EVENTOS
    ALLEGRO_EVENT_QUEUE *Fila_Eventos = NULL;

    ALLEGRO_DISPLAY *display = NULL;

    // MOSTRA MENSAGEM DE ERRO CASO O ALLEGRO NAO SE INICIALIZE CORRETAMENTE
    if(!al_init())
    {
        al_show_native_message_box(NULL, "AVISO!", "ERRO:",
        "ALLEGRO NAO PODE SER INICIALIZADO!", NULL, ALLEGRO_MESSAGEBOX_ERROR);

        return -1;
    }

    display = al_create_display(Largura_Tela, Altura_Tela);



		// MOSTRA MENSAGEM DE ERRO CASO O DISPLAY NAO SE INICIALIZE CORRETAMENTE
    if(!display)
    {
        al_show_native_message_box(NULL, "AVISO!", "ERRO:", "O DISPLAY NAO PODE SER CRIADO!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    /// ----------INICIALIZAÇÃO DE ADDONS E INSTALAÇÕES----------
    // INSTALANDO O TECLADO
    al_install_keyboard();

    al_init_primitives_addon();

    al_init_image_addon();

    /// ----------CRIACAO DA FILA E DEMAIS DISPOSITIVOS----------
    // CRIANDO A FILA DE EVENTO
    Fila_Eventos = al_create_event_queue();

    sonic[0] = al_load_bitmap("sonic01.bmp");
    sonic[1] = al_load_bitmap("sonic02.bmp");
    sonic[2] = al_load_bitmap("sonic03.bmp");
    sonic[3] = al_load_bitmap("sonic04.bmp");
    sonic[4] = al_load_bitmap("sonic05.bmp");
    sonic[5] = al_load_bitmap("sonic06.bmp");
    sonic[6] = al_load_bitmap("sonic07.bmp");
    sonic[7] = al_load_bitmap("sonic08.bmp");
    sonic[8] = al_load_bitmap("sonic09.bmp");
    sonic[9] = al_load_bitmap("sonic10.bmp");

    /// ----------REGISTRO DE SOURCES----------
    // TODO EVENTO RELACIONADO AO TECLADO SERA REGISTRADO EM FILA_EVENTOS
    al_register_event_source(Fila_Eventos, al_get_keyboard_event_source());

    // TODO EVENTO RELACIONADO AO DISPLAY SERA REGISTRADA EM FILA_EVENTOS
    al_register_event_source(Fila_Eventos, al_get_display_event_source(display));

    /// ----------LOOP PRINCIPAL----------
    while(!fim)
    {
        // CRIANDO UM EVENTO
        ALLEGRO_EVENT ev;

        // AGUARDANDO UM EVENTO ACONTECER
        al_wait_for_event(Fila_Eventos, &ev);

        /// ----------EVENTOS E LOGICAS----------
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
            {
                fim = true;
            }
            switch(ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_UP:
                direcao[CIMA] = true;
                break;

            case ALLEGRO_KEY_DOWN:
                direcao[BAIXO] = true;
                break;

            case ALLEGRO_KEY_RIGHT:
                direcao[DIREITA] = true;
                break;

            case ALLEGRO_KEY_LEFT:
                direcao[ESQUERDA] = true;
                break;
            }
        }

        if(posx >= 0)
        {
            if(direcao[DIREITA])
                i = posx % 10;
        }

        if(ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            switch(ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_UP:
                direcao[CIMA] = false;
                break;

            case ALLEGRO_KEY_DOWN:
                direcao[BAIXO] = false;
                break;

            case ALLEGRO_KEY_RIGHT:
                direcao[DIREITA] = false;
                i = 0;
                break;

            case ALLEGRO_KEY_LEFT:
                direcao[ESQUERDA] = false;
                break;
            }
        }

        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            fim = true;
        }

        //posy -= direcao[CIMA] * 10;
        //posy += direcao[BAIXO] * 10;
        posx -= direcao[ESQUERDA];
        posx += direcao[DIREITA];

        /// ----------DESENHO----------

        al_draw_filled_rectangle(0, 0, 800, 600, al_map_rgb(255, 255, 255));
        al_convert_mask_to_alpha(sonic[0], al_map_rgb(0, 0, 0));
        al_convert_mask_to_alpha(sonic[1], al_map_rgb(0, 0, 0));
        al_convert_mask_to_alpha(sonic[2], al_map_rgb(0, 0, 0));
        al_convert_mask_to_alpha(sonic[3], al_map_rgb(0, 0, 0));
        al_convert_mask_to_alpha(sonic[4], al_map_rgb(0, 0, 0));
        al_convert_mask_to_alpha(sonic[5], al_map_rgb(0, 0, 0));
        al_convert_mask_to_alpha(sonic[6], al_map_rgb(0, 0, 0));
        al_convert_mask_to_alpha(sonic[7], al_map_rgb(0, 0, 0));
        al_convert_mask_to_alpha(sonic[8], al_map_rgb(0, 0, 0));
        al_convert_mask_to_alpha(sonic[9], al_map_rgb(0, 0, 0));

        al_draw_bitmap(sonic[i], 100, 360, NULL);

        al_flip_display();

        // LIMPANDO O BUFFER
        al_clear_to_color(al_map_rgb(0,0,0));
    }

    /// ----------FINALIZAÇÕES DO PROGRAMA----------
    al_destroy_display(display);
    al_destroy_event_queue(Fila_Eventos);
    al_destroy_bitmap(sonic[0]);
    al_destroy_bitmap(sonic[1]);
    al_destroy_bitmap(sonic[2]);
    al_destroy_bitmap(sonic[3]);
    al_destroy_bitmap(sonic[4]);
    al_destroy_bitmap(sonic[5]);
    al_destroy_bitmap(sonic[6]);
    al_destroy_bitmap(sonic[7]);
    al_destroy_bitmap(sonic[8]);
    al_destroy_bitmap(sonic[9]);

    return 0;
}

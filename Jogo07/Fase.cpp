#include "Fase.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <iostream>
#define DEBUG 0


Fase::Fase(){
}

Fase::~Fase(){
}

void Fase::Init(){

    /// ----------VARIÁVEIS DO JOGO----------
    fim = false; // VARIAVEL REFERENTE AO LOOP PRINCIPAL DO JOGO
    bool escolha=false;
    load=false;

    /// ----------LOOP PRINCIPAL----------
    // INICIANDO O CONTADOR
    al_start_timer(Gerenciador.GetTimer());

    // ESCONDENDO O CURSOR DO MOUSE
    // al_hide_mouse_cursor(display);

    /// Teste da tela inicial

    int tel_ini = 0;

    Gerenciador.Tela_inicial(0);

    while(!escolha){
        al_wait_for_event(Gerenciador.GetFilaEventos(), &ev);
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
        switch(ev.keyboard.keycode){
            case ALLEGRO_KEY_RIGHT:
            tel_ini++;
            if(tel_ini>=3)
                tel_ini=0;

            Gerenciador.Tela_inicial(tel_ini);
            break;

            case ALLEGRO_KEY_LEFT:
            tel_ini--;
            if(tel_ini < 0)
                tel_ini = 2;

            Gerenciador.Tela_inicial(tel_ini);
            break;

            case ALLEGRO_KEY_ENTER:
                if(tel_ini==0)
                {
                 escolha=true;
                }
                else if(tel_ini==1)
                {
                 load=true;
                 escolha=true;
                }
                else if(tel_ini==2)
                {
                 escolha=true;
                 fim=true;
                }
            break;
           }

        }
    }

/// fim de teste tela pinicial
}

void Fase::Play(){

    fim = false; // VARIAVEL REFERENTE AO LOOP PRINCIPAL DO JOGO
    //botaoprecionado = false; // ATRIBUTO AUXILIAR PARA IDENTIFICAR SE UMA TECLA ESTA PRECIONADA
    bool system_pause= false;
    salve=false;
    int opcao_pause =0;
    int enable_pause=0;

        system_pause = false;

        // AGUARDANDO UM EVENTO ACONTECER
        al_wait_for_event(Gerenciador.GetFilaEventos(), &ev);

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
                botaoprecionado = true;
                DIRECAO_F=CIMA;
                break;

                case ALLEGRO_KEY_DOWN:
                botaoprecionado= true;
                DIRECAO_F=BAIXO;
                break;

                case ALLEGRO_KEY_RIGHT:
                botaoprecionado = true;
                DIRECAO_F=DIREITA;
                break;

                case ALLEGRO_KEY_LEFT:
                botaoprecionado = true;
                DIRECAO_F=ESQUERDA;
                break;

                case ALLEGRO_KEY_SPACE:
                Gerenciador.Pause(opcao_pause);

                while(!system_pause)
                {
                    al_wait_for_event(Gerenciador.GetFilaEventos(), &ev);

                    if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                        system_pause = true;

                    switch(ev.keyboard.keycode)
                    {
                        case ALLEGRO_KEY_DOWN:
                        if(enable_pause==0)
                        {
                            opcao_pause++;
                            if(opcao_pause==3)
                                opcao_pause=0;
                                Gerenciador.Pause(opcao_pause);
                                enable_pause=1;
                        }
                        break;

                        case ALLEGRO_KEY_RIGHT:
                        if(enable_pause==0)
                        {
                            opcao_pause++;
                            if(opcao_pause==3)
                                opcao_pause=0;
                                Gerenciador.Pause(opcao_pause);
                                enable_pause=1;
                        }
                        break;

                        case ALLEGRO_KEY_ENTER:
                        switch(opcao_pause){
                            case 0:
                            system_pause=true;
                            opcao_pause=0;
                            break;

                            case 1:
                            salve=true;
                            break;

                            case 2:
                            system_pause=true;
                            fim=true;
                            opcao_pause=0;
                            break;
                        }
                        break;

                        default:
                        enable_pause=0;
                        break;
                    }
                }
            }
        }


}


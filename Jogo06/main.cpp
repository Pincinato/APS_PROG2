// MESCLANDO OS DOIS PROGRAMAS
// DATA DE MODIFICAÇÃO: 20/05/2016

#include "GerenciadorGrafico.h"
#include "Jogador.h"
#include "Crabmeat.h"
#include "GerenciadorArquivo.h"

#include <iostream>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#define DEBUG 1

using namespace std;

int main()
{

 ///teste audio por sample
 /*
 ALLEGRO_SAMPLE *sample = NULL;
    if (!al_install_audio())
    {
        fprintf(stderr, "Falha ao inicializar áudio.\n");
        return false;
    }

    if (!al_init_acodec_addon())
    {
        fprintf(stderr, "Falha ao inicializar codecs de áudio.\n");
        return false;
    }
    if (!al_reserve_samples(1))
    {
        fprintf(stderr, "Falha ao alocar canais de áudio.\n");
        return false;
    }
     sample = al_load_sample("/home/thiago/TeM/Sonic_BOOM.ogg");
    if (!sample)
    {
        fprintf(stderr, "Falha ao carregar sample.\n");
//        al_destroy_display(janela);
        return false;
    }
    al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
    ///
 */
    ///fim de teste audio

    if(DEBUG==1){printf("Criando objeto Gerenciador \n");}
    GerenciadorGrafico Gerenciador;
    if(DEBUG==1){printf("Criando jogador \n ");}
    Jogador Player1;
    if(DEBUG==1){printf("Criando Inimigo \n");}
    Crabmeat Enemy1;
    if(DEBUG==1){printf("Criando arquivo \n");}
    GerenciadorArquivo arquivo;

    /// ----------VARIÁVEIS DO JOGO----------
    bool fim = false; // VARIAVEL REFERENTE AO LOOP PRINCIPAL DO JOGO
    bool botaoprecionado = false; // ATRIBUTO AUXILIAR PARA IDENTIFICAR SE UMA TECLA ESTA PRECIONADA
    bool system_pause= false;
    bool escolha=false;
    bool load=false;
    int opcao_pause =0;
    int enable_pause=0;
    /// ----------LOOP PRINCIPAL----------
    // INICIANDO O CONTADOR
    al_start_timer(Gerenciador.GetTimer());
    Gerenciador.CriaFonte();

    // ESCONDENDO O CURSOR DO MOUSE
    // al_hide_mouse_cursor(display);

    // CRIANDO UM EVENTO
    ALLEGRO_EVENT ev;


/// Testa da tela inicial

    int tel_ini=0;
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

    /// teste para carregar os elementos
    if(load==true){
        if(DEBUG==1){printf("Carregando Inimigo \n ");}
        arquivo.Load_Inimigo(&Enemy1);
        if(DEBUG==1){printf("Carregando Jogador \n");}
        arquivo.Load_Jogador(&Player1);
    }
    ///
    while(!fim)
    {
        system_pause=false;

        // AGUARDANDO UM EVENTO ACONTECER
        al_wait_for_event(Gerenciador.GetFilaEventos(), &ev);

        /// ----------EVENTOS E LOGICAS----------
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            botaoprecionado = true;

            if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
            {
                fim = true;
            }

            switch(ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_UP:
                Player1.SetDirecao(CIMA);
                break;

            case ALLEGRO_KEY_DOWN:
                Player1.SetDirecao(BAIXO);
                break;

            case ALLEGRO_KEY_RIGHT:
                Player1.SetDirecao(DIREITA);
                break;

            case ALLEGRO_KEY_LEFT:
                Player1.SetDirecao(ESQUERDA);
                break;
            case ALLEGRO_KEY_SPACE:
                Gerenciador.Pause(opcao_pause);
                while(!system_pause)
                {
                 al_wait_for_event(Gerenciador.GetFilaEventos(), &ev);
                 if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                    {
                    system_pause = true;
                    }
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
                            arquivo.Salva_jogo();
                            arquivo.Salva_Jogador(Player1);
                            arquivo.Salva_Inimigo(&Enemy1);
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

        /*if(Player1.GetX() > 0)
        {
            if(Player1.GetDirecao(DIREITA) || Player1.GetDirecao(ESQUERDA))
            {
                aux = Player1.GetX() % 10;

            }

            if(Player1.GetDirecao(DIREITA) & Player1.GetDirecao(ESQUERDA))
                aux = 0;
        }*/

        if(ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            botaoprecionado = false;
        }

        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            fim = true;
        }

        else if(ev.type == ALLEGRO_EVENT_TIMER)
        {
            if(botaoprecionado)
            {
                if(ALLEGRO_KEY_RIGHT || ALLEGRO_KEY_LEFT)
                    Player1.SetX();

            cout << "Jogador: x = " << Player1.GetX() << endl;
            cout << "Inimigo: x = " << Enemy1.GetX() << endl;
            }
            if(Player1.GetposX() > (Enemy1.GetX()-al_get_bitmap_width(Enemy1.GetBitmap())/2 )&& Player1.GetX() < (Enemy1.GetX() +al_get_bitmap_width(Enemy1.GetBitmap())/2) )
            {
                if(Player1.GetposY() < (Enemy1.GetY()+al_get_bitmap_height(Enemy1.GetBitmap())/2 ))
                printf("Colidiu \n");
            }
            Player1.SetSources(botaoprecionado);
            Enemy1.SetX();
            Enemy1.SetSources();
        }

        /// ----------DESENHO----------

        al_draw_filled_rectangle(0, 0, 800, 600, al_map_rgb(255, 255, 255));

        Player1.DesenhaJogador();
        Enemy1.DesenhaPersonagem();

        // DUPLO BUFFER
        al_flip_display();

        // LIMPANDO O BUFFER
        al_clear_to_color(al_map_rgb(0,0,0));
    }

    // PERGUNTAR AO PROFESSOR
    Player1.DestroiTudo();
    Enemy1.DestroiTudo();
    Gerenciador.DestroiTudo();
//    al_destroy_sample(sample);

    return 0;
}

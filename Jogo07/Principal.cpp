#include "Principal.h"

#include "GerenciadorGrafico.h"
#include "Jogador.h"
#include "Crabmeat.h"
#include "GerenciadorArquivo.h"
#include "Cenario.h"
#include "Fase1.h"
#include "Fase2.h"
#include "Fase3.h"

#include <iostream>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <string>

#define DEBUG 0
#define AUDIO 0

using namespace std;
Principal::Principal()
{

}
Principal::~Principal(){

}

bool Principal::Start(){
///teste audio por sample
 if (AUDIO==1){
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
    }
    ///fim de teste audio
    bool fim = false; // VARIAVEL REFERENTE AO LOOP PRINCIPAL DO JOGO
    bool escolha=false;
    bool load=false;
    GerenciadorGrafico Gerenciador;
    Gerenciador.Init();
    ALLEGRO_EVENT ev;
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
                 load=false;
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
    if(escolha==true && load==false && fim==false){
      escolha=false;
      Gerenciador.EscolhaJogadores(0);
      int tel_joga;
      bool Player2;
      tel_joga=0;
      while(!escolha){
        al_wait_for_event(Gerenciador.GetFilaEventos(), &ev);
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
        switch(ev.keyboard.keycode){
            case ALLEGRO_KEY_RIGHT:
            tel_joga++;
            if(tel_joga>=3)
                tel_joga=0;

            Gerenciador.EscolhaJogadores(tel_joga);
            break;

            case ALLEGRO_KEY_LEFT:
            tel_joga--;
            if(tel_joga < 0)
                tel_joga = 2;

            Gerenciador.EscolhaJogadores(tel_joga);
            break;

            case ALLEGRO_KEY_ENTER:
                if(tel_joga==0)
                {
                 escolha=true;
                 Player2=false;
                }
                else if(tel_joga==1)
                {
                 Player2=true;
                 escolha=true;
                }
                else if(tel_joga==2)
                {
                 escolha=true;
                 fim=true;
                }
            break;
           }

        }
     }
      if(escolha==true && fim ==false){
       escolha=false;
       Gerenciador.EscolheFase(0);
       int tel_fase;
       bool Fase_1;
       bool Fase_2;
       tel_fase=0;
       while(!escolha){
        al_wait_for_event(Gerenciador.GetFilaEventos(), &ev);
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
        switch(ev.keyboard.keycode){
            case ALLEGRO_KEY_RIGHT:
            tel_fase++;
            if(tel_fase>=3)
                tel_fase=0;

            Gerenciador.EscolheFase(tel_fase);
            break;

            case ALLEGRO_KEY_LEFT:
            tel_fase--;
            if(tel_fase < 0)
                tel_fase = 2;

            Gerenciador.EscolheFase(tel_fase);
            break;

            case ALLEGRO_KEY_ENTER:
                if(tel_fase==0)
                {
                 escolha=true;
                 Fase_2=false;
                 Fase_1=true;
                }
                else if(tel_fase==1)
                {
                 Fase_2=true;
                 Fase_1=false;
                 escolha=true;
                }
                else if(tel_fase==2)
                {
                 escolha=true;
                 Fase_2=false;
                 Fase_1=false;
                }
            break;
           }

        }
      }
      if(Fase_1==true){
        Fase1 nivel_1;
        nivel_1.Init(false,Player2);
        Gerenciador.DestroiTudo();
        if(nivel_1.Joga_fase()){
            Fase_2=true;
            if(DEBUG==0){printf("Passou de fase \n");}
            }
      }
      if(Fase_2==true){
        Fase2 nivel_2;
        nivel_2.Init(false,Player2);
        if(Gerenciador.estado==1)
            Gerenciador.DestroiTudo();
        if(nivel_2.Joga_fase()){
            Fase_1=false;
            Fase_2=false;
            }
      }
      if(Fase_1==false && Fase_2==false){
        Fase3 nivel_3;
        nivel_3.Init(false,Player2);
        if(Gerenciador.estado==1)
            Gerenciador.DestroiTudo();
        nivel_3.Joga_fase();
     }
    }
    }
    else if(escolha==true && load ==true){
        if(DEBUG==0){printf("\n Opcao load escolhida \n");}
        string fase_salva;
        GerenciadorArquivo arq;
        fase_salva=arq.Load_Fase();
        if(DEBUG==0){printf("\n fase :\n%s",&fase_salva[0]);}
         if (strcmp(&fase_salva[0],"Fase1")==0)
            {
            if(DEBUG==0){printf("\n Carregando fase 1 \n");}
            Fase1 nivel_A;
            nivel_A.Init(true,false);
            if(Gerenciador.estado==1)
                Gerenciador.DestroiTudo();
            if(nivel_A.Joga_fase()){
             /// fazer cair no iff de baixo
             fase_salva.clear();
             fase_salva.append("Fase2");
                }
            }
        if (strcmp(&fase_salva[0],"Fase2")==0)
            {
            if(DEBUG==0){printf("\n Carregando fase 2 \n");}
            Fase2 nivel_B;
            nivel_B.Init(true,false);
            if(Gerenciador.estado==1)
                Gerenciador.DestroiTudo();
            if(nivel_B.Joga_fase())
            {
             fase_salva.clear();
             fase_salva.append("Fase3");
            }

            }
        if (strcmp(&fase_salva[0],"Fase3")==0)
            {
            if(DEBUG==0){printf("\n Carregando fase 3 \n");}
            Fase3 nivel_C;
            nivel_C.Init(true,false);
            if(Gerenciador.estado==1)
                Gerenciador.DestroiTudo();
            nivel_C.Joga_fase();
            }
        else
            printf("\n Arquivo de Dados com problemas \n");
        }

}

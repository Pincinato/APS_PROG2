// COLOCANDO O PERSONAGEM
// DATA DE MODIFICAÇÃO: 18/05/2016

#include "GerenciadorGrafico.h"
#include "Jogador.h"
#include "GerenciadorArquivo.h"
#define CIMA 0
#define BAIXO 1
#define DIREITA 2
#define ESQUERDA 3

#include <iostream>

using namespace std;

int main()
{
    GerenciadorGrafico Gerenciador;
    Jogador Player1;
    GerenciadorArquivo Arquivo;
    /// ----------VARIÁVEIS DO JOGO----------
    bool fim = false; // VARIAVEL REFERENTE AO LOOP PRINCIPAL DO JOGO
    int aux = 0; // VARIAVEL AUXILIAR PARA PERCORRER O VETOR DA IMAGEM DO JOGADOR

    /// ----------LOOP PRINCIPAL----------
    // INICIANDO O CONTADOR
    al_start_timer(Gerenciador.GetTimer());

    // ESCONDENDO O CURSOR DO MOUSE
    // al_hide_mouse_cursor(display);
    Arquivo.Load_Jogador(&Player1);
    while(!fim)
    {
        // CRIANDO UM EVENTO
        ALLEGRO_EVENT ev;

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
                Player1.SetDirecao(CIMA, true);
                break;

            case ALLEGRO_KEY_DOWN:
                Player1.SetDirecao(BAIXO, true);
                break;

            case ALLEGRO_KEY_RIGHT:
                Player1.SetDirecao(DIREITA, true);
                Player1.SetSentido(false);
                break;

            case ALLEGRO_KEY_LEFT:
                Player1.SetDirecao(ESQUERDA, true);
                Player1.SetSentido(true);
                break;
            }
        }

        if(Player1.GetX() > 0)
        {
            if(Player1.GetDirecao(DIREITA) || Player1.GetDirecao(ESQUERDA))
            {
                aux = Player1.GetX() % 10;
                cout << "x = " << Player1.GetX() << endl;
            }

            if(Player1.GetDirecao(DIREITA) & Player1.GetDirecao(ESQUERDA))
                aux = 0;
        }

        if(ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            switch(ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_UP:
                Player1.SetDirecao(CIMA, false);
                break;

            case ALLEGRO_KEY_DOWN:
                Player1.SetDirecao(BAIXO, false);
                break;

            case ALLEGRO_KEY_RIGHT:
                Player1.SetDirecao(DIREITA, false);
                aux = 0;
                break;

            case ALLEGRO_KEY_LEFT:
                Player1.SetDirecao(ESQUERDA, false);
                aux = 0;
                break;
            }
        }

        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            fim = true;
        }

        // PASSANDO A POSICAO DO MOUSE PARA AS VARIAVEIS DE POSICAO
       /*else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
        {
            posx = ev.mouse.x;
            posy = ev.mouse.y;
        }*/

        // PRECIONANDO UM BOTAO DO MOUSE
        else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            if(ev.mouse.button & 2)
            {
                fim = true;
            }
        }

        /* EM (ev.mouse.button & 2), 2 SIGNIFICA BOTAO DIREITO, 1 BOTAO ESQUERDO */

        else if(ev.type == ALLEGRO_EVENT_TIMER)
        {
            if(Player1.GetDirecao(DIREITA) == true || Player1.GetDirecao(ESQUERDA) == true)
                Player1.SetX();
        }

        /// ----------DESENHO----------

        al_draw_filled_rectangle(0, 0, 800, 600, al_map_rgb(255, 255, 255));

        Player1.DesenhaJogador(aux);

        // DUPLO BUFFER
        al_flip_display();

        // LIMPANDO O BUFFER
        al_clear_to_color(al_map_rgb(0,0,0));
    }

    // PERGUNTAR AO PROFESSOR
    Arquivo.Salva_Jogador(Player1);
    Player1.DestroiTudo();
    Gerenciador.DestroiTudo();

    return 0;
}

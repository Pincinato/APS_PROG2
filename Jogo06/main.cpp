// MESCLANDO OS DOIS PROGRAMAS
// DATA DE MODIFICAÇÃO: 20/05/2016

#include "GerenciadorGrafico.h"
#include "Jogador.h"
#include "Crabmeat.h"

#include <iostream>

using namespace std;

int main()
{
    GerenciadorGrafico Gerenciador;
    Jogador Player1;
    Crabmeat Enemy1;

    /// ----------VARIÁVEIS DO JOGO----------
    bool fim = false; // VARIAVEL REFERENTE AO LOOP PRINCIPAL DO JOGO
    bool botaoprecionado = false; // ATRIBUTO AUXILIAR PARA IDENTIFICAR SE UMA TECLA ESTA PRECIONADA

    /// ----------LOOP PRINCIPAL----------
    // INICIANDO O CONTADOR
    al_start_timer(Gerenciador.GetTimer());

    // ESCONDENDO O CURSOR DO MOUSE
    // al_hide_mouse_cursor(display);

    while(!fim)
    {
        // CRIANDO UM EVENTO
        ALLEGRO_EVENT ev;

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

    return 0;
}

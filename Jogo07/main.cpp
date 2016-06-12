// MESCLANDO OS DOIS PROGRAMAS
// DATA DE MODIFICAÇÃO: 20/05/2016

#include "GerenciadorGrafico.h"
#include "Jogador.h"
#include "Crabmeat.h"
#include "GerenciadorArquivo.h"
#include "Cenario.h"
#include "Fase1.h"
#include "Fase2.h"

#include <iostream>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#define DEBUG 0

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

    ///Fase1 nivel_1;
    Fase2 nivel_2;
    ///nivel_1.Joga_fase();
    nivel_2.Joga_fase();
    return 0;
}

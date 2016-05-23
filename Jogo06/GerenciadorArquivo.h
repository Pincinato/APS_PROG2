#ifndef GERENCIADORARQUIVO_H_INCLUDED
#define GERENCIADORARQUIVO_H_INCLUDED
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <string>
///
#include "Jogador.h"
#include "Crabmeat.h"
///

class GerenciadorArquivo
{
private:

    FILE *arquivo;
    int Salva_Fase(/*Fase*/);
    int Salva_Cenario(/* Cenario c*/);
    int Salva_Chefao(/*Chefao che*/);

    void Load_Fase();
    void Load_Cenario();
    void Load_Chefao();


public:
    // CONSTRUTORA DA CLASSE GERENCIADORGRAFICO
    GerenciadorArquivo();

    // DESTRUTORA DA CLASSE GERENCIADORGRAFICO
    ~GerenciadorArquivo();

    int Salva_jogo(/* Fase f */);
    /*Fase*/ void Load_jogo();
    int Salva_Jogador(Jogador j);
    void Load_Jogador(Jogador *j);
    int Salva_Inimigo(Inimigo *i);
    void Load_Inimigo(Inimigo *i);

};

#endif // GERENCIADORGRAFICO_H_INCLUDED

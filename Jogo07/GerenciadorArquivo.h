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
#include "Cenario.h"
///

class GerenciadorArquivo
{
private:

    FILE *arquivo;


    int Salva_Chefao(/*Chefao c*/);
    void Load_Chefao();


public:
    // CONSTRUTORA DA CLASSE GERENCIADORARQUIVO
    GerenciadorArquivo();

    // DESTRUTORA DA CLASSE GERENCIADORARQUIVO
    ~GerenciadorArquivo();

    int Salva_jogo(/* Fase f */);
    /*Fase*/ void Load_jogo();
    int Salva_Jogador(Jogador j);
    void Load_Jogador(Jogador *j);
    int Salva_Inimigo(Inimigo *i);
    void Load_Inimigo(Inimigo *i);
    int Salva_Cenario( Cenario *c);
    void Load_Cenario(Cenario *c);
    int Salva_Fase(std::string n);
    const char * Load_Fase();

};

#endif // GERENCIADORGRAFICO_H_INCLUDED

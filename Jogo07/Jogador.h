// CLASSE REFERENTE AO PERSONAGEM JOGADOR DO JOGO
// DATA DE MODIFICACAO: 18/05/2016

#ifndef JOGADOR_H_INCLUDED
#define JOGADOR_H_INCLUDED
#include "GerenciadorGrafico.h"
#include <iostream>

//enum DIRECAO{DIREITA, ESQUERDA, CIMA, BAIXO};

using namespace std;

class Jogador
{
private:
    ALLEGRO_BITMAP *Sonic; // ATRIBUTO REFERENTE AO PONTEIRO DOS SPRITES DO SONIC

    float posx; // ATRIBUTO REFERENTE A COORDENADA X DA POSICAO DO PERSONAGEM
    float posy; // ATRIBUTO REFERENTE A COORDENADA Y DA POSICAO DO PERSONAGEM
    const float velocidade = 1.5; // ATRIBUTO REFERENTE A VELOCIDADE DO PERSONAGEM
    int direcao; // ATRIBUTO REFERENTE AS DIRECOES
    int sourceX; // ATRIBUTO AUXILIAR PARA DESENHAR
    int sourceY; // ATRIBUTO AUXILIAR PARA DESENHAR

public:
    // CONSTRUTORA DA CLASSE JOGADOR
    Jogador();

    // DESTRUTORA DA CLASSE JOGADOR
    ~Jogador();

    // METODO PARA CARREGAR AS IMAGENS DO PERSONAGEM
    void CarregaImagem();

    // METODO PARA OBTER A COORDENADA X DA POSICAO DO PERSONAGEM
    float GetX();

    int GetposX();

    int GetposY();

    // METODO PARA ALTERAR A COORDENADA X DA POSICAO DO PERSONAGEM
    void SetX();

    void SetposX(int x);

    // METODO PARA ALTERAR A DIRECAO
    void SetDirecao(int Direcao);

    // METODO PARA OBTER A DIRECAO
    int GetDirecao();

    // METODO PARA ATUALIZAR OS SPRITES DO JOGADOR
    void SetSources(bool ev_botao);

    // METODO PARA DESENHAR O JOGADOR
    void DesenhaJogador();

    // PERGUNTAR PARA O PROFESSOR
    void DestroiTudo();
};

#endif // JOGADOR_H_INCLUDED

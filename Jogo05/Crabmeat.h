// CLASSE REFERENTE AO PRIMEIRO INIMIGO DO SONIC. INIMIGO CRABMEAT

#ifndef CRABMEAT_H_INCLUDED
#define CRABMEAT_H_INCLUDED
#include "GerenciadorGrafico.h"

class Crabmeat
{
private:
    ALLEGRO_BITMAP *crabmeat[2]; // ATRIBUTO REFERENTE AO PONTEIRO DOS SPRITES DO INIMIGO CRABMEAT

    int posx; // ATRIBUTO REFERENTE A COORDENADA X DA POSICAO DO INIMIGO CRABMEAT
    int posy; // ATRIBUTO REFERENTE A COORDENADA Y DA POSICAO DO INIMIGO CRABMEAT
    bool direcao[4]; // VETOR REFERENTE AS DIRECOES
    bool sentido; // ATRIBUTO AUXILIAR PARA DESENHAR O SENTIDO DA IMAGEM DO JOGADOR

public:
    // CONSTRUTORA DA CLASSE CRABMEAT
    Crabmeat();

    // DESTRUTORA DA CLASSE CRABMEAT
    ~Crabmeat();

    // METODO PARA CARREGAR AS IMAGENS DO PERSONAGEM
    void CarregaImagem();

    // METODO PARA CONVERTER A MASCARA DE CORES DO PERSONAGEM
    void ConvertMask();

    // METODO PARA OBTER A COORDENADA X DA POSICAO DO PERSONAGEM
    int GetX();

    // METODO PARA ALTERAR A COORDENADA X DA POSICAO DO PERSONAGEM
    void SetX();

    // METODO PARA ALTERAR A DIRECAO
    void SetDirecao(int i, bool Direcao);

    // METODO PARA OBTER A DIRECAO
    bool GetDirecao(int i);

    // METODO PARA ALTERAR O SENTIDO DA IMAGEM
    void SetSentido(bool Sentido);

    // METODO PARA DESENHAR O INIMIGO CRABMEAT
    void DesenhaInimigo(int i);

    // PERGUNTAR PARA O PROFESSOR
    void DestroiTudo();
};


#endif // CRABMEAT_H_INCLUDED
// CLASSE REFERENTE AO PRIMEIRO INIMIGO DO SONIC. INIMIGO CRABMEAT

#ifndef CRABMEAT_H_INCLUDED
#define CRABMEAT_H_INCLUDED
#include "GerenciadorGrafico.h"
#include "Inimigo.h"

class Crabmeat: public Inimigo
{
private:
    // ATRIBUTO REFERENTE AO PONTEIRO DOS SPRITES DO INIMIGO CRABMEAT

    int sourceX; // ATRIBUTO AUXILIAR PARA DESENHAR
    int sourceY; // ATRIBUTO AUXILIAR PARA DESENHAR
    bool delay; // ATRIBUTO REFERENTE AO TEMPO DE PAUSA DO INIMIGO


public:
    // CONSTRUTORA DA CLASSE CRABMEAT
    Crabmeat();
    Crabmeat(int position);
    // DESTRUTORA DA CLASSE CRABMEAT
    ~Crabmeat();
    void MoveX();
    // METODO PARA CARREGAR AS IMAGENS DO PERSONAGEM
    void CarregaImagem();

    // METODO PARA OBTER A COORDENADA X DA POSICAO DO PERSONAGEM
    float GetX();

    // METODO PARA OBTER A COORDENADA Y DA POSICAO DO PERSONAGEM
    float GetY();

    //int GetposX();
    //const int GetposY();

    ALLEGRO_BITMAP* GetBitmap();

    // METODO PARA ALTERAR A COORDENADA X DA POSICAO DO PERSONAGEM
    void SetX();
    //
    //void SetposX(int x);

    // METODO PARA ATUALIZAR OS SPRITES DO PERSONAGEM
    void SetSources();

    // METODO PARA DESENHAR O PERSONAGEM
    void DesenhaPersonagem();

    // PERGUNTAR PARA O PROFESSOR
    void DestroiTudo();

};

#endif // CRABMEAT_H_INCLUDED

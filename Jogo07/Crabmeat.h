// CLASSE REFERENTE AO PRIMEIRO INIMIGO DO SONIC. INIMIGO CRABMEAT

#ifndef CRABMEAT_H_INCLUDED
#define CRABMEAT_H_INCLUDED
#include "GerenciadorGrafico.h"
#include "Inimigo.h"

class Crabmeat: public Inimigo
{
private:
    ALLEGRO_BITMAP *crabmeat; // ATRIBUTO REFERENTE AO PONTEIRO DOS SPRITES DO INIMIGO CRABMEAT

    int posxo = 400; // ATRIBUTO REFERENTE A COORDENADA X INICIAL DA POSICAO DO INIMIGO CRABMEAT
    int velocidade = 1; // ATRIBUTO REFERENTE A VELOCIDADE DE MOVIMENTO DO INIMIGO CRABMEAT
    const int deslocamento=150;
    int sourceX; // ATRIBUTO AUXILIAR PARA DESENHAR
    int sourceY; // ATRIBUTO AUXILIAR PARA DESENHAR
    int direcao; // ATRIBUTO REFERENTE A DIRECAO QUE O INIMIGO ESTA SE LOCOMOVENDO
    bool delay; // ATRIBUTO REFERENTE AO TEMPO DE PAUSA DO INIMIGO
    int control_posx;

public:
    // CONSTRUTORA DA CLASSE CRABMEAT
    Crabmeat();

    // DESTRUTORA DA CLASSE CRABMEAT
    ~Crabmeat();

    // METODO PARA CARREGAR AS IMAGENS DO PERSONAGEM
    void CarregaImagem();

    // METODO PARA OBTER A COORDENADA X DA POSICAO DO PERSONAGEM
    float GetX();

    // METODO PARA OBTER A COORDENADA Y DA POSICAO DO PERSONAGEM
    float GetY();

    int GetposX();
    int GetposY();

    ALLEGRO_BITMAP* GetBitmap();

    // METODO PARA ALTERAR A COORDENADA X DA POSICAO DO PERSONAGEM
    void SetX();
    //
    void SetposX(int x);

    // METODO PARA ATUALIZAR OS SPRITES DO PERSONAGEM
    void SetSources();

    // METODO PARA DESENHAR O PERSONAGEM
    void DesenhaPersonagem();

    // PERGUNTAR PARA O PROFESSOR
    void DestroiTudo();

    void Ajusteposx();

    void SetDirecao(const int d);
};

#endif // CRABMEAT_H_INCLUDED

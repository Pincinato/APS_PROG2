#ifndef CENARIO_H_INCLUDED
#define CENARIO_H_INCLUDED
#include "GerenciadorGrafico.h"
#include <string.h>
using namespace std;

class Cenario
{
private:
    ALLEGRO_BITMAP *cenario; // ATRIBUTO REFERENTE AO PONTEIRO DA IMAGEM DO CENARIO

    int posx; // ATRIBUTO REFERENTE A COORDENADA X DA POSICAO DO PERSONAGEM
    int direcao; // ATRIBUTO REFERENTE AS DIRECOES

public:
    // CONSTRUTORA DA CLASSE CENARIO
    Cenario(int x);

    // CONSTRUTORA SEM PARAMETROS DA CLASSE CENARIO
    Cenario();

    // DESTRUTORA DA CLASSE CENARIO
    ~Cenario();

    // METODO PARA CARREGAR A IMAGEM DO CENARIO
    void CarregaImagem(char *Imagem);

    // METODO PARA OBTER A COORDENADA X DA POSICAO DO CENARIO
    int GetX();

    // METODO PARA ALTERAR A DIRECAO
    void SetDirecao(int Direcao);

    // METODO PARA ALTERAR A COORDENADA X DA POSICAO DO CENARIO
    void SetX();
    void SetposX(const int x);

    // METODO PARA DESENHAR O CENARIO
    void DesenhaCenario();

    // PERGUNTAR PARA O PROFESSOR
    void DestroiTudo();
};

#endif // CENARIO_H_INCLUDED

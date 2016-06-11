#include "Cenario.h"
#include <stdio.h>
using namespace std;

// CONSTRUTORA DA CLASSE CENARIO
Cenario::Cenario(int x)
{
    cenario = NULL;
    posx = x;

    CarregaImagem(); // CARREGA AS IMAGENS DO PERSONAGEM
}

// CONSTRUTORA SEM PARAMETROS DA CLASSE CENARIO
Cenario::Cenario()
{
    cenario = NULL;
    posx = 0;
    direcao = DIREITA;

    CarregaImagem(); // CARREGA AS IMAGENS DO PERSONAGEM
}

// DESTRUTORA DA CLASSE CENARIO
Cenario::~Cenario()
{

}

// METODO PARA CARREGAR A IMAGEM DO CENARIO
void Cenario::CarregaImagem()
{
    printf("Carrengando imagem cenario \n");
    cenario = al_load_bitmap("/home/thiago/TeM/Jogo07/Imagens/Cenario3.png");
}

// METODO PARA OBTER A COORDENADA X DA POSICAO DO CENARIO
int Cenario::GetX()
{
    return posx;
}

// METODO PARA ALTERAR A DIRECAO
void Cenario::SetDirecao(int Direcao)
{
    direcao = Direcao;
}

// METODO PARA ALTERAR A COORDENADA X DA POSICAO DO CENARIO
void Cenario::SetX()
{
    printf(" Cenario setX \n");
    switch(direcao)
    {
    case ESQUERDA:

        if(posx < 0)
            posx = posx + 2;

        else
            posx = 0;
    break;

    case DIREITA:
        if(posx > -2000)
            posx = posx - 2;

        else
            posx = -2000;
    break;
    }
}

// METODO PARA DESENHAR O CENARIO
void Cenario::DesenhaCenario()
{
 printf(" Cenario desenha \n");
 al_draw_bitmap(cenario, posx, 0, NULL);
 printf(" Cenario sai desenha \n");
}

// PERGUNTAR PARA O PROFESSOR
void Cenario::DestroiTudo()
{
    al_destroy_bitmap(cenario);
}

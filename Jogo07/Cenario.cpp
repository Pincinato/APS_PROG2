#include "Cenario.h"
#include <stdio.h>


// CONSTRUTORA DA CLASSE CENARIO
Cenario::Cenario(int x)
{
    cenario = NULL;
    posx = x;

   // CarregaImagem(Imagem); // CARREGA AS IMAGENS DO PERSONAGEM
}

// CONSTRUTORA SEM PARAMETROS DA CLASSE CENARIO
Cenario::Cenario()
{
    cenario = NULL;
    posx = 0;
    direcao = DIREITA;

 //   CarregaImagem("/home/thiago/TeM/Imagem_Cenario/cenario01_2.png"); // CARREGA AS IMAGENS DO PERSONAGEM
}

// DESTRUTORA DA CLASSE CENARIO
Cenario::~Cenario()
{

}

// METODO PARA CARREGAR A IMAGEM DO CENARIO
void Cenario::CarregaImagem(char * Imagem)
{
    printf("Carrengando imagem cenario \n");
    cenario = al_load_bitmap(Imagem);
    printf("Carrengou imagem cenario \n");

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
 al_draw_bitmap(cenario, posx, 0, NULL);
}

// PERGUNTAR PARA O PROFESSOR
void Cenario::DestroiTudo()
{
    al_destroy_bitmap(cenario);
}

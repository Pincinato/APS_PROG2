#include "Jogador.h"

// CONSTRUTORA DA CLASSE JOGADOR
Jogador::Jogador()
{
    Sonic = NULL;
    posx = 100;
    posy = 360;
    direcao = DIREITA;
    sourceX = 104;
    sourceY = 0;

    CarregaImagem(); // CARREGA AS IMAGENS DO PERSONAGEM
}

// DESTRUTORA DA CLASSE JOGADOR
Jogador::~Jogador()
{
    /*for(int i = 0; i < 10; i++)
        al_destroy_bitmap(Sonic[i]);*/
}

// METODO PARA CARREGAR AS IMAGENS DO PERSONAGEM
void Jogador::CarregaImagem()
{
    Sonic = al_load_bitmap("Imagens/Sonic.png");
}

// METODO PARA OBTER A COORDENADA X DA POSICAO DO PERSONAGEM
float Jogador::GetX()
{
    return posx;
}

// METODO PARA ALTERAR A COORDENADA X DA POSICAO DO PERSONAGEM
void Jogador::SetX()
{
    if(direcao == ESQUERDA)
    {
        if(posx > 0)
            posx -= velocidade;

        else
            posx = 0;
    }

    else if(direcao == DIREITA)
        posx += velocidade;
}

// METODO PARA ALTERAR A DIRECAO
void Jogador::SetDirecao(int Direcao)
{
    direcao = Direcao;
}

// METODO PARA OBTER A DIRECAO
int Jogador::GetDirecao()
{
    return direcao;
}

// METODO PARA ATUALIZAR OS SPRITES DO JOGADOR
void Jogador::SetSources(bool ev_botao)
{
    if(ev_botao)
        sourceX += al_get_bitmap_width(Sonic) / 10;

    else
        sourceX = 0;

    if(sourceX >= al_get_bitmap_width(Sonic))
        sourceX = 0;

    sourceY = direcao;
}

// METODO PARA DESENHAR O JOGADOR
void Jogador::DesenhaJogador()
{
    if(posx <= 300)
        al_draw_bitmap_region(Sonic, sourceX, sourceY * al_get_bitmap_height(Sonic) / 3, 104, 125, posx, posy, NULL);

    else
        al_draw_bitmap_region(Sonic, sourceX, sourceY * al_get_bitmap_height(Sonic) / 3, 104, 125, 300, posy, NULL);
}

// PERGUNTAR PARA O PROFESSOR
void Jogador::DestroiTudo()
{
    al_destroy_bitmap(Sonic);
}

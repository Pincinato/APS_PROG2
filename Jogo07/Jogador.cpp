#include "Jogador.h"
#include <stdio.h>

#define DEBUG 0
// CONSTRUTORA DA CLASSE JOGADOR
Jogador::Jogador():Personagem()
{
    Forma = NULL;
    posx = 50;
    posy = 360;
    posy_pulo=posy;
    direcao = DIREITA;
    sourceX = 104;
    sourceY = 0;
    Forma = al_load_bitmap("/home/thiago/TeM/Jogo07/Imagens/Sonic.png");
    id++;
    myId=id;
// CarregaImagem(); // CARREGA AS IMAGENS DO PERSONAGEM
}

// DESTRUTORA DA CLASSE JOGADOR
Jogador::~Jogador()
{
    /*al_destroy_bitmap(Sonic);*/
}

// METODO PARA CARREGAR AS IMAGENS DO PERSONAGEM
void Jogador::CarregaImagem()
{
    Forma = al_load_bitmap("/home/thiago/TeM/Jogo07/Imagens/Sonic.png");
}

// METODO PARA OBTER A COORDENADA X DA POSICAO DO PERSONAGEM
float Jogador::GetX()
{
    return posx;
}

// METODO PARA OBTER A COORDENADA Y DA POSICAO DO PERSONAGEM
const int Jogador::GetposY(){

    return posy;
}

// METODO PARA ALTERAR A COORDENADA X DA POSICAO DO PERSONAGEM
void Jogador::SetposX(int x){

    posx=x;

}

// METODO PARA OBTER A COORDENADA X DA POSICAO DO PERSONAGEM
int Jogador::GetposX()
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
    if (pulando == 1)
    {
        if(DEBUG==1){printf("pulando\n");
        printf("pulando\n");
        printf("pulando\n");
        printf("pulando\n");
        printf("pulando\n");
        printf("pulando\n");}
        posy_pulo=posy_pulo+1;
        if(posy_pulo>=posy+altura_pulo)
            pulando=3;
        else
            pulando=2;
   }
   else if (pulando==3)
    {
        posy_pulo=posy_pulo-1;
        if(posy_pulo<=posy)
        {
            pulando=0;
        }
    }

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
        sourceX += al_get_bitmap_width(Forma) / 10;

    else
        sourceX = 0;

    if(sourceX >= al_get_bitmap_width(Forma))
        sourceX = 0;

    if(direcao == BAIXO)
        sourceY = CIMA;
    else  if(direcao != CIMA){
        sourceY = direcao;
        }
    else if (direcao==CIMA){
        if(pulando==0)
            pulando=1;

        if(DEBUG==1){printf("pulando\n");
        printf("pulando\n");
        printf("pulando\n");
        printf("pulando\n");
        printf("pulando\n");}
        }
}

// METODO PARA DESENHAR O JOGADOR
void Jogador::DesenhaJogador()
{
    if(posx <= 300)
        al_draw_bitmap_region(Forma, sourceX, sourceY * al_get_bitmap_height(Forma) / 3, 52, 63, posx, posy, NULL);

    else
        al_draw_bitmap_region(Forma, sourceX, sourceY * al_get_bitmap_height(Forma) / 3, 52, 63, 300, posy, NULL);
}

// PERGUNTAR PARA O PROFESSOR
void Jogador::DestroiTudo()
{
    al_destroy_bitmap(Forma);
}

void Jogador::MoveX(){

}

void Jogador::SetposY(const int y){

 posy=y;
}

const int Jogador::GetId(){

    return myId;
}

int Jogador::id=0;


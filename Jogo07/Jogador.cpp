#include "Jogador.h"
#include <stdio.h>

#define DEBUG 0
// CONSTRUTORA DA CLASSE JOGADOR
Jogador::Jogador():Personagem()
{
    Forma = NULL;
    this->posx = 50;
    this->posy = 360;
    this->posy_pulo=posy;
    this->direcao = DIREITA;
    this->sourceX = 104;
    this->sourceY = 0;
    this->Forma = al_load_bitmap("/home/thiago/TeM/Jogo07/Imagens/Sonic.png");
    id++;
    this->myId=id;
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

}

int Jogador::Pulo(){

  int posemy;
  if (pulando == 1  || pulando==2)
    {
        if(DEBUG==1){printf("pulando 2\n");}
        posy_pulo=posy_pulo-2;
        if(posy_pulo<=posy-altura_pulo){
            pulando=3;
            if(DEBUG==1){printf("pulando = 3 \n");}
            }
        else{
            pulando=2;
            if(DEBUG==1){printf("pulando = 2\n");}
            }
     posemy=posy_pulo;
     }
    else if (pulando==3)
    {
        if(DEBUG==1){printf("pulando = 3 descendo\n");}
        posy_pulo=posy_pulo+2;
        if(posy_pulo>=posy)
        {
            pulando=0;
        }
     posemy=posy_pulo;
    }
    return posemy;

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

    if(direcao == BAIXO){
        sourceY = CIMA;
        ataque=true;
        }
    else  if(direcao != CIMA){
        sourceY = direcao;
        ataque=false;
        }
    else if (direcao==CIMA){
        if(pulando==0){
            pulando=1;
            if(DEBUG==1){printf("pulando 1 \n");}
            }
        }
}

// METODO PARA DESENHAR O JOGADOR
void Jogador::DesenhaJogador()
{
    int posemy=0;
    if(pulando!=0){
        posemy=Pulo();
        }
    else
        posemy=posy;

    if(posx <= 300 )

        al_draw_bitmap_region(Forma, sourceX, sourceY * al_get_bitmap_height(Forma) / 3, 52, 63, posx, posemy, NULL);

    /*else if( posx >= 1200){
        al_draw_bitmap_region(Forma, sourceX, sourceY * al_get_bitmap_height(Forma) / 3, 52, 63, posx-1200, posy, NULL);
    }
    */
    else{
        al_draw_bitmap_region(Forma, sourceX, sourceY * al_get_bitmap_height(Forma) / 3, 52, 63, 300, posemy, NULL);

    }
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

const int Jogador::Getposy_pulo(){

    return posy_pulo;
}

const int Jogador::GetPulando(){

    return pulando;
}

const int Jogador::GetId(){

    return myId;
}

int Jogador::id=0;


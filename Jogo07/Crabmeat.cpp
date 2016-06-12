#include "Crabmeat.h"
#include <stdio.h>

#define DEBUG 0
// CONSTRUTORA DA CLASSE CRABMEAT
Crabmeat::Crabmeat():Inimigo()
{
    Forma = NULL;
    posxo = 400; // ATRIBUTO REFERENTE A COORDENADA X INICIAL DA POSICAO DO INIMIGO CRABMEAT
    velocidade = 1; // ATRIBUTO REFERENTE A VELOCIDADE DE MOVIMENTO DO INIMIGO CRABMEAT
    deslocamento=150;
    posx = posxo;
    posy = 400;
    sourceX = 50;
    sourceY = 0;
    direcao = 1;
    delay = false;
    std::string n;
    n.clear();
    n.append("Inimigo-Crabmeat");
    n.append("\0");
    control_posx=0;
    //strcpy(name,"Inimigo-Crabmeat \n");
    Set_Name(n);

    CarregaImagem(); // CARREGA AS IMAGENS DO PERSONAGEM
}

Crabmeat::Crabmeat(int position):Inimigo()
{

    Forma = NULL;
    posxo = position; // ATRIBUTO REFERENTE A COORDENADA X INICIAL DA POSICAO DO INIMIGO CRABMEAT
    velocidade = 1; // ATRIBUTO REFERENTE A VELOCIDADE DE MOVIMENTO DO INIMIGO CRABMEAT
    deslocamento=150;
    posx = posxo;
    posy = 400;
    sourceX = 50;
    sourceY = 0;
    direcao = 1;
    delay = false;
    std::string n;
    n.clear();
    n.append("Inimigo-Crabmeat \n");
    n.append("\0");
    control_posx=0;
    //strcpy(name,"Inimigo-Crabmeat \n");
    Set_Name(n);

    CarregaImagem();
}
// DESTRUTORA DA CLASSE CRABMEAT
Crabmeat::~Crabmeat()
{
    /*al_destroy_bitmap(crabmeat);*/
}

// METODO PARA CARREGAR AS IMAGENS DO PERSONAGEM
void Crabmeat::CarregaImagem()
{
    Forma = al_load_bitmap("/home/thiago/TeM/Jogo07/Imagens/Crabmeat.png");
}

// METODO PARA OBTER A COORDENADA X DA POSICAO DO PERSONAGEM
float Crabmeat::GetX()
{
    return posx;
}

// METODO PARA OBTER A COORDENADA Y DA POSICAO DO PERSONAGEM
float Crabmeat::GetY()
{
    return posy;
}
// METODO PARA ALTERAR A COORDENADA X DA POSICAO DO PERSONAGEM
void Crabmeat::SetX()
{
 /*  if(posx <= posxo)
    {
        direcao = 1;
        delay = true;
    }

    if(posx >= posxo + 150)
    {
        direcao = -1;
        delay = true;
    }

    posx += direcao * velocidade;
    delay = false;
    */
   if(DEBUG==1){printf(" Posicao posxo = %d \n",posxo);
   printf(" Posicao posx = %d \n",posx);
   printf(" Velocidade= %d \n",velocidade);
   printf(" Control = %d \n",control_posx);}
   if(control_posx<deslocamento/2)
   {
    posx=posx-1*velocidade;
    control_posx++;
   }
   else if( control_posx>=deslocamento/2){
    posx=posx+1*velocidade;
    control_posx++;
     if(control_posx==deslocamento+1){
      control_posx=0;
      }
    }
    if(DEBUG==1){printf("Posicao posx %d \n",posx);}
    }

// METODO PARA ALTERAR O SENTIDO DA IMAGEM
void Crabmeat::SetSources()
{
    if(!delay)
    {
        sourceX += al_get_bitmap_width(Forma) / 2;
        sourceY = 0;
    }

    else
    {
        sourceX = 0;
        sourceY = al_get_bitmap_height(Forma) / 2;
    }

    if(sourceX >= al_get_bitmap_width(Forma))
        sourceX = 0;
}

ALLEGRO_BITMAP* Crabmeat::GetBitmap(){

    return Forma;

}

// METODO PARA DESENHAR O INIMIGO CRABMEAT
void Crabmeat::DesenhaPersonagem()
{
    //al_draw_scaled_bitmap(crabmeat, sourceX, sourceY, 50, 35, posx, posy, 100, 70, NULL);
    al_draw_bitmap_region(Forma, sourceX, sourceY, 50, 35, posx, posy, NULL);
}

// PERGUNTAR PARA O PROFESSOR
void Crabmeat::DestroiTudo()
{
   al_destroy_bitmap(Forma);
}

void Crabmeat::MoveX(){

}

#include "Crabmeat.h"

// CONSTRUTORA DA CLASSE CRABMEAT
Crabmeat::Crabmeat()
{
    crabmeat = NULL;
    posx = posxo;
    posy = 400;
    sourceX = 50;
    sourceY = 0;
    direcao = 1;
    delay = false;

    CarregaImagem(); // CARREGA AS IMAGENS DO PERSONAGEM
}

// DESTRUTORA DA CLASSE CRABMEAT
Crabmeat::~Crabmeat()
{
    //al_destroy_bitmap(crabmeat);
}

// METODO PARA CARREGAR AS IMAGENS DO PERSONAGEM
void Crabmeat::CarregaImagem()
{
    crabmeat = al_load_bitmap("Imagens/Crabmeat.png");
}

// METODO PARA OBTER A COORDENADA X DA POSICAO DO PERSONAGEM
float Crabmeat::GetX()
{
    return posx;
}

int Crabmeat::GetposX(){

    return posx;
}

int Crabmeat::GetposY(){

    return posy;
}

void Crabmeat::SetposX(int x){

    posx=x;

}

// METODO PARA ALTERAR A COORDENADA X DA POSICAO DO PERSONAGEM
void Crabmeat::SetX()
{
    if(posx == posxo)
    {
        direcao = 1;
        delay = true;
    }

    if(posx == posxo + 150)
    {
        direcao = -1;
        delay = true;
    }

    posx += direcao * velocidade;
    delay = false;
}

// METODO PARA ALTERAR O SENTIDO DA IMAGEM
void Crabmeat::SetSources()
{
    if(!delay)
    {
        sourceX += al_get_bitmap_width(crabmeat) / 2;
        sourceY = 0;
    }

    else
    {
        sourceX = 0;
        sourceY = al_get_bitmap_height(crabmeat) / 2;
    }

    if(sourceX >= al_get_bitmap_width(crabmeat))
        sourceX = 0;
}

ALLEGRO_BITMAP * Crabmeat::GetBitmap(){

    return crabmeat;

}



// METODO PARA DESENHAR O INIMIGO CRABMEAT
void Crabmeat::DesenhaPersonagem()
{
    al_draw_scaled_bitmap(crabmeat, sourceX, sourceY, 50, 35, posx, posy, 100, 70, NULL);
    //al_draw_bitmap_region(crabmeat, sourceX, sourceY, 50, 35, posx, posy, NULL);
}

// PERGUNTAR PARA O PROFESSOR
void Crabmeat::DestroiTudo()
{
   al_destroy_bitmap(crabmeat);
}

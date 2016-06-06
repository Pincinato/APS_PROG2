#include "Crabmeat.h"

// CONSTRUTORA DA CLASSE CRABMEAT
Crabmeat::Crabmeat()
{
    for(int i = 0; i < 2; i++)
        crabmeat[i] = NULL;

    for(int i = 0; i < 4; i++)
        direcao[i] = false;

    posx = 500;
    posy = 360;
    sentido = true;

    CarregaImagem(); // CARREGA AS IMAGENS DO PERSONAGEM
    ConvertMask(); // DEIXA O BACKGROUND DAS IMAGENS COMO TRANSPARENTE
}

// DESTRUTORA DA CLASSE CRABMEAT
Crabmeat::~Crabmeat()
{
    /*for(int i = 0; i < 2; i++)
        al_destroy_bitmap(crabmeat[i]);*/
}

// METODO PARA CARREGAR AS IMAGENS DO PERSONAGEM
void Crabmeat::CarregaImagem()
{
    crabmeat[0] = al_load_bitmap("Imagens/Crabmeat/crabmeat01.bmp");
    crabmeat[1] = al_load_bitmap("Imagens/Crabmeat/crabmeat02.bmp");
}

// METODO PARA CONVERTER A MASCARA DE CORES DO PERSONAGEM
void Crabmeat::ConvertMask()
{
    for(int i = 0; i < 2; i++)
        al_convert_mask_to_alpha(crabmeat[i], al_map_rgb(0, 99, 191));
}

// METODO PARA OBTER A COORDENADA X DA POSICAO DO PERSONAGEM
int Crabmeat::GetX()
{
    return posx;
}

/*// METODO PARA ALTERAR A COORDENADA X DA POSICAO DO PERSONAGEM
void Crabmeat::SetX()
{
    if(posx >= 0)
        posx -= direcao[ESQUERDA];

    else
        posx = 0;

    posx += direcao[DIREITA];
} */

// METODO PARA ALTERAR A DIRECAO
void Crabmeat::SetDirecao(int i, bool Direcao)
{
    direcao[i] = Direcao;
}

// METODO PARA OBTER A DIRECAO
bool Crabmeat::GetDirecao(int i)
{
    return direcao[i];
}

// METODO PARA ALTERAR O SENTIDO DA IMAGEM
void Crabmeat::SetSentido(bool Sentido)
{
    sentido = Sentido;
}

// METODO PARA DESENHAR O INIMIGO CRABMEAT
void Crabmeat::DesenhaInimigo(int i)
{
    if(sentido == false)
    {
        if(posx == 600 || posx == 750)
            al_draw_bitmap(crabmeat[i], posx, 360, NULL);

        else
            al_draw_bitmap(crabmeat[i], posx, 360, ALLEGRO_FLIP_HORIZONTAL);
    }
    else
    {
        if(posx == 600 || posx == 750)
            al_draw_bitmap(crabmeat[i], posx, 360, NULL);

        else
            al_draw_bitmap(crabmeat[i], posx, 360, NULL);
    }
}

// PERGUNTAR PARA O PROFESSOR
void Crabmeat::DestroiTudo()
{
    for(int i = 0; i < 2; i++)
        al_destroy_bitmap(crabmeat[i]);

}

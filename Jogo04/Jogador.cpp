#include "Jogador.h"

// CONSTRUTORA DA CLASSE JOGADOR
Jogador::Jogador()
{
    for(int i = 0; i < 10; i++)
        Sonic[i] = NULL;

    for(int i = 0; i < 4; i++)
        direcao[i] = false;

    posx = 100;
    posy = 360;
    sentido = false;

    CarregaImagem(); // CARREGA AS IMAGENS DO PERSONAGEM
    ConvertMask(); // DEIXA O BACKGROUND DAS IMAGENS COMO TRANSPARENTE
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
    Sonic[0] = al_load_bitmap("Imagens/sonic01.bmp");
    Sonic[1] = al_load_bitmap("Imagens/sonic02.bmp");
    Sonic[2] = al_load_bitmap("Imagens/sonic03.bmp");
    Sonic[3] = al_load_bitmap("Imagens/sonic04.bmp");
    Sonic[4] = al_load_bitmap("Imagens/sonic05.bmp");
    Sonic[5] = al_load_bitmap("Imagens/sonic06.bmp");
    Sonic[6] = al_load_bitmap("Imagens/sonic07.bmp");
    Sonic[7] = al_load_bitmap("Imagens/sonic08.bmp");
    Sonic[8] = al_load_bitmap("Imagens/sonic09.bmp");
    Sonic[9] = al_load_bitmap("Imagens/sonic10.bmp");
}

// METODO PARA CONVERTER A MASCARA DE CORES DO PERSONAGEM
void Jogador::ConvertMask()
{
    for(int i = 0; i < 10; i++)
        al_convert_mask_to_alpha(Sonic[i], al_map_rgb(0, 0, 0));
}

// METODO PARA OBTER A COORDENADA X DA POSICAO DO PERSONAGEM
int Jogador::GetX()
{
    return posx;
}

// METODO PARA ALTERAR A COORDENADA X DA POSICAO DO PERSONAGEM
void Jogador::SetX()
{
    if(posx >= 0)
        posx -= direcao[ESQUERDA];

    else
        posx = 0;

    posx += direcao[DIREITA];
}

// METODO PARA ALTERAR A DIRECAO
void Jogador::SetDirecao(int i, bool Direcao)
{
    direcao[i] = Direcao;
}

// METODO PARA OBTER A DIRECAO
bool Jogador::GetDirecao(int i)
{
    return direcao[i];
}

// METODO PARA ALTERAR O SENTIDO DA IMAGEM
void Jogador::SetSentido(bool Sentido)
{
    sentido = Sentido;
}

// METODO PARA DESENHAR O JOGADOR
void Jogador::DesenhaJogador(int i)
{
    if(sentido == false)
    {
        if(posx > 300)
            al_draw_bitmap(Sonic[i], 300, 360, NULL);

        else
            al_draw_bitmap(Sonic[i], posx, 360, NULL);
    }
    else
    {
        if(posx > 300)
            al_draw_bitmap(Sonic[i], 300, 360, ALLEGRO_FLIP_HORIZONTAL);

        else
            al_draw_bitmap(Sonic[i], posx, 360, ALLEGRO_FLIP_HORIZONTAL);
    }
}

// PERGUNTAR PARA O PROFESSOR
void Jogador::DestroiTudo()
{
    for(int i = 0; i < 10; i++)
        al_destroy_bitmap(Sonic[i]);

}

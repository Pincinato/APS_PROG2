
// CLASSE CENARIO DESENHA TODOS OS CENARIOS DAS FASES
// AUTOR: JOSE GERALDO MIRACHI
// DATA: 10/03/2016 HORA: 10:44

#ifndef CENARIO_H_INCLUDED
#define CENARIO_H_INCLUDED
#include <allegro.h>
//#include "Inicializa.h"
#define SCREEN_W 820
#define SCREEN_H 640

/*
volatile int PosicaoNuvem; // ATRIBUTO INDICADOR DA POSICAO DA NUVEM
bool SentidoNuvem; // ATRIBUTO INDICADOR O SENTIDO DE MOVIMENTO DA NUVEM - FALSE = DIREITA E TRUE = ESQUERDA

void MoveNuvem(){
        if(SentidoNuvem == FALSE){
        PosicaoNuvem ++;
        if(PosicaoNuvem == 2800){
            SentidoNuvem = TRUE;
        }
    }else{
        PosicaoNuvem --;
        if(PosicaoNuvem == 2100){
            SentidoNuvem = FALSE;
        }
    }
}
END_OF_FUNCTION(MoveNuvem);
*/

// DEFININDO A CLASSE CENARIO
class Cenario{
private:
    int Fase; // ATRIBUTO QUE INDICA O NUMERO DA FASE
    int PosX; // ATRITUTO QUE AUXILIA A POSICAO INICIAL DO CENARIO NO EIXO X
    int PosY; // ATRIBUTO QUE AUXILIA A POSICAO INICIAL DO CENARIO NO EIXO Y
    volatile int PosicaoNuvem; // ATRIBUTO INDICADOR DA POSICAO DA NUVEM
    bool SentidoNuvem; // ATRIBUTO INDICADOR O SENTIDO DE MOVIMENTO DA NUVEM - FALSE = DIREITA E TRUE = ESQUERDA

    // PONTEIROS DO TIPO BITMAP PARA CARREGAR AS IMAGENS
    ALLEGRO_BITMAP *Buffer = al_create_bitmap(SCREEN_W, SCREEN_H);
    ALLEGRO_BITMAP *Sky = al_load_bitmap("Imagens/ceu.bmp");
    ALLEGRO_BITMAP *Floor_02 = al_load_bitmap("Imagens/chao_02.bmp");
    ALLEGRO_BITMAP *Floor_05 = al_load_bitmap("Imagens/chao_05.bmp");
    ALLEGRO_BITMAP *Trap = al_load_bitmap("Imagens/espinhos.bmp");
    ALLEGRO_BITMAP *River = al_load_bitmap("Imagens/rio.bmp");
    ALLEGRO_BITMAP *Clound = al_load_bitmap("Imagens/nuvem.bmp");
    ALLEGRO_BITMAP *Bridge = al_load_bitmap("Imagens/ponte.bmp");
    ALLEGRO_BITMAP *Bridge2 = al_load_bitmap("Imagens/ponte2.bmp");
    ALLEGRO_BITMAP *Door = al_load_bitmap("Imagens/porta2.bmp");

public:
    // DEFININDO A CONSTRUTORA DA CLASSE CENARIO
    Cenario(int fase);

    // DEFININDO A CONSTRUTORA SEM PARAMETROS DA CLASSE CENARIO
    Cenario();

    // DEFININDO A DESTRUTORA DA CLASSE CENARIO
    ~Cenario();

    // METODO PARA DESENHAR O CEU DA FASE
    void Ceu();

    // METODO PARA DESENHAR O CHAO DA FASE
    void Chao();

    // METODO PARA DESENHAR A PONTE
    void Ponte();

    // METODO PARA DESENHAR AS ARMADILHAS DA FASE
    void Armadilhas();

    // METODO PARA DESENHAR A PORTA DE SAIDA
    void Porta();

    // METODO PARA DESENHAR TODAS AS IMAGENS DO CENARIO
    void DesenhaCenario();

    // METODO PARA ATUALIZAR O CENARIO
    void AtualizaCenario();

    // METODO PARA MOVIMENTAR O CENARIO PARA A DIREITA
    void MoveRight();

    // METODO PARA MOVIMENTAR O CENARIO PARA A ESQUERDA
    void MoveLeft();

    // METODO PARA MOVIMENTAR A NUVEM DA FASE 01
    void MoveNuvem();
};

#endif // CENARIO_H_INCLUDED

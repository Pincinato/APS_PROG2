
#include "Cenario.h"
#include <iostream>
using namespace std;

// DEFININDO A CONSTRUTORA DA CLASSE CENARIO
Cenario::Cenario(int fase){
    Fase = fase;
    PosX = 0;
    PosY = 0;

    PosicaoNuvem = 2100;
    SentidoNuvem = 0;
///    LOCK_FUNCTION(MoveNuvem);
///    LOCK_VARIABLE(PosicaoNuvem);
    ///install_int_ex(MoveNuvem(), SECS_TO_TIMER(1));
}

// DEFININDO A CONSTRUTORA SEM PARAMETROS DA CLASSE CENARIO
Cenario::Cenario(){
    Fase = 1;
    PosX = 0;
    PosY = 0;

    PosicaoNuvem = 2100;
    SentidoNuvem = 0;
///    LOCK_FUNCTION(MoveNuvem);
///    LOCK_VARIABLE(PosicaoNuvem);
    ///install_int_ex(MoveNuvem, SECS_TO_TIMER(1));
}

// DEFININDO A DESTRUTORA DA CLASSE CENARIO
Cenario::~Cenario(){
    al_destroy_bitmap(Buffer);
    al_destroy_bitmap(Sky);
    al_destroy_bitmap(Floor_02);
    al_destroy_bitmap(Floor_05);
    al_destroy_bitmap(Trap);
    al_destroy_bitmap(River);
    al_destroy_bitmap(Clound);
    al_destroy_bitmap(Bridge);
    al_destroy_bitmap(Bridge2);
    al_destroy_bitmap(Door);
}

// METODO PARA DESENHAR O CEU DA FASE
void Cenario::Ceu(){
    if(Fase == 1){
        for(int i = 0; i < 5; i++){
            al_draw_bitmap (Buffer, int(Sky), int(PosX + i * 800), 0);
        }
    }
}

// METODO PARA DESENHAR O CHAO DA FASE
void Cenario::Chao(){
    if(Fase == 1){
        for(int i = 0; i < 4; i++){
            al_draw_bitmap(Buffer, int(Floor_02), int(PosX + i * 50), 500);
            al_draw_bitmap(Buffer, int(Floor_05), int(PosX + i * 50), 550);
        }
        for(int i = 0; i < 12; i++){
            al_draw_bitmap(Buffer, int(Floor_02), int(PosX + 300 + i * 50), 500);
            al_draw_bitmap(Buffer, int(Floor_05), int(PosX + 300 + i * 50), 550);
            }
        for(int i = 0; i < 5; i++){
            al_draw_bitmap(Buffer, int(Floor_02), PosX + 400 + i * 50, 450);
        }
        for(int i = 0; i < 12; i++){
            al_draw_bitmap(Buffer, int(Floor_02), PosX + 1500 + i * 50, 500);
            al_draw_bitmap(Buffer, int(Floor_05), PosX + 1500 + i * 50, 550);
        }
        for(int i = 0; i < 7; i++){
            al_draw_bitmap(Buffer, int(Floor_02), PosX + 2950 + i * 50, 500);
            al_draw_bitmap(Buffer, int (Floor_05), PosX + 2950 + i * 50, 550);
        }
    }
}

// METODO PARA DESENHAR A PONTE
void Cenario::Ponte(){
    if(Fase == 1){
        for(int i = 0; i < 14; i++){
          al_draw_bitmap_region (Buffer,int(Bridge), int(PosX + 850 + i * 50), 400, 50, 50);
        }
        al_draw_bitmap_region(Buffer, int (Bridge2), PosX + 850, 400, 50, 100);
        al_draw_bitmap_region(Buffer, Bridge2, PosX + 1500, 400, 50, 100);
    }
}

// METODO PARA DESENHAR AS ARMADILHAS DA FASE
void Cenario::Armadilhas(){
    if(Fase == 1){
        for(int i = 0; i < 2; i++){
            al_draw_bitmap_region(Buffer, Trap, PosX + 200 + i * 50, 550, 50, 50);
        }
        for(int i = 0; i < 12; i++){
            al_draw_bitmap_region(Buffer, River, PosX + 900 + i * 50, 550, 50, 50);
        }
        al_draw_bitmap_region(Buffer, Clound, PosX + PosicaoNuvem, 550, 150, 50);
    }
}

// METODO PARA DESENHAR A PORTA DE SAIDA
void Cenario::Porta(){
    stretch_sprite (Buffer, Door, PosX + 3100, 334, 150, 170);
}

// METODO PARA DESENHAR TODAS AS IMAGENS DO CENARIO
void Cenario::DesenhaCenario(){
    Ceu();
    Chao();
    Armadilhas();
    Ponte();
    Porta();
    draw_sprite(screen, Buffer, 0, 0);
}

// METODO PARA ATUALIZAR O CENARIO
void Cenario::AtualizaCenario(){

}

// METODO PARA MOVIMENTAR O CENARIO PARA A DIREITA
void Cenario::MoveRight(){
    if(PosX > -2500){
        PosX --;
    }
    cout << "POSICAO X: " << PosX << endl;
}

// METODO PARA MOVIMENTAR O CENARIO PARA A ESQUERDA
void Cenario::MoveLeft(){
    if(PosX < 0){
        PosX ++;
    }
    cout << "POSICAO X: " << PosX << endl;
}

// METODO PARA MOVIMENTAR A NUVEM DA FASE 01
void Cenario::MoveNuvem(){
    if(SentidoNuvem == 0){
        PosicaoNuvem ++;
        if(PosicaoNuvem == 2800){
            SentidoNuvem = 1;
        }
    }else{
        PosicaoNuvem --;
        if(PosicaoNuvem == 2100){
            SentidoNuvem = 0;
        }
    }
}

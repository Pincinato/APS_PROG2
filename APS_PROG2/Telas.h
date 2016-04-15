#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <string.h>
#include <iostream>
using namespace std;


class Telas{

 private:
    ALLEGRO_BITMAP *botao;
    ALLEGRO_DISPLAY *janela;
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    ALLEGRO_FONT *fonte;


 public:

 Telas();
 ~Telas();
 void Init(ALLEGRO_DISPLAY *janelas,ALLEGRO_EVENT_QUEUE *fila_evento, ALLEGRO_FONT *font);
 int Mostrar_tela_principal(int Largura_tela, int Altura_tela, int tamanho_fonte);
 int Mostrar_tela_opcoes_jogo(int Largura_tela, int Altura_tela, int tamanho_fonte);
 int Mostrar_tela_escolhe_jogador(int Largura_tela, int Altura_tela, int tamanho_fonte,int jogadores);
 int Limpa_tela();
 private:

 void Desenha_Botoes(int posicao_n[],int posicao_c [],int posicao_s[]);
 void Desenha_Strings(int posicao_n[],int posicao_c [],int posicao_s[], char* n, char* c, char* s, int tamanho_fonte);
 int Cria_Bitmap(int Largura_bitmap , int Altura_bitmap);
 int Detecta_click(int posicao_novo[], int posicao_continuar[], int posicao_sair[]);

};

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class Tela_Principal{

private:
  ALLEGRO_DISPLAY *janela;
  ALLEGRO_EVENT_QUEUE *fila_eventos;
  ALLEGRO_BITMAP *botao_sair;
  ALLEGRO_BITMAP *botao_novo_jogo;
  ALLEGRO_BITMAP *botao_continuar_jogo;
  ALLEGRO_FONT *fonte;
  int Largura_tela;
  int Altura_tela;
  int tamanho_fonte;


public:

 Tela_Principal();
 ~Tela_Principal();
 int Mostra_Tela();
 void Destroi_Tela();

private:

 void Init();
 int Cria_Janela();
 int Cria_Mouse();
 int Cria_Bitmap();
 int Cria_Evento();
 int Cria_Font();
 void Desenha_Botoes(int posicao_n[],int posicao_c [],int posicao_s[]);
 void Desenha_Strings(int posicao_n[],int posicao_c [],int posicao_s[]);
};



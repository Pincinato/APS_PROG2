#include "Telas.h"
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class Principal{

  Telas gerenciador_tela;
  ALLEGRO_DISPLAY *janelas;
  ALLEGRO_EVENT_QUEUE *fila_eventos;
  ALLEGRO_FONT *fonte;
  int Largura_tela;
  int Altura_tela;
  int tamanho_fonte;

public:

 Principal();
 ~Principal();
int Executar();

private:

 void Init();
 int Cria_Janela();
 int Cria_Mouse();
 int Cria_Evento();
 int Cria_Font();
 void Destroi_Tela();

};


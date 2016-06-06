#include "Telas.h"

Telas::Telas(){

}

Telas::~Telas(){

}

void Telas::Init(ALLEGRO_DISPLAY *janelas,ALLEGRO_EVENT_QUEUE *fila_evento, ALLEGRO_FONT *font){

 janela=janelas;
 fila_eventos=fila_evento;
 fonte=font;

}


void Telas::Desenha_Botoes(int posicao_n[],int posicao_c[], int posicao_s []){

    //Colorindo botoes
    cout<<"\n Desenha botoes \n"<<endl;
    al_set_target_bitmap(botao);
    al_clear_to_color(al_map_rgb(0, 0, 255));
    al_set_target_bitmap(al_get_backbuffer(janela));
    al_draw_bitmap(botao,posicao_n[0],posicao_n[1], 0);
    al_flip_display();

    al_set_target_bitmap(botao);
    al_clear_to_color(al_map_rgb(0,255, 0));
    al_set_target_bitmap(al_get_backbuffer(janela));
    al_draw_bitmap(botao,posicao_c[0],posicao_c[1],0);
    al_flip_display();

    al_set_target_bitmap(botao);
    al_clear_to_color(al_map_rgb(255, 0, 0));
    al_set_target_bitmap(al_get_backbuffer(janela));
    al_draw_bitmap(botao,posicao_s[0],posicao_s[1],0);
    al_flip_display();
}

void Telas::Desenha_Strings(int posicao_n[], int posicao_c[],int posicao_s[], char* n, char* c, char* s, int tamanho_fonte){

  al_draw_text(fonte, al_map_rgb(255, 255, 255), posicao_n[0] +al_get_bitmap_width(botao)/2, posicao_n[1] +tamanho_fonte, ALLEGRO_ALIGN_CENTRE,n);
  al_draw_text(fonte, al_map_rgb(255, 255, 255), posicao_c[0] +al_get_bitmap_width(botao)/2, posicao_c[1] +tamanho_fonte, ALLEGRO_ALIGN_CENTRE,c);
  al_draw_text(fonte, al_map_rgb(255, 255, 255), posicao_s[0] +al_get_bitmap_width(botao)/2, posicao_s[1] +tamanho_fonte, ALLEGRO_ALIGN_CENTRE, s);
  al_flip_display();

}

int Telas::Limpa_tela(){

return 0;
}





int Telas::Mostrar_tela_principal(int Largura_tela, int Altura_tela, int tamanho_fonte){

  cout<<"\nMostrar tela principal \n"<<endl;
  int ACK_L;
  ACK_L=Cria_Bitmap(Largura_tela/6,Altura_tela/6);
  if (ACK_L==-1)
  {
    return-1;
  }
  int posicao_continua[2],posicao_sai[2],posicao_nov[2];
  posicao_nov[0]=Largura_tela/2-al_get_bitmap_width(botao)/2;
  posicao_nov[1]=Altura_tela/4 -al_get_bitmap_height(botao)/2;
  posicao_continua[0]=posicao_nov[0];
  posicao_continua[1]=posicao_nov[1]+ al_get_bitmap_height(botao)+al_get_bitmap_height(botao)/2;
  posicao_sai[0]=posicao_continua[0];
  posicao_sai[1]=posicao_continua[1] +al_get_bitmap_height(botao)+ al_get_bitmap_height(botao)/2;
  Desenha_Botoes(posicao_nov,posicao_continua,posicao_sai);
  Desenha_Strings(posicao_nov,posicao_continua,posicao_sai,"Novo","Continua","Sair", tamanho_fonte);
  ACK_L=Detecta_click(posicao_nov,posicao_continua,posicao_sai);
return ACK_L;
}

int Telas::Mostrar_tela_opcoes_jogo(int Largura_tela,int Altura_tela, int tamanho_fonte)
{
  int ACK_L;
  int posicao_continua[2],posicao_sai[2],posicao_nov[2];
  posicao_nov[0]=Largura_tela/2-al_get_bitmap_width(botao)/2;
  posicao_nov[1]=Altura_tela/4 -al_get_bitmap_height(botao)/2;
  posicao_continua[0]=posicao_nov[0];
  posicao_continua[1]=posicao_nov[1]+ al_get_bitmap_height(botao)+al_get_bitmap_height(botao)/2;
  posicao_sai[0]=posicao_continua[0];
  posicao_sai[1]=posicao_continua[1] +al_get_bitmap_height(botao)+ al_get_bitmap_height(botao)/2;
  Desenha_Botoes(posicao_nov,posicao_continua,posicao_sai);
  Desenha_Strings(posicao_nov,posicao_continua,posicao_sai,"1-player","2-player","Voltar", tamanho_fonte);
  ACK_L=Detecta_click(posicao_nov,posicao_continua,posicao_sai);
return ACK_L;

}


int Telas::Mostrar_tela_escolhe_jogador(int Largura_tela,int Altura_tela,int tamanho_fonte,int jogadores)
{
  int ACK_L;
  al_destroy_bitmap(botao);
  Cria_Bitmap(70,70);
  int posicao_continua[2],posicao_sai[2],posicao_nov[2];
  posicao_nov[0]=Largura_tela/2-al_get_bitmap_width(botao)/2;
  posicao_nov[1]=Altura_tela/2 -al_get_bitmap_height(botao)/2;
  posicao_continua[0]=posicao_nov[0]+ al_get_bitmap_height(botao)+al_get_bitmap_height(botao)/2;
  posicao_continua[1]=posicao_nov[1];
  posicao_sai[0]=posicao_continua[0]+al_get_bitmap_height(botao)+ al_get_bitmap_height(botao)/2;
  posicao_sai[1]=posicao_continua[1];
  al_draw_text(fonte, al_map_rgb(255, 255, 255),Largura_tela/2, Altura_tela/10+tamanho_fonte, ALLEGRO_ALIGN_CENTRE,"Escolha um personagem");
  Desenha_Botoes(posicao_nov,posicao_continua,posicao_sai);
  Desenha_Strings(posicao_nov,posicao_continua,posicao_sai,"Blue"," Green","Red", tamanho_fonte);
  ACK_L=Detecta_click(posicao_nov,posicao_continua,posicao_sai);
  if (jogadores==2){
  al_draw_text(fonte, al_map_rgb(255, 255, 255),Largura_tela/2, Altura_tela/10+tamanho_fonte, ALLEGRO_ALIGN_CENTRE,"Player 2 escolha um personagem");
  al_flip_display();
  if(ACK_L==0)
  {
    Desenha_Botoes(posicao_nov,posicao_continua,posicao_sai);
    Desenha_Strings(posicao_nov,posicao_continua,posicao_sai,"1-p"," Green","Red", tamanho_fonte);
    posicao_nov[0]=0;
    posicao_nov[1]=0;
    ACK_L=Detecta_click(posicao_nov,posicao_continua,posicao_sai);
  }
  else if (ACK_L==1)
  {
    Desenha_Botoes(posicao_nov,posicao_continua,posicao_sai);
    Desenha_Strings(posicao_nov,posicao_continua,posicao_sai,"Blue"," 1-p","Red", tamanho_fonte);
    posicao_continua[0]=0;
    posicao_continua[1]=0;
    ACK_L=Detecta_click(posicao_nov,posicao_continua,posicao_sai);
  }
  else if (ACK_L==2)
  {
    Desenha_Botoes(posicao_nov,posicao_continua,posicao_sai);
    Desenha_Strings(posicao_nov,posicao_continua,posicao_sai,"Blue"," Green","1-p", tamanho_fonte);
    posicao_sai[0]=0;
    posicao_sai[1]=0;
    ACK_L=Detecta_click(posicao_nov,posicao_continua,posicao_sai);
    }
  }
return ACK_L;

}



int Telas::Cria_Bitmap(int Largura_bitmap,int Altura_bitmap)
{
    botao= al_create_bitmap(Largura_bitmap,Altura_bitmap);
    if (!botao)
    {
        fprintf(stderr, "Falha ao criar bitmap.\n");
        return -1;
    }
 return 1;
}

int Telas::Detecta_click(int posicao_novo[], int posicao_continuar[], int posicao_sair[])
{

  int sair=0;
  int continuar_jogo=0;
  int novo_jogo=0;
  while (sair==0 && continuar_jogo==0 && novo_jogo==0)
    {
       usleep(500);
        // Verificamos se há eventos na fila
        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);
            // Se o evento foi de click do mouse
            if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
            {
                // Verificamos se ele está sobre a região do retângulo central
                if (evento.mouse.x >= posicao_novo[0] &&
                    evento.mouse.x <= posicao_novo[0]+ al_get_bitmap_width(botao) &&
                    evento.mouse.y >= posicao_novo[1] &&
                    evento.mouse.y <= posicao_novo[1] + al_get_bitmap_height(botao))
                    {
                    novo_jogo = 1;
                    }
                if(evento.mouse.x >= posicao_continuar[0] &&
                   evento.mouse.x <= posicao_continuar[0]+ al_get_bitmap_width(botao) &&
                   evento.mouse.y >= posicao_continuar[1] &&
                   evento.mouse.y <= posicao_continuar[1] + al_get_bitmap_height(botao))
                    {
                    continuar_jogo=1;
                    }
                if(evento.mouse.x >= posicao_sair[0] &&
                    evento.mouse.x <= posicao_sair[0]+ al_get_bitmap_width(botao) &&
                    evento.mouse.y >= posicao_sair[1] &&
                    evento.mouse.y <= posicao_sair[1] + al_get_bitmap_height(botao))
                    {
                     sair=1;
                    }
             }
        }
        // Limpamos a tela
        al_clear_to_color(al_map_rgb(0, 0, 0));
    }

 if(novo_jogo==1){

  printf("\n novo jogo \n");
  return 0;
 }
  if (continuar_jogo==1){

  printf("\n continuar jogo\n");
  return 1;
  }
  if(sair==1){

  printf("\n Sair \n");
  return 2;
  }

 return -1;
}

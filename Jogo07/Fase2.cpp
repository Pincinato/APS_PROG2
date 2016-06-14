#include "Fase2.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <iostream>


#define DEBUG 0

Fase2::Fase2():Fase(){

 std::string Imagem;
 Imagem.clear();
 Imagem.append("/home/thiago/TeM/Imagem_Cenario/cenario02_1.png");
 Imagem.append("\0");
 Cenario01.CarregaImagem(&Imagem[0]);
 std::string n;
 n.clear();
 n.append("Fase2");
 n.append("\0");
 SetName(n);


}

Fase2::~Fase2(){
}

void Fase2::Inicia(bool op, int n_jogadores){

}

void Fase2::Salva(){

}

void Fase2::AjusteY_Jogador(int Y,Jogador *j){

    int novo_y;
    if(DEBUG==1){printf("Altura do sonic %d ",al_get_bitmap_height(j->Forma));}
    novo_y =Y-al_get_bitmap_height(j->Forma)/3;//Imagem do sonic é uma matris de 3 linhas
    j->SetposY(novo_y);
}

void Fase2::AjusteY(int Y,Personagem *p){

    int novo_y;
    if(DEBUG==1){printf("Altura do sonic %d ",al_get_bitmap_height(p->Forma));}
    novo_y =Y-al_get_bitmap_height(p->Forma)/2;//Imagem do sonic é uma matris de 3 linhas
    p->SetposY(novo_y);

}

bool Fase2::Joga_fase(){

    printf("Começando fase 2 \n");
    fim=false;
    /// ----------VARIÁVEIS DO JOGO----------
   /// ----------LOOP PRINCIPAL----------
    // INICIANDO O CONTADOR
    int i;
if(!fim){

    Jogador Player1;
    AjusteY_Jogador(y_cenario[0],&Player1);
    if(DEBUG==1){printf("Criando Inimigo \n");}
    Crabmeat Enemy1(700);
    Enemy1.SetDeslocamento(230);
    AjusteY(y_cenario[0],&Enemy1);
    inimigos.push_back(&Enemy1);
    Crabmeat Enemy2(800);
    AjusteY(y_cenario[0],&Enemy2);
    inimigos.push_back(&Enemy2);
    Crabmeat Enemy3(1700);
    Enemy3.SetDeslocamento(200);
    AjusteY(y_cenario[0],&Enemy3);
    inimigos.push_back(&Enemy3);
    if(DEBUG==1){printf("Crinado Cenario \n");}
    //Cenario Cenario01;


    /// ----------VARIÁVEIS DO JOGO----------
    // VARIAVEL REFERENTE AO LOOP PRINCIPAL DO JOGO
    /// teste para carregar os elementos
    if(load==true){
        if(DEBUG==1){printf("Carregando Inimigo \n ");}
        for(int i=0;i<3;i++)
            arquivo.Load_Inimigo(inimigos[i]);
        if(DEBUG==1){printf("Carregando Jogador \n");}
            arquivo.Load_Jogador(&Player1);
        if(DEBUG==1){printf("Carregando Cenario \n");}
            arquivo.Load_Cenario(&Cenario01);
    }
    ///
    botaoprecionado=false;
    while(!fim)
    {
    Play();
    if(salve==true){
        arquivo.Salva_jogo();
        arquivo.Salva_Fase(name);
        arquivo.Salva_Jogador(Player1);
        for(int i=0; i<3;i++)
            arquivo.Salva_Inimigo(inimigos[i]);
        arquivo.Salva_Cenario(&Cenario01);
        salve=false;
    }
    if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
     {
        Player1.SetDirecao(DIRECAO_F);
        Cenario01.SetDirecao(DIRECAO_F);
        if(DIRECAO_F==ESQUERDA || DIRECAO_F==DIRECAO_F){
        Enemy1.SetDirecao(DIRECAO_F);
        Enemy2.SetDirecao(DIRECAO_F);
        Enemy3.SetDirecao(DIRECAO_F);
        }

     }

        if(ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            if(DEBUG==1){printf("Botao precionado = false \n");}
            botaoprecionado = false;
        }

        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            if(DEBUG==1){printf("fim == TRUE \n");}
            fim = true;
        }

        else if(ev.type == ALLEGRO_EVENT_TIMER)
        {
            if(DEBUG==1){printf("ev.type ALLEGRO_EVENT_TIMER = true \n");}

            if(botaoprecionado)
            {
             if(DEBUG==1){printf("Botao precionado = true \n");}
                if(ALLEGRO_KEY_RIGHT || ALLEGRO_KEY_LEFT)
                {
                    if(DEBUG==1){printf("RIGHT ou LEFT TRUE \n");}
                    Player1.SetX();
                    Cenario01.SetX();
                    if((Cenario01.GetX())<0){
                      Enemy1.Ajusteposx();
                      Enemy2.Ajusteposx();
                      Enemy3.Ajusteposx();
                      for(i=1 ; i < 10;i++){
                        if(Cenario01.GetX()<= x_muda_cenario[i] && Cenario01.GetX() > x_muda_cenario[i+1]){
                            AjusteY_Jogador(y_cenario[i],&Player1);
                            i=10;
                            }
                        }
                      if (Cenario01.GetX() <= x_muda_cenario[10] ){
                        AjusteY_Jogador(y_cenario[10],&Player1);
                        }

                     }
                }

            if(DEBUG==1){cout << "Jogador: x = " << Player1.GetX() << endl;
                         cout << "Inimigo: x = " << Enemy1.GetX() << endl;}
            }
           if(Player1.GetposX() > (Enemy1.GetX()-al_get_bitmap_width(Enemy1.GetBitmap())/2 )&& Player1.GetX() < (Enemy1.GetX() +al_get_bitmap_width(Enemy1.GetBitmap())/2) )
            {
                if(Player1.GetposY() < (Enemy1.GetY()+al_get_bitmap_height(Enemy1.GetBitmap())/2 ))
                if(DEBUG==1){printf("Colidiu \n");}
            }
            Player1.SetSources(botaoprecionado);
            Enemy1.SetX();
            Enemy1.SetSources();
            Enemy2.SetX();
            Enemy2.SetSources();
            Enemy3.SetX();
            Enemy3.SetSources();
        }

        /// ----------DESENHO----------

        al_draw_filled_rectangle(0, 0, 800, 600, al_map_rgb(255, 255, 255));

        Cenario01.DesenhaCenario();
        if(DEBUG ==0) {cout << "POSICAO DO CENARIO: "<< Cenario01.GetX() << endl;}
        Player1.DesenhaJogador();
        Enemy1.DesenhaPersonagem();
        Enemy2.DesenhaPersonagem();
        Enemy3.DesenhaPersonagem();
        // DUPLO BUFFER
        al_flip_display();

        // LIMPANDO O BUFFER
        al_clear_to_color(al_map_rgb(0,0,0));
    }

    // PERGUNTAR AO PROFESSOR
    Player1.DestroiTudo();
    Enemy1.DestroiTudo();
    Enemy2.DestroiTudo();
    Enemy3.DestroiTudo();
    Gerenciador.DestroiTudo();
    Cenario01.DestroiTudo();
    //al_destroy_sample(sample);
   // Fase teste;
   // teste.Load_Jogo();
   return false;
    }
}


#include "Fase1.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <iostream>


#define DEBUG 0

Fase1::Fase1():Fase(){

 std::string Imagem;
 Imagem.clear();
 Imagem.append("/home/thiago/TeM/Imagem_Cenario/cenario01_2.png");
 Imagem.append("\0");
 Cenario01.CarregaImagem(&Imagem[0]);
 std::string n;
 n.clear();
 n.append("Fase1");
 n.append("\0");
 SetName(n);


}

Fase1::~Fase1(){
}

void Fase1::Inicia(bool op, int n_jogadores){

}

void Fase1::Tratamento_colisao(Inimigo *EnemyA,int x,Jogador *player)
{
    //printf("posicao jogador %d\n posicao Inimigo%d \n",player->GetposX(),EnemyA->GetposX());
    if(EnemyA->GetposX()+al_get_bitmap_width(EnemyA->Forma)/4 > 300 && EnemyA->GetposX()-al_get_bitmap_width(EnemyA->Forma)/4<=300)
        {
        if(DEBUG==0){printf("Colisão \n");}
         if(player->ataque==true)
         {
            EnemyA->vivo=false;
         }
         else
            player->vivo=false;
        }
}

void Fase1::AjusteY_Jogador(int Y,Jogador *j){

    int novo_y;
    if(DEBUG==1){printf("Altura do sonic %d ",al_get_bitmap_height(j->Forma));}
    novo_y =Y-al_get_bitmap_height(j->Forma)/3;//Imagem do sonic é uma matris de 3 linhas
    j->SetposY(novo_y);
}

void Fase1::AjusteY(int Y,Personagem *p){

    int novo_y;
    if(DEBUG==1){printf("Altura do sonic %d ",al_get_bitmap_height(p->Forma));}
    novo_y =Y-al_get_bitmap_height(p->Forma)/2;//Imagem do sonic é uma matris de 3 linhas
    p->SetposY(novo_y);

}

void Fase1::Salve(){



}

void Fase1::Load(){

}

void Fase1::Joga_fase(){

    fim=false;
  //  Init();

    int i=0;
if(!fim){

    if(DEBUG==1){printf("Criando jogador \n");}
    Jogador Player1;
    AjusteY_Jogador(y_cenario[0],&Player1);
    if(DEBUG==1){printf("Criando Inimigo \n");}
    Crabmeat Enemy1(900);
    AjusteY(y_cenario[3],&Enemy1);
    inimigos.push_back(&Enemy1);
    Crabmeat Enemy2(1100);
    Enemy2.SetDeslocamento(270);
    AjusteY(y_cenario[3],&Enemy2);
    inimigos.push_back(&Enemy2);
    Crabmeat Enemy3(1300);
    Enemy3.SetDeslocamento(170);
    AjusteY(y_cenario[3],&Enemy3);
    inimigos.push_back(&Enemy3);
   if(DEBUG==1){printf("Crinado Cenario \n");}
    //Cenario Cenario01;
    ///Atualiza posição dos inimigos
   /* x_inimigo[0]=x_inimigo[0]-Enemy1.Getdeslocamento();
    x_inimigo[1]=x_inimigo[1]-Enemy2.Getdeslocamento();
    x_inimigo[2]=x_inimigo[2]-Enemy3.Getdeslocamento();
    */
    /// ----------VARIÁVEIS DO JOGO----------
    // VARIAVEL REFERENTE AO LOOP PRINCIPAL DO JOGO
    /// teste para carregar os elementos
    if(load==true){
        Load();
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
    if(DEBUG==1){
    if(Enemy1.Getcontrol_posx()>=Enemy1.Getdeslocamento()/2)
        //cout << "Teste = " << (x_inimigo[0]-Enemy1.Getdeslocamento()/2 + (Enemy1.Getcontrol_posx()*Enemy1.Getvelocidade())/2)-(Enemy1.Getdeslocamento()/2-(Enemy1.Getcontrol_posx()-Enemy1.Getdeslocamento()/2)*2) << endl;
        cout<< "Teste p2 = "<<x_inimigo[0] - (+Enemy1.Getcontrol_posx()-Enemy1.Getdeslocamento()/2) <<endl;
    else
        //cout << "Teste = " << (x_inimigo[0] - (Enemy1.Getcontrol_posx()*Enemy1.Getvelocidade()))-(Enemy1.Getdeslocamento()/2-Enemy1.Getcontrol_posx()*2) << endl;
        cout << "Teste = "<<x_inimigo[0]-Enemy1.Getdeslocamento()/2+Enemy1.Getcontrol_posx()<<endl;
        }
    if(salve==true){
        Salve();
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
                    /*  if(Cenario01.GetX()== (x_inimigos[0]-460))
                        {
                        Enemy1.SetposX(460);
                        Enemy1.SetControl_posx(0);
                        Enemy1.SetDirecao(0);
                        AjusteY(y_cenario[3],&Enemy1);
                        if(DEBUG==0){printf(" inimigo 1 posicao %d",y_cenario[3]);}
                        }
                      else if(Cenario01.GetX()== (x_inimigos[1]-460))
                        {
                        Enemy2.SetposX(460);
                        Enemy2.SetControl_posx(0);
                        Enemy2.SetDirecao(0);
                        AjusteY(y_cenario[3],&Enemy2);
                        if(DEBUG==0){printf(" inimigo 1 posicao %d",y_cenario[3]);}
                        }
*/                     ///Verifica obstáculos
                       for(i=1 ; i < 5;i++){
                        if(Cenario01.GetX()<= x_muda_cenario[i] && Cenario01.GetX() > x_muda_cenario[i+1]){
                            AjusteY_Jogador(y_cenario[i],&Player1);
                            i=6;
                            }
                        }
                      if (Cenario01.GetX() <= x_muda_cenario[5] ){
                        AjusteY_Jogador(y_cenario[5],&Player1);
                        }
                        ///Fim do obstáculos.
                        ///Tratamento de colisão personagem 1
                     }
                }

            if(DEBUG==1){cout << "Jogador: x = " << Player1.GetX() << endl;
                         cout << "Inimigo: x1 = " << Enemy1.GetX() << endl;
                         cout << "Inimigo: x2 = " << Enemy2.GetX() << endl;
                         cout << "Inimigo: x3 = " << Enemy3.GetX() << endl;
                         }
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
        if(DEBUG ==1) {cout << "POSICAO DO CENARIO: "<< Cenario01.GetX() << endl;}
         if(DEBUG==1){printf("Tratamento de colisão Cenario \n");}
        if(Cenario01.GetX()<=x_inimigo[0] && Cenario01.GetX() > x_inimigo[0] -Enemy1.Getdeslocamento()/2-al_get_bitmap_width(Enemy1.Forma)/2 )
            {
            Tratamento_colisao(&Enemy1,x_inimigo[0],&Player1);
            }
        else if(Cenario01.GetX()<=x_inimigo[1] && Cenario01.GetX() > x_inimigo[1] -Enemy2.Getdeslocamento()/2-al_get_bitmap_width(Enemy2.Forma)/2 )
            {
            Tratamento_colisao(&Enemy2,x_inimigo[1],&Player1);
            }
        else if(Cenario01.GetX()<=x_inimigo[2] && Cenario01.GetX() > x_inimigo[2] -Enemy3.Getdeslocamento()/2-al_get_bitmap_width(Enemy3.Forma)/2 )
            {
            Tratamento_colisao(&Enemy3,x_inimigo[2],&Player1);
            }
        ///Fim do tratamento de colisoes inimigos
        Player1.DesenhaJogador();
        if(Enemy1.vivo)
            Enemy1.DesenhaPersonagem();
        if(Enemy2.vivo)
            Enemy2.DesenhaPersonagem();
        if(Enemy3.vivo)
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
    }
}

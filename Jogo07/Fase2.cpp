#include "Fase2.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <iostream>
#include <string>


#define DEBUG 0

Fase2::Fase2():Fase(){

 std::string Imagem;
 Imagem.clear();
 Imagem.append("/home/thiago/TeM/Imagem_Cenario/cenario02_3.png");
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

void Fase2::Tratamento_colisao(Inimigo *EnemyA,int x,Jogador *player)
{
    //printf("posicao jogador %d\n posicao Inimigo%d \n",player->GetposX(),EnemyA->GetposX());
   if(EnemyA->vivo){
    if(EnemyA->GetposX()+al_get_bitmap_width(EnemyA->Forma)/4 > 300 && EnemyA->GetposX()-al_get_bitmap_width(EnemyA->Forma)/4<=300)
        {
        if(player->GetPulando()!=0){
            if(DEBUG==0){printf("posicao player em y = %d \n  posicao do inimigo em y %d \n",player->Getposy_pulo()+al_get_bitmap_height(player->Forma)/6,EnemyA->GetposY()-al_get_bitmap_height(EnemyA->Forma)/2);}
            if(player->Getposy_pulo()+al_get_bitmap_height(player->Forma)/6>=EnemyA->GetposY()-al_get_bitmap_height(EnemyA->Forma)/2)
            {
                if(DEBUG==0){printf("Colisão por cima \n");}
                if(player->ataque==true)
                {
                    EnemyA->vivo=false;
                }
                else if(strcmp(EnemyA->Get_Name(),"Inimigo-Crabmeat")==0)
                    player->vivo=false;
                else if(strcmp(EnemyA->Get_Name(),"Inimigo-Crabmeat")!=0)
                    EnemyA->vivo=false;
            }
        }
        else{
            if(DEBUG==0){printf("Colisão \n");}
            if(player->ataque==true)
            {
                EnemyA->vivo=false;
            }
            else
            {
                player->vivo=false;
            }
          }
        }

    }
}

void Fase2::AjusteY_Jogador(int Y,Jogador *j){

    int novo_y;
    int aux=0;
    int i=0;
    if(DEBUG==1){printf("Altura do sonic %d ",al_get_bitmap_height(j->Forma));}
    novo_y =Y-al_get_bitmap_height(j->Forma)/3;//Imagem do sonic é uma matris de 3 linhas
    j->SetposY(novo_y);
    for(i=0;i<3;i++)
        {
         if(DEBUG==0){printf("x_obstaculo %d \n",x_obstaculo[i]);}
            if(Cenario01.GetX()<x_obstaculo[i] && Cenario01.GetX()>=x_obstaculo[i+1])
               {
               aux=i;
               i=4;
               }

        }
    if(i==3)
        aux=3;
    if(Cenario01.GetX()<= x_obstaculo[aux] && Cenario01.GetX() > x_obstaculo[aux]-20)
     if(j->GetposX() >= 60 && j->GetPulando()==0)
    {
        j->DesenhaJogador();
        usleep(50);
        j->vivo=false;

    }

}

void Fase2::AjusteY(int Y,Personagem *p){

    int novo_y;
    if(DEBUG==1){printf("Altura do sonic %d ",al_get_bitmap_height(p->Forma));}
    novo_y =Y-al_get_bitmap_height(p->Forma)/2;//Imagem do sonic é uma matris de 3 linhas
    p->SetposY(novo_y);

}

void Fase2::Salve(){



}

void Fase2::Load(){

}

bool Fase2::Joga_fase(){

    fim=false;
    bool passou =false;
    int i=0;
if(!fim){

    if(DEBUG==1){printf("Criando jogador \n");}
    Jogador Player1;
    AjusteY_Jogador(y_cenario[0],&Player1);
    Jogador Player2;
    if(player_2==true)
        AjusteY_Jogador(y_cenario[0],&Player2);
    if(DEBUG==1){printf("Criando Inimigo \n");}
    Crabmeat Enemy1(800);
    Enemy1.SetDeslocamento(200);
    AjusteY(y_cenario[4],&Enemy1);
    inimigos.push_back(&Enemy1);
    Crabmeat Enemy2(900);
    AjusteY(y_cenario[4],&Enemy2);
    inimigos.push_back(&Enemy2);
    Crabmeat Enemy3(1425);
    Enemy3.SetDeslocamento(50);
    AjusteY(y_cenario[8],&Enemy3);
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
            if(player_2==true)
                arquivo.Load_Jogador(&Player2);
        if(DEBUG==1){printf("Carregando Cenario \n");}
            arquivo.Load_Cenario(&Cenario01);

    }
    ///
    botaoprecionado=false;
    botaoprecionado2=false;
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
        arquivo.Salva_Jogador(&Player1);
        if(player_2==true)
            arquivo.Salva_Jogador(&Player2);
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
        if(player_2)
            Player2.SetDirecao(DIRECAO_P2);
        }

     }

        if(ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            if(DEBUG==1){printf("Botao precionado = false \n");}
            botaoprecionado = false;
            botaoprecionado2 = false;
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
                       ///Verifica obstáculos
                       for(i=1 ; i < 10;i++){
                        if(Cenario01.GetX()<= x_muda_cenario[i] && Cenario01.GetX() > x_muda_cenario[i+1]){
                            AjusteY_Jogador(y_cenario[i],&Player1);
                            i=11;
                            }
                        }
                      if (Cenario01.GetX() <= x_muda_cenario[10] ){
                        AjusteY_Jogador(y_cenario[10],&Player1);
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
            if(botaoprecionado2==true && player_2==true){
                 if(ALLEGRO_KEY_A || ALLEGRO_KEY_D)
                {
                    if(DEBUG==1){printf("RIGHT ou LEFT TRUE \n");}
                    if(Player2.GetposX()<300)
                        Player2.SetX();
                    //Cenario01.SetX();
                    if((Cenario01.GetX())<0){
                      for(i=1 ; i < 10;i++){
                        if(Cenario01.GetX()<= x_muda_cenario[i] && Cenario01.GetX() > x_muda_cenario[i+1]){
                            AjusteY_Jogador(y_cenario[i],&Player2);
                            i=11;
                            }
                        }
                      if (Cenario01.GetX() <= x_muda_cenario[10] ){
                        AjusteY_Jogador(y_cenario[10],&Player2);
                        }
                     }
                }


            }
           if(Player1.GetposX() > (Enemy1.GetX()-al_get_bitmap_width(Enemy1.GetBitmap())/2 )&& Player1.GetX() < (Enemy1.GetX() +al_get_bitmap_width(Enemy1.GetBitmap())/2) )
            {
                if(Player1.GetposY() < (Enemy1.GetY()+al_get_bitmap_height(Enemy1.GetBitmap())/2 ))
                if(DEBUG==1){printf("Colidiu \n");}
            }
            Player1.SetSources(botaoprecionado);
            if(player_2==true)
                Player2.SetSources(botaoprecionado2);
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
        ///Final da Fase
        if(Cenario01.GetX()<=-1200)
            {
            fim=true;
            passou=true;
            }
        ///
        if(Player1.vivo==false)
        {
        ///chama ima imagem de game over
            fim=true;
            passou=false;
        }
        Player1.DesenhaJogador();
        if(player_2==true && Player2.vivo==true)
            Player2.DesenhaJogador();
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
    Player2.DestroiTudo();
    Enemy1.DestroiTudo();
    Enemy2.DestroiTudo();
    Enemy3.DestroiTudo();
    //Gerenciador.DestroiTudo();
    Cenario01.DestroiTudo();
    return passou;
    //al_destroy_sample(sample);
   // Fase teste;
   // teste.Load_Jogo();
    }
}


/*



                if(player_2==true){
                    if(ALLEGRO_KEY_A || ALLEGRO_KEY_D)
                    {
                    Player2.SetX();
                        if(ALLEGRO_KEY_A)
                            Player2.SetDirecao(ESQUERDA);
                        else
                            Player2.SetDirecao(DIREITA);
                    }
                    else if(ALLEGRO_KEY_W)
                    {
                        Player2.SetDirecao(CIMA);
                    }
                    else if(ALLEGRO_KEY_S)
                    {
                        Player2.SetDirecao(BAIXO);
                    }
            }


            */

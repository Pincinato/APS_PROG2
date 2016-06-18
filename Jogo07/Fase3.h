

#ifndef Fase3_H_INCLUDED
#define Fase3_H_INCLUDED
#include <string.h>
#include "GerenciadorArquivo.h"
#include "GerenciadorGrafico.h"
#include "Crabmeat.h"
#include "Jogador.h"
#include "Cenario.h"
#include "Fase.h"

class Fase3 : public Fase
{
public:
    Fase3();
    virtual ~Fase3();
    void Inicia(bool op, int n_jogadores);
    bool Joga_fase();
    void AjusteY(int Y, Personagem *p);
    void AjusteY_Jogador(int Y, Jogador *j);
    void Tratamento_colisao(Inimigo *EnemyA,int x,Jogador *player);
    void Salve();
    void Load();

private:
    Cenario Cenario01;
    int y_cenario[15]={420,435,470,460,470,460,470,460,470,460,470,460,470,435,420};// nivel2 457 pedra 466 lava 470
    int x_muda_cenario[15]={0,-44,-86,-102,-128,-148,-176,-194,-224,-240,-286,-318,-374,-408,-596}; //16
    const int x_obstaculo[6]={-86,-128,-176,-224,-286,-374};
    int x_inimigo[5]={-668,-698,-820,-838,-880};
};

#endif



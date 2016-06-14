
#ifndef FASE1_H_INCLUDED
#define FASE1_H_INCLUDED
#include <string.h>
#include "GerenciadorArquivo.h"
#include "GerenciadorGrafico.h"
#include "Crabmeat.h"
#include "Jogador.h"
#include "Cenario.h"
#include "Fase.h"



class Fase1 : public Fase
{
public:
    Fase1();
    virtual ~Fase1();
    void Inicia(bool op, int n_jogadores);
    void Joga_fase();
    void AjusteY(int Y, Personagem *p);
    void AjusteY_Jogador(int Y, Jogador *j);
    void Tratamento_colisao(Inimigo *EnemyA,int x,Jogador *player);
    void Salve();
    void Load();

private:
    Cenario Cenario01;
    int y_cenario[6]={438,487,438,471,520,471};
    int x_muda_cenario[6]={0,-18,-150,-358,-1322,-1384};
    int x_inimigo[3]={-510,-660,-880};

};

#endif


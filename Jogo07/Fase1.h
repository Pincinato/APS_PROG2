
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
    bool Joga_fase();
    void AjusteY(int Y, Personagem *p);
    void AjusteY_Jogador(int Y, Jogador *j);
    void Tratamento_colisao(Inimigo *EnemyA,int x,Jogador *player);
    void Salve();
    void Load();
    bool Get_load();

private:
    Cenario Cenario01;
    int y_cenario[8]={438,487,438,487,438,471,520,471};
    int x_muda_cenario[8]={0,-118,-158,-214,-252,-358,-902,-964};//-1322,-1384};
    int x_obstaculo[4]={-118,-214,-902};
    int x_inimigo[3]={-510,-660,-980};

};

#endif


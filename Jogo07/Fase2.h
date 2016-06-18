
#ifndef FASE2_H_INCLUDED
#define FASE2_H_INCLUDED
#include <string.h>
#include "GerenciadorArquivo.h"
#include "GerenciadorGrafico.h"
#include "Crabmeat.h"
#include "Jogador.h"
#include "Cenario.h"
#include "Fase.h"

class Fase2 : public Fase
{
public:
    Fase2();
    virtual ~Fase2();
    void Inicia(bool op, int n_jogadores);
    bool Joga_fase();
    void AjusteY(int Y, Personagem *p);
    void AjusteY_Jogador(int Y, Jogador *j);
    void Tratamento_colisao(Inimigo *EnemyA,int x,Jogador *player);
    void Salve();
    void Load();

private:
    Cenario Cenario01;
    int y_cenario[11]={490,600,457,600,490,466,442,600,457,600,457};
    int x_muda_cenario[11]={0,-160,-176,-228,-254,-886,-950,-1032,-1072,-1170,-1190}; //16
    const int x_obstaculo[4]={-160,-228,-1032,-1170};
    int x_inimigo[3]={-384,-504,-1074};
};

#endif



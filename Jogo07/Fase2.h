
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
    void Salva();
    void AjusteY(int Y, Personagem *p);
    void AjusteY_Jogador(int Y, Jogador *j);

private:
    Cenario Cenario01;
    int y_cenario[11]={490,600,457,600,490,466,442,600,457,600,490};
    int x_muda_cenario[11]={0,-182,-202,-262,-280,-886,-950,-1036,-1072,-1176,-1208};

};

#endif



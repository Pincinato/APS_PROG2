#ifndef FASE_H_INCLUDED
#define FASE_H_INCLUDED
#include "GerenciadorArquivo.h"
#include "GerenciadorGrafico.h"
#include "Crabmeat.h"
#include "Jogador.h"
#include "Personagem.h"

//enum DIRECAO{DIREITA, ESQUERDA, CIMA, BAIXO};

class Fase
{
public:
    Fase();
    virtual ~Fase();
    void Init();
    void Play();
    //void SetGerenciador(GerenciadorGrafico g);
    //virtual void Joga_fase();
protected:
    GerenciadorGrafico Gerenciador;
    GerenciadorArquivo arquivo;
    // CRIANDO UM EVENTO
    ALLEGRO_EVENT ev;
    bool load;
    bool salve;
    bool fim;
    bool botaoprecionado;
    int DIRECAO_F;



};

#endif


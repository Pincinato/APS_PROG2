#ifndef FASE_H_INCLUDED
#define FASE_H_INCLUDED
#include "GerenciadorArquivo.h"
#include "GerenciadorGrafico.h"
#include "Crabmeat.h"
#include "Jogador.h"
#include "Personagem.h"
#include <vector>
#include <string>

//enum DIRECAO{DIREITA, ESQUERDA, CIMA, BAIXO};

class Fase
{
public:
    Fase();
    virtual ~Fase();
    void Transfere(GerenciadorGrafico *Gra, ALLEGRO_EVENT *e,GerenciadorGrafico *Graf, ALLEGRO_EVENT *evento);
    void Init(bool l,bool player);
    void Destroi();
    void Play();
    void SetName(std::string n);
    const char * GetName();



    //void SetGerenciador(GerenciadorGrafico g);
    //virtual void Joga_fase();
protected:
    GerenciadorGrafico Gerenciador;
    GerenciadorArquivo arquivo;
    vector<Inimigo *> inimigos;
    // CRIANDO UM EVENTO
    ALLEGRO_EVENT ev;
    bool load;
    bool salve;
    bool fim;
    bool player_2;
    bool botaoprecionado;
    int DIRECAO_F;
    std::string name;




};

#endif


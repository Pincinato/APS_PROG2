#ifndef INIMIGO_H_INCLUDED
#define INIMIGO_H_INCLUDED
#include <string>
#include "Personagem.h"

class Inimigo:public Personagem
{
public:
    Inimigo();
    virtual ~Inimigo();
    //virtual void  Movex();
    const char* Get_Name();
    const int GetposX();
    const int GetposY();
    const int Getposxo();
    const int Getdirecao();
    const int Getvelocidade();
    const int Getdeslocamento();
    const int Getcontrol_posx();
    void Set_Name(std::string n);
    void SetposX(const int x);
    void SetposY(const int y);
    void SetDirecao(const int d);
    void SetVelocidade(const int v);
    void SetDeslocamento(const int des);
    void SetPosxo(const int po);
    void SetControl_posx(const int control);
    void Ajusteposx();


protected:


    int direcao,posxo,posx, posy;
    int velocidade,deslocamento;
    int control_posx;
    std::string name;
};

#endif // INIMIGO_H_INCLUDED

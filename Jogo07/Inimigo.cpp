#include "Inimigo.h"

Inimigo::Inimigo():Personagem()
{
    //Actor
}

Inimigo::~Inimigo()
{
    //dtor
}

/*
virtual void Inimigo::MoveX(){

}
*/

const char* Inimigo::Get_Name(){

    return &name[0];
}

const int Inimigo:: GetposX(){

 return posx;
}

const int Inimigo::GetposY(){

 return posy;
}

void Inimigo::Set_Name(std::string n){

 name.clear();
 name.append(n);
 name.append("\0");
}

void Inimigo::SetposX(const int x){

   posx=x;
}

void Inimigo::SetposY(const int y){

    posy=y;

}

void Inimigo::Ajusteposx()
{
 if(direcao==0)
    {
    posx=posx-2;
    }
 if(direcao==1)
 {
    posx=posx+2;
 }
 //posx=posxo;
}

const int Inimigo::Getposxo(){

    return posxo;

}


const int Inimigo::Getdeslocamento(){

    return deslocamento;
}

const int Inimigo::Getvelocidade(){

    return velocidade;

}

const int Inimigo::Getdirecao(){

    return direcao;

}

const int Inimigo::Getcontrol_posx(){

    return control_posx;
}

void Inimigo::SetDirecao(const int d){

    direcao=d;

}


void Inimigo::SetPosxo(const int po){

    posxo=po;

}


void Inimigo::SetDeslocamento(const int des){
    deslocamento=des;

}

void Inimigo::SetVelocidade(const int v){

    velocidade=v;
}

void Inimigo::SetControl_posx(const int control){

    control_posx=control;
}

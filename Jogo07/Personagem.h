#ifndef PERSONAGEM_H_INCLUDED
#define PERSONAGEM_H_INCLUDED

class Personagem
{
public:
    Personagem();
    virtual ~Personagem();
    virtual void MoveX()=0;
    virtual void SetposY(const int y)=0;

protected:
    bool estado;
};

#endif


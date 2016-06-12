#ifndef PERSONAGEM_H_INCLUDED
#define PERSONAGEM_H_INCLUDED

class Personagem
{
public:
    Personagem();
    virtual ~Personagem();
    void MoveX();

protected:
    bool estado;
};

#endif


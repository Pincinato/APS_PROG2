#ifndef PERSONAGEM_H_INCLUDED
#define PERSONAGEM_H_INCLUDED
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class Personagem
{
public:
    Personagem();
    virtual ~Personagem();
    virtual void MoveX()=0;
    virtual void SetposY(const int y)=0;
    virtual const int GetposY()=0;
    ALLEGRO_BITMAP *Forma;

protected:
    bool estado;

};

#endif


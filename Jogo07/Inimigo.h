#ifndef INIMIGO_H_INCLUDED
#define INIMIGO_H_INCLUDED
#include <string>

class Inimigo
{
public:
    Inimigo();
    virtual ~Inimigo();
    const char* Get_Name();
    const int GetposX();
    const int GetposY();
    void Set_Name(std::string n);
    void SetposX(const int x);
    void SetposY(const int y);


    int posx, posy;
    std::string name;
};

#endif // INIMIGO_H_INCLUDED

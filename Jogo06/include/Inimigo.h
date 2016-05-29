#ifndef INIMIGO_H
#define INIMIGO_H
#include <string>

class Inimigo
{
    protected:
        static int id;
    public:
        Inimigo();
        virtual ~Inimigo();
        const char* Get_Name();
        const int GetposX();
        const int GetposY();
        const int GetId();
        void Set_Name(std::string n);
        void SetposX(const int x);
        void SetposY(const int y);
        int posx, posy,myId;
        std::string name;
};


#endif // INIMIGO_H

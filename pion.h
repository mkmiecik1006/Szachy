#ifndef PION_H
#define PION_H
#include "bierka.cpp"


class Pion : public Bierka
{
    bool    pierwszy = false;   //czy wykonano pierwszy ruch

public:
    Pion();
    Pion(char k, int n) :Bierka(k, n){};
    int rusz(int x, int y) override
    {

        if( pozycja[0]==x) //ta sama kolumna
        {
            if(pozycja[1]==y+1)
            {
                return 0;
            }
            else if(pierwszy==false&&pozycja[1]==y+2)
            {
                return 0;
            }
            else
            {
                return 1;
            }

        }
    }
    int promotuj()
    {
        return 0;
    }



};

#endif // PION_H

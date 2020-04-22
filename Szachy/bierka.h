#ifndef BIERKA_H
#define BIERKA_H
//#include "szachownica.h"
using namespace std;
class Bierka
{
protected:
    char    kolor;
    int     numer;
    //string  nazwa;
    bool    zbity;  //domyślnie figury nie są zbite
    int     pozycja[2];


public:


    Bierka()
    {
        kolor = 'w';
        numer = 1;
        zbity = false;

    }

    Bierka(char k, int n)
    {
        kolor = k;
        numer = n;
        zbity = false;
        pozycja[0] = -1;
        pozycja[-1] = -1;
    }
    int rusz()  {return 1;}
    char podajkolor();
    /*{
        return kolor;
    }*/

    int podajnumer()
    {
        return numer;
    }

    int czyzbity()
    {
        return zbity;
    }

    int zbij()
    {
        if (zbity == false)
        {
            zbity =true;
            return 0;
        }
        return 1;
    }

    int zmienpozycje(int* x)
    {
        pozycja[0]=x[0];
        pozycja[1]=x[1];
        return 0;
    }


    int* podajpozycje()
    {
        return pozycja;
    }


};

#endif // BIERKA_H

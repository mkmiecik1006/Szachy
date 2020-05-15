#ifndef PION_H
#define PION_H
#include "bierka.h"
#include <iostream>
#include "stdlib.h"
//#include "szachownica.h"

class Szachownica;


class Pion : public Bierka
{
    int promocja;

public:

    ~Pion()
    {
      // cout<<"destruktor"<<endl;
    }
    Pion(char k, int n, int x, int y) :Bierka(k, n, x, y)
    {
        //cout<<"konstruktor"<<kolor<<numer<<endl;

        zbity = false;
        pierwszy = false;
        promocja = 1;
        if(n>0) rysuj =  1;
        else    rysuj = -1;
    }
    int rusz(Szachownica* s, int pole[2], bool t = false);
    int bij(Szachownica* s, int pole[2], bool t = false);
    int zmienpozycje(int *pole);



    int promotuj(int p);



};

#endif // PION_H


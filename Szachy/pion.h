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


    Pion(char k, int n, int x, int y) :Bierka(k, n, x, y)
    {
        zbity = false;
        pierwszy = false;
        promocja = 1;
        if(n>0) rysuj =  1;
        else    rysuj = -1;
    }
    int rusz(Szachownica* s, int pole[2], bool t = false);
    int bij(Szachownica* s, int pole[2], bool t = false);
    int zmienpozycje(int pole[2]); //tak jak w klasie bazowej, ale dodatkowo obsluga promocji
    int promotuj(int p);    //metoda promocji piona po dotarciu na przeciwlegly koniec planszy

};

#endif // PION_H


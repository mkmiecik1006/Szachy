#ifndef PION_H
#define PION_H
#include "bierka.h"
#include <iostream>
#include "stdlib.h"
//#include "szachownica.h"

class Szachownica;


class Pion : public Bierka
{
    bool    pierwszy;   //czy wykonano pierwszy ruch
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
        promocja = 0;
    }
    int rusz(Szachownica* s, int* pole);
    int zmienpozycje(int *pole);

    bool czypierwszy()
    {
        return pierwszy;
    }

    int promotuj(int p);



};

#endif // PION_H


#ifndef PION_H
#define PION_H
#include "bierka.h"
#include <iostream>
//#include "szachownica.h"

class Szachownica;


class Pion : public Bierka
{
    bool    pierwszy;   //czy wykonano pierwszy ruch

public:

    ~Pion()
    {
      // cout<<"destruktor"<<endl;
    }
    Pion(char k, int n) :Bierka(k, n){
        //cout<<"konstruktor"<<kolor<<numer<<endl;
        pozycja[0] = -1;
        pozycja[-1] = -1;
        zbity = false;
        pierwszy = false;
    }
    int rusz(Szachownica* s, int* pole) override;
    int zmienpozycje(int *pole)
    {
        pozycja[0]=pole[0];
        pozycja[1]=pole[1];
        pierwszy = true;
        return 0;
    }

    bool czypierwszy()
    {
        return pierwszy;
    }

    int promotuj()
    {
        return 0;
    }



};

#endif // PION_H

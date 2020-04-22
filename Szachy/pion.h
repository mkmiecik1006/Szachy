#ifndef PION_H
#define PION_H
#include "bierka.h"
#include <iostream>
#include "szachownica.h"



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
    int rusz(Szachownica s, int* poz);

    int promotuj()
    {
        return 0;
    }



};

#endif // PION_H

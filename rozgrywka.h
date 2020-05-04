#ifndef ROZGRYWKA_H
#define ROZGRYWKA_H
#include "bierka.h"
#include "szachownica.h"
#include <stdlib.h>

class Rozgrywka
{

    char kolej;
    bool aktywna;
public:
    Rozgrywka();
    Szachownica szachownica;
    int nowa();
    int zakoncz();
    int ruch(Bierka* b, int* pole);
    void zmienkolej();
    int szach();
    bool czyaktywna();
    char podajkolej() {return kolej;}
};

#endif // ROZGRYWKA_H

#ifndef ROZGRYWKA_H
#define ROZGRYWKA_H
#include "bierka.h"
#include "szachownica.h"
#include <stdlib.h>

class Rozgrywka
{
    Szachownica szachownica;
    char kolej;
    bool aktywna;
public:
    Rozgrywka();

    int nowa();
    int zakoncz();
    int ruch(int bierka, int* pole);
    void zmienkolej();
    int roszada(int bierka);
    int szach();
};

#endif // ROZGRYWKA_H

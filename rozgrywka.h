#ifndef ROZGRYWKA_H
#define ROZGRYWKA_H
#include "bierka.h"
#include "szachownica.h"
#include <stdlib.h>
#include "poprzedniruch.h"

class Rozgrywka
{

    char kolej;
    bool aktywna;

public:
    Rozgrywka();
    Szachownica szachownica;
    PoprzedniRuch poprzedni;
    int nowa();
    int zakoncz();
    int ruch(Bierka* b, int* pole);
    void zmienkolej();
    int szach();
    bool czyaktywna();
    char podajkolej() {return kolej;}
    int cofnij();
    int szachb();
    int szachw();
};

#endif // ROZGRYWKA_H

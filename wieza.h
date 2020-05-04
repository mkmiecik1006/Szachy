#ifndef WIEZA_H
#define WIEZA_H
#include "bierka.h"
#include "szachownica.h"
#include "stdlib.h"

class Wieza : public Bierka
{
    bool    pierwszy;
public:
    Wieza(char k, int n, int x, int y) :Bierka(k, n, x, y)
    {
        zbity = false;
        pierwszy = false;
    }
    int rusz(Szachownica* s, int* poz);
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
};

#endif // WIEZA_H

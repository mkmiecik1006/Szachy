#ifndef WIEZA_H
#define WIEZA_H
#include "bierka.h"
#include "szachownica.h"
#include "stdlib.h"

class Wieza : public Bierka
{
public:
    Wieza(char k, int n, int x, int y) :Bierka(k, n, x, y)
    {
        zbity = false;
        pierwszy = false;
    }
    int rusz(Szachownica* s, int* poz, bool t = false);
    int bij(Szachownica* s, int* pole, bool t = false);
    bool czypierwszy()
    {
        return pierwszy;
    }
};

#endif // WIEZA_H

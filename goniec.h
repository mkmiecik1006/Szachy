#ifndef GONIEC_H
#define GONIEC_H
#include "stdlib.h"
#include "bierka.h"
#include "szachownica.h"

class Goniec : public Bierka
{
public:

    Goniec(char k, int n, int x, int y) :Bierka(k, n, x, y)
    {
        zbity = false;

    }
    int rusz(Szachownica* s, int* poz, bool t = false);
    int bij(Szachownica* s, int* pole, bool t = false);
};

#endif // GONIEC_H

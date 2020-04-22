#ifndef GONIEC_H
#define GONIEC_H
#include "stdlib.h"
#include "bierka.h"
#include "szachownica.h"

class Goniec : public Bierka
{
public:

    Goniec(char k, int n) :Bierka(k, n)
    {
        zbity = false;
        pozycja[0] = -1;
        pozycja[-1] = -1;
    }
    int rusz(Szachownica s, int* poz);
};

#endif // GONIEC_H

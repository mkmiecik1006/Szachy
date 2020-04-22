#ifndef HETMAN_H
#define HETMAN_H
#include "bierka.h"
#include "szachownica.h"
#include "stdlib.h"
class Hetman : public Bierka
{
public:
    Hetman(char k, int n): Bierka(k, n)
    {
        zbity = false;
        pozycja[0] = -1;
        pozycja[-1] = -1;
    }
    int rusz(Szachownica s, int* poz);
};

#endif // HETMAN_H

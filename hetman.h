#ifndef HETMAN_H
#define HETMAN_H
#include "bierka.h"
#include "szachownica.h"
#include "stdlib.h"
class Hetman : public Bierka
{
public:
    Hetman(char k, int n, int x, int y) :Bierka(k, n, x, y)
    {
        zbity = false;
    }
    int rusz(Szachownica* s, int* poz);
};

#endif // HETMAN_H

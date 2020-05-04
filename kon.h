#ifndef KON_H
#define KON_H
#include "bierka.h"
#include "szachownica.h"

class Kon : public Bierka
{
public:
    Kon(char k, int n, int x, int y) :Bierka(k, n, x, y)
    {
        zbity = false;

    }
    int rusz(Szachownica* s, int* poz);
};

#endif // KON_H

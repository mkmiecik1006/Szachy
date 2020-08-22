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
    int rusz(Szachownica* s, int poz[2], bool t = false);
    int bij(Szachownica* s, int pole[2], bool t = false);
};

#endif // KON_H

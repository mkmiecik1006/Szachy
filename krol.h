#ifndef KROL_H
#define KROL_H
#include "bierka.h"
#include "szachownica.h"
#include "stdlib.h"

class Krol : public Bierka
{
public:
    Krol(char k, int n, int x, int y) :Bierka(k, n, x, y)
    {
        zbity = false;
        pierwszy = false;
    }
    int rusz(Szachownica* s, int poz[2], bool t = false);
    int bij(Szachownica* s, int pole[2], bool t = false);
    bool czypierwszy()
    {
        return pierwszy;
    }
    bool szach(int* pole, Szachownica* szachownica);
};

#endif // KROL_H

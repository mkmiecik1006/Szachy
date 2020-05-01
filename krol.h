#ifndef KROL_H
#define KROL_H
#include "bierka.h"
#include "szachownica.h"
#include "stdlib.h"

class Krol : public Bierka
{
    bool    pierwszy;
public:
    Krol(char k, int n): Bierka(k, n)
    {
        zbity = false;
        pozycja[0] = -1;
        pozycja[-1] = -1;
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

#endif // KROL_H

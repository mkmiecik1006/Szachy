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
    int rusz(Szachownica s, int* poz);
};

#endif // KROL_H

#ifndef KON_H
#define KON_H
#include "bierka.h"
#include "szachownica.h"

class Kon : public Bierka
{
public:
    Kon(char k, int n):Bierka(k, n)
    {
        zbity = false;
        pozycja[0] = -1;
        pozycja[-1] = -1;
    }
    int rusz(Szachownica* s, int* poz);
};

#endif // KON_H

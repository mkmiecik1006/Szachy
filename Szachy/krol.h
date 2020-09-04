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
    bool szach(int pole[2], Szachownica* szachownica);  //metoda sprawdzajaca czy w na danej pozycju krol znajduje sie pod szachem
};

#endif // KROL_H

#ifndef POPRZEDNIRUCH_H
#define POPRZEDNIRUCH_H
#include "bierka.h"
#include <stddef.h>
#include <stdexcept>

class PoprzedniRuch
{
    Bierka* poprzednia;
    int pozycja[2];
    Bierka* bita;
    int pozycjabita[2];
    bool bicie;
    char kolej;
    bool promocja;
    bool aktywny;
    bool pierwszy;
    bool pierwszybity;
public:
    PoprzedniRuch();

    int ZapiszPoprzedni(char k, Bierka* b, int* p, Bierka* bb = NULL, int* pb = NULL);
    Bierka* PodajPoprzednia();
    int* PodajPozycja();
    Bierka* PodajBita();
    int* PodajPozycjaBita();
    char PodajKolej();
    bool PodajBicie() {return bicie;}
    void Promocja();
    bool PodajPromocja() {return promocja;}
    void ZmienAktywny();
    bool PodajAktywny() {return aktywny;}
    bool PodajPierwszy() {return pierwszy;}
    bool PodajPierwszyBity() {return pierwszybity;}

};

#endif // POPRZEDNIRUCH_H

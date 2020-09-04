#ifndef POPRZEDNIRUCH_H
#define POPRZEDNIRUCH_H
#include "bierka.h"
#include <stddef.h>
#include <stdexcept>

class PoprzedniRuch // klasa przechowujaca informacje o otsrtniw wykonanym ruchu umozliwiajaca cofanie
{
private:
    Bierka* poprzednia;     //bierka ktora zostal wykonany poprzedni ruch
    int pozycja[2];         //pozycja bierki poprzedniej przed ruchem
    Bierka* bita;           //bierka kotra ewentualnie zostala zbita w poprzednim ruchu
    int pozycjabita[2];     //pozycja bierki zbitej
    int licznik;            //
    bool bicie;             //informacja czy w poprzednim ruchu byla zbita bierka
    char kolej;             //kolej graczy w poprzednim ruchu
    bool promocja;          //czy w poprzenim ruchu pion dokonal promocji
    bool aktywny;           //czy mozna dokonac cofniecia ruchu
    bool pierwszy;          //czy poprzedni ruch byl pierwszyn danej bierki
    bool pierwszybity;      //czy poprzedni ruch byl pierwszyn bierki bitej
public:
    PoprzedniRuch();

    int ZapiszPoprzedni(int l, char k, Bierka* b, int p[2], Bierka* bb = NULL, int* pb = NULL); //zapisuje dane przed ruchem
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

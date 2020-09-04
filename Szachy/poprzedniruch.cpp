#include "poprzedniruch.h"

PoprzedniRuch::PoprzedniRuch()
{
    poprzednia = NULL;
    bita = NULL;
    pozycja[0] = -10;
    pozycja[1] = -10;
    licznik = 0;
    pozycjabita[0] = -10;
    pozycjabita[1] = -10;
    bicie = false;
    kolej = 'w';
    promocja = false;
    aktywny = false;
    pierwszy = true;
    pierwszybity = true;
}

int PoprzedniRuch::ZapiszPoprzedni(int l, char k, Bierka *b, int  p[2], Bierka* bb, int* pb)
{

    kolej = k;
    promocja= false;
    bicie = false;
    aktywny = true;
    poprzednia = b;
    pozycja[0] = p[0];
    pozycja[1] = p[1];
    pierwszy = b->czypierwszy();
    licznik = l;
    if(pb!=NULL && bb!= NULL )
    {
        bicie = true;
        bita = bb;
        pozycjabita[0] = pb[0];
        pozycjabita[1] = pb[1];
        pierwszybity = bb->czypierwszy();
    }
    else
    {
        bita = NULL;
        pozycjabita[0] = -10;
        pozycjabita[1] = -10;
        pierwszybity = true;
    }
    return 0;
}
Bierka* PoprzedniRuch::PodajPoprzednia()
{
    return poprzednia;
}

Bierka* PoprzedniRuch::PodajBita()
{
    if(bicie) return bita;
    else throw std::runtime_error("W poprzednim ruchu nie została zbita bierka!");
}

int* PoprzedniRuch::PodajPozycja()
{
    return pozycja;
}

int* PoprzedniRuch::PodajPozycjaBita()
{
    if(bicie) return pozycjabita;
    else throw std::runtime_error("W poprzednim ruchu nie została zbita bierka!");
}
char PoprzedniRuch::PodajKolej()
{
    return kolej;
}
void PoprzedniRuch::Promocja()
{
    promocja = true;
}
void PoprzedniRuch::ZmienAktywny()
{
    aktywny = false;
}


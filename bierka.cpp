#include "bierka.h"

Bierka::Bierka()
{

}

Bierka::Bierka(char k, int n)
{
    kolor = k;
    numer = n;
}

Bierka::podajkolor()
{
    return kolor;
}

Bierka::podajnumer()
{
    return numer;
}

Bierka::czyzbity()
{
    return zbity;
}

Bierka::zbij()
{
    zbity =true;
}

Bierka::zmienpozycje(int x, int y)
{
    pozycja[0]=x;
    pozycja[1]=y;
    return 0;
}

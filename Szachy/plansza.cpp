#include "plansza.h"
int Plansza::porownaj(Plansza* p)
{
    int roznica=0;
    if(kolej==p->kolej)
    {
        for(int i =0; i<8; i++)
        {
            for(int j =0; j<8; j++)
            {
                if(plansza[i][j]!=p->plansza[i][j]) roznica++;
            }
        }
    }
    else roznica++;
    return roznica;
}


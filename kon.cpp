#include "kon.h"

#include "szachownica.h"
#include "bierka.h"

int Kon::rusz(Szachownica* s, int poz[2], bool t)
{
    if(s->czywolne(poz))
    {}

    int x   = poz[0];               //pozycja na którą chcemy się ruszyć
    int y   = poz[1];
    int x2;                         //pozycja na której obecnie jestesmy
    int y2;
    if(t)
    {
        x2 = tmp[0];
        y2 = tmp[1];
    }
    else
    {
        x2 = pozycja[0];
        y2 = pozycja[1];
    }
    if(zbity==false)
    {
        if(x!=x2||y!=y2) //ruszamy się gdzieś
        {

            if((y2==y-2||y2==y+2)&&(x2==x-1||x2==x+1))
            {
                return 0;
            }
            else if((x2==x-2||x2==x+2)&&(y2==y-1||y2==y+1))
            {
                return 0;
            }
        }
    }
    return 1;
}

int Kon::bij(Szachownica* s, int poz[2], bool t)
{
    if(s->czywolne(poz))
    {}

    int x   = poz[0];               //pozycja na którą chcemy się ruszyć
    int y   = poz[1];
    int x2;                         //pozycja na której obecnie jestesmy
    int y2;
    if(t)
    {
        x2 = tmp[0];
        y2 = tmp[1];
    }
    else
    {
        x2 = pozycja[0];
        y2 = pozycja[1];
    }
    if(zbity==false)
    {
        if(x!=x2||y!=y2) //ruszamy się gdzieś
        {

            if((y2==y-2||y2==y+2)&&(x2==x-1||x2==x+1))
            {
                return 0;
            }
            else if((x2==x-2||x2==x+2)&&(y2==y-1||y2==y+1))
            {
                return 0;
            }
        }
    }
    return 1;
}

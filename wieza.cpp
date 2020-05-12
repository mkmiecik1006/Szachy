#include "wieza.h"
#include "bierka.h"
#include "szachownica.h"

int Wieza::rusz(Szachownica* s, int *poz, bool t)
{
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
            int rx = x-x2;      //odległość od aktualnej pozycji
            int ry = y-y2;
            int kx = 0; //krok dla x
            int ky = 0; //krok dla y
            int z = 0;
            int krok[2] = {x2, y2};
            if(x2==x||y2==y)    //ruch po prostych
            {
                if(rx!=0)
                {
                    z = abs(rx);
                    if(rx>0)   kx=1;      //krok dla x
                    else     kx =-1;     //krok dla y
                }
                else if(ry!=0)
                {
                    z = abs(ry);
                    if(ry>0)  ky=1;
                    else     ky =-1;
                }
                for(int i = 0; i <z; i++)
                {
                    krok[0] +=kx;
                    krok[1] +=ky;
                    if(i==z-1)  //ostatnie pole
                    {
                        return 0;
                    }
                    else if(s->czywolne(krok, t)!=0)    //czy pola po drodze są wolne
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 1;
}


int Wieza::bij(Szachownica* s, int* poz, bool t)
{
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
            int rx = x-x2;      //odległość od aktualnej pozycji
            int ry = y-y2;
            int kx = 0; //krok dla x
            int ky = 0; //krok dla y
            int z = 0;
            int krok[2] = {x2, y2};
            if(x2==x||y2==y)    //ruch po prostych
            {
                if(rx!=0)
                {
                    z = abs(rx);
                    if(rx>0)   kx=1;      //krok dla x
                    else     kx =-1;     //krok dla y
                }
                else if(ry!=0)
                {
                    z = abs(ry);
                    if(ry>0)  ky=1;
                    else     ky =-1;
                }
                for(int i = 0; i <z; i++)
                {
                    krok[0] +=kx;
                    krok[1] +=ky;
                    if(i==z-1)  //ostatnie pole
                    {
                        return 0;
                    }
                    else if(s->czywolne(krok, t)!=0)    //czy pola po drodze są wolne
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 1;
}

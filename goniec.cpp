#include "goniec.h"
#include "bierka.h"
#include "szachownica.h"
//#include "szachownica.cpp"


int Goniec::rusz(Szachownica* s, int poz[2], bool t)
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
        if(x!=x2&&y!=y2)    //musimy sie gdzieś poruszyć
        {
            int rx = x-x2;      //odległość od aktualnej pozycji
            int ry = y-y2;
            int krok[2] = {x2, y2};
            if(abs(rx)==abs(ry))   //jezeli poruszamy się po przekątnej
            {
                int kx, ky;
                if(rx>0)  kx=1;      //krok dla x
                else     kx =-1;     //krok dla y
                if(ry>0)  ky=1;
                else     ky =-1;
                for(int i=0; i<abs(rx); i++)
                {
                    krok[0] +=kx;
                    krok[1] +=ky;
                    if(i==abs(rx)-1)  //ostatnie pole
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

int Goniec::bij(Szachownica* s, int pole[2], bool t)
{
    int x   = pole[0];               //pozycja na którą chcemy się ruszyć
    int y   = pole[1];
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
        if(x!=x2&&y!=y2)    //musimy sie gdzieś poruszyć
        {
            int rx = x-x2;      //odległość od aktualnej pozycji
            int ry = y-y2;
            int krok[2] = {x2, y2};
            if(abs(rx)==abs(ry))   //jezeli poruszamy się po przekątnej
            {
                int kx, ky;
                if(rx>0)  kx=1;      //krok dla x
                else     kx =-1;     //krok dla y
                if(ry>0)  ky=1;
                else     ky =-1;
                for(int i=0; i<abs(rx); i++)
                {
                    krok[0] +=kx;
                    krok[1] +=ky;
                    if(i==abs(rx)-1)  //ostatnie pole
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

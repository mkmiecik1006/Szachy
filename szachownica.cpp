#include "szachownica.h"
#include "pion.h"
#include "bierka.h"
#include "goniec.h"
#include "kon.h"
#include "hetman.h"
#include "wieza.h"
#include "krol.h"
#include <stdexcept>

typedef std::pair<int, Bierka*> MyPair;
int Szachownica::wyczysc()
{
    map<int, Bierka*> ::iterator it = figury.begin();
    while(it!=figury.end())
    {
        delete it->second;
        it++;
    }
    figury.clear();
    for(int i=0; i<8;i++)
    {
        for(int j=0; j<8;j++)
        {
            plansza[i][j]   = 0;
            tmp[i][j]       = 0;
        }
    }
    return 0;
}


/*int     Szachownica::czywolne(int* t)
{
    return plansza[t[0]] [t[1]];//zwraca wartość bierki na danym polu
}
*/

/*
int Szachownica::dodaj(Bierka b, int* t)
{
    if(czywolne(t)==0)
    {
        b.zmienpozycje(t);
        plansza[t[0]][t[1]] = b.podajnumer();
        return 0;
    }
    else
    {
        return 1;

    }
}*/
int Szachownica::usun(Bierka* b)
{
    int* p = b->podajpozycje();
    if(p!=NULL)
    {
        int i[2] = {-1, -1};
        b->zmienpozycje(i);
        plansza[p[0]][p[1]] = 0;
        figury.erase(figury.find(b->podajnumer()));
        return 0;
    }
    else
    {
        return 1;
    }

}

int Szachownica::przesun(Bierka* b, int* t)
{

        if(czywolne(t)==0)
        {
            int* p = b->podajpozycje();
            plansza[t[0]][t[1]] = plansza[p[0]][p[1]];
            plansza[p[0]][p[1]] = 0;
            b->zmienpozycje(t);
            return 0;

        }
        else
        {
            return 1;
        }

}

Bierka* Szachownica::znajdz(int* pole)
{
    int bierka = plansza[pole[0]][pole[1]];
    if(pole[0]>=0&&pole[1]>=0&&pole[0]<=7&&pole[1]<=7)
    {
        if(bierka!=0)
        {
            return figury.find(bierka)->second;
        }
        else throw std::runtime_error("Podane pole jest puste!");
    }
    else throw std::runtime_error("Pole poza planszą!");
}

int Szachownica::ustaw()
{
    wyczysc();      //ustaw wszystkie wartości na 0
    figury.insert( make_pair<int, Pion*>(1, new Pion('w', 1, 0, 1)));
    figury.insert( make_pair<int, Pion*>(2, new Pion('w', 2, 1, 1)));
    figury.insert( make_pair<int, Pion*>(3, new Pion('w', 3, 2, 1)));
    figury.insert( make_pair<int, Pion*>(4, new Pion('w', 4, 3, 1)));
    figury.insert( make_pair<int, Pion*>(5, new Pion('w', 5, 4, 1)));
    figury.insert( make_pair<int, Pion*>(6, new Pion('w', 6, 5, 1)));
    figury.insert( make_pair<int, Pion*>(7, new Pion('w', 7, 6, 1)));
    figury.insert( make_pair<int, Pion*>(8, new Pion('w', 8, 7, 1)));
    figury.insert(make_pair<int, Wieza*>(9, new Wieza('w', 9, 0, 0)));
    figury.insert(make_pair<int, Wieza*>(10, new Wieza('w', 10, 7, 0)));
    figury.insert(make_pair<int, Kon*>(11, new Kon('w', 11, 1, 0)));
    figury.insert(make_pair<int, Kon*>(12, new Kon('w', 12, 6, 0)));
    figury.insert(make_pair<int, Goniec*>(13, new Goniec('w', 13, 2, 0)));
    figury.insert(make_pair<int, Goniec*>(14, new Goniec('w', 14, 5, 0)));
    figury.insert(make_pair<int, Hetman*>(15, new Hetman('w', 15, 3, 0)));
    figury.insert(make_pair<int, Krol*>(16, new Krol('w', 16, 4, 0)));

    figury.insert( make_pair<int, Pion*>(-1, new Pion('b', -1, 0, 6)));
    figury.insert( make_pair<int, Pion*>(-2, new Pion('b', -2, 1, 6)));
    figury.insert( make_pair<int, Pion*>(-3, new Pion('b', -3, 2, 6)));
    figury.insert( make_pair<int, Pion*>(-4, new Pion('b', -4, 3, 6)));
    figury.insert( make_pair<int, Pion*>(-5, new Pion('b', -5, 4, 6)));
    figury.insert( make_pair<int, Pion*>(-6, new Pion('b', -6, 5, 6)));
    figury.insert( make_pair<int, Pion*>(-7, new Pion('b', -7, 6, 6)));
    figury.insert( make_pair<int, Pion*>(-8, new Pion('b', -8, 7, 6)));
    figury.insert(make_pair<int, Wieza*>(-9, new Wieza('b', -9, 0, 7)));
    figury.insert(make_pair<int, Wieza*>(-10, new Wieza('b', -10, 7, 7)));
    figury.insert(make_pair<int, Kon*>(-11,  new Kon('b', -11, 1, 7)));
    figury.insert(make_pair<int, Kon*>(-12, new Kon('b', -12, 6, 7)));
    figury.insert(make_pair<int, Goniec*>(-13, new Goniec('b', -13, 2, 7)));
    figury.insert(make_pair<int, Goniec*>(-14, new Goniec('b', -14, 5, 7)));
    figury.insert(make_pair<int, Hetman*>(-15, new Hetman('b', -15, 3, 7)));
    figury.insert(make_pair<int, Krol*>(-16, new Krol('b', -16, 4, 7)));


    plansza[0][0] = 9;
    plansza[1][0] = 11;
    plansza[2][0] = 13;
    plansza[3][0] = 15;
    plansza[4][0] = 16;
    plansza[5][0] = 14;
    plansza[6][0] = 12;
    plansza[7][0] = 10;

    plansza[0][1] = 1;
    plansza[1][1] = 2;
    plansza[2][1] = 3;
    plansza[3][1] = 4;
    plansza[4][1] = 5;
    plansza[5][1] = 6;
    plansza[6][1] = 7;
    plansza[7][1] = 8;

    plansza[0][7] = -9;
    plansza[1][7] = -11;
    plansza[2][7] = -13;
    plansza[3][7] = -15;
    plansza[4][7] = -16;
    plansza[5][7] = -14;
    plansza[6][7] = -12;
    plansza[7][7] = -10;

    plansza[0][6] = -1;
    plansza[1][6] = -2;
    plansza[2][6] = -3;
    plansza[3][6] = -4;
    plansza[4][6] = -5;
    plansza[5][6] = -6;
    plansza[6][6] = -7;
    plansza[7][6] = -8;

    ///////////////////////////
    tmp[0][0] = 9;
    tmp[1][0] = 11;
    tmp[2][0] = 13;
    tmp[3][0] = 15;
    tmp[4][0] = 16;
    tmp[5][0] = 14;
    tmp[6][0] = 12;
    tmp[7][0] = 10;

    tmp[0][1] = 1;
    tmp[1][1] = 2;
    tmp[2][1] = 3;
    tmp[3][1] = 4;
    tmp[4][1] = 5;
    tmp[5][1] = 6;
    tmp[6][1] = 7;
    tmp[7][1] = 8;

    tmp[0][7] = -9;
    tmp[1][7] = -11;
    tmp[2][7] = -13;
    tmp[3][7] = -15;
    tmp[4][7] = -16;
    tmp[5][7] = -14;
    tmp[6][7] = -12;
    tmp[7][7] = -10;

    tmp[6][0] = -1;
    tmp[6][1] = -2;
    tmp[6][2] = -3;
    tmp[6][3] = -4;
    tmp[6][4] = -5;
    tmp[6][5] = -6;
    tmp[6][6] = -7;
    tmp[6][7] = -8;
    return 0;
}








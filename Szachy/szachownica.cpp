#include "szachownica.h"
#include "pion.h"
#include "bierka.h"
#include "goniec.h"
#include "kon.h"
#include "hetman.h"

int Szachownica::wyczysc()
{
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
}
int Szachownica::usun(Bierka b)
{
    int* p = b.podajpozycje();
    if(p!=NULL)
    {
        int i[2] = {-1, -1};
        b.zmienpozycje(i);
        plansza[p[0]][p[1]] = 0;
        figury.erase(figury.find(b.podajnumer()));
        return 0;
    }
    else
    {
        return 1;
    }

}

int Szachownica::przesun(Bierka b, int* t)
{

        if(czywolne(t)==0)
        {
            int* p = b.podajpozycje();
            plansza[p[0]][p[1]] = 0;
            plansza[t[0]][t[1]] = b.podajnumer();
            b.zmienpozycje(t);
            return 0;

        }
        else
        {
            return 1;
        }

}

int Szachownica::ustaw()
{
    wyczysc();      //ustaw wszystkie wartości na 0
    figury.insert( make_pair<int, Pion>(1, Pion('w', 1)));
    figury.insert( make_pair<int, Pion>(2, Pion('w', 2)));
    figury.insert( make_pair<int, Pion>(3, Pion('w', 3)));
    figury.insert( make_pair<int, Pion>(4, Pion('w', 4)));
    figury.insert( make_pair<int, Pion>(5, Pion('w', 5)));
    figury.insert( make_pair<int, Pion>(6, Pion('w', 6)));
    figury.insert( make_pair<int, Pion>(7, Pion('w', 7)));
    figury.insert( make_pair<int, Pion>(8, Pion('w', 8)));


    figury.insert(make_pair<int, Kon>(11, Kon('w', 11)));
    figury.insert(make_pair<int, Kon>(12, Kon('w', 12)));
    figury.insert(make_pair<int, Goniec>(13, Goniec('w', 13)));
    figury.insert(make_pair<int, Goniec>(14, Goniec('w', 14)));
    figury.insert(make_pair<int, Hetman>(15, Hetman('w', 15)));

    figury.insert( make_pair<int, Pion>(-1, Pion('b', -1)));
    figury.insert( make_pair<int, Pion>(-2, Pion('b', -2)));
    figury.insert( make_pair<int, Pion>(-3, Pion('b', -3)));
    figury.insert( make_pair<int, Pion>(-4, Pion('b', -4)));
    figury.insert( make_pair<int, Pion>(-5, Pion('b', -5)));
    figury.insert( make_pair<int, Pion>(-6, Pion('b', -6)));
    figury.insert( make_pair<int, Pion>(-7, Pion('b', -7)));
    figury.insert( make_pair<int, Pion>(-8, Pion('b', -8)));


    figury.insert(make_pair<int, Kon>(-11, Kon('b', -11)));
    figury.insert(make_pair<int, Kon>(-12, Kon('b', -12)));
    figury.insert(make_pair<int, Goniec>(-13, Goniec('b', -13)));
    figury.insert(make_pair<int, Goniec>(-14, Goniec('b', -14)));
    figury.insert(make_pair<int, Hetman>(15, Hetman('b', -15)));

    wyczysc();      //ustaw wszystkie wartości na 0
    plansza[0][0] = -9;
    plansza[0][1] = -11;
    plansza[0][2] = -13;
    plansza[0][3] = -15;
    plansza[0][4] = -16;
    plansza[0][5] = -14;
    plansza[0][6] = -12;
    plansza[0][7] = -10;

    plansza[1][0] = -1;
    plansza[1][1] = -2;
    plansza[1][2] = -3;
    plansza[1][3] = -4;
    plansza[1][4] = -5;
    plansza[1][5] = -6;
    plansza[1][6] = -7;
    plansza[1][7] = -8;

    plansza[7][0] = 9;
    plansza[7][1] = 11;
    plansza[7][2] = 13;
    plansza[7][3] = 15;
    plansza[7][4] = 16;
    plansza[7][5] = 14;
    plansza[7][6] = 12;
    plansza[7][7] = 10;

    plansza[6][0] = 1;
    plansza[6][1] = 2;
    plansza[6][2] = 3;
    plansza[6][3] = 4;
    plansza[6][4] = 5;
    plansza[6][5] = 6;
    plansza[6][6] = 7;
    plansza[6][7] = 8;

    ///////////////////////////
    tmp[0][0] = -9;
    tmp[0][1] = -11;
    tmp[0][2] = -13;
    tmp[0][3] = -15;
    tmp[0][4] = -16;
    tmp[0][5] = -14;
    tmp[0][6] = -14;
    tmp[0][7] = -10;

    tmp[1][0] = -1;
    tmp[1][1] = -2;
    tmp[1][2] = -3;
    tmp[1][3] = -4;
    tmp[1][4] = -5;
    tmp[1][5] = -6;
    tmp[1][6] = -7;
    tmp[1][7] = -8;

    tmp[7][0] = 9;
    tmp[7][1] = 11;
    tmp[7][2] = 13;
    tmp[7][3] = 15;
    tmp[7][4] = 16;
    tmp[7][5] = 14;
    tmp[7][6] = 14;
    tmp[7][7] = 10;

    tmp[6][0] = 1;
    tmp[6][1] = 2;
    tmp[6][2] = 3;
    tmp[6][3] = 4;
    tmp[6][4] = 5;
    tmp[6][5] = 6;
    tmp[6][6] = 7;
    tmp[6][7] = 8;
    return 0;
}








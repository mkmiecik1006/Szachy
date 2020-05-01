#ifndef SZACHOWNICA_H
#define SZACHOWNICA_H
#include <map>
#include "bierka.h"



using namespace std;


class Szachownica
{
private:
public:
    int     plansza[8][8];

    int     tmp[8][8];

    map <int, Bierka> figury;
public:
    Szachownica()
    {
        for(int i = 0; i<8;i++)
        {
            for(int j = 0; j<8; j++)
            {
                plansza[i][j] = 0;
            }
        }
    }

    ~Szachownica()
    {
        wyczysc();
    }


    int     wyczysc();
    int     usun(Bierka*);
    int     przesun(Bierka*, int*);
   // int     dodaj(Bierka, int*);
    int     czywolne(int* t)
    {
        return plansza[t[0]] [t[1]];//zwraca wartość bierki na danym polu
    }

    int     ustaw();
    char    kolor(int n)
    {

        Bierka* b = &(figury.find(n)->second);
        return b->podajkolor();
    }
    int     zbij(Bierka* b)
    {
        int* pole = b->podajpozycje();
        b->zbij();
        plansza[pole[0]][pole[1]] = 0;
        return 0;

    }//zbija bierkę o danym numerze


};
#endif // SZACHOWNICA_H

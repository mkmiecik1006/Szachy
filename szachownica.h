#ifndef SZACHOWNICA_H
#define SZACHOWNICA_H
#include <map>
#include "bierka.h"
#include <memory>


using namespace std;


class Szachownica
{
private:
public:
    int     plansza[8][8];

    int     tmp[8][8];

    map <int, Bierka*> figury;
public:
    Szachownica()
    {
        for(int i = 0; i<8;i++)
        {
            for(int j = 0; j<8; j++)
            {
                plansza[i][j] = 0;
                tmp[i][j] = 0;
            }
        }
    }

    ~Szachownica()
    {
        wyczysc();
    }


    int     wyczysc();
    int     przesun(Bierka*, int*);
    int     przesuntmp(Bierka*, int*);
    int     czywolne(int* t, bool t2 =false)
    {
        if(!t2)    return plansza[t[0]] [t[1]];//zwraca wartość bierki na danym polu
        else        return tmp[t[0]] [t[1]];
    }
    void cofnijtmp();
    int     ustaw();
    char    kolor(int n)
    {

        Bierka* b = figury.find(n)->second;
        return b->podajkolor();
    }
    int     zbij(Bierka* b, bool t= false)
    {
        int* pole = b->podajpozycje();
        if(t)   plansza[pole[0]][pole[1]] = 0;
        else    tmp[pole[0]][pole[1]] = 0;
        b->zbij();
        return 0;


    }//zbija bierkę o danym numerze

    Bierka* znajdz(int* pole);

};
#endif // SZACHOWNICA_H

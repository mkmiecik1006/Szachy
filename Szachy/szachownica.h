#ifndef SZACHOWNICA_H
#define SZACHOWNICA_H
#include <map>
#include "bierka.h"



using namespace std;


class Szachownica
{
private:
public:
    int     plansza[8][8]; /*= {{-9, -11, -13, -15, -16, -14, -12, -10},
    { -1,  -2,  -3,  -4,  -5,  -6,  -7,  -8},
    {  0,   0,   0,   0,   0,   0,   0,   0},
    {  0,   0,   0,   0,   0,   0,   0,   0},
    {  0,   0,   0,   0,   0,   0,   0,   0},
    {  0,   0,   0,   0,   0,   0,   0,   0},
    {  1,   2,   3,   4,   5,   6,   7,   8},
    {  9,  11,  13,  15,  16,  14,  12,  10}};*/

    int     tmp[8][8]; /*{{-9, -11, -13, -15, -16, -14, -12, -10},
    { -1,  -2,  -3,  -4,  -5,  -6,  -7,  -8},
    {  0,   0,   0,   0,   0,   0,   0,   0},
    {  0,   0,   0,   0,   0,   0,   0,   0},
    {  0,   0,   0,   0,   0,   0,   0,   0},
    {  0,   0,   0,   0,   0,   0,   0,   0},
    {  1,   2,   3,   4,   5,   6,   7,   8},
    {  9,  11,  13,  15,  16,  14,  12,  10}};*/

    map <int, Bierka> figury;
public:
    Szachownica()
    {
        ustaw();
    }


    int     wyczysc();
    int     usun(Bierka);
    int     przesun(Bierka, int*);
    int     dodaj(Bierka, int*);
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
    int     zbij(int n)
    {
        Bierka* b = &(figury.find(n)->second);
        return b->zbij();

    }//zbija bierkę o danym numerze


};

#endif // SZACHOWNICA_H

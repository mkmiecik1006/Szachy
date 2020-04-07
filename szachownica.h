#ifndef SZACHOWNICA_H
#define SZACHOWNICA_H
#include <map>
using namespace std;
class Szachownica
{
private:
    int     plansza[8][8];
    int     tmp[8][8]=
    {{-9, -11, -13, -15, -16, -14, -12, -10},
    { -1,  -2,  -3,  -4,  -5,  -6,  -7,  -8},
    {  0,   0,   0,   0,   0,   0,   0,   0},
    {  0,   0,   0,   0,   0,   0,   0,   0},
    {  0,   0,   0,   0,   0,   0,   0,   0},
    {  0,   0,   0,   0,   0,   0,   0,   0},
    {  1,   2,   3,   4,   5,   6,   7,   8},
    {  9,  11,  13,  15,  16,  14,  12,  10}};

    map <int, Bierka> figury;
public:
    Szachownica();
    int     wyczysc();
    int     usun(Bierka, int*);
    int     przesun(Bierka, int*);
    int     dodaj(Bierka, int*);
    int     czywolne(int*);

};

#endif // SZACHOWNICA_H

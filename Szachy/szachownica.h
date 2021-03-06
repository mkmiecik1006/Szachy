#ifndef SZACHOWNICA_H
#define SZACHOWNICA_H
#include <map>
#include "bierka.h"
#include <memory>


using namespace std;


class Szachownica
{
    friend class Rozgrywka;
protected:
    map <int, Bierka*> figury;  // kontener przechowujacy wskazniki do bierek na danej planszy

    int     plansza[8][8]; //tablica 8x8 odwzorowujaca szachownice, przechowuje numery bierek

    int     tmp[8][8];      //tablica tymczaasowa wykorzystywana do sprawdzania poprawnosci ruchow
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

    //int    podajplansza(){return plansza;}
    int     wyczysc(); //czyszenie planszy po skonczonej rozgrywce
    int     przesun(Bierka*, int [2]); //zmiana pozycji bierki na planszy
    int     przesuntmp(Bierka*, int [2]); //zmiana pozycji bierki na planszy tymczasowej
    int     czywolne(int t[2], bool t2 =false) //metoda zwraca numer bierki znajdujacej sie na wskazanym polu, jak t2=true naplanszy tyczasowej
    {
        if(!t2)    return plansza[t[0]] [t[1]];//zwraca wartość bierki na danym polu
        else        return tmp[t[0]] [t[1]];
    }
    void    cofnijtmp(); //metoda przepisuje ustawienie z planszy wlasciwej do tymczasowej
    int     ustaw();    //metoda ustawia bierki na planszy na poczatku rozgrywki
    char    kolor(int n) // metoda podajaca kolor bierki o podanym numerze
    {

        Bierka* b = figury.find(n)->second;
        return b->podajkolor();
    }
    int     zbij(Bierka* b, bool t= false)  // metoda zbijajaca podana bierke na planszy wlasciwej lub tymczasowej
    {
        int* pole = b->podajpozycje();
        if(!t)   plansza[pole[0]][pole[1]] = 0;
        else    tmp[pole[0]][pole[1]] = 0;
        b->zbij();
        return 0;


    }//zbija bierkę o danym numerze

    Bierka* znajdz(int pole[2]); // metodna znajdujaca bierka na planszy
    Bierka* znajdz(int n);
    map <int, Bierka*>::iterator znajdz2(int n);
};
#endif // SZACHOWNICA_H

#ifndef PLANSZA_H
#define PLANSZA_H

class Plansza  //klasa zawierajaca podstawowe informacje zapisywane w historii ruchow, do gry wykozystywana jest klasa szachownica
{
public:
    int     plansza[8][8];      //tablica 8x8 odwzorowujaca szachownice, przechowuje numery bierek
    char    kolej;              //pole przechowuje informacje o tym ktory gracz ma ruch, b/w
public:

    Plansza()
    {
        for(int i = 0; i<8;i++) //na poczatku plansza jest pusta
        {
            for(int j = 0; j<8; j++)
            {
                plansza[i][j] = 0;
            }
        }
    }



    Plansza(const Plansza &p )
    {
        kolej= p.kolej;
        for(int i = 0; i<8;i++)
        {
            for(int j = 0; j<8; j++)
            {
                plansza[i][j] = p.plansza[i][j];
            }
        }
    }

    template<typename T> Plansza(T p[8][8], char k)
    {
        kolej = k;
        for(int i = 0; i<8;i++)
        {
            for(int j = 0; j<8; j++)
            {
                plansza[i][j] = (int)p[i][j];
            }
        }
    }

    int porownaj(Plansza* p); //metoda porownujaca ze soba 2 plansze

};

#endif // PLANSZA_H

#ifndef PLANSZA_H
#define PLANSZA_H

class Plansza
{
public:
//protected:
    int     plansza[8][8];
    char    kolej;
public:

    Plansza()
    {
        for(int i = 0; i<8;i++)
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

    Plansza(int p[8][8], char k)
    {
        kolej = k;
        for(int i = 0; i<8;i++)
        {
            for(int j = 0; j<8; j++)
            {
                plansza[i][j] = p[i][j];
            }
        }
    }

    int porownaj(Plansza* p);
};

#endif // PLANSZA_H

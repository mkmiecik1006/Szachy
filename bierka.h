#ifndef BIERKA_H
#define BIERKA_H
class Szachownica;

using namespace std;
class Bierka
{
protected:
    char    kolor;
    int     numer;
    //string  nazwa;
    bool    zbity;  //domyślnie figury nie są zbite
    int     pozycja[2];
    bool    pierwszy;


public:


    Bierka()
    {
        kolor = 'w';
        numer = 1;
        zbity = false;
        pierwszy = false;

    }

    Bierka(char k, int n, int x, int y)
    {
        kolor = k;
        numer = n;
        zbity = false;
        pozycja[0] = x;
        pozycja[1] = y;
    }
    int virtual rusz(Szachownica* s, int* pole)  =0;

    char podajkolor();
    /*
    {
        return kolor;
    }*/

    int podajnumer()
    {
        return numer;
    }

    int czyzbity()
    {
        return zbity;
    }

    int zbij()
    {
        if (zbity == false)
        {
            zbity =true;
            pozycja[0] = -10;
            pozycja[1] = -10;
            return 0;
        }
        return 1;
    }

    int virtual zmienpozycje(int* x)
    {
        pozycja[0]=x[0];
        pozycja[1]=x[1];
        return 0;
    }

    bool czypierwszy()
    {
        return pierwszy;
    }
    void pierwszyruch()
    {
        pierwszy = true;
    }

    int* podajpozycje()
    {
        return pozycja;
    }

    int virtual promotuj(int p)
    {
        return p;
    }


};



/*
class Pion : public Bierka
{
    bool    pierwszy;   //czy wykonano pierwszy ruch

public:

    ~Pion()
    {
      // cout<<"destruktor"<<endl;
    }
    Pion(char k, int n) :Bierka(k, n){
        //cout<<"konstruktor"<<kolor<<numer<<endl;
        pozycja[0] = -1;
        pozycja[1] = -1;
        zbity = false;
        pierwszy = false;
    }
    int rusz(Szachownica* s, int* pole);
    int zmienpozycje(int *pole)
    {
        pozycja[0]=pole[0];
        pozycja[1]=pole[1];
        pierwszy = true;
        return 0;
    }

    bool czypierwszy()
    {
        return pierwszy;
    }

    int promotuj()
    {
        return 0;
    }



};*/


#endif // BIERKA_H

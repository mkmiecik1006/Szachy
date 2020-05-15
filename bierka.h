#ifndef BIERKA_H
#define BIERKA_H
class Szachownica;

using namespace std;
class Bierka
{
protected:
    char    kolor;
    int     numer;
    int     rysuj;
    bool    zbity;  //domyślnie figury nie są zbite
    int     pozycja[2];
    int     tmp[2];
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
        tmp[0] = x;
        tmp[1] = y;
        rysuj = n;
        pierwszy = false;
    }
    int virtual rusz(Szachownica* s, int pole[2], bool t = false)  =0;

    int virtual bij(Szachownica* s, int pole[2], bool t = false)  =0;

    char podajkolor(){return kolor;}

    int podajnumer(){ return numer;}

    int czyzbity() {return zbity;}

    int zbij()
    {
        if (zbity == false)
        {
            zbity =true;
            return 0;
        }
        return 1;
    }

    int cofnijzbij()
    {
        zbity = false;
        return 0;
    }

    int virtual zmienpozycje(int* x)
    {
        pierwszy = true;
        pozycja[0]=x[0];
        pozycja[1]=x[1];
        tmp[0]=x[0];
        tmp[1]=x[1];
        return 0;
    }

    int zmientmp(int* x)
    {
        tmp[0]=x[0];
        tmp[1]=x[1];
        return 0;
    }

    bool czypierwszy(){ return pierwszy; }
    void pierwszyruch() { pierwszy = true;}
    void ustawPierwszy(bool p) {pierwszy = p;}
    int* podajpozycje(){  return pozycja;}
    int* podajtmp(){  return tmp;}
    int virtual promotuj(int p) { return p;}
    int narysuj() {return rysuj;}

    void cofnijtmp()
    {
        tmp[0]=pozycja[0];
        tmp[1]=pozycja[1];
    }


};



#endif // BIERKA_H

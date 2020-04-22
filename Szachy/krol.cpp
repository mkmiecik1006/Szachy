#include "krol.h"
#include "bierka.h"
#include "szachownica.h"

int Krol::rusz(Szachownica s, int *poz)
{
    int x   = poz[0];               //jeżeli zajęte poda numer bierki
    int y   = poz[1];
    bool bicie = false;
    int bierka = s.czywolne(poz);
    if(x>=0&&y>=0&&x<8&&y<8) //jesteśmy wewnątrz planszy
    {
        if(x!=pozycja[0]&&y!=pozycja[1]) //ruszamy się gdzieś
        {
            if(bierka!=0)
            {

                Bierka* b = &(s.figury.find(bierka)->second); //znadujemy bierkę o numerze na pozycji
                if(kolor != b->podajkolor())  bicie = true;
                else bicie = false;

            }
            if(bierka==0||bicie) //bicie dozwolone, rózny kolor
            {
                int rx = x-pozycja[0];      //odległość od aktualnej pozycji
                int ry = y-pozycja[1];
                if(abs(rx)<=1&&abs(ry)<=1)  //pola do okoła
                {
                    return 0;
                }
            }

        }

    }
    return 1;

}

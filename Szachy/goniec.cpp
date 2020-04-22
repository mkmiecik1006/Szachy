#include "goniec.h"
#include "bierka.h"
#include "szachownica.h"
//#include "szachownica.cpp"


int Goniec::rusz(Szachownica s, int* poz)
{

    int x   = poz[0];               //jeżeli zajęte poda numer bierki
    int y   = poz[1];

    if(x>=0&&y>=0&&x<8&&y<8)
    {
        if(x!=pozycja[0]&&y!=pozycja[1])    //musimy sie gdzieś poruszyć
        {
            int rx = x-pozycja[0];      //odległość od aktualnej pozycji
            int ry = y-pozycja[1];
            int krok[2] = {pozycja[0], pozycja[1]};
            if(abs(rx)==abs(ry))   //jezeli poruszamy się po przekątnej
            {
                int kx, ky;
                if(rx>0)  kx=1;      //krok dla x
                else     kx =-1;     //krok dla y
                if(ry>0)  ky=1;
                else     ky =-1;
                for(int i=0; i<abs(rx); i++)
                {
                    krok[0] +=kx;
                    krok[1] +=ky;
                    if(i==abs(rx))  //ostatnie pole
                    {
                        int bierka = s.czywolne(krok);
                        if(bierka==0)
                        {
                            return 0;   //ruch dozwolony
                        }
                        else //bicie
                        {
                            Bierka* b = &(s.figury.find(bierka)->second); //znadujemy bierkę o numerze na pozycji
                            if(kolor != b->podajkolor())
                            {
                                return 0;
                            }
                        }
                    }
                    else if(s.czywolne(krok)!=0)    //czy pola po drodze są wolne
                    {
                        return 1;
                    }


                }
            }
        }

    }
    return 1;
}



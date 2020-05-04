#include "hetman.h"
#include "bierka.h"
#include "szachownica.h"

int Hetman::rusz(Szachownica* s, int *poz)
{
    int x   = poz[0];               //jeżeli zajęte poda numer bierki
    int y   = poz[1];
    bool bicie = false;
    int bierka = s->czywolne(poz);
    if(zbity==false)
    {
        if(x!=pozycja[0]||y!=pozycja[1]) //ruszamy się gdzieś
        {
            if(bierka!=0)
            {

                Bierka* b = s->figury.find(bierka)->second; //znadujemy bierkę o numerze na pozycji
                if(kolor != b->podajkolor())  bicie = true;
                else bicie = false;

            }
            if(bierka==0||bicie) //bicie dozwolone, rózny kolor
            {
                int rx = x-pozycja[0];      //odległość od aktualnej pozycji
                int ry = y-pozycja[1];
                int kx = 0; //krok dla x
                int ky = 0; //krok dla y
                int z = 0;
                int krok[2] = {pozycja[0], pozycja[1]};
                if(pozycja[0]==x||pozycja[1]==y)    //ruch po prostych
                {
                    if(rx!=0)
                    {
                        z = abs(rx);
                        if(rx>0)   kx=1;      //krok dla x
                        else     kx =-1;     //krok dla y
                    }
                    else if(ry!=0)
                    {
                        z = abs(ry);
                        if(ry>0)  ky=1;
                        else     ky =-1;
                    }


                }
                else if(abs(rx)==abs(ry))       //ruch po przekątnych
                {
                    z = abs(rx);
                    if(rx>0)  kx=1;      //krok dla x
                    else     kx =-1;     //krok dla y
                    if(ry>0)  ky=1;
                    else     ky =-1;
                }
                if(z!=0)
                {
                    for(int i = 0; i <z; i++)
                    {
                        krok[0] +=kx;
                        krok[1] +=ky;
                        if(i==z-1)  //ostatnie pole
                        {
                            int bierka = s->czywolne(krok);
                            if(bierka==0)
                            {
                                return 0;   //ruch dozwolony
                            }
                            else //bicie
                            {
                                Bierka* b = s->figury.find(bierka)->second; //znadujemy bierkę o numerze na pozycji
                                if(kolor != b->podajkolor())
                                {
                                    return 0;
                                }
                            }
                        }
                        else if(s->czywolne(krok)!=0)    //czy pola po drodze są wolne
                        {
                            return 1;
                        }

                    }
                }
            }
        }
    }
    return 1;
}

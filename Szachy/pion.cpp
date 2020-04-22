#include "bierka.h"
#include "pion.h"

#include "szachownica.h"

//#include  "szachownica.cpp"


int Pion::rusz(Szachownica s, int* poz)
{
    int bierka = s.czywolne(poz);   //na planszy znajdujemy dane pole, jeżeli jest wolne ma wartość 0
    int x   = poz[0];               //jeżeli zajęte poda numer bierki
    int y   = poz[1];
    if(x>=0&&y>=0&& x<8&&y<8)
    {
        if( bierka == 0)
        {
            if( pozycja[0]==x) //ta sama kolumna
            {
                if(pozycja[1]==y+1)
                {

                    return 0;
                }
                else if(pierwszy==false&&pozycja[1]==y+2)
                {

                    return 0;
                }
                else
                {
                    return 1;
                }

            }
            else
            {
                return 1;
            }
        }
        else //bicie
        {
            Bierka* b = &(s.figury.find(bierka)->second); //znadujemy bierkę o numerze na pozycji
            if(kolor != b->podajkolor())    //jeżeli bierka jest innego koloru to można bić
            {
                if((pozycja[1]==y+1)&&(pozycja[0]==x-1||pozycja[0]==x+1))   //pole o 1 do przodu i po skosie
                {
                    return 0;
                }
            }
            else
            {
                return 1;   //bierek własnych nie bijemy, ruch zabroniony
            }
        }
    }
    else
    {
        return 1;
    }
    return 1;
}



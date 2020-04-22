#include "kon.h"

#include "szachownica.h"
#include "bierka.h"

int Kon::rusz(Szachownica s, int *poz)
{

    int x   = poz[0];               //jeżeli zajęte poda numer bierki
    int y   = poz[1];
    bool bicie = false;
    int bierka = s.czywolne(poz);
    if(x>=0&&y>=0&&x<8&&y<8)
    {
        if(x!=pozycja[0]&&y!=pozycja[1]) //ruszamy się gdzieś
        {

            if(bierka!=0)
            {

                Bierka* b = &(s.figury.find(bierka)->second); //znadujemy bierkę o numerze na pozycji
                if(kolor != b->podajkolor())  bicie = true;
                else bicie = false;

            }
            if(bierka==0||bicie)
            {
                if(s.czywolne(poz)==0)
                {
                    if((pozycja[1]==y-2||pozycja[1]==y+2)&&(pozycja[0]==x-1||pozycja[0]==x+1))
                    {
                        return 0;
                    }
                    else if((pozycja[0]==x-2||pozycja[0]==x+2)&&(pozycja[1]==y-1||pozycja[1]==y+1))
                    {
                        return 0;
                    }
                }
            }
            else
            {
                return 1;
            }


        }
    }
    return 1;
}

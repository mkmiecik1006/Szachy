#include "bierka.h"
#include "pion.h"

#include "szachownica.h"

//#include  "szachownica.cpp"


int Pion::rusz(Szachownica* s, int* poz, bool t)
{
    int x   = poz[0];               //pozycja na którą chcemy się ruszyć
    int y   = poz[1];
    int x2;                         //pozycja na której obecnie jestesmy
    int y2;
    if(t)
    {
        x2 = tmp[0];
        y2 = tmp[1];
    }
    else
    {
        x2 = pozycja[0];
        y2 = pozycja[1];
    }

    if(zbity==false)
    {
        if(promocja==1)
        {
            if( x2==x) //ta sama kolumna
            {
                if((numer>0 && y2+1==y) || (numer<0&& y2-1 == y))
                {
                    return 0;
                }
                else if(pierwszy==false)
                {
                    if((numer>0 && y2+2==y))
                    {
                        int krok[2] = {x2, y2+1};
                        if(s->czywolne(krok, t)==0) return 0;
                    }
                    else if(numer<0&& y2-2 ==y)
                    {
                        int krok[2] = {x2, y2-1};
                        if(s->czywolne(krok, t)==0)  return 0;
                    }

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
        else if(promocja == 9)
        {
            int rx = x-x2;      //odległość od aktualnej pozycji
            int ry = y-y2;
            int kx = 0; //krok dla x
            int ky = 0; //krok dla y
            int z = 0;
            int krok[2] = {x2, y2};
            if(x2==x||y2==y)    //ruch po prostych
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
                for(int i = 0; i <z; i++)
                {
                    krok[0] +=kx;
                    krok[1] +=ky;
                    if(i==z-1)  //ostatnie pole
                    {
                        return 0;
                    }
                    else if(s->czywolne(krok, t)!=0)    //czy pola po drodze są wolne
                    {
                        return 1;
                    }
                }
            }
        }
        else if(promocja == 11)
        {
            if((y2==y-2||y2==y+2)&&(x2==x-1||x2==x+1))
            {
                return 0;
            }
            else if((x2==x-2||x2==x+2)&&(y2==y-1||y2==y+1))
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else if(promocja == 13)
        {
            int rx = x-x2;      //odległość od aktualnej pozycji
            int ry = y-y2;
            int krok[2] = {x2, y2};
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
                    if(i==abs(rx)-1)  //ostatnie pole
                    {
                        return 0;
                    }
                    else if(s->czywolne(krok, t)!=0)    //czy pola po drodze są wolne
                    {
                        return 1;
                    }


                }
            }
        }
        else if(promocja ==15)
        {
            int rx = x-x2;      //odległość od aktualnej pozycji
            int ry = y-y2;
            int kx = 0; //krok dla x
            int ky = 0; //krok dla y
            int z = 0;
            int krok[2] = {x2, y2};
            if(x2==x||y2==y)    //ruch po prostych
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
                        return 0;
                    }
                    else if(s->czywolne(krok, t)!=0)    //czy pola po drodze są wolne
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 1;
}

int Pion::promotuj(int p)
{
    promocja = p;
    if(numer >0)rysuj = p;
    else rysuj = -p;
    return 0;
}
int Pion::zmienpozycje(int* pole)
{
    pozycja[0]=pole[0];
    pozycja[1]=pole[1];
    tmp[0]=pole[0];
    tmp[1]=pole[1];
    pierwszy = true;
    if(promocja==1 &&((numer>0&& pole[1]==7)||(numer<0 &&pole[1]==0)))
    {
        std::string wyjatek = "promocja";
        throw wyjatek;
    }
    return 0;
}

int Pion::bij(Szachownica* s, int* poz, bool t)
{
    int x   = poz[0];               //pozycja na którą chcemy się ruszyć
    int y   = poz[1];
    int x2;                         //pozycja na której obecnie jestesmy
    int y2;
    if(t)
    {
        x2 = tmp[0];
        y2 = tmp[1];
    }
    else
    {
        x2 = pozycja[0];
        y2 = pozycja[1];
    }
    if(zbity==false)
    {
        if(promocja==1)
        {
            if(((numer>0&& y2+1==y)||(numer<0 && y2-1==y))&&(x2-1 ==x||x2+1 ==x))   //pole o 1 do przodu i po skosie
            {
                return 0;
            }
            else
            {
                return 1;   //bierek własnych nie bijemy, ruch zabroniony
            }
        }
        else if(promocja == 9)
        {
            int rx = x-x2;      //odległość od aktualnej pozycji
            int ry = y-y2;
            int kx = 0; //krok dla x
            int ky = 0; //krok dla y
            int z = 0;
            int krok[2] = {x2, y2};
            if(x2==x||y2==y)    //ruch po prostych
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
                for(int i = 0; i <z; i++)
                {
                    krok[0] +=kx;
                    krok[1] +=ky;
                    if(i==z-1)  //ostatnie pole
                    {
                        return 0;
                    }
                    else if(s->czywolne(krok, t)!=0)    //czy pola po drodze są wolne
                    {
                        return 1;
                    }
                }
            }
        }
        else if(promocja == 11)
        {
            if((y2==y-2||y2==y+2)&&(x2==x-1||x2==x+1))
            {
                return 0;
            }
            else if((x2==x-2||x2==x+2)&&(y2==y-1||y2==y+1))
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else if(promocja == 13)
        {
            int rx = x-x2;      //odległość od aktualnej pozycji
            int ry = y-y2;
            int krok[2] = {x2, y2};
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
                    if(i==abs(rx)-1)  //ostatnie pole
                    {
                        return 0;
                    }
                    else if(s->czywolne(krok, t)!=0)    //czy pola po drodze są wolne
                    {
                        return 1;
                    }


                }
            }
        }
        else if(promocja ==15)
        {
            int rx = x-x2;      //odległość od aktualnej pozycji
            int ry = y-y2;
            int kx = 0; //krok dla x
            int ky = 0; //krok dla y
            int z = 0;
            int krok[2] = {x2, y2};
            if(x2==x||y2==y)    //ruch po prostych
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
                        return 0;
                    }
                    else if(s->czywolne(krok, t)!=0)    //czy pola po drodze są wolne
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 1;
}




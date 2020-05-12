#include "bierka.h"
#include "pion.h"

#include "szachownica.h"

//#include  "szachownica.cpp"


int Pion::rusz(Szachownica* s, int* poz)
{
    int bierka = s->czywolne(poz);   //na planszy znajdujemy dane pole, jeżeli jest wolne ma wartość 0
    int x   = poz[0];               //jeżeli zajęte poda numer bierki
    int y   = poz[1];
    bool bicie = false;
    if(zbity==false)
    {
        if(promocja==1)
        {
            if( bierka == 0)
            {
                if( pozycja[0]==x) //ta sama kolumna
                {
                    if((numer>0 && pozycja[1]+1==y) || (numer<0&& pozycja[1]-1 == y))
                    {

                        return 0;
                    }
                    else if(pierwszy==false&&((numer>0 && pozycja[1]+2==y) ||(numer<0&& pozycja[1]-2 ==y) ))
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
                Bierka* b = s->figury.find(bierka)->second; //znadujemy bierkę o numerze na pozycji
                if(kolor != b->podajkolor())    //jeżeli bierka jest innego koloru to można bić
                {
                    if(((numer>0&& pozycja[1]+1==y)||(numer<0 && pozycja[1]-1==y))&&(pozycja[0]-1 ==x||pozycja[0]+1 ==x))   //pole o 1 do przodu i po skosie
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
        else if(promocja == 9)
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
        else if(promocja == 11)
        {
            if(bierka!=0)
            {

                Bierka* b = s->figury.find(bierka)->second; //znadujemy bierkę o numerze na pozycji
                if(kolor != b->podajkolor())  bicie = true;
                else bicie = false;

            }
            if(bierka==0||bicie)
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
            else
            {
                return 1;
            }
        }
        else if(promocja == 13)
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
                    if(i==abs(rx)-1)  //ostatnie pole
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
        else if(promocja ==15)
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
    else
    {
        return 1;
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
    pierwszy = true;
    if(promocja==1 &&((numer>0&& pole[1]==7)||(numer<0 &&pole[1]==0)))
    {
        std::string wyjatek = "promocja";
        throw wyjatek;
    }
    return 0;
}





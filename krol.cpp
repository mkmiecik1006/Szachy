#include "krol.h"
#include "bierka.h"
#include "szachownica.h"
#include <string>

int Krol::rusz(Szachownica* s, int *poz)
{
    int x   = poz[0];               //jeżeli zajęte poda numer bierki
    int y   = poz[1];
    int bierka = s->czywolne(poz);
    if(zbity==false)
    {
        if(x!=pozycja[0]||y!=pozycja[1]) //ruszamy się gdzieś
        {

            if(bierka==0) //bicie dozwolone, rózny kolor
            {
                int rx = x-pozycja[0];      //odległość od aktualnej pozycji
                int ry = y-pozycja[1];
                if(abs(rx)<=1&&abs(ry)<=1)  //pola do okoła
                {
                    return 0;
                }
                else if(pierwszy==false && x==2 && pozycja[1]==y)       //roszada
                {
                    Bierka* b;
                    if(numer>0) b = s->figury.find(9)->second;
                    else b = s->figury.find(-9)->second;
                    if(b->czypierwszy()==false)
                    {
                        int p1[2] = {1, y};
                        int p2[2] = {2, y};
                        int p3[2] = {3, y};
                        if((s->czywolne(p1)==0 && s->czywolne(p2)==0) && s->czywolne(p3)==0) //czy pola miedzy krolem a wieza są wolne
                        {
                            if((szach(pozycja, s)!=0 && szach(p2, s)!=0) && szach(p3, s)!=0) //król i pola przez które przejdzie nie są szachowane
                            {
                                std::string wyjatek = "roszada1";
                                throw wyjatek;
                            }
                        }
                    }
                }
                else if(pierwszy== false && x==6&& pozycja[1]==y)
                {
                    Bierka* b;
                    if(numer>0) b = s->figury.find(10)->second;
                    else b = s->figury.find(-10)->second;
                    if(b->czypierwszy()==false)
                    {
                        int p1[2] = {5, y};
                        int p2[2] = {6, y};
                        if(s->czywolne(p1)==0&&s->czywolne(p2)==0) //czy pola miedzy krolem a wieza są wolne
                        {
                            if(szach(pozycja, s)!=0&&szach(p2, s)!=0) //król i pola przez które przejdzie nie są szachowane
                            {
                                std::string wyjatek = "roszada2";
                                throw wyjatek;
                            }
                        }
                    }
                }
            }
            else //bicie
            {
                Bierka* b = s->figury.find(bierka)->second; //znadujemy bierkę o numerze na pozycji
                if(kolor != b->podajkolor())
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

    }
    return 1;

}

bool Krol::szach(int* pole, Szachownica* szachownica)
{
    map<int, Bierka*> ::iterator it = szachownica->figury.begin();
    while(it!=szachownica->figury.end())
    {
        if(it->second->podajkolor()!=kolor)
        {
            if(it->second->rusz(szachownica, pole)==0)
            {
                return 0;
            }

        }
        it++;
    }

    return 1;
}

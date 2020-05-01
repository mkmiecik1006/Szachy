#include "rozgrywka.h"
#include "wieza.h"

Rozgrywka::Rozgrywka()
{
    kolej = 'w';
    Szachownica szachownica();
    aktywna = false;
}

int Rozgrywka::nowa()
{
    szachownica.ustaw();
    kolej = 'w';
    aktywna = true;
    return 0;
}

int Rozgrywka::zakoncz()
{
    szachownica.wyczysc();
    aktywna = false;
    return 0;
}
void Rozgrywka::zmienkolej()
{
    if(kolej=='w') kolej='b';
    else if(kolej=='b') kolej ='w';

}

int Rozgrywka::ruch(int bierka, int *pole)
{
    Bierka* b = &(szachownica.figury.find(bierka)->second);
    if(kolej == b->podajkolor())
    {
        int x   = pole[0];               //jeżeli zajęte poda numer bierki
        int y   = pole[1];

        if(x>=0&&y>=0&&x<8&&y<8)
        {
            if(szachownica.czywolne(pole)==0)
            {
                if(b->rusz(&szachownica, pole)==0)
                {
                    szachownica.przesun(b, pole);
                    zmienkolej();
                    return 0;
                }
                else
                {
                    return 1;
                }

            }
            else
            {
                int bierka2 = szachownica.czywolne(pole);
                Bierka* b2 = &(szachownica.figury.find(bierka2)->second);
                if(b->podajkolor()!=b2->podajkolor())
                {
                    if(b->rusz(&szachownica, pole))
                    {
                        szachownica.zbij(b2);
                        szachownica.przesun(b, pole);
                        zmienkolej();
                        return 0;
                    }
                }
                else
                {
                    return 1;
                }
            }
        }
    }
    return 1;
}

int Rozgrywka::roszada(int bierka)
{
    Bierka* w = &(szachownica.figury.find(bierka)->second);//wieza
    int* p1;
    int* p2;
    int* p3;
    Bierka* k; //krol
    if(w->podajnumer()>0)
    {
        k = &(szachownica.figury.find(16)->second);
    }
    else
    {
        k = &(szachownica.figury.find(-16)->second);
    }
    if(w->podajkolor()==kolej)
    {
        if(abs(w->podajnumer())==9||abs(w->podajnumer())==10)
        {
            if(w->czypierwszy()==false && k->czypierwszy()==false &&szach()==1)
            {
                if(abs(w->podajnumer())==9)
                {
                       p1 = w->podajpozycje();
                       p1[0] = 1;
                       p2 = w->podajpozycje();
                       p2[0] = 2;
                       p3 = w->podajpozycje();
                       p3[0] = 3;
                       map<int, Bierka> ::iterator it = szachownica.figury.begin();


                       while(it!=szachownica.figury.end())
                       {
                           if(w->podajkolor()!=it->second.podajkolor())
                           {
                                if(it->second.rusz(&szachownica, p2)==0||it->second.rusz(&szachownica, p3)==0)
                                {
                                    return 1;
                                }
                                it++;
                           }
                       }

                       if(szachownica.czywolne(p1)==0&&szachownica.czywolne(p2)==0&&szachownica.czywolne(p1)==0)
                       {
                            k->zmienpozycje(p2);
                            w->zmienpozycje(p3);
                            return 0;
                       }
                }
                else if(abs(w->podajnumer())==10)
                {
                    p1 = w->podajpozycje();
                    p1[0] = 5;
                    p2 = w->podajpozycje();
                    p2[0] = 6;
                    map<int, Bierka> ::iterator it = szachownica.figury.begin();


                    while(it!=szachownica.figury.end())
                    {
                        if(w->podajkolor()!=it->second.podajkolor())
                        {
                             if(it->second.rusz(&szachownica, p1)==0||it->second.rusz(&szachownica, p2)==0)
                             {
                                 return 1;
                             }
                             it++;
                        }
                    }
                    if(szachownica.czywolne(p1)&&szachownica.czywolne(p2))
                    {
                        k->zmienpozycje(p2);
                        w->zmienpozycje(p1);
                        return 0;
                    }
                }

            }

        }
    }
    return 1;
}

int Rozgrywka::szach()
{
    Bierka* kw; //krol bialy
    kw = &(szachownica.figury.find(16)->second);
    int* pw = kw->podajpozycje();
    Bierka* kb; //krol czarny
    int* pb = kb->podajpozycje();
    kb = &(szachownica.figury.find(-16)->second);
    map<int, Bierka> ::iterator it = szachownica.figury.begin();
    while(it!=szachownica.figury.end())
    {
        if(it->second.rusz(&szachownica, pw)==0||it->second.rusz(&szachownica, pb)==0)
        {
            return 0;
        }
        it++;
    }

    return 1;
}


#include "rozgrywka.h"
#include "wieza.h"

#include <stdexcept>

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
bool Rozgrywka::czyaktywna()
{
    return aktywna;
}

int Rozgrywka::ruch(Bierka* b, int* pole)
{
    if(kolej == b->podajkolor())
    {
        int x   = pole[0];               //jeżeli zajęte poda numer bierki
        int y   = pole[1];

        if(x>=0&&y>=0&&x<8&&y<8)
        {
            if(szachownica.czywolne(pole)==0)
            {
                try
                {
                    if(b->rusz(&szachownica, pole)==0)
                    {
                        szachownica.przesun(b, pole);
                        zmienkolej();
                        return 0;
                    }
                    else
                    {
                        throw std::runtime_error("Nie prawidłowy ruch");
                    }
                }
                catch(std::string wyjatek)
                {
                    if(wyjatek=="roszada1")
                    {
                        Bierka* b2;
                        if(b->podajnumer()>0) b2 = szachownica.figury.find(9)->second;
                        else if(b->podajnumer()<0) b2 = szachownica.figury.find(-9)->second;
                        int pole2[2] = {3, pole[1]};
                        szachownica.przesun(b, pole);
                        szachownica.przesun(b2, pole2);
                        zmienkolej();
                        throw wyjatek;
                    }
                    else if(wyjatek=="roszada2")
                    {
                        Bierka* b2;
                        if(b->podajnumer()>0) b2 = szachownica.figury.find(10)->second;
                        else if(b->podajnumer()<0) b2 = szachownica.figury.find(-10)->second;
                        int pole2[2] = {5, pole[1]};
                        szachownica.przesun(b, pole);
                        szachownica.przesun(b2, pole2);
                        zmienkolej();
                        throw wyjatek;
                    }
                    else if(wyjatek=="promocja")
                    {
                        //zmienkolej();
                        throw wyjatek;
                    }
                }

            }
            else
            {
                int bierka2 = szachownica.czywolne(pole);
                Bierka* b2 = szachownica.figury.find(bierka2)->second;
                if(b->podajkolor()!=b2->podajkolor())
                {
                    if(b->rusz(&szachownica, pole)==0)
                    {
                        if(b2->podajnumer()==16||b2->podajnumer()==-16) throw std::runtime_error("Szach, bicie króla");
                        else
                        {
                            b->pierwszyruch();
                            szachownica.zbij(b2);
                            szachownica.przesun(b, pole);
                            zmienkolej();
                            return 0;
                        }
                    }
                }
                else
                {
                    throw std::runtime_error("Nie można bić własnych figur!");
                }
            }
        }
        else throw std::runtime_error("Wybrano pole poza planszą!");
    }
    else throw std::runtime_error("Teraz nie jest twoja kolej!");
    return 1;
}


int Rozgrywka::szach()
{
    Bierka* kw; //krol bialy
    kw = szachownica.figury.find(16)->second;
    int* pw = kw->podajpozycje();
    Bierka* kb; //krol czarny
    kb = szachownica.figury.find(-16)->second;
    int* pb = kb->podajpozycje();
    map<int, Bierka*> ::iterator it = szachownica.figury.begin();
    while(it!=szachownica.figury.end())
    {
        if(it->second->rusz(&szachownica, pw)==0||it->second->rusz(&szachownica, pb)==0)
        {
            return 0;
        }
        it++;
    }

    return 1;
}


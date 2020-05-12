#include "rozgrywka.h"
#include "wieza.h"

#include <stdexcept>

Rozgrywka::Rozgrywka()
{
    kolej = 'w';
    Szachownica szachownica();
    aktywna = false;
    poprzedni = PoprzedniRuch();
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
                        int p1[2];
                        p1[0] = b->podajpozycje()[0];
                        p1[1] = b->podajpozycje()[1];
                        poprzedni.ZapiszPoprzedni(kolej, b, p1);
                       // bool pierwszy = b->czypierwszy();
                        szachownica.przesun(b, pole);
                        zmienkolej();
                        return 0;
                        /*
                        if(b->podajnumer()>0)
                        {
                            if(szachw()!=0)
                            {
                                poprzedni.ZapiszPoprzedni(kolej, b, p1);
                                zmienkolej();
                                return 0;
                            }
                            else
                            {
                                szachownica.przesun(b, p1);
                                b->ustawPierwszy(pierwszy);
                                throw std::runtime_error("Twój król jest szachowany!");
                            }
                        }
                        else
                        {
                            if(szachb()!=0)
                            {
                                poprzedni.ZapiszPoprzedni(kolej, b, p1);
                                zmienkolej();
                                return 0;
                            }
                            else
                            {
                                szachownica.przesun(b, p1);
                                throw std::runtime_error("Twój król jest szachowany!");
                            }
                        }*/

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
                        poprzedni.ZapiszPoprzedni(kolej, b, b->podajpozycje(), b2, b2->podajpozycje());
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
                        poprzedni.ZapiszPoprzedni(kolej, b, b->podajpozycje(), b2, b2->podajpozycje());
                        szachownica.przesun(b, pole);
                        szachownica.przesun(b2, pole2);
                        zmienkolej();
                        throw wyjatek;
                    }
                    else if(wyjatek=="promocja")
                    {
                        poprzedni.Promocja();
                        zmienkolej();
                        throw wyjatek;
                    }
                }

            }
            else
            {
                int bierka2 = szachownica.czywolne(pole);
                Bierka* b2 = szachownica.figury.find(bierka2)->second;
                int p1[2];
                int p2[2];
                p1[0] = b->podajpozycje()[0];
                p1[1] = b->podajpozycje()[1];
                p2[0] = b2->podajpozycje()[0];
                p2[1] = b2->podajpozycje()[1];
                //bool pierwszy1 = b->czypierwszy();
                //bool pierwszy2 = b2->czypierwszy();
                if(b->podajkolor()!=b2->podajkolor())
                {
                    try
                    {
                        if(b->rusz(&szachownica, pole)==0)
                        {
                            if(b2->podajnumer()==16||b2->podajnumer()==-16) throw std::runtime_error("Szach, bicie króla");
                            else
                            {
                                poprzedni.ZapiszPoprzedni(kolej, b, p1, b2, p2);
                                szachownica.zbij(b2);
                                szachownica.przesun(b, pole);
                                zmienkolej();
                                return 0;
                                /*
                                if(b->podajnumer()>0)
                                {
                                    if(szachw()!=0)
                                    {
                                        poprzedni.ZapiszPoprzedni(kolej, b, p1, b2, p2);
                                        zmienkolej();
                                        return 0;
                                    }
                                    else
                                    {
                                        szachownica.przesun(b, p1);
                                        szachownica.przesun(b2, p2);
                                        b->ustawPierwszy(pierwszy1);
                                        b2->ustawPierwszy(pierwszy2);
                                        b2->cofnijzbij();
                                        throw std::runtime_error("Twój król jest szachowany!");
                                    }
                                }
                                else
                                {
                                    if(szachb()!=0)
                                    {
                                        poprzedni.ZapiszPoprzedni(kolej, b, p1, b2, p2);
                                        zmienkolej();
                                        return 0;
                                    }
                                    else
                                    {
                                        szachownica.przesun(b, p1);
                                        szachownica.przesun(b2, p2);
                                        b2->czyzbity();
                                        throw std::runtime_error("Twój król jest szachowany!");
                                    }
                                }*/
                            }
                        }
                    }
                    catch(std::string wyjatek)
                    {

                    if(wyjatek=="promocja")
                        {
                            poprzedni.Promocja();
                            zmienkolej();
                            throw wyjatek;
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


int Rozgrywka::cofnij()
{
    if(poprzedni.PodajAktywny())
    {

        if(poprzedni.PodajBicie())
        {
            szachownica.przesun(poprzedni.PodajPoprzednia(), poprzedni.PodajPozycja());
            szachownica.przesun(poprzedni.PodajBita(), poprzedni.PodajPozycjaBita());
            poprzedni.PodajBita()->cofnijzbij();
            if(!poprzedni.PodajPierwszy()) poprzedni.PodajPoprzednia()->ustawPierwszy(false);
            if(!poprzedni.PodajPierwszy()) poprzedni.PodajBita()->ustawPierwszy(false);
        }
        else //jeżeli nie było bicia
        {
            szachownica.przesun(poprzedni.PodajPoprzednia(), poprzedni.PodajPozycja());
            if(!poprzedni.PodajPierwszy()) poprzedni.PodajPoprzednia()->ustawPierwszy(false);
        }

        if(poprzedni.PodajPromocja())
        {
            poprzedni.PodajPoprzednia()->promotuj(1);
        }
        poprzedni.ZmienAktywny();
        zmienkolej();
    }
    return 0;
}

int Rozgrywka::szachw()
{
    Bierka* kw; //krol bialy
    kw = szachownica.figury.find(16)->second;
    int* pw = kw->podajpozycje();
    map<int, Bierka*> ::iterator it = szachownica.figury.begin();
    while(it!=szachownica.figury.end())
    {
        if(it->second->rusz(&szachownica, pw)==0)
        {
            return 0;
        }
        it++;
    }

    return 1;

}

int Rozgrywka::szachb()
{
    Bierka* kb; //krol bialy
    kb = szachownica.figury.find(-16)->second;
    int* pb = kb->podajpozycje();
    map<int, Bierka*> ::iterator it = szachownica.figury.begin();
    while(it!=szachownica.figury.end())
    {
        if(it->second->rusz(&szachownica, pb)==0)
        {
            return 0;
        }
        it++;
    }

    return 1;

}

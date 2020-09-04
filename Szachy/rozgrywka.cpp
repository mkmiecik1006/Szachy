#include "rozgrywka.h"
#include "wieza.h"

#include <stdexcept>

Rozgrywka::Rozgrywka()
{
    kolej = 'w';
    Szachownica szachownica();
    aktywna = false;
    poprzedni = PoprzedniRuch();
    Plansza historia();
    wygrana = ' ';
}

int Rozgrywka::nowa()
{
    szachownica.ustaw();
    kolej = 'w';
    historia.push_back(Plansza(szachownica.plansza, kolej));
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

int Rozgrywka::ruch(Bierka* b, int pole[2])
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

                            szachownica.przesuntmp(b, pole);
                            if(b->podajnumer()>0)
                            {
                                if(szachw()!=0)
                                {
                                    poprzedni.ZapiszPoprzedni(licznik, kolej, b, p1);
                                    szachownica.przesun(b, pole);
                                    zmienkolej();
                                    if(abs(b->narysuj())==1) licznik = 0;
                                    else licznik++;
                                    historia.push_back(Plansza(szachownica.plansza, kolej));

                                    return 0;
                                }
                                else
                                {
                                    szachownica.cofnijtmp();
                                    b->cofnijtmp();
                                    throw std::runtime_error("Twój król jest szachowany!");
                                }
                            }
                            else
                            {
                                if(szachb()!=0)
                                {
                                    poprzedni.ZapiszPoprzedni(licznik, kolej, b, p1);
                                    szachownica.przesun(b, pole);
                                    zmienkolej();
                                    if(abs(b->narysuj())==1) licznik = 0;
                                    else licznik++;
                                    historia.push_back(Plansza(szachownica.plansza, kolej));
                                    return 0;
                                }
                                else
                                {
                                    szachownica.cofnijtmp();
                                    b->cofnijtmp();
                                    throw std::runtime_error("Twój król jest szachowany!");
                                }
                            }
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
                        if(b->podajnumer()>0) b2 = szachownica.znajdz(9);
                        else if(b->podajnumer()<0) b2 = szachownica.znajdz(-9);
                        int pole2[2] = {3, pole[1]};
                        poprzedni.ZapiszPoprzedni(licznik, kolej, b, b->podajpozycje(), b2, b2->podajpozycje());
                        szachownica.przesun(b, pole);
                        szachownica.przesun(b2, pole2);
                        zmienkolej();
                        licznik++;
                        historia.push_back(Plansza(szachownica.plansza, kolej));
                        throw wyjatek;
                    }
                    else if(wyjatek=="roszada2")
                    {
                        Bierka* b2;
                        if(b->podajnumer()>0) b2 = szachownica.znajdz(10);
                        else if(b->podajnumer()<0) b2 = szachownica.znajdz(-10);
                        int pole2[2] = {5, pole[1]};
                        poprzedni.ZapiszPoprzedni(licznik, kolej, b, b->podajpozycje(), b2, b2->podajpozycje());
                        szachownica.przesun(b, pole);
                        szachownica.przesun(b2, pole2);
                        zmienkolej();
                        licznik++;
                        historia.push_back(Plansza(szachownica.plansza, kolej));
                        throw wyjatek;
                    }
                    else if(wyjatek=="promocja")
                    {
                        poprzedni.Promocja();
                        zmienkolej();
                        licznik = 0;
                        historia.push_back(Plansza(szachownica.plansza, kolej));
                        throw wyjatek;
                    }
                }

            }
            else      //bicie
            {
                int bierka2 = szachownica.czywolne(pole);
                Bierka* b2 = szachownica.znajdz(bierka2);
                int p1[2];
                int p2[2];
                p1[0] = b->podajpozycje()[0];
                p1[1] = b->podajpozycje()[1];
                p2[0] = b2->podajpozycje()[0];
                p2[1] = b2->podajpozycje()[1];
                if(b->podajkolor()!=b2->podajkolor())
                {
                    try
                    {
                        if(b->bij(&szachownica, pole)==0)
                        {
                            if(b2->podajnumer()==16||b2->podajnumer()==-16) return 1;
                            else
                            {
                                szachownica.zbij(b2, true);
                                szachownica.przesuntmp(b, pole);
                                if(b->podajnumer()>0)
                                {
                                    if(szachw()!=0)
                                    {
                                        poprzedni.ZapiszPoprzedni(licznik, kolej, b, p1, b2, p2);
                                        szachownica.zbij(b2);
                                        szachownica.przesun(b, pole);
                                        zmienkolej();
                                        licznik = 0;
                                        historia.push_back(Plansza(szachownica.plansza, kolej));

                                        return 0;
                                    }
                                    else
                                    {
                                        szachownica.cofnijtmp();
                                        b2->cofnijzbij();
                                        b->cofnijtmp();
                                        b2->cofnijtmp();
                                        throw std::runtime_error("Twój król jest szachowany!");
                                    }
                                }
                                else
                                {
                                    if(szachb()!=0)
                                    {
                                        poprzedni.ZapiszPoprzedni(licznik, kolej, b, p1, b2, p2);
                                        szachownica.zbij(b2);
                                        szachownica.przesun(b, pole);
                                        zmienkolej();
                                        licznik  = 0;
                                        historia.push_back(Plansza(szachownica.plansza, kolej));

                                        return 0;
                                    }
                                    else
                                    {
                                        szachownica.cofnijtmp();
                                        b2->cofnijzbij();
                                        b->cofnijtmp();
                                        b2->cofnijtmp();
                                        throw std::runtime_error("Twój król jest szachowany!");
                                    }
                                }

                            }
                        }
                        else
                        {
                            throw std::runtime_error("Nie prawidłowy ruch");
                        }
                    }
                    catch(std::string wyjatek)
                    {
                        if(wyjatek=="promocja")
                        {
                            poprzedni.Promocja();
                            zmienkolej();
                            licznik = 0;
                            historia.push_back(Plansza(szachownica.plansza, kolej));

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
    kw = szachownica.znajdz(16);
    int* pw = kw->podajpozycje();
    Bierka* kb; //krol czarny
    kb = szachownica.znajdz(-16);
    int* pb = kb->podajpozycje();
    map<int, Bierka*> ::iterator it = szachownica.znajdz2(-16);
    for(int i =0; i<16; i++)
    {
        if(it->second->bij(&szachownica, pw)==0)   //sprawdzamy czy któraś z bierek przeciwnika atakuje króla
        {
            return 0;
        }
        it++;
    }
    it = szachownica.znajdz2(1);
    for(int i =0; i<16; i++)
    {
        if(it->second->bij(&szachownica, pb)==0)   //sprawdzamy czy któraś z bierek przeciwnika atakuje króla
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
        historia.erase(historia.end());
        poprzedni.ZmienAktywny();
        zmienkolej();
    }
    return 0;
}

int Rozgrywka::szachw()
{
    Bierka* kw; //krol bialy
    kw = szachownica.znajdz(16);
    int* pw = kw->podajtmp();
    map<int, Bierka*> ::iterator it = szachownica.znajdz2(-16);
    for(int i =0; i<16; i++)
    {
        if(it->second->bij(&szachownica, pw, true)==0)   //sprawdzamy czy któraś z bierek przeciwnika atakuje króla
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
    kb = szachownica.znajdz(-16);
    int* pb = kb->podajtmp();
    map<int, Bierka*> ::iterator it = szachownica.znajdz2(1);
    for(int i = 0; i<16; i++)
    {
        if(it->second->bij(&szachownica, pb, true)==0)    //sprawdzamy czy któraś z bierek przeciwnika atakuje króla
        {
            return 0;
        }
        it++;
    }
    return 1;
}

int Rozgrywka::mat()
{
    if(kolej=='b')
    {
        map<int, Bierka*> ::iterator it = szachownica.znajdz2(1);
        Bierka* b;
        Bierka* b2;
        for(int k = 0; k<16; k++)
        {
            b = it->second;
            if(!b->czyzbity())
            {
                for(int i = 0; i <8; i++)
                {
                    for(int j = 0; j<8; j++)
                    {
                        int pole[2] = {i, j};
                        int bierka = szachownica.czywolne(pole);
                        if(bierka==0) //puste, ruszamy
                        {
                            if(b->rusz(&szachownica, pole, true)==0)
                            {
                                szachownica.przesuntmp(b, pole);
                                if(szachb()!=0)
                                {
                                    szachownica.cofnijtmp();
                                    b->cofnijtmp();
                                    return 1;  //jeżeli udało wykonać się ruch i nie ma szacha zwraczmy 1
                                }
                                else
                                {
                                    szachownica.cofnijtmp();
                                    b->cofnijtmp();
                                }
                            }
                        }
                        else if(bierka>0) //przeciwnik bijemy
                        {
                            b2 = szachownica.znajdz(bierka);
                            if(b->bij(&szachownica, pole, true)==0)
                            {
                                szachownica.zbij(b2, true);
                                szachownica.przesuntmp(b, pole);
                                if(szachb()!=0)
                                {
                                    szachownica.cofnijtmp();
                                    b->cofnijtmp();
                                    b2->cofnijzbij();
                                    return 1;  //jeżeli udało wykonać się ruch i nie ma szacha zwraczmy 1
                                }
                                else //jak nie to cofamy ruch i próbujemy dalej
                                {
                                    szachownica.cofnijtmp();
                                    b->cofnijtmp();
                                    b2->cofnijzbij();
                                }
                            }
                        }
                    }
                }
            }
        it--;
        }
        return 0;
    }
    else if(kolej=='w')
    {
        map<int, Bierka*> ::iterator it = szachownica.znajdz2(1);
        Bierka* b;
        Bierka* b2;
        for(int k = 0; k<16; k++)
        {            
            b = it->second;
            if(!b->czyzbity())
            {
                for(int i = 0; i <8; i++)
                {
                    for(int j = 0; j<8; j++)
                    {
                        int pole[2] = {i, j};
                        int bierka = szachownica.czywolne(pole);
                        if(bierka==0) //puste, ruszamy
                        {
                            if(b->rusz(&szachownica, pole, true)==0)
                            {
                                szachownica.przesuntmp(b, pole);
                                if(szachw()!=0)
                                {
                                    szachownica.cofnijtmp();
                                    b->cofnijtmp();
                                    return 1;  //jeżeli udało wykonać się ruch i nie ma szacha zwraczmy 1
                                }
                                else
                                {
                                    szachownica.cofnijtmp();
                                    b->cofnijtmp();
                                }
                            }
                        }
                        else if(bierka<0) //przeciwnik bijemy
                        {
                            b2 = szachownica.znajdz(bierka);
                            if(b->bij(&szachownica, pole, true)==0)
                            {
                                szachownica.zbij(b2, true);
                                szachownica.przesuntmp(b, pole);
                                if(szachw()!=0)
                                {
                                    szachownica.cofnijtmp();
                                    b->cofnijtmp();
                                    b2->cofnijzbij();
                                    return 1;  //jeżeli udało wykonać się ruch i nie ma szacha zwraczmy 1
                                }
                                else //jak nie to cofamy ruch i próbujemy dalej
                                {
                                    szachownica.cofnijtmp();
                                    b->cofnijtmp();
                                    b2->cofnijzbij();
                                }
                            }
                        }
                    }
                }
            }
            it++;
        }
    }
    return 0;
}

int Rozgrywka::koniec_gry(char k)
{
    if(k=='w'||k=='b'||k=='r')
    {
        wygrana = k;
        aktywna = false;
        return 0;
    }
    else return 1;
}

int Rozgrywka::powtorzenia()
{
    int powt = 0;
    int s = historia.size();
    Plansza aktualny = historia.back();
    if(s>0)
    {
        for(int i = 0; i<s; i++)
        {
            Plansza* sprawdzana = &historia[i];
            if(aktualny.porownaj(sprawdzana)==0) powt++;
        }
    }
    return powt;
}

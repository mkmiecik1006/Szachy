#include "krol.h"
#include "bierka.h"
#include "szachownica.h"
#include <string>

int Krol::rusz(Szachownica* s, int poz[2], bool t)
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
        if(x!=x2||y!=y2) //ruszamy się gdzieś
        {
            int rx = x-x2;      //odległość od aktualnej pozycji
            int ry = y-y2;
            if(abs(rx)<=1&&abs(ry)<=1)  //pola do okoła
            {
                return 0;
            }
            else if(pierwszy==false && x==2 && y2==y)       //roszada
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

    }
    return 1;

}

bool Krol::szach(int* pole, Szachownica* szachownica)
{
    map<int, Bierka*> ::iterator it = szachownica->figury.find(-16);
    if(numer>0)
    {
        for(int i =0; i<16; i++)
        {
            if(it->second->bij(szachownica, pole)==0)   //sprawdzamy czy któraś z bierek przeciwnika atakuje króla
            {
                return 0;
            }
            it++;
        }
    }
    else
    {
        it = szachownica->figury.find(1);
        for(int i =0; i<16; i++)
        {
            if(it->second->bij(szachownica, pole)==0)   //sprawdzamy czy któraś z bierek przeciwnika atakuje króla
            {
                return 0;
            }
            it++;
        }
    }
    return 1;
}

int Krol::bij(Szachownica* s, int poz[2], bool t)
{

    if(s->czywolne(poz))
    {}
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
        if(x!=x2||y!=y2) //ruszamy się gdzieś
        {
            int rx = x-x2;      //odległość od aktualnej pozycji
            int ry = y-y2;
            if(abs(rx)<=1&&abs(ry)<=1)  //pola do okoła
            {
                return 0;
            }
        }
    }

    return 1;
}

#ifndef ROZGRYWKA_H
#define ROZGRYWKA_H
#include "bierka.h"
#include "szachownica.h"
#include <stdlib.h>
#include "poprzedniruch.h"
#include <list>
#include <vector>
#include "plansza.h"

class Rozgrywka
{

    char    kolej;         //flaga kolejności gracza w- white, b- black
    bool    aktywna;       //flaga rozpoczętej rozgrywki
    int     licznik;        //licznik 50 ruchów bez bicia lub ruchu pionem
    std::vector<Plansza> historia;    //historia ruchów w danej partii
    char    wygrana;
    //int     poworzenia;
public:
    Rozgrywka();
    Szachownica szachownica;
    PoprzedniRuch poprzedni;
    int nowa();         //rozpoczęcie nowej partii
    int zakoncz();      //zakończenie aktualniej partii
    int ruch(Bierka* b, int pole[2]);     //wykonanie ruchu bierka b na pole
    void zmienkolej();      //zmienia kolej aktualnego gracza
    int szach();            //sprawdzenie czy szachowany jest król
    bool czyaktywna();      //zwraca pole aktywna
    char podajkolej() {return kolej;}
    int cofnij();       //cofniecie o 1 ruch
    int szachb();       //sprawdzenie czy czrny król jest szachowany
    int szachw();       //sprawdzenie czy biały król jest szachowany
    int koniec_gry(char k);
    int mat();          //spradzamy czy mmożliwy jest ruch po którym niebedzie szacha
    int powtorzenia(); //metoda zwracajaca liczbe takich samych ukladow na planszy
    int podajlicznik() {return licznik;}

};

#endif // ROZGRYWKA_H

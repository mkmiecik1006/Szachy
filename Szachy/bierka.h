#ifndef BIERKA_H
#define BIERKA_H
class Szachownica;

using namespace std;
class Bierka
{
protected:
    char    kolor;      // kolor bierki w - biełe, b - czarne
    int     numer;      // unikalny numer bierki od 1 do 16, dla bialych +, dla czarnych - określający rodzaj danej bierki
    int     rysuj;      // zmienna określająca numer wyz=swietlanej ikony bierki
    bool    zbity;      // informacja czy dana bierka została zbita
    int     pozycja[2]; // aktualna pozycja bierki na planszy, pierwsza liczba oznacza pozycje w poziomie druga w pionie
    int     tmp[2];     // pozycja tymczasowa sluzaca do sprawdzenia poprawnosci ruchu
    bool    pierwszy;   // informacja czy dana bierka wykonala pierszy ruch, istotne przy ruchu pionem, krolem i wieza



public:


    Bierka()
    {
        kolor = 'w';
        numer = 1;
        zbity = false;
        pierwszy = false;
    }

    Bierka(char k, int n, int x, int y)
    {
        kolor = k;
        numer = n;
        zbity = false; //domyślnie figury nie są zbite
        pozycja[0] = x;
        pozycja[1] = y;
        tmp[0] = x;
        tmp[1] = y;
        rysuj = n;
        pierwszy = false;
    }
    int virtual rusz(Szachownica* s, int pole[2], bool t = false)  =0;      //metody ruchow figur

    int virtual bij(Szachownica* s, int pole[2], bool t = false)  =0;       // metody bicia figur, wyroznione ze wzgledu na odmieny sposob poruszania piona w trakcie bicia

    char podajkolor(){return kolor;}        // metoda zwracajaca kolor

    int podajnumer(){ return numer;}        // metoda zwracajaca numer

    int czyzbity() {return zbity;}          //metoda zwracajaca informacje czy bierka jest zbita

    int zbij();                             //metoda zmieniajaca wartosc pola zbity na true


    int cofnijzbij();                       //metoda zmieniajaca wartosc pola zbity na false (do cofania ruchow)

    int virtual zmienpozycje(int x[2])        //metoda zmieniajaca pozycje birki na plansszy po wykonanym ruchu
    {
        pierwszy = true;
        pozycja[0]=x[0];
        pozycja[1]=x[1];
        tmp[0]=x[0];
        tmp[1]=x[1];
        return 0;
    }

    int zmientmp(int x[2]);                 //metoda zmieniajaca pola tymczasowe polozenie bierki (sprawdzanie czy ruch jest dozwolony)
    bool czypierwszy(){ return pierwszy; }  //metoda zwracajaca czy bierka wykonala pierwszy ruch
    void ustawPierwszy(bool p) {pierwszy = p;}  //metoda zmieniajaca wartosc pola pierwszy
    int* podajpozycje(){  return pozycja;}      //metoda zwracajaca pozycje bierki
    int* podajtmp(){  return tmp;}              //metoda zwracajaca tymczasowa pozycje bierki
    int virtual promotuj(int p) { return p;}    //metoda domyslnie sluzaca do promocji piona
    int narysuj() {return rysuj;}               //metoda zwracajaca wartosc pola rysuj

    void cofnijtmp()                    // metoda przywracajaca wartosc pozycji tymczasowej do aktualnej
    {
        tmp[0]=pozycja[0];
        tmp[1]=pozycja[1];
    }


};



#endif // BIERKA_H

#ifndef BIERKA_H
#define BIERKA_H

class Bierka
{
protected:
    char    kolor;
    int     numer;
    bool    zbity = false;  //domyślnie figury nie są zbite
    int     pozycja[2];
public:
    Bierka();
    Bierka(char k, int n);
    virtual     int rusz(int x, int y);
    char podajkolor();
    int podajnumer();
    virtual     int zbij();
    virtual     int czyzbity();
};

#endif // BIERKA_H

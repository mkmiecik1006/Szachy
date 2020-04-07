#ifndef PION_H
#define PION_H
#include "bierka.cpp"


class Pion : public Bierka
{
    bool    pierwszy = false;   //czy wykonano pierwszy ruch

public:
    Pion();
    Pion(char k, int n) :Bierka(k, n){};
};

#endif // PION_H

#include "szachownica.h"
#include "pion.h"

Szachownica::Szachownica()
{
    figury[0]= new Pion('b', 1);
    figury[1]= new Pion('b', 2);
    figury[2]= new Pion('b', 3);
    figury[3]=new Pion('b', 4);
    figury[4]=new Pion('b', 5);
    figury[5]=new Pion('b', 6);
    figury[6]=new Pion('b', 7);
    figury[7]=new Pion('b', 8);

    figury[8]= new Pion('c', -1);
    figury[9]= new Pion('c', -2);
    figury[10]= new Pion('c', -3);
    figury[11]=new Pion('c', -4);
    figury[12]=new Pion('c', -5);
    figury[13]=new Pion('c', -6);
    figury[14]=new Pion('c', -7);
    figury[15]=new Pion('c', -8);
}

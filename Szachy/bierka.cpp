#include "bierka.h"

int Bierka:: zbij()
{
    if (zbity == false)
    {
        zbity =true;
        return 0;
    }
    return 1;
}

int Bierka::cofnijzbij()
{
    zbity = false;
    return 0;
}

int Bierka::zmientmp(int x[2])
{
    tmp[0]=x[0];
    tmp[1]=x[1];
    return 0;
}

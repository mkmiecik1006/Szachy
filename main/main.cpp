#include <iostream>
#include <map>
#include <vector>
#include "C:\Users\acer\Documents\GitHub\Szachy\pion.h"
#include "C:\Users\acer\Documents\GitHub\Szachy\bierka.h"
using namespace std;


class A {
private:
    int Dana;
public:
    A(int init) : Dana(init) {};
    int value() const { return Dana; }
    void operator-= (int i)
{
 Dana -=i;
}

};
ostream& operator << (ostream& os, const A& dt)
{
    os <<dt.value();
    return os;
}
int main()
{

        A a(15);
        a -= 10;
        cout << a;

    //cout<<sum2(v, 18);

   /* map <int, Bierka> mapa;

    Pion* b1 = new Pion('w', 1);

    mapa.insert( make_pair<int, Pion>(1, *b1));
    mapa.insert( make_pair<int, Pion>(2, Pion('w', 2)));
    mapa.insert( make_pair<int, Pion>(3, Pion('b', 3)));
    mapa.insert( make_pair<int, Pion>(4, Pion('b', 4)));
    map<int, Bierka> ::iterator it = mapa.begin();
     mapa.insert(b2->podajnumer(), b2);
    mapa.insert(b3->podajnumer(), b3);
    mapa.insert(b4->podajnumer(), b4);*/
    /*Bierka* a;
    Bierka* b;
    a= &(mapa.find(1)->second);
    cout<<a->podajnumer()<<" :: "<<a->podajkolor()<<endl;
    b = &(mapa.find(3)->second);
    cout<<b->podajnumer()<<" :: "<<b->podajkolor()<<endl;

    cout<<mapa.size()<<endl;
    mapa.erase(mapa.find(1));
    cout<<mapa.size()<<endl;
   it = mapa.begin();

    cout<< it->second.podajnumer()<<endl;
    it++;
    cout<< it->second.podajnumer()<<endl;
    it++;
    cout<< it->second.podajnumer()<<endl;
    it++;
    cout<< a->podajnumer()<<endl;
    delete a;
    cout<< a->podajnumer()<<endl;*/


    return 0;
}


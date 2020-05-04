#include <iostream>
#include <cstdlib>

using namespace std;

class Pojazd {
public:
    virtual void zatrzymaj() {
        cout << "zatrzymuje pojazd..?\n";
    }
};

class Samochod : public Pojazd {
public:
    void zatrzymaj() {
        cout << "zatrzymuje samochod, puszczam gaz\n";
    }
};

class Rower : public Pojazd {
public:
    void zatrzymaj() {
        cout << "zatrzymuje rower, przestaje pedalowac\n";
    }
};

class Rolki : public Pojazd {
public:
    void zatrzymaj() {
        cout << "zatrzymuje rolki, przestaje ruszac nogami\n\n";
    }
};

int main()
{
    Pojazd **tablica = new Pojazd*[3];

    tablica[0] = new Samochod();
    tablica[1] = new Rower();
    tablica[2] = new Rolki();

    for (int i = 0; i<3; i++) {
        tablica[i]->zatrzymaj();
    }

    system("pause");
    return 0;
}

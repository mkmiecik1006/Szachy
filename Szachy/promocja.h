#ifndef PROMOCJA_H
#define PROMOCJA_H
#include "bierka.h"

#include <QDialog>

namespace Ui {
class Promocja; //klasa obslugujaca wyswietlanie wybor figury na jaka zostal promowany pion
}

class Promocja : public QDialog
{
    Q_OBJECT
private:
    Bierka* bierka;

public:
    explicit Promocja(Bierka* b, QWidget *parent = 0);
    ~Promocja();
    
private slots:
    void on_bWieza_clicked();

    void on_bSkoczek_clicked();

    void on_bGoniec_clicked();

    void on_bHetman_clicked();

private:
    Ui::Promocja *ui;
};

#endif // PROMOCJA_H

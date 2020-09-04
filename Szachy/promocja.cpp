#include "promocja.h"
#include "ui_promocja.h"

Promocja::Promocja(Bierka* b, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Promocja)
{
    bierka = b;
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
}

Promocja::~Promocja()
{
    delete ui;
}

void Promocja::on_bWieza_clicked()
{
    bierka->promotuj(9);
    this->close();
}

void Promocja::on_bSkoczek_clicked()
{
    bierka->promotuj(11);;
    this->close();
}

void Promocja::on_bGoniec_clicked()
{
    bierka->promotuj(13);
    this->close();
}

void Promocja::on_bHetman_clicked()
{
    bierka->promotuj(15);
    this->close();

}

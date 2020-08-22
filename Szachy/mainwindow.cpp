#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <QMessageBox>
#include <stdexcept>
#include "rozgrywka.h"
#include "bierka.h"
#include "pion.h"
#include "promocja.h"

using namespace std;


QIcon gb, gw, hb, hw, kb, kw, k2b, k2w, krb, krw, pb, pw, wb, ww, puste;
QString tx1, tx2;


Bierka* bierka;
Rozgrywka rozgrywka;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    r= false;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Nowa_clicked()
{
    rozgrywka.nowa();
    puste.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/puste.png"));
    gb.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/gb.png"));
    gw.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/gw.png"));
    hw.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/hw.png"));
    hb.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/hb.png"));
    kb.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/kb.png"));
    kw.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/kw.png"));
    k2b.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/k2b.png"));
    k2w.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/k2w.png"));
    krb.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/krb.png"));
    krw.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/krw.png"));
    pb.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/pb.png"));
    pw.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/pw.png"));
    wb.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/wb.png"));
    ww.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/ww.png"));
    ui->A1->setIcon(ww);
    ui->B1->setIcon(kw);
    ui->C1->setIcon(gw);
    ui->D1->setIcon(hw);
    ui->E1->setIcon(krw);
    ui->F1->setIcon(gw);
    ui->G1->setIcon(k2w);
    ui->H1->setIcon(ww);
    ui->A2->setIcon(pw);
    ui->A2->setIcon(pw);
    ui->B2->setIcon(pw);
    ui->C2->setIcon(pw);
    ui->D2->setIcon(pw);
    ui->E2->setIcon(pw);
    ui->F2->setIcon(pw);
    ui->G2->setIcon(pw);
    ui->H2->setIcon(pw);
    ui->A3->setIcon(puste);
    ui->B3->setIcon(puste);
    ui->C3->setIcon(puste);
    ui->D3->setIcon(puste);
    ui->E3->setIcon(puste);
    ui->F3->setIcon(puste);
    ui->G3->setIcon(puste);
    ui->H3->setIcon(puste);
    ui->A4->setIcon(puste);
    ui->B4->setIcon(puste);
    ui->C4->setIcon(puste);
    ui->D4->setIcon(puste);
    ui->E4->setIcon(puste);
    ui->F4->setIcon(puste);
    ui->G4->setIcon(puste);
    ui->H4->setIcon(puste);
    ui->A5->setIcon(puste);
    ui->B5->setIcon(puste);
    ui->C5->setIcon(puste);
    ui->D5->setIcon(puste);
    ui->E5->setIcon(puste);
    ui->F5->setIcon(puste);
    ui->G5->setIcon(puste);
    ui->H5->setIcon(puste);
    ui->A6->setIcon(puste);
    ui->B6->setIcon(puste);
    ui->C6->setIcon(puste);
    ui->D6->setIcon(puste);
    ui->E6->setIcon(puste);
    ui->F6->setIcon(puste);
    ui->G6->setIcon(puste);
    ui->H6->setIcon(puste);
    ui->A8->setIcon(wb);
    ui->B8->setIcon(kb);
    ui->C8->setIcon(gb);
    ui->D8->setIcon(hb);
    ui->E8->setIcon(krb);
    ui->F8->setIcon(gb);
    ui->G8->setIcon(k2b);
    ui->H8->setIcon(wb);
    ui->A7->setIcon(pb);
    ui->A7->setIcon(pb);
    ui->B7->setIcon(pb);
    ui->C7->setIcon(pb);
    ui->D7->setIcon(pb);
    ui->E7->setIcon(pb);
    ui->F7->setIcon(pb);
    ui->G7->setIcon(pb);
    ui->H7->setIcon(pb);
    ui->Ruch->setEnabled(true);
    ui->lineEdit->setEnabled(true);
    ui->lineEdit_2->setEnabled(true);
    ui->Wyczysc->setEnabled(true);
    ui->Czysc->setEnabled(true);
    ui->Poddana->setEnabled(true);
    ui->Remis->setEnabled(true);
    ui->Reklamacja->setEnabled(false);
    ui->lbKolej->setText("Kolej: BIAŁE");
}

void MainWindow::on_Wyczysc_clicked()
{
    rozgrywka.szachownica.wyczysc();
    puste.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/puste.png"));
    ui->A1->setIcon(puste);
    ui->B1->setIcon(puste);
    ui->C1->setIcon(puste);
    ui->D1->setIcon(puste);
    ui->E1->setIcon(puste);
    ui->F1->setIcon(puste);
    ui->G1->setIcon(puste);
    ui->H1->setIcon(puste);
    ui->A2->setIcon(puste);
    ui->B2->setIcon(puste);
    ui->C2->setIcon(puste);
    ui->D2->setIcon(puste);
    ui->E2->setIcon(puste);
    ui->F2->setIcon(puste);
    ui->G2->setIcon(puste);
    ui->H2->setIcon(puste);
    ui->A3->setIcon(puste);
    ui->B3->setIcon(puste);
    ui->C3->setIcon(puste);
    ui->D3->setIcon(puste);
    ui->E3->setIcon(puste);
    ui->F3->setIcon(puste);
    ui->G3->setIcon(puste);
    ui->H3->setIcon(puste);
    ui->A4->setIcon(puste);
    ui->B4->setIcon(puste);
    ui->C4->setIcon(puste);
    ui->D4->setIcon(puste);
    ui->E4->setIcon(puste);
    ui->F4->setIcon(puste);
    ui->G4->setIcon(puste);
    ui->H4->setIcon(puste);
    ui->A5->setIcon(puste);
    ui->B5->setIcon(puste);
    ui->C5->setIcon(puste);
    ui->D5->setIcon(puste);
    ui->E5->setIcon(puste);
    ui->F5->setIcon(puste);
    ui->G5->setIcon(puste);
    ui->H5->setIcon(puste);
    ui->A6->setIcon(puste);
    ui->B6->setIcon(puste);
    ui->C6->setIcon(puste);
    ui->D6->setIcon(puste);
    ui->E6->setIcon(puste);
    ui->F6->setIcon(puste);
    ui->G6->setIcon(puste);
    ui->H6->setIcon(puste);
    ui->A7->setIcon(puste);
    ui->A7->setIcon(puste);
    ui->B7->setIcon(puste);
    ui->C7->setIcon(puste);
    ui->D7->setIcon(puste);
    ui->E7->setIcon(puste);
    ui->F7->setIcon(puste);
    ui->G7->setIcon(puste);
    ui->H7->setIcon(puste);
    ui->A8->setIcon(puste);
    ui->B8->setIcon(puste);
    ui->C8->setIcon(puste);
    ui->D8->setIcon(puste);
    ui->E8->setIcon(puste);
    ui->F8->setIcon(puste);
    ui->G8->setIcon(puste);
    ui->H8->setIcon(puste);
    ui->Ruch->setEnabled(false);
    ui->lineEdit->setEnabled(false);
    ui->lineEdit->clear();
    ui->lineEdit_2->setEnabled(false);
    ui->lineEdit_2->clear();
    ui->Wyczysc->setEnabled(false);
    ui->Czysc->setEnabled(false);
    ui->Poddana->setEnabled(false);
    ui->Remis->setEnabled(false);
    ui->Reklamacja->setEnabled(false);
    ui->lbKolej->setText("Kolej:");
}

void MainWindow::on_Ruch_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        int pozycja1[2];    //Pozycja bierki przed ruchem
        int pozycja2[2];    //Docelowa pozycja bierki
        int b;

        tx1 = ui->lineEdit->text();
        tx2 = ui->lineEdit_2->text();
        if(!tx1.isEmpty()&& !tx2.isEmpty())
        {
            try
            {
                if(OdczytajPozycje(tx1, pozycja1)==0&& OdczytajPozycje(tx2, pozycja2)==0)
                {
                    bierka = rozgrywka.szachownica.znajdz(pozycja1);
                    b = bierka->narysuj();
                    if(rozgrywka.ruch(bierka, pozycja2)==0)
                    {
                        ZmienIkone(b, pozycja2);
                        ZmienIkone(0, pozycja1);
                        /////////////////////////////////////////////////////////
                        int s = rozgrywka.szach();
                        int m = rozgrywka.mat(); //sprawdzamy czy mat
                        if(m==0&&s==0)
                        {
                            rozgrywka.zmienkolej();
                            koniec(rozgrywka.podajkolej());
                            QMessageBox::about(this,"Koniec gry!", "Szach mat");
                        }
                        else if(m==0&&s!=0)
                        {
                            koniec('r');
                            QMessageBox::about(this,"Koniec gry!", "Remis: PAT");
                        }
                        else if(s==0) QMessageBox::about(this, "Szach", "Król jest szachowany");
                        remis();


                    }
                }


            }
            catch(std::runtime_error &e)
            {
                QMessageBox::about(this, "Błąd", e.what());
            }
            catch(std::string wyjatek)
            {
                if(wyjatek=="roszada1")
                {
                    Bierka* bierka2;
                    if(bierka->podajnumer()>0) bierka2 = rozgrywka.szachownica.figury.find(9)->second;
                    else if(bierka->podajnumer()<0) bierka2 = rozgrywka.szachownica.figury.find(-9)->second;
                    int b2 = bierka2->narysuj();
                    int pozycja3[2] = {0, pozycja1[1]};
                    int pozycja4[2] = {3, pozycja1[1]};
                    ZmienIkone(b, pozycja2);
                    ZmienIkone(0, pozycja1);
                    ZmienIkone(b2, pozycja4);
                    ZmienIkone(0, pozycja3);
                    remis();


                }
                else if(wyjatek=="roszada2")
                {
                    Bierka* bierka2;
                    if(bierka->podajnumer()>0) bierka2 = rozgrywka.szachownica.figury.find(10)->second;
                    else if(bierka->podajnumer()<0) bierka2 = rozgrywka.szachownica.figury.find(-10)->second;
                    int b2 = bierka2->narysuj();
                    int pozycja3[2] = {7, pozycja1[1]};
                    int pozycja4[2] = {5, pozycja1[1]};
                    ZmienIkone(b, pozycja2);
                    ZmienIkone(0, pozycja1);
                    ZmienIkone(b2, pozycja4);
                    ZmienIkone(0, pozycja3);
                    if(r) //jeśli gracz zaproponował remis
                    remis();

                }
                else if(wyjatek == "promocja")
                {
                    Promocja* prom = new Promocja(bierka, this);
                    prom->setModal(true);
                    prom->exec();
                    b = bierka->narysuj();
                    ZmienIkone(0, pozycja1);
                    ZmienIkone(b, pozycja2);
                    rozgrywka.poprzedni.Promocja();
                    int s = rozgrywka.szach();
                    int m = rozgrywka.mat(); //sprawdzamy czy mat
                    if(m==0&&s==0) QMessageBox::about(this,"Koniec gry!", "Szach mat");
                    else if(m==0&&s!=0) QMessageBox::about(this,"Koniec gry!", "Remis: PAT");
                    else if(s==0) QMessageBox::about(this, "Szach", "król jest szachowany");
                    delete prom;
                    if(r) //jeśli gracz zaproponował remis
                    remis();


                }
            }

        }
        else
        {
            QMessageBox::about(this, "Błąd", "Nie wpisano pola!");
        }
        if(rozgrywka.podajkolej()=='w') ui->lbKolej->setText("Kolej: BIAŁE");
        else if(rozgrywka.podajkolej()=='b') ui->lbKolej->setText("Kolej: CZARNE");

    }
    else QMessageBox::about(this, "Błąd", "Rozpocznij rozgrywkę!");
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    if(rozgrywka.poprzedni.PodajAktywny()) ui->btnCofnij->setEnabled(true);

}

int MainWindow::OdczytajPozycje(QString txt, int pozycja[2])
{
    if(txt.isEmpty()) throw std::runtime_error("Nie wpisano pola");
    else if(txt.length()!=2) throw std::runtime_error("Podano błędną wartość pola!");
    else if(txt[0] == 'A'|| txt[0] =='a') pozycja[0]=0;
    else if(txt[0] == 'B'|| txt[0] =='b') pozycja[0]=1;
    else if(txt[0] == 'C'|| txt[0] =='c') pozycja[0]=2;
    else if(txt[0] == 'D'|| txt[0] =='d') pozycja[0]=3;
    else if(txt[0] == 'E'|| txt[0] =='e') pozycja[0]=4;
    else if(txt[0] == 'F'|| txt[0] =='f') pozycja[0]=5;
    else if(txt[0] == 'G'|| txt[0] =='g') pozycja[0]=6;
    else if(txt[0] == 'H'|| txt[0] =='h') pozycja[0]=7;
    else throw std::runtime_error("Podano błędną wartość pola!");


    if(txt[1]=='1') pozycja[1] = 0;
    else if(txt[1]=='2') pozycja[1] = 1;
    else if(txt[1]=='3') pozycja[1] = 2;
    else if(txt[1]=='4') pozycja[1] = 3;
    else if(txt[1]=='5') pozycja[1] = 4;
    else if(txt[1]=='6') pozycja[1] = 5;
    else if(txt[1]=='7') pozycja[1] = 6;
    else if(txt[1]=='8') pozycja[1] = 7;
    else throw std::runtime_error("Podano błędną wartość pola!");
    return 0;

}

int MainWindow::ZmienIkone(int bierka, int* pozycja)
{
    QIcon ikona;
    if(bierka==0)    ikona.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/puste.png"));
    else if(bierka >= 1 && bierka <=8) ikona.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/pw.png"));
    else if(bierka >= -8 && bierka <=-1) ikona.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/pb.png"));
    else if(bierka == 9 || bierka == 10) ikona.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/ww.png"));
    else if(bierka == -9 || bierka == -10) ikona.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/wb.png"));
    else if(bierka == 11) ikona.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/kw.png"));
    else if(bierka == 12) ikona.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/k2w.png"));
    else if(bierka == -11) ikona.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/kb.png"));
    else if(bierka == -12) ikona.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/k2b.png"));
    else if(bierka == 13|| bierka == 14 ) ikona.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/gw.png"));
    else if(bierka == -13|| bierka == -14 ) ikona.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/gb.png"));
    else if(bierka == 15) ikona.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/hw.png"));
    else if(bierka == -15) ikona.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/hb.png"));
    else if(bierka == 16) ikona.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/krw.png"));
    else if(bierka == -16) ikona.addFile(QString::fromUtf8("C:/Users/acer/Documents/SzachyGUI/krb.png"));
    else throw std::runtime_error("Błędny numer ikony bierki");

    if(pozycja[0]==0 && pozycja[1]==0) ui->A1->setIcon(ikona);
    else if(pozycja[0]==0 && pozycja[1]==1) ui->A2->setIcon(ikona);
    else if(pozycja[0]==0 && pozycja[1]==2) ui->A3->setIcon(ikona);
    else if(pozycja[0]==0 && pozycja[1]==3) ui->A4->setIcon(ikona);
    else if(pozycja[0]==0 && pozycja[1]==4) ui->A5->setIcon(ikona);
    else if(pozycja[0]==0 && pozycja[1]==5) ui->A6->setIcon(ikona);
    else if(pozycja[0]==0 && pozycja[1]==6) ui->A7->setIcon(ikona);
    else if(pozycja[0]==0 && pozycja[1]==7) ui->A8->setIcon(ikona);

    else if(pozycja[0]==1 && pozycja[1]==0) ui->B1->setIcon(ikona);
    else if(pozycja[0]==1 && pozycja[1]==1) ui->B2->setIcon(ikona);
    else if(pozycja[0]==1 && pozycja[1]==2) ui->B3->setIcon(ikona);
    else if(pozycja[0]==1 && pozycja[1]==3) ui->B4->setIcon(ikona);
    else if(pozycja[0]==1 && pozycja[1]==4) ui->B5->setIcon(ikona);
    else if(pozycja[0]==1 && pozycja[1]==5) ui->B6->setIcon(ikona);
    else if(pozycja[0]==1 && pozycja[1]==6) ui->B7->setIcon(ikona);
    else if(pozycja[0]==1 && pozycja[1]==7) ui->B8->setIcon(ikona);

    else if(pozycja[0]==2 && pozycja[1]==0) ui->C1->setIcon(ikona);
    else if(pozycja[0]==2 && pozycja[1]==1) ui->C2->setIcon(ikona);
    else if(pozycja[0]==2 && pozycja[1]==2) ui->C3->setIcon(ikona);
    else if(pozycja[0]==2 && pozycja[1]==3) ui->C4->setIcon(ikona);
    else if(pozycja[0]==2 && pozycja[1]==4) ui->C5->setIcon(ikona);
    else if(pozycja[0]==2 && pozycja[1]==5) ui->C6->setIcon(ikona);
    else if(pozycja[0]==2 && pozycja[1]==6) ui->C7->setIcon(ikona);
    else if(pozycja[0]==2 && pozycja[1]==7) ui->C8->setIcon(ikona);

    else if(pozycja[0]==3 && pozycja[1]==0) ui->D1->setIcon(ikona);
    else if(pozycja[0]==3 && pozycja[1]==1) ui->D2->setIcon(ikona);
    else if(pozycja[0]==3 && pozycja[1]==2) ui->D3->setIcon(ikona);
    else if(pozycja[0]==3 && pozycja[1]==3) ui->D4->setIcon(ikona);
    else if(pozycja[0]==3 && pozycja[1]==4) ui->D5->setIcon(ikona);
    else if(pozycja[0]==3 && pozycja[1]==5) ui->D6->setIcon(ikona);
    else if(pozycja[0]==3 && pozycja[1]==6) ui->D7->setIcon(ikona);
    else if(pozycja[0]==3 && pozycja[1]==7) ui->D8->setIcon(ikona);

    else if(pozycja[0]==4 && pozycja[1]==0) ui->E1->setIcon(ikona);
    else if(pozycja[0]==4 && pozycja[1]==1) ui->E2->setIcon(ikona);
    else if(pozycja[0]==4 && pozycja[1]==2) ui->E3->setIcon(ikona);
    else if(pozycja[0]==4 && pozycja[1]==3) ui->E4->setIcon(ikona);
    else if(pozycja[0]==4 && pozycja[1]==4) ui->E5->setIcon(ikona);
    else if(pozycja[0]==4 && pozycja[1]==5) ui->E6->setIcon(ikona);
    else if(pozycja[0]==4 && pozycja[1]==6) ui->E7->setIcon(ikona);
    else if(pozycja[0]==4 && pozycja[1]==7) ui->E8->setIcon(ikona);

    else if(pozycja[0]==5 && pozycja[1]==0) ui->F1->setIcon(ikona);
    else if(pozycja[0]==5 && pozycja[1]==1) ui->F2->setIcon(ikona);
    else if(pozycja[0]==5 && pozycja[1]==2) ui->F3->setIcon(ikona);
    else if(pozycja[0]==5 && pozycja[1]==3) ui->F4->setIcon(ikona);
    else if(pozycja[0]==5 && pozycja[1]==4) ui->F5->setIcon(ikona);
    else if(pozycja[0]==5 && pozycja[1]==5) ui->F6->setIcon(ikona);
    else if(pozycja[0]==5 && pozycja[1]==6) ui->F7->setIcon(ikona);
    else if(pozycja[0]==5 && pozycja[1]==7) ui->F8->setIcon(ikona);

    else if(pozycja[0]==6 && pozycja[1]==0) ui->G1->setIcon(ikona);
    else if(pozycja[0]==6 && pozycja[1]==1) ui->G2->setIcon(ikona);
    else if(pozycja[0]==6 && pozycja[1]==2) ui->G3->setIcon(ikona);
    else if(pozycja[0]==6 && pozycja[1]==3) ui->G4->setIcon(ikona);
    else if(pozycja[0]==6 && pozycja[1]==4) ui->G5->setIcon(ikona);
    else if(pozycja[0]==6 && pozycja[1]==5) ui->G6->setIcon(ikona);
    else if(pozycja[0]==6 && pozycja[1]==6) ui->G7->setIcon(ikona);
    else if(pozycja[0]==6 && pozycja[1]==7) ui->G8->setIcon(ikona);

    else if(pozycja[0]==7 && pozycja[1]==0) ui->H1->setIcon(ikona);
    else if(pozycja[0]==7 && pozycja[1]==1) ui->H2->setIcon(ikona);
    else if(pozycja[0]==7 && pozycja[1]==2) ui->H3->setIcon(ikona);
    else if(pozycja[0]==7 && pozycja[1]==3) ui->H4->setIcon(ikona);
    else if(pozycja[0]==7 && pozycja[1]==4) ui->H5->setIcon(ikona);
    else if(pozycja[0]==7 && pozycja[1]==5) ui->H6->setIcon(ikona);
    else if(pozycja[0]==7 && pozycja[1]==6) ui->H7->setIcon(ikona);
    else if(pozycja[0]==7 && pozycja[1]==7) ui->H8->setIcon(ikona);
    else throw std::runtime_error("Błędna pozycja/ Ikona");
    return 0;
}


void MainWindow::on_Czysc_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void MainWindow::on_A1_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("A1");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("A1");
    }
}

void MainWindow::on_B1_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("B1");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("B1");
    }

}

void MainWindow::on_C1_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("C1");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("C1");
    }
}

void MainWindow::on_D1_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("D1");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("D1");
    }
}

void MainWindow::on_E1_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("E1");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("E1");
    }
}

void MainWindow::on_F1_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("F1");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("F1");
    }
}

void MainWindow::on_G1_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("G1");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("G1");
    }
}

void MainWindow::on_H1_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("H1");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("H1");
    }
}

void MainWindow::on_A2_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("A2");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("A2");
    }
}

void MainWindow::on_B2_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("B2");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("B2");
    }
}

void MainWindow::on_C2_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("C2");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("C2");
    }
}

void MainWindow::on_D2_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("D2");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("D2");
    }
}

void MainWindow::on_E2_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("E2");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("E2");
    }
}

void MainWindow::on_F2_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("F2");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("F2");
    }
}

void MainWindow::on_G2_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("G2");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("G2");
    }
}

void MainWindow::on_H2_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("H2");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("H2");
    }
}

void MainWindow::on_A3_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("A3");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("A3");
    }
}

void MainWindow::on_B3_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("B3");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("B3");
    }
}

void MainWindow::on_C3_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("C3");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("C3");
    }
}

void MainWindow::on_D3_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("D3");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("D3");
    }
}

void MainWindow::on_E3_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("E3");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("E3");
    }
}

void MainWindow::on_F3_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("F3");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("F3");
    }
}

void MainWindow::on_G3_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("G3");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("G3");
    }
}

void MainWindow::on_H3_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("H3");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("H3");
    }
}

void MainWindow::on_A4_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("A4");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("A4");
    }
}

void MainWindow::on_B4_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("B4");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("B4");
    }
}

void MainWindow::on_C4_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("C4");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("C4");
    }
}

void MainWindow::on_D4_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("D4");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("D4");
    }
}

void MainWindow::on_E4_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("E4");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("E4");
    }
}

void MainWindow::on_F4_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("F4");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("F4");
    }
}

void MainWindow::on_G4_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("G4");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("G4");
    }
}

void MainWindow::on_H4_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("H4");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("H4");
    }
}

void MainWindow::on_A5_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("A5");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("A5");
    }
}

void MainWindow::on_B5_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("B5");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("B5");
    }
}

void MainWindow::on_C5_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("C5");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("C5");
    }
}

void MainWindow::on_D5_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("D5");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("D5");
    }
}

void MainWindow::on_E5_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("E5");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("E5");
    }
}

void MainWindow::on_F5_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("F5");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("F5");
    }
}

void MainWindow::on_G5_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("G5");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("G5");
    }
}

void MainWindow::on_H5_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("H5");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("H5");
    }
}

void MainWindow::on_A6_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("A6");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("A6");
    }
}

void MainWindow::on_B6_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("B6");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("B6");
    }
}

void MainWindow::on_C6_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("C6");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("C6");
    }
}

void MainWindow::on_D6_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("D6");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("D6");
    }
}

void MainWindow::on_E6_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("E6");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("E6");
    }
}

void MainWindow::on_F6_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("F6");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("F6");
    }
}

void MainWindow::on_G6_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("G6");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("G6");
    }
}

void MainWindow::on_H6_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("H6");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("H6");
    }
}

void MainWindow::on_A7_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("A7");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("A7");
    }
}

void MainWindow::on_B7_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("B7");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("B7");
    }
}

void MainWindow::on_C7_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("C7");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("C7");
    }
}

void MainWindow::on_D7_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("D7");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("D7");
    }
}

void MainWindow::on_E7_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("E7");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("E7");
    }
}

void MainWindow::on_F7_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("F7");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("F7");
    }
}

void MainWindow::on_G7_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("G7");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("G7");
    }
}

void MainWindow::on_H7_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("H7");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("H7");
    }
}

void MainWindow::on_A8_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("A8");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("A8");
    }
}
void MainWindow::on_B8_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("B8");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("B8");
    }
}

void MainWindow::on_C8_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("C8");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("C8");
    }
}

void MainWindow::on_D8_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("D8");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("D8");
    }
}

void MainWindow::on_E8_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("E8");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("E8");
    }
}

void MainWindow::on_F8_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("F8");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("F8");
    }
}

void MainWindow::on_G8_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("G8");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("G8");
    }
}

void MainWindow::on_H8_clicked()
{
    if(rozgrywka.czyaktywna())
    {
        if(ui->lineEdit->text().isEmpty()) ui->lineEdit->setText("H8");
        else if(ui->lineEdit_2->text().isEmpty()) ui->lineEdit_2->setText("H8");
    }
}

void MainWindow::on_btnCofnij_clicked()
{
    int pozycja1[2];
    int pozycja3[2];
    bool bicie = rozgrywka.poprzedni.PodajBicie();
    Bierka* bierka = rozgrywka.poprzedni.PodajPoprzednia();
    int* pozycja2 = rozgrywka.poprzedni.PodajPozycja();
    pozycja1[0] = bierka->podajpozycje()[0];
    pozycja1[1] = bierka->podajpozycje()[1];
    Bierka* bierka2;
    int* pozycja4;
    if(bicie)
    {
        bierka2 = rozgrywka.poprzedni.PodajBita();
        pozycja3[0] = bierka2->podajpozycje()[0];
        pozycja3[1] = bierka2->podajpozycje()[1];
        pozycja4 = rozgrywka.poprzedni.PodajPozycjaBita();
    }
    rozgrywka.cofnij();

    int b1 = bierka->narysuj();
    ZmienIkone(0, pozycja1);
    ZmienIkone(b1, pozycja2);

    if(bicie)
    {
        int b2 = bierka2->narysuj();
        if(pozycja3[0]>=0&&pozycja3[1]>=0)ZmienIkone(0, pozycja3);
        ZmienIkone(b2, pozycja4);

    }

    if(!rozgrywka.poprzedni.PodajAktywny()) ui->btnCofnij->setEnabled(false);
    if(rozgrywka.podajkolej()=='w') ui->lbKolej->setText("Kolej: BIAŁE");
    else if(rozgrywka.podajkolej()=='b') ui->lbKolej->setText("Kolej: CZARNE");
}



void MainWindow::on_Poddana_clicked()
{
    QMessageBox msg;
    msg.setText("Czy na pewno chcesz się poddać?");
    msg.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    int ret = msg.exec();


    switch (ret) {
    case QMessageBox::Yes:
        if(rozgrywka.podajkolej()=='w')
        {
            koniec('b');
            QMessageBox::about(this,"Koniec gry!", "Koniec rozgrywki wygrały czarne!");
            ui->Ruch->setEnabled(false);
            ui->lineEdit->setEnabled(false);
            ui->lineEdit->clear();
            ui->lineEdit_2->setEnabled(false);
            ui->lineEdit_2->clear();
            ui->btnCofnij->setEnabled(false);
            ui->Czysc->setEnabled(false);
            ui->Poddana->setEnabled(false);
            ui->Remis->setEnabled(false);
            ui->lbKolej->setText("Kolej:");
        }
        else
        {
            koniec('w');
            QMessageBox::about(this,"Koniec gry!", "Koniec rozgrywki wygrały białe!");
            ui->Ruch->setEnabled(false);
            ui->lineEdit->setEnabled(false);
            ui->lineEdit->clear();
            ui->lineEdit_2->setEnabled(false);
            ui->lineEdit_2->clear();
            ui->btnCofnij->setEnabled(false);
            ui->Czysc->setEnabled(false);
            ui->Poddana->setEnabled(false);
            ui->Remis->setEnabled(false);
            ui->lbKolej->setText("Kolej:");
        }
        break;
    case QMessageBox::No:

        break;
    default:
        break;
    }
}

void MainWindow::koniec(char k)
{
    if(rozgrywka.koniec_gry(k)==0)
    {
        //zapisz
        ui->Ruch->setEnabled(false);
        ui->lineEdit->setEnabled(false);
        ui->lineEdit->clear();
        ui->lineEdit_2->setEnabled(false);
        ui->lineEdit_2->clear();
        ui->btnCofnij->setEnabled(false);
        ui->Czysc->setEnabled(false);
        ui->Poddana->setEnabled(false);
        ui->Remis->setEnabled(false);
        ui->lbKolej->setText("Kolej:");
        ui->Reklamacja->setEnabled(false);
    }
}

void MainWindow::on_Remis_clicked()
{
    r= true;
    ui->Remis->setEnabled(false);
}

void MainWindow::remis()
{
    if(r)
    {
        QMessageBox msg;
            msg.setText("Czy przyjmujesz remis?");
            msg.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
            int ret = msg.exec();
            switch (ret)
            {
            case QMessageBox::Yes:
                    koniec('r');
                    r = false;
                    QMessageBox::about(this,"Koniec gry!", "Remis!");

                break;
            case QMessageBox::No:
                r= false;
                ui->Remis->setEnabled(true);
                break;
            default:
                break;
            }
    }
    int powt = rozgrywka.powtorzenia();
    if(rozgrywka.podajlicznik()>=50||powt>=3)
    {
        ui->Reklamacja->setEnabled(true);
    }
    else ui->Reklamacja->setEnabled(false);
}

void MainWindow::on_Reklamacja_clicked()
{
    QMessageBox msg;
        msg.setText("Czy na pewno reklamujesz remis?");
        msg.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
        int ret = msg.exec();
        switch (ret)
        {
        case QMessageBox::Yes:
                koniec('r');
                r = false;

                QMessageBox::about(this,"Koniec gry!", "Remis!");

            break;
        case QMessageBox::No:
            r= false;
            ui->Remis->setEnabled(true);
            break;
        default:
            break;
        }
}

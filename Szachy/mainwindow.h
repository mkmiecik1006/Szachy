#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    bool r; //flaga remisu
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int ZmienIkone(int bierka, int pozycja[2]);       //metoda zmieniajaca pozycje bierki na wyswietlanej planszy
    int OdczytajPozycje(QString txt, int pozycja[2]); //metoda konwerujaca podana nazwe pola np 'A1' na tablice w tym przypadku {0, 0}
    void koniec(char k);        //metoda czyszczaca plansze po zakonczonej grze
    void remis();               //metoda obslugujaca propozyjcje remisu graczy
private slots:

    void on_Nowa_clicked();

    void on_Wyczysc_clicked();

    void on_Ruch_clicked();

    void on_btnCofnij_clicked();

    void on_Czysc_clicked();

    void on_Poddana_clicked();

    void on_Remis_clicked();

    void on_Reklamacja_clicked();



    void on_A1_clicked();

    void on_A8_clicked();

    void on_B1_clicked();

    void on_C1_clicked();

    void on_D1_clicked();

    void on_E1_clicked();

    void on_F1_clicked();

    void on_G1_clicked();

    void on_H1_clicked();

    void on_A2_clicked();

    void on_B2_clicked();

    void on_C2_clicked();

    void on_D2_clicked();

    void on_E2_clicked();

    void on_F2_clicked();

    void on_G2_clicked();

    void on_H2_clicked();

    void on_A3_clicked();

    void on_B3_clicked();

    void on_C3_clicked();

    void on_D3_clicked();

    void on_E3_clicked();

    void on_F3_clicked();

    void on_G3_clicked();

    void on_H3_clicked();

    void on_A4_clicked();

    void on_B4_clicked();

    void on_C4_clicked();

    void on_D4_clicked();

    void on_E4_clicked();

    void on_F4_clicked();

    void on_G4_clicked();

    void on_H4_clicked();

    void on_A5_clicked();

    void on_B5_clicked();

    void on_C5_clicked();

    void on_D5_clicked();

    void on_E5_clicked();

    void on_F5_clicked();

    void on_G5_clicked();

    void on_H5_clicked();

    void on_A6_clicked();

    void on_B6_clicked();

    void on_C6_clicked();

    void on_D6_clicked();

    void on_E6_clicked();

    void on_F6_clicked();

    void on_G6_clicked();

    void on_H6_clicked();

    void on_A7_clicked();

    void on_B7_clicked();

    void on_C7_clicked();

    void on_D7_clicked();

    void on_E7_clicked();

    void on_F7_clicked();

    void on_G7_clicked();

    void on_H7_clicked();

    void on_B8_clicked();

    void on_C8_clicked();

    void on_D8_clicked();

    void on_E8_clicked();

    void on_F8_clicked();

    void on_G8_clicked();

    void on_H8_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
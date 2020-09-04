/********************************************************************************
** Form generated from reading UI file 'promocja.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROMOCJA_H
#define UI_PROMOCJA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Promocja
{
public:
    QPushButton *bWieza;
    QPushButton *bSkoczek;
    QPushButton *bGoniec;
    QPushButton *bHetman;
    QLabel *label;

    void setupUi(QDialog *Promocja)
    {
        if (Promocja->objectName().isEmpty())
            Promocja->setObjectName(QStringLiteral("Promocja"));
        Promocja->resize(400, 300);
        bWieza = new QPushButton(Promocja);
        bWieza->setObjectName(QStringLiteral("bWieza"));
        bWieza->setGeometry(QRect(60, 90, 101, 71));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/Pliki/ww.png"), QSize(), QIcon::Normal, QIcon::Off);
        bWieza->setIcon(icon);
        bWieza->setIconSize(QSize(60, 60));
        bSkoczek = new QPushButton(Promocja);
        bSkoczek->setObjectName(QStringLiteral("bSkoczek"));
        bSkoczek->setGeometry(QRect(220, 90, 111, 71));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/Pliki/kw.png"), QSize(), QIcon::Normal, QIcon::Off);
        bSkoczek->setIcon(icon1);
        bSkoczek->setIconSize(QSize(60, 60));
        bGoniec = new QPushButton(Promocja);
        bGoniec->setObjectName(QStringLiteral("bGoniec"));
        bGoniec->setGeometry(QRect(60, 180, 101, 71));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/Pliki/gw.png"), QSize(), QIcon::Normal, QIcon::Off);
        bGoniec->setIcon(icon2);
        bGoniec->setIconSize(QSize(60, 60));
        bHetman = new QPushButton(Promocja);
        bHetman->setObjectName(QStringLiteral("bHetman"));
        bHetman->setGeometry(QRect(220, 180, 111, 71));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/Pliki/hw.png"), QSize(), QIcon::Normal, QIcon::Off);
        bHetman->setIcon(icon3);
        bHetman->setIconSize(QSize(60, 60));
        label = new QLabel(Promocja);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 40, 91, 16));

        retranslateUi(Promocja);

        QMetaObject::connectSlotsByName(Promocja);
    } // setupUi

    void retranslateUi(QDialog *Promocja)
    {
        Promocja->setWindowTitle(QApplication::translate("Promocja", "Dialog", 0));
        bWieza->setText(QApplication::translate("Promocja", "Wie\305\274a", 0));
        bSkoczek->setText(QApplication::translate("Promocja", "Skoczek", 0));
        bGoniec->setText(QApplication::translate("Promocja", "Goniec", 0));
        bHetman->setText(QApplication::translate("Promocja", "Hetman", 0));
        label->setText(QApplication::translate("Promocja", "Promocja Pion na:", 0));
    } // retranslateUi

};

namespace Ui {
    class Promocja: public Ui_Promocja {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROMOCJA_H

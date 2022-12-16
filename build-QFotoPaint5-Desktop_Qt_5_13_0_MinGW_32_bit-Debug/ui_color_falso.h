/********************************************************************************
** Form generated from reading UI file 'color_falso.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLOR_FALSO_H
#define UI_COLOR_FALSO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Color_falso
{
public:
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;

    void setupUi(QDialog *Color_falso)
    {
        if (Color_falso->objectName().isEmpty())
            Color_falso->setObjectName(QString::fromUtf8("Color_falso"));
        Color_falso->resize(400, 300);
        radioButton = new QRadioButton(Color_falso);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(70, 30, 95, 20));
        radioButton_2 = new QRadioButton(Color_falso);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(70, 70, 95, 20));
        radioButton_3 = new QRadioButton(Color_falso);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(70, 110, 95, 20));
        radioButton_4 = new QRadioButton(Color_falso);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(70, 150, 95, 20));

        retranslateUi(Color_falso);

        QMetaObject::connectSlotsByName(Color_falso);
    } // setupUi

    void retranslateUi(QDialog *Color_falso)
    {
        Color_falso->setWindowTitle(QCoreApplication::translate("Color_falso", "Dialog", nullptr));
        radioButton->setText(QCoreApplication::translate("Color_falso", "JET", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Color_falso", "WINTER", nullptr));
        radioButton_3->setText(QCoreApplication::translate("Color_falso", "SPRING", nullptr));
        radioButton_4->setText(QCoreApplication::translate("Color_falso", "HSV", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Color_falso: public Ui_Color_falso {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLOR_FALSO_H

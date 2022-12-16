/********************************************************************************
** Form generated from reading UI file 'modelo_color.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELO_COLOR_H
#define UI_MODELO_COLOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Modelo_color
{
public:
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;

    void setupUi(QDialog *Modelo_color)
    {
        if (Modelo_color->objectName().isEmpty())
            Modelo_color->setObjectName(QString::fromUtf8("Modelo_color"));
        Modelo_color->resize(400, 300);
        radioButton = new QRadioButton(Modelo_color);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(100, 40, 95, 20));
        radioButton_2 = new QRadioButton(Modelo_color);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(100, 70, 95, 20));
        radioButton_3 = new QRadioButton(Modelo_color);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(100, 100, 95, 20));
        radioButton_4 = new QRadioButton(Modelo_color);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(100, 130, 95, 20));
        radioButton_5 = new QRadioButton(Modelo_color);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));
        radioButton_5->setGeometry(QRect(100, 160, 95, 20));

        retranslateUi(Modelo_color);

        QMetaObject::connectSlotsByName(Modelo_color);
    } // setupUi

    void retranslateUi(QDialog *Modelo_color)
    {
        Modelo_color->setWindowTitle(QCoreApplication::translate("Modelo_color", "Dialog", nullptr));
        radioButton->setText(QCoreApplication::translate("Modelo_color", "RGB", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Modelo_color", "HLS", nullptr));
        radioButton_3->setText(QCoreApplication::translate("Modelo_color", "HSV", nullptr));
        radioButton_4->setText(QCoreApplication::translate("Modelo_color", "XYZ", nullptr));
        radioButton_5->setText(QCoreApplication::translate("Modelo_color", "YUV", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Modelo_color: public Ui_Modelo_color {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELO_COLOR_H

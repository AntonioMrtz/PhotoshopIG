/********************************************************************************
** Form generated from reading UI file 'bajorrelieve.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BAJORRELIEVE_H
#define UI_BAJORRELIEVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_Bajorrelieve
{
public:
    QDialogButtonBox *buttonBox;
    QSlider *horizontalSlider;
    QLabel *label;
    QLabel *label_2;
    QDial *dial;
    QLabel *label_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;

    void setupUi(QDialog *Bajorrelieve)
    {
        if (Bajorrelieve->objectName().isEmpty())
            Bajorrelieve->setObjectName(QString::fromUtf8("Bajorrelieve"));
        Bajorrelieve->resize(553, 300);
        buttonBox = new QDialogButtonBox(Bajorrelieve);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(310, 230, 201, 31));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalSlider = new QSlider(Bajorrelieve);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 30, 271, 21));
        horizontalSlider->setMinimum(0);
        horizontalSlider->setMaximum(400);
        horizontalSlider->setPageStep(16);
        horizontalSlider->setValue(100);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(32);
        label = new QLabel(Bajorrelieve);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 271, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Bajorrelieve);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 271, 16));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);
        dial = new QDial(Bajorrelieve);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(80, 110, 141, 141));
        dial->setMaximum(360);
        dial->setWrapping(true);
        dial->setNotchTarget(3.000000000000000);
        dial->setNotchesVisible(true);
        label_3 = new QLabel(Bajorrelieve);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(320, 10, 201, 20));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignCenter);
        radioButton = new QRadioButton(Bajorrelieve);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(340, 50, 95, 20));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(Bajorrelieve);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(340, 80, 95, 20));
        radioButton_3 = new QRadioButton(Bajorrelieve);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(340, 140, 95, 20));
        radioButton_4 = new QRadioButton(Bajorrelieve);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(340, 110, 95, 20));

        retranslateUi(Bajorrelieve);
        QObject::connect(buttonBox, SIGNAL(accepted()), Bajorrelieve, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Bajorrelieve, SLOT(reject()));

        QMetaObject::connectSlotsByName(Bajorrelieve);
    } // setupUi

    void retranslateUi(QDialog *Bajorrelieve)
    {
        Bajorrelieve->setWindowTitle(QCoreApplication::translate("Bajorrelieve", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Bajorrelieve", "Grado del efecto", nullptr));
        label_2->setText(QCoreApplication::translate("Bajorrelieve", "\303\201ngulo del efecto", nullptr));
        label_3->setText(QCoreApplication::translate("Bajorrelieve", "Textura de fondo", nullptr));
        radioButton->setText(QCoreApplication::translate("Bajorrelieve", "Arena", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Bajorrelieve", "Cielo", nullptr));
        radioButton_3->setText(QCoreApplication::translate("Bajorrelieve", "Madera", nullptr));
        radioButton_4->setText(QCoreApplication::translate("Bajorrelieve", "Gris", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Bajorrelieve: public Ui_Bajorrelieve {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BAJORRELIEVE_H

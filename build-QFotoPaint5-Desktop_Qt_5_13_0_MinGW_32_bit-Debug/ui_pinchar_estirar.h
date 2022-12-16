/********************************************************************************
** Form generated from reading UI file 'pinchar_estirar.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PINCHAR_ESTIRAR_H
#define UI_PINCHAR_ESTIRAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_pinchar_estirar
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QSpinBox *spinBox_2;

    void setupUi(QDialog *pinchar_estirar)
    {
        if (pinchar_estirar->objectName().isEmpty())
            pinchar_estirar->setObjectName(QString::fromUtf8("pinchar_estirar"));
        pinchar_estirar->resize(400, 190);
        buttonBox = new QDialogButtonBox(pinchar_estirar);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(90, 140, 201, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(pinchar_estirar);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 271, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(pinchar_estirar);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 70, 271, 16));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);
        spinBox = new QSpinBox(pinchar_estirar);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(310, 20, 61, 22));
        spinBox->setMinimum(1);
        spinBox->setMaximum(1000);
        spinBox->setValue(200);
        horizontalSlider = new QSlider(pinchar_estirar);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(30, 40, 271, 21));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(1000);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setPageStep(20);
        horizontalSlider->setValue(30);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(32);
        horizontalSlider_2 = new QSlider(pinchar_estirar);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(30, 90, 271, 21));
        horizontalSlider_2->setMinimum(-60);
        horizontalSlider_2->setMaximum(60);
        horizontalSlider_2->setValue(30);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_2->setTickInterval(10);
        spinBox_2 = new QSpinBox(pinchar_estirar);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(310, 70, 61, 22));
        spinBox_2->setMinimum(-60);
        spinBox_2->setMaximum(60);
        spinBox_2->setValue(30);

        retranslateUi(pinchar_estirar);
        QObject::connect(buttonBox, SIGNAL(accepted()), pinchar_estirar, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), pinchar_estirar, SLOT(reject()));

        QMetaObject::connectSlotsByName(pinchar_estirar);
    } // setupUi

    void retranslateUi(QDialog *pinchar_estirar)
    {
        pinchar_estirar->setWindowTitle(QCoreApplication::translate("pinchar_estirar", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("pinchar_estirar", "Radio de la deformacion", nullptr));
        label_2->setText(QCoreApplication::translate("pinchar_estirar", "Grado de la deformacion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pinchar_estirar: public Ui_pinchar_estirar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PINCHAR_ESTIRAR_H

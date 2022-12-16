/********************************************************************************
** Form generated from reading UI file 'movimiento.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVIMIENTO_H
#define UI_MOVIMIENTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_Movimiento
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider;

    void setupUi(QDialog *Movimiento)
    {
        if (Movimiento->objectName().isEmpty())
            Movimiento->setObjectName(QString::fromUtf8("Movimiento"));
        Movimiento->resize(384, 133);
        buttonBox = new QDialogButtonBox(Movimiento);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 71));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Movimiento);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 271, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Movimiento);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 271, 16));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);
        horizontalSlider_2 = new QSlider(Movimiento);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(10, 90, 271, 21));
        horizontalSlider_2->setMinimum(1);
        horizontalSlider_2->setMaximum(100);
        horizontalSlider_2->setValue(100);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_2->setTickInterval(100);
        horizontalSlider = new QSlider(Movimiento);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 40, 271, 21));
        horizontalSlider->setMinimum(0);
        horizontalSlider->setMaximum(256);
        horizontalSlider->setPageStep(16);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(32);

        retranslateUi(Movimiento);
        QObject::connect(buttonBox, SIGNAL(accepted()), Movimiento, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Movimiento, SLOT(reject()));

        QMetaObject::connectSlotsByName(Movimiento);
    } // setupUi

    void retranslateUi(QDialog *Movimiento)
    {
        Movimiento->setWindowTitle(QCoreApplication::translate("Movimiento", "Movimiento", nullptr));
        label->setText(QCoreApplication::translate("Movimiento", "Frame inicial", nullptr));
        label_2->setText(QCoreApplication::translate("Movimiento", "Frame final", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Movimiento: public Ui_Movimiento {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVIMIENTO_H

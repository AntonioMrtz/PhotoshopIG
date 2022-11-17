/********************************************************************************
** Form generated from reading UI file 'matsatlum.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATSATLUM_H
#define UI_MATSATLUM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Matsatlum
{
public:
    QDialogButtonBox *buttonBox;
    QSpinBox *spinBox_2;
    QLabel *label_2;
    QSlider *horizontalSlider;
    QSpinBox *spinBox;
    QSlider *horizontalSlider_2;
    QLabel *label;
    QLabel *label_3;
    QDial *dial;

    void setupUi(QDialog *Matsatlum)
    {
        if (Matsatlum->objectName().isEmpty())
            Matsatlum->setObjectName(QString::fromUtf8("Matsatlum"));
        Matsatlum->resize(400, 300);
        buttonBox = new QDialogButtonBox(Matsatlum);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(300, 210, 81, 71));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        spinBox_2 = new QSpinBox(Matsatlum);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(310, 80, 61, 22));
        spinBox_2->setMinimum(0);
        spinBox_2->setMaximum(400);
        spinBox_2->setValue(100);
        label_2 = new QLabel(Matsatlum);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 80, 271, 16));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);
        horizontalSlider = new QSlider(Matsatlum);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(30, 50, 271, 21));
        horizontalSlider->setMinimum(0);
        horizontalSlider->setMaximum(400);
        horizontalSlider->setPageStep(16);
        horizontalSlider->setValue(100);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(25);
        spinBox = new QSpinBox(Matsatlum);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(310, 30, 61, 22));
        spinBox->setMinimum(0);
        spinBox->setMaximum(400);
        spinBox->setValue(100);
        horizontalSlider_2 = new QSlider(Matsatlum);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(30, 100, 271, 21));
        horizontalSlider_2->setMinimum(0);
        horizontalSlider_2->setMaximum(400);
        horizontalSlider_2->setValue(100);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_2->setTickInterval(25);
        label = new QLabel(Matsatlum);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 271, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(Matsatlum);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 140, 271, 16));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignCenter);
        dial = new QDial(Matsatlum);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(110, 180, 111, 81));
        dial->setMaximum(255);
        dial->setWrapping(true);
        dial->setNotchTarget(4.000000000000000);
        dial->setNotchesVisible(true);

        retranslateUi(Matsatlum);
        QObject::connect(buttonBox, SIGNAL(accepted()), Matsatlum, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Matsatlum, SLOT(reject()));

        QMetaObject::connectSlotsByName(Matsatlum);
    } // setupUi

    void retranslateUi(QDialog *Matsatlum)
    {
        Matsatlum->setWindowTitle(QCoreApplication::translate("Matsatlum", "Ajuste Matiz Saturaci\303\263n Luminosidad", nullptr));
        label_2->setText(QCoreApplication::translate("Matsatlum", "Luminosidad", nullptr));
        spinBox->setSuffix(QString());
        label->setText(QCoreApplication::translate("Matsatlum", "Saturaci\303\263n", nullptr));
        label_3->setText(QCoreApplication::translate("Matsatlum", "Matiz", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Matsatlum: public Ui_Matsatlum {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATSATLUM_H

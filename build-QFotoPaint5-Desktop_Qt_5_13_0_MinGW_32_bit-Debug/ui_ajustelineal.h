/********************************************************************************
** Form generated from reading UI file 'ajustelineal.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJUSTELINEAL_H
#define UI_AJUSTELINEAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Ajustelineal
{
public:
    QDialogButtonBox *buttonBox;
    QSpinBox *spinBox;
    QSlider *horizontalSlider_2;
    QCheckBox *checkBox;
    QLabel *label_2;
    QLabel *label;
    QSpinBox *spinBox_2;
    QSlider *horizontalSlider;

    void setupUi(QDialog *Ajustelineal)
    {
        if (Ajustelineal->objectName().isEmpty())
            Ajustelineal->setObjectName(QString::fromUtf8("Ajustelineal"));
        Ajustelineal->resize(400, 189);
        buttonBox = new QDialogButtonBox(Ajustelineal);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-140, 140, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        spinBox = new QSpinBox(Ajustelineal);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(310, 40, 61, 22));
        spinBox->setMinimum(0);
        spinBox->setMaximum(100);
        spinBox->setValue(2);
        horizontalSlider_2 = new QSlider(Ajustelineal);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(30, 110, 271, 21));
        horizontalSlider_2->setMinimum(0);
        horizontalSlider_2->setMaximum(100);
        horizontalSlider_2->setSingleStep(2);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_2->setTickInterval(10);
        checkBox = new QCheckBox(Ajustelineal);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(210, 148, 101, 17));
        checkBox->setChecked(true);
        label_2 = new QLabel(Ajustelineal);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 90, 271, 16));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);
        label = new QLabel(Ajustelineal);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 40, 271, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);
        spinBox_2 = new QSpinBox(Ajustelineal);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(310, 90, 61, 22));
        spinBox_2->setMinimum(0);
        spinBox_2->setMaximum(100);
        spinBox_2->setValue(2);
        horizontalSlider = new QSlider(Ajustelineal);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(30, 60, 271, 21));
        horizontalSlider->setMinimum(0);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setPageStep(10);
        horizontalSlider->setValue(2);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(10);

        retranslateUi(Ajustelineal);
        QObject::connect(buttonBox, SIGNAL(accepted()), Ajustelineal, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Ajustelineal, SLOT(reject()));

        QMetaObject::connectSlotsByName(Ajustelineal);
    } // setupUi

    void retranslateUi(QDialog *Ajustelineal)
    {
        Ajustelineal->setWindowTitle(QCoreApplication::translate("Ajustelineal", "Ajuste lineal del histograma", nullptr));
        checkBox->setText(QCoreApplication::translate("Ajustelineal", "Previsualizar", nullptr));
        label_2->setText(QCoreApplication::translate("Ajustelineal", "Percentil m\303\241ximo", nullptr));
        label->setText(QCoreApplication::translate("Ajustelineal", "Percentil m\303\255nimo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ajustelineal: public Ui_Ajustelineal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJUSTELINEAL_H

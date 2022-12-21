/********************************************************************************
** Form generated from reading UI file 'ajuste_rojo_verde_azul.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJUSTE_ROJO_VERDE_AZUL_H
#define UI_AJUSTE_ROJO_VERDE_AZUL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Ajuste_rojo_verde_azul
{
public:
    QDialogButtonBox *buttonBox;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;

    void setupUi(QDialog *Ajuste_rojo_verde_azul)
    {
        if (Ajuste_rojo_verde_azul->objectName().isEmpty())
            Ajuste_rojo_verde_azul->setObjectName(QString::fromUtf8("Ajuste_rojo_verde_azul"));
        Ajuste_rojo_verde_azul->resize(599, 397);
        buttonBox = new QDialogButtonBox(Ajuste_rojo_verde_azul);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 320, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalSlider = new QSlider(Ajuste_rojo_verde_azul);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(100, 140, 221, 22));
        horizontalSlider->setMinimum(-255);
        horizontalSlider->setMaximum(255);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(Ajuste_rojo_verde_azul);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(100, 180, 221, 22));
        horizontalSlider_2->setMinimum(-255);
        horizontalSlider_2->setMaximum(255);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_3 = new QSlider(Ajuste_rojo_verde_azul);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setGeometry(QRect(100, 220, 221, 22));
        horizontalSlider_3->setMinimum(-255);
        horizontalSlider_3->setMaximum(255);
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        label = new QLabel(Ajuste_rojo_verde_azul);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 140, 55, 16));
        label_2 = new QLabel(Ajuste_rojo_verde_azul);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 180, 55, 16));
        label_3 = new QLabel(Ajuste_rojo_verde_azul);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 220, 55, 16));
        spinBox = new QSpinBox(Ajuste_rojo_verde_azul);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(340, 140, 42, 22));
        spinBox->setMinimum(-255);
        spinBox->setMaximum(255);
        spinBox_2 = new QSpinBox(Ajuste_rojo_verde_azul);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(340, 180, 42, 22));
        spinBox_2->setMinimum(-255);
        spinBox_2->setMaximum(255);
        spinBox_3 = new QSpinBox(Ajuste_rojo_verde_azul);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(340, 220, 42, 22));
        spinBox_3->setMinimum(-255);
        spinBox_3->setMaximum(255);
        checkBox = new QCheckBox(Ajuste_rojo_verde_azul);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(430, 140, 121, 20));
        checkBox_2 = new QCheckBox(Ajuste_rojo_verde_azul);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(430, 180, 141, 20));
        checkBox_3 = new QCheckBox(Ajuste_rojo_verde_azul);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(430, 220, 131, 20));

        retranslateUi(Ajuste_rojo_verde_azul);
        QObject::connect(buttonBox, SIGNAL(accepted()), Ajuste_rojo_verde_azul, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Ajuste_rojo_verde_azul, SLOT(reject()));

        QMetaObject::connectSlotsByName(Ajuste_rojo_verde_azul);
    } // setupUi

    void retranslateUi(QDialog *Ajuste_rojo_verde_azul)
    {
        Ajuste_rojo_verde_azul->setWindowTitle(QCoreApplication::translate("Ajuste_rojo_verde_azul", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Ajuste_rojo_verde_azul", "Rojo", nullptr));
        label_2->setText(QCoreApplication::translate("Ajuste_rojo_verde_azul", "Verde", nullptr));
        label_3->setText(QCoreApplication::translate("Ajuste_rojo_verde_azul", "Azul", nullptr));
        checkBox->setText(QCoreApplication::translate("Ajuste_rojo_verde_azul", "Multiplicar Rojo", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Ajuste_rojo_verde_azul", "Multiplicar verde", nullptr));
        checkBox_3->setText(QCoreApplication::translate("Ajuste_rojo_verde_azul", "Multiplicar azul", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ajuste_rojo_verde_azul: public Ui_Ajuste_rojo_verde_azul {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJUSTE_ROJO_VERDE_AZUL_H

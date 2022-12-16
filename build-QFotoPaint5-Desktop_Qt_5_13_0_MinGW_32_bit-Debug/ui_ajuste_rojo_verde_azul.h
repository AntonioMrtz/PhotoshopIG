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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Ajuste_rojo_verde_azul
{
public:
    QDialogButtonBox *buttonBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QCheckBox *checkBox;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;

    void setupUi(QDialog *Ajuste_rojo_verde_azul)
    {
        if (Ajuste_rojo_verde_azul->objectName().isEmpty())
            Ajuste_rojo_verde_azul->setObjectName(QString::fromUtf8("Ajuste_rojo_verde_azul"));
        Ajuste_rojo_verde_azul->resize(400, 300);
        buttonBox = new QDialogButtonBox(Ajuste_rojo_verde_azul);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-40, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        radioButton = new QRadioButton(Ajuste_rojo_verde_azul);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setEnabled(true);
        radioButton->setGeometry(QRect(20, 10, 95, 20));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(Ajuste_rojo_verde_azul);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(20, 40, 95, 20));
        horizontalSlider = new QSlider(Ajuste_rojo_verde_azul);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(100, 90, 221, 22));
        horizontalSlider->setMinimum(-255);
        horizontalSlider->setMaximum(255);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(Ajuste_rojo_verde_azul);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(100, 130, 221, 22));
        horizontalSlider_2->setMinimum(-255);
        horizontalSlider_2->setMaximum(255);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_3 = new QSlider(Ajuste_rojo_verde_azul);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setGeometry(QRect(100, 170, 221, 22));
        horizontalSlider_3->setMinimum(-255);
        horizontalSlider_3->setMaximum(255);
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        label = new QLabel(Ajuste_rojo_verde_azul);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 90, 55, 16));
        label_2 = new QLabel(Ajuste_rojo_verde_azul);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 130, 55, 16));
        label_3 = new QLabel(Ajuste_rojo_verde_azul);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 170, 55, 16));
        checkBox = new QCheckBox(Ajuste_rojo_verde_azul);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(280, 10, 111, 20));
        spinBox = new QSpinBox(Ajuste_rojo_verde_azul);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(340, 90, 42, 22));
        spinBox->setMinimum(-255);
        spinBox->setMaximum(255);
        spinBox_2 = new QSpinBox(Ajuste_rojo_verde_azul);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(340, 130, 42, 22));
        spinBox_2->setMinimum(-255);
        spinBox_2->setMaximum(255);
        spinBox_3 = new QSpinBox(Ajuste_rojo_verde_azul);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(340, 170, 42, 22));
        spinBox_3->setMinimum(-255);
        spinBox_3->setMaximum(255);

        retranslateUi(Ajuste_rojo_verde_azul);
        QObject::connect(buttonBox, SIGNAL(accepted()), Ajuste_rojo_verde_azul, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Ajuste_rojo_verde_azul, SLOT(reject()));

        QMetaObject::connectSlotsByName(Ajuste_rojo_verde_azul);
    } // setupUi

    void retranslateUi(QDialog *Ajuste_rojo_verde_azul)
    {
        Ajuste_rojo_verde_azul->setWindowTitle(QCoreApplication::translate("Ajuste_rojo_verde_azul", "Dialog", nullptr));
        radioButton->setText(QCoreApplication::translate("Ajuste_rojo_verde_azul", "Sumar", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Ajuste_rojo_verde_azul", "Multiplicar", nullptr));
        label->setText(QCoreApplication::translate("Ajuste_rojo_verde_azul", "Rojo", nullptr));
        label_2->setText(QCoreApplication::translate("Ajuste_rojo_verde_azul", "Verde", nullptr));
        label_3->setText(QCoreApplication::translate("Ajuste_rojo_verde_azul", "Azul", nullptr));
        checkBox->setText(QCoreApplication::translate("Ajuste_rojo_verde_azul", "Previsualizar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ajuste_rojo_verde_azul: public Ui_Ajuste_rojo_verde_azul {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJUSTE_ROJO_VERDE_AZUL_H

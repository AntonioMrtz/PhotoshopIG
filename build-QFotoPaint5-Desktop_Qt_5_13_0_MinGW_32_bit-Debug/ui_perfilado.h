/********************************************************************************
** Form generated from reading UI file 'perfilado.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERFILADO_H
#define UI_PERFILADO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Perfilado
{
public:
    QDialogButtonBox *buttonBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox;
    QSlider *horizontalSlider_2;
    QLabel *label;
    QLabel *label_2;
    QSlider *horizontalSlider;

    void setupUi(QDialog *Perfilado)
    {
        if (Perfilado->objectName().isEmpty())
            Perfilado->setObjectName(QString::fromUtf8("Perfilado"));
        Perfilado->resize(389, 209);
        buttonBox = new QDialogButtonBox(Perfilado);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-60, 150, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        spinBox_2 = new QSpinBox(Perfilado);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(310, 90, 61, 22));
        spinBox_2->setMinimum(0);
        spinBox_2->setMaximum(400);
        spinBox_2->setValue(100);
        spinBox = new QSpinBox(Perfilado);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(310, 40, 61, 22));
        spinBox->setMinimum(1);
        spinBox->setMaximum(9);
        spinBox->setSingleStep(2);
        spinBox->setValue(3);
        horizontalSlider_2 = new QSlider(Perfilado);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(30, 110, 271, 21));
        horizontalSlider_2->setMinimum(0);
        horizontalSlider_2->setMaximum(400);
        horizontalSlider_2->setValue(100);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_2->setTickInterval(25);
        label = new QLabel(Perfilado);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 40, 271, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Perfilado);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 90, 271, 16));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);
        horizontalSlider = new QSlider(Perfilado);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(30, 60, 271, 21));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(9);
        horizontalSlider->setSingleStep(2);
        horizontalSlider->setPageStep(16);
        horizontalSlider->setValue(3);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(2);

        retranslateUi(Perfilado);
        QObject::connect(buttonBox, SIGNAL(accepted()), Perfilado, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Perfilado, SLOT(reject()));

        QMetaObject::connectSlotsByName(Perfilado);
    } // setupUi

    void retranslateUi(QDialog *Perfilado)
    {
        Perfilado->setWindowTitle(QCoreApplication::translate("Perfilado", "Perfilado", nullptr));
        spinBox->setSuffix(QString());
        label->setText(QCoreApplication::translate("Perfilado", "Radio de la Laplaciana", nullptr));
        label_2->setText(QCoreApplication::translate("Perfilado", "Grado del efecto", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Perfilado: public Ui_Perfilado {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERFILADO_H

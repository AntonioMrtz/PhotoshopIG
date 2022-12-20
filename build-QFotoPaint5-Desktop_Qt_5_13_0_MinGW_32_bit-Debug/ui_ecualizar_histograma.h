/********************************************************************************
** Form generated from reading UI file 'ecualizar_histograma.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ECUALIZAR_HISTOGRAMA_H
#define UI_ECUALIZAR_HISTOGRAMA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Ecualizar_histograma
{
public:
    QDialogButtonBox *buttonBox;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QLabel *label;

    void setupUi(QDialog *Ecualizar_histograma)
    {
        if (Ecualizar_histograma->objectName().isEmpty())
            Ecualizar_histograma->setObjectName(QString::fromUtf8("Ecualizar_histograma"));
        Ecualizar_histograma->resize(400, 300);
        buttonBox = new QDialogButtonBox(Ecualizar_histograma);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-50, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        checkBox = new QCheckBox(Ecualizar_histograma);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(250, 20, 141, 20));
        checkBox_2 = new QCheckBox(Ecualizar_histograma);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(30, 110, 81, 20));
        checkBox_3 = new QCheckBox(Ecualizar_histograma);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(30, 140, 81, 20));
        checkBox_4 = new QCheckBox(Ecualizar_histograma);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(30, 170, 81, 20));
        label = new QLabel(Ecualizar_histograma);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 70, 131, 16));

        retranslateUi(Ecualizar_histograma);
        QObject::connect(buttonBox, SIGNAL(accepted()), Ecualizar_histograma, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Ecualizar_histograma, SLOT(reject()));

        QMetaObject::connectSlotsByName(Ecualizar_histograma);
    } // setupUi

    void retranslateUi(QDialog *Ecualizar_histograma)
    {
        Ecualizar_histograma->setWindowTitle(QCoreApplication::translate("Ecualizar_histograma", "Dialog", nullptr));
        checkBox->setText(QCoreApplication::translate("Ecualizar_histograma", "Ecualizaci\303\263n canales", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Ecualizar_histograma", "Canal B", nullptr));
        checkBox_3->setText(QCoreApplication::translate("Ecualizar_histograma", "Canal G", nullptr));
        checkBox_4->setText(QCoreApplication::translate("Ecualizar_histograma", "Canal R", nullptr));
        label->setText(QCoreApplication::translate("Ecualizar_histograma", "Canales a ecualizar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ecualizar_histograma: public Ui_Ecualizar_histograma {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ECUALIZAR_HISTOGRAMA_H

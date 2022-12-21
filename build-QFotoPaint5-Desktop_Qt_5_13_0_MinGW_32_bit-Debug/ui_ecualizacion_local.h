/********************************************************************************
** Form generated from reading UI file 'ecualizacion_local.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ECUALIZACION_LOCAL_H
#define UI_ECUALIZACION_LOCAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Ecualizacion_local
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_4;

    void setupUi(QDialog *Ecualizacion_local)
    {
        if (Ecualizacion_local->objectName().isEmpty())
            Ecualizacion_local->setObjectName(QString::fromUtf8("Ecualizacion_local"));
        Ecualizacion_local->resize(400, 300);
        buttonBox = new QDialogButtonBox(Ecualizacion_local);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(280, 110, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Ecualizacion_local);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 90, 131, 16));
        checkBox_3 = new QCheckBox(Ecualizacion_local);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(40, 160, 81, 20));
        checkBox = new QCheckBox(Ecualizacion_local);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(30, 30, 201, 20));
        checkBox_2 = new QCheckBox(Ecualizacion_local);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(40, 130, 81, 20));
        checkBox_4 = new QCheckBox(Ecualizacion_local);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(40, 190, 81, 20));

        retranslateUi(Ecualizacion_local);
        QObject::connect(buttonBox, SIGNAL(accepted()), Ecualizacion_local, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Ecualizacion_local, SLOT(reject()));

        QMetaObject::connectSlotsByName(Ecualizacion_local);
    } // setupUi

    void retranslateUi(QDialog *Ecualizacion_local)
    {
        Ecualizacion_local->setWindowTitle(QCoreApplication::translate("Ecualizacion_local", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Ecualizacion_local", "Canales a ecualizar", nullptr));
        checkBox_3->setText(QCoreApplication::translate("Ecualizacion_local", "Canal G", nullptr));
        checkBox->setText(QCoreApplication::translate("Ecualizacion_local", "Ecualizaci\303\263n conjunta canales", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Ecualizacion_local", "Canal B", nullptr));
        checkBox_4->setText(QCoreApplication::translate("Ecualizacion_local", "Canal R", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ecualizacion_local: public Ui_Ecualizacion_local {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ECUALIZACION_LOCAL_H

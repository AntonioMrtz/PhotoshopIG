/********************************************************************************
** Form generated from reading UI file 'rotar_reescalar.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROTAR_REESCALAR_H
#define UI_ROTAR_REESCALAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_rotar_escalar
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;

    void setupUi(QDialog *rotar_escalar)
    {
        if (rotar_escalar->objectName().isEmpty())
            rotar_escalar->setObjectName(QString::fromUtf8("rotar_escalar"));
        rotar_escalar->resize(400, 300);
        buttonBox = new QDialogButtonBox(rotar_escalar);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-40, 230, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(rotar_escalar);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 110, 121, 16));
        label_2 = new QLabel(rotar_escalar);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 150, 131, 16));
        spinBox = new QSpinBox(rotar_escalar);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(270, 110, 42, 22));
        spinBox->setMinimum(-360);
        spinBox->setMaximum(360);
        spinBox_2 = new QSpinBox(rotar_escalar);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(270, 150, 42, 22));

        retranslateUi(rotar_escalar);
        QObject::connect(buttonBox, SIGNAL(accepted()), rotar_escalar, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), rotar_escalar, SLOT(reject()));

        QMetaObject::connectSlotsByName(rotar_escalar);
    } // setupUi

    void retranslateUi(QDialog *rotar_escalar)
    {
        rotar_escalar->setWindowTitle(QCoreApplication::translate("rotar_escalar", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("rotar_escalar", "\303\201ngulo rotaci\303\263n", nullptr));
        label_2->setText(QCoreApplication::translate("rotar_escalar", "Escala del reescalado", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rotar_escalar: public Ui_rotar_escalar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROTAR_REESCALAR_H

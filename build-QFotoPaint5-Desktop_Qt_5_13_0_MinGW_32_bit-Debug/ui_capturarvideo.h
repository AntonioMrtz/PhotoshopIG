/********************************************************************************
** Form generated from reading UI file 'capturarvideo.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAPTURARVIDEO_H
#define UI_CAPTURARVIDEO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Capturarvideo
{
public:
    QDialogButtonBox *buttonBox;
    QSlider *horizontalSlider;
    QLabel *label;
    QSpinBox *spinBox;

    void setupUi(QDialog *Capturarvideo)
    {
        if (Capturarvideo->objectName().isEmpty())
            Capturarvideo->setObjectName(QString::fromUtf8("Capturarvideo"));
        Capturarvideo->resize(469, 126);
        buttonBox = new QDialogButtonBox(Capturarvideo);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-30, 80, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalSlider = new QSlider(Capturarvideo);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 50, 341, 21));
        horizontalSlider->setMinimum(0);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setPageStep(10);
        horizontalSlider->setValue(0);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(10);
        label = new QLabel(Capturarvideo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 341, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);
        spinBox = new QSpinBox(Capturarvideo);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(370, 30, 61, 22));
        spinBox->setMinimum(0);
        spinBox->setMaximum(100);
        spinBox->setValue(0);

        retranslateUi(Capturarvideo);
        QObject::connect(buttonBox, SIGNAL(accepted()), Capturarvideo, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Capturarvideo, SLOT(reject()));

        QMetaObject::connectSlotsByName(Capturarvideo);
    } // setupUi

    void retranslateUi(QDialog *Capturarvideo)
    {
        Capturarvideo->setWindowTitle(QCoreApplication::translate("Capturarvideo", "Capturar de video", nullptr));
        label->setText(QCoreApplication::translate("Capturarvideo", "Posici\303\263n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Capturarvideo: public Ui_Capturarvideo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAPTURARVIDEO_H

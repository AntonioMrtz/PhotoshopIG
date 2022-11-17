/********************************************************************************
** Form generated from reading UI file 'perspectiva.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSPECTIVA_H
#define UI_PERSPECTIVA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_Perspectiva
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *listWidget;
    QLabel *label_2;
    QListWidget *listWidget_2;
    QLabel *label_3;

    void setupUi(QDialog *Perspectiva)
    {
        if (Perspectiva->objectName().isEmpty())
            Perspectiva->setObjectName(QString::fromUtf8("Perspectiva"));
        Perspectiva->resize(617, 261);
        buttonBox = new QDialogButtonBox(Perspectiva);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(190, 210, 211, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        listWidget = new QListWidget(Perspectiva);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 70, 281, 111));
        listWidget->setAlternatingRowColors(false);
        listWidget->setViewMode(QListView::ListMode);
        label_2 = new QLabel(Perspectiva);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 30, 281, 16));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(127, 127, 127);\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);
        listWidget_2 = new QListWidget(Perspectiva);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(310, 70, 281, 111));
        listWidget_2->setAlternatingRowColors(false);
        listWidget_2->setViewMode(QListView::ListMode);
        label_3 = new QLabel(Perspectiva);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(310, 30, 281, 16));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(127, 127, 127);\n"
"color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignCenter);

        retranslateUi(Perspectiva);
        QObject::connect(buttonBox, SIGNAL(accepted()), Perspectiva, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Perspectiva, SLOT(reject()));

        listWidget->setCurrentRow(-1);
        listWidget_2->setCurrentRow(-1);


        QMetaObject::connectSlotsByName(Perspectiva);
    } // setupUi

    void retranslateUi(QDialog *Perspectiva)
    {
        Perspectiva->setWindowTitle(QCoreApplication::translate("Perspectiva", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("Perspectiva", "Imagen de origen", nullptr));
        label_3->setText(QCoreApplication::translate("Perspectiva", "Imagen de destino", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Perspectiva: public Ui_Perspectiva {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSPECTIVA_H

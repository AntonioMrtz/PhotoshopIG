#include "matsatlum.h"
#include "ui_matsatlum.h"
#include "imagenes.h"

Matsatlum::Matsatlum(int numfoto,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Matsatlum)
{
    ui->setupUi(this);
    nfoto=numfoto;
    matiz=0;
    luminosidad=1;
    saturacion=1;
    set_callback_foto(nfoto,false);

}

Matsatlum::~Matsatlum()
{
    set_callback_foto(nfoto,true);
    delete ui;
}

void Matsatlum::on_dial_valueChanged(int value)
{
    matiz=value;
    ver_matiz_saturacion_luminosidad(nfoto,matiz,saturacion,luminosidad);
}

void Matsatlum::on_horizontalSlider_valueChanged(int value)
{
    saturacion=value/100.0;
    ui->spinBox->setValue(value);
    ver_matiz_saturacion_luminosidad(nfoto,matiz,saturacion,luminosidad);

}

void Matsatlum::on_spinBox_valueChanged(int arg1)
{
    ui->horizontalSlider->setValue(arg1);
}

void Matsatlum::on_horizontalSlider_2_valueChanged(int value)
{
    luminosidad=value/100.0;
    ui->spinBox_2->setValue(value);
    ver_matiz_saturacion_luminosidad(nfoto,matiz,saturacion,luminosidad);

}

void Matsatlum::on_spinBox_2_valueChanged(int arg1)
{
    ui->horizontalSlider_2->setValue(arg1);

}

void Matsatlum::on_Matsatlum_accepted()
{
    ver_matiz_saturacion_luminosidad(nfoto,matiz,saturacion,luminosidad,true);

}

void Matsatlum::on_Matsatlum_rejected()
{
    mostrar(nfoto);
}

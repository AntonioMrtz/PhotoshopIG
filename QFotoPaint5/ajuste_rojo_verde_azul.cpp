#include "ajuste_rojo_verde_azul.h"
#include "ui_ajuste_rojo_verde_azul.h"

#include "imagenes.h"


Ajuste_rojo_verde_azul::Ajuste_rojo_verde_azul(int numfoto,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ajuste_rojo_verde_azul)
{
    ui->setupUi(this);
    nfoto=numfoto;
    suma= 0.0;
    multiplica= 1.0;
}

Ajuste_rojo_verde_azul::~Ajuste_rojo_verde_azul()
{
    delete ui;
}

void Ajuste_rojo_verde_azul::actualizar(){



}

void Ajuste_rojo_verde_azul::on_horizontalSlider_valueChanged(int value)
{
    ui->spinBox->setValue(value);
    actualizar();
}



void Ajuste_rojo_verde_azul::on_horizontalSlider_2_valueChanged(int value)
{
    ui->spinBox_2->setValue(value);
    actualizar();
}

void Ajuste_rojo_verde_azul::on_horizontalSlider_3_valueChanged(int value)
{
    ui->spinBox_3->setValue(value);
    actualizar();
}

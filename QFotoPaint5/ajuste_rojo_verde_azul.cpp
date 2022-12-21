#include "ajuste_rojo_verde_azul.h"
#include "ui_ajuste_rojo_verde_azul.h"
#include "imagenes.h"


Ajuste_rojo_verde_azul::Ajuste_rojo_verde_azul(int numfoto,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ajuste_rojo_verde_azul)
{
    ui->setupUi(this);
    nfoto=numfoto;
    verde=0;
    azul=0;
    rojo=0;

}

Ajuste_rojo_verde_azul::~Ajuste_rojo_verde_azul()
{
    destroyWindow("Ajuste Rojo Azul Verde");


    delete ui;
}


void Ajuste_rojo_verde_azul::actualizar(){

    type[2]=ui->checkBox->checkState();
    type[1]=ui->checkBox_2->checkState();
    type[0]=ui->checkBox_3->checkState();

    ajuste_rojo_verde_azul(nfoto,azul,verde,rojo,type);



}

void Ajuste_rojo_verde_azul::on_horizontalSlider_valueChanged(int value)
{
    ui->spinBox->setValue(value);
    rojo=value;
    actualizar();
}



void Ajuste_rojo_verde_azul::on_horizontalSlider_2_valueChanged(int value)
{
    ui->spinBox_2->setValue(value);
    verde=value;
    actualizar();
}

void Ajuste_rojo_verde_azul::on_horizontalSlider_3_valueChanged(int value)
{
    ui->spinBox_3->setValue(value);
    azul=value;
    actualizar();
}



void Ajuste_rojo_verde_azul::on_Ajuste_rojo_verde_azul_rejected()
{
    destroyWindow("Ajuste Rojo Azul Verde");
}

void Ajuste_rojo_verde_azul::on_Ajuste_rojo_verde_azul_accepted()
{

    type[2]=ui->checkBox->checkState();
    type[1]=ui->checkBox_2->checkState();
    type[0]=ui->checkBox_3->checkState();

    ajuste_rojo_verde_azul(nfoto,azul,verde,rojo,type,true);
    destroyWindow("Ajuste Rojo Azul Verde");


}

void Ajuste_rojo_verde_azul::on_checkBox_stateChanged(int arg1)
{

}

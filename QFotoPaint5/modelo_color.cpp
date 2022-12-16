#include "modelo_color.h"
#include "ui_modelo_color.h"
#include "imagenes.h"

//extern int nfoto;

Modelo_color::Modelo_color(int numfoto,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modelo_color)
{
    ui->setupUi(this);
    nfoto=numfoto;
}

Modelo_color::~Modelo_color()
{
    delete ui;
}

void Modelo_color::on_radioButton_clicked()
{
    transformar_modelo_color(nfoto,0);
}


void Modelo_color::on_radioButton_2_clicked()
{
    transformar_modelo_color(nfoto,1);

}

void Modelo_color::on_radioButton_3_clicked()
{
    transformar_modelo_color(nfoto,2);

}


void Modelo_color::on_radioButton_4_clicked()
{
    transformar_modelo_color(nfoto,3);

}


void Modelo_color::on_radioButton_5_clicked()
{
    transformar_modelo_color(nfoto,4);

}


void Modelo_color::on_Modelo_color_rejected()
{
    destroyWindow("canal 0");
    destroyWindow("canal 1");
    destroyWindow("canal 2");

}

#include "color_falso.h"
#include "ui_color_falso.h"
#include "imagenes.h"

Color_falso::Color_falso(int numfoto,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Color_falso)
{
    ui->setupUi(this);
    nfoto=numfoto;
}

Color_falso::~Color_falso()
{
    delete ui;
}

void Color_falso::on_radioButton_clicked()
{
    color_falso(foto_activa(),primera_libre(),0);
}

void Color_falso::on_radioButton_2_clicked()
{
    color_falso(foto_activa(),primera_libre(),1);
}

void Color_falso::on_radioButton_3_clicked()
{
    color_falso(foto_activa(),primera_libre(),2);
}

void Color_falso::on_radioButton_4_clicked()
{
    color_falso(foto_activa(),primera_libre(),3);
}

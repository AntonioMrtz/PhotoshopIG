#include "rotar_reescalar.h"
#include "ui_rotar_reescalar.h"
#include "imagenes.h"

rotar_escalar::rotar_escalar(int numfoto,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rotar_escalar)
{
    ui->setupUi(this);
    nfoto=numfoto;
}

rotar_escalar::~rotar_escalar()
{
    delete ui;
}


void rotar_escalar::on_buttonBox_accepted()
{
    rotar_y_reescalar(nfoto, ui->spinBox->value(),ui->spinBox_2->value(),true);

}

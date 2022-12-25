#include "rotar_reescalar.h"
#include "ui_rotar_reescalar.h"

Rotar_reescalar::Rotar_reescalar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rotar_reescalar)
{
    ui->setupUi(this);
}

Rotar_reescalar::~Rotar_reescalar()
{
    delete ui;
}

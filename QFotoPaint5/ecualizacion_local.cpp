#include "ecualizacion_local.h"
#include "ui_ecualizacion_local.h"
#include <vector>

#include "imagenes.h"

Ecualizacion_local::Ecualizacion_local(int numfoto,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ecualizacion_local)
{
    ui->setupUi(this);
    nfoto=numfoto;
}

Ecualizacion_local::~Ecualizacion_local()
{
    delete ui;
}

void Ecualizacion_local::on_buttonBox_accepted()
{


    bool ecualizar = ui->checkBox->checkState();

    if(ecualizar==true){

        int array[3]={0,1,2};
        ecualizar_histograma_local(nfoto,primera_libre(),array,3,true);
        return;
    }



   vector<int> vec ;
   bool b = ui->checkBox_2->checkState();
   bool g = ui->checkBox_3->checkState();
   bool r = ui->checkBox_4->checkState();

   int array_size=0;


   if(b==1){

       array_size++;
       vec.push_back(0);

   }


   if(g==1){

       array_size++;
       vec.push_back(1);

   }


   if(r==1){


       array_size++;
       vec.push_back(2);

    }

   int array[array_size];

   for(int i=0;i<array_size;i++){

        array[i]=vec[i];
   }

    qDebug("%d",array_size);
    ecualizar_histograma_local(nfoto,primera_libre(),array,array_size,false);


}

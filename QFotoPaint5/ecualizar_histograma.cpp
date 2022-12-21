#include "ecualizar_histograma.h"
#include "ui_ecualizar_histograma.h"
#include "imagenes.h"
#include "vector"

Ecualizar_histograma::Ecualizar_histograma(int numfoto,int primerlib,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ecualizar_histograma)
{
    ui->setupUi(this);
    nfoto=numfoto;
    primerlibre=primerlib;
}

Ecualizar_histograma::~Ecualizar_histograma()
{
    delete ui;
}

void Ecualizar_histograma::on_Ecualizar_histograma_accepted()
{



    bool ecualizar = ui->checkBox->checkState();

    if(ecualizar==true){

        int array[1]={0};
        ecualizar_histograma(nfoto,primera_libre(),array,1,true);
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


    ecualizar_histograma(nfoto,primera_libre(),array,array_size,false);


}


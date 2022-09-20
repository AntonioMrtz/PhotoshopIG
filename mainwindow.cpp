#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>
#include <QFileDialog>

using namespace cv;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


/* BUTTONS */

void MainWindow::on_pushButton_clicked()
{

     QString nombre= QFileDialog::getOpenFileName();
     Mat img= imread(nombre.toLatin1().data());
     namedWindow("Imagen", WINDOW_NORMAL);
     imshow("Imagen", img);


}

void MainWindow::on_pushButton_2_clicked()
{

}

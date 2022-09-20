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

    //qDebug("%d %d",img.cols,img.rows);

    Mat img2,img3;
    cv::resize(img,img2,Size(img.cols*4,img.rows*4));

    namedWindow("Imagen2", WINDOW_NORMAL);
    //resizeWindow("Imagen2",img.cols,img.rows);
    imshow("Imagen2", img2);

    //qDebug("%d %d",img2.cols,img2.rows);

    cv::resize(img,img3,Size(img.cols*4,img.rows*4),INTER_LINEAR);
    namedWindow("Imagen3", WINDOW_NORMAL);
    //resizeWindow("Imagen3",img.cols,img.rows);
    imshow("Imagen3", img3);


    //imwrite("C:\\Users\\Usuario\\Downloads\\prueba.jpg",img2);

}

void MainWindow::on_pushButton_2_clicked()
{

}


void MainWindow::on_pushButton_3_clicked()
{
    close();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QColorDialog>
#include <QMessageBox>


#include <opencv2/opencv.hpp>
using namespace cv;

#include "acercade.h"
#include "brillocontraste.h"
#include "dialognueva.h"
#include "imagenes.h"
#include "mediadevideo.h"
#include "mediaponderada.h"
#include "rotaravideo.h"
#include "suavizados.h"
#include "video.h"
#include "bajorrelieve.h"
#include "ajustelineal.h"
#include "capturarvideo.h"
#include "pinchar_estirar.h"
#include "matsatlum.h"
#include "perfilado.h"
#include "perspectiva.h"
#include "movimiento.h"
#include "modelo_color.h"
#include "color_falso.h"
#include "ajuste_rojo_verde_azul.h"
#include "ecualizar_histograma.h"
#include "ecualizacion_local.h"
#include "rotar_reescalar.h"
QString FiltroImagen = "Todos los formatos (*.jpg *.jpeg *.jpe .jp2 *.tif *.tiff *.png *.gif *.bmp *.dib *.webp *.ppm);;Archivos JPG (*.jpg *.jpeg *.jpe);;Archivos TIF (*.tif *.tiff);;Archivos PNG (*.png);;Archivos GIF (*.gif);;Archivos BMP (*.bmp *.dib);;Otros (*.*)";

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

void MainWindow::show()
{
    QMainWindow::show();
    move(x(), 0);
}

void MainWindow::setStatusBarText(QString cadena)
{
    ui->statusBar->showMessage(cadena, 0);
}

int MainWindow::comprobar_primera_libre (void)
{
    int pl= primera_libre();
    if (pl == -1)
        QMessageBox::warning(this, "Error al crear imagen",
                             "Lo siento. No se pueden crear más ventanas.");
    return pl;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_actionSalir_triggered()
{
    close();
}

void MainWindow::on_actionNueva_imagen_triggered()
{
    int pl= comprobar_primera_libre();
    if (pl != -1) {
        DialogNueva nueva(pl, this);
        nueva.exec();
    }
}

void MainWindow::on_actionAbrir_imagen_triggered()
{
    int pl= comprobar_primera_libre();
    if (pl != -1) {
        QString nombre= QFileDialog::getOpenFileName(this, "Abrir imagen", ".", FiltroImagen);
        if (!nombre.isEmpty())
            crear_nueva(pl, nombre.toUtf8().data());
    }
}

void MainWindow::on_actionPunto_triggered()
{
    herr_actual= HER_PUNTO;
    ui->toolButton_4->setChecked(true);
}

void MainWindow::on_actionLinea_triggered()
{
    herr_actual= HER_LINEA;
    ui->toolButton_5->setChecked(true);
}

void MainWindow::on_actionSeleccionar_triggered()
{
    herr_actual= HER_SELECCION;
    ui->toolButton_6->setChecked(true);
}

void MainWindow::on_toolButton_2_clicked()
{
    on_actionNueva_imagen_triggered();
}

void MainWindow::on_pushButton_clicked()
{
    QColor color= QColorDialog::getColor();
    if (color.isValid()) {
        QString estilo= "background-color: rgb(";
        estilo+= QString::number(color.red())+",";
        estilo+= QString::number(color.green())+",";
        estilo+= QString::number(color.blue())+")";
        ui->pushButton->setStyleSheet(estilo);
        color_pincel= CV_RGB(color.red(), color.green(), color.blue());
    }
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    radio_pincel= value;
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    difum_pincel= value;
}

void MainWindow::on_toolButton_clicked()
{
    on_actionAbrir_imagen_triggered();
}

void MainWindow::on_actionGuardar_triggered()
{
    int fa= foto_activa();
    if (fa != -1)
        guardar_foto(fa);
}

void MainWindow::on_actionGuardar_como_triggered()
{
    int fa= foto_activa();
    if (fa != -1) {
        QString nombre= QFileDialog::getSaveFileName(this, "Guardar imagen", QString::fromStdString(foto[fa].nombre), FiltroImagen);
        if (!nombre.isEmpty())
            guardar_foto(fa, nombre.toUtf8().data());
    }
}

void MainWindow::on_actionCerrar_triggered()
{
    int fa= foto_activa();
    if (fa != -1) {
        if (foto[fa].modificada && preguntar_guardar) {
            QString nombre= QString::fromStdString(foto[fa].nombre);
            nombre= "El archivo " + nombre + " ha sido modificado.\n¿Desea guardarlo?";
            int resp= QMessageBox::question(this, "Archivo modificado", nombre,
                                            QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
            if (resp==QMessageBox::Yes)
                guardar_foto(fa);
            else if (resp==QMessageBox::Cancel)
                return;
            else
                foto[fa].modificada= false;
        }
        cerrar_foto(fa);
    }
}

void MainWindow::on_actionPreguntar_si_guardar_triggered()
{
    preguntar_guardar= ui->actionPreguntar_si_guardar->isChecked();
}

void MainWindow::on_actionColor_del_pincel_triggered()
{
    on_pushButton_clicked();
}

void MainWindow::on_actionSeleccionar_todo_triggered()
{
    int fa= foto_activa();
    if (fa != -1) {
        foto[fa].roi= Rect(0, 0, foto[fa].img.cols, foto[fa].img.rows);
        mostrar(fa);
    }
}

void MainWindow::on_toolButton_3_clicked()
{
    on_actionGuardar_triggered();
}

void MainWindow::on_toolButton_4_clicked()
{
    herr_actual= HER_PUNTO;
}

void MainWindow::on_toolButton_5_clicked()
{
    herr_actual= HER_LINEA;
}

void MainWindow::on_toolButton_6_clicked()
{
    herr_actual= HER_SELECCION;
}

void MainWindow::on_actionInvertir_triggered()
{
    int fa= foto_activa();
    if (fa != -1) {
        int pl= comprobar_primera_libre();
        if (pl != -1)
            invertir(fa, pl);
    }
}

void MainWindow::on_actionRotar_90_triggered()
{
    int fa= foto_activa();
    if (fa != -1) {
        int pl= comprobar_primera_libre();
        if (pl != -1)
            rotar_exacto(fa, pl, 1);
    }
}

void MainWindow::on_actionRotar_180_triggered()
{
    int fa= foto_activa();
    if (fa != -1) {
        int pl= comprobar_primera_libre();
        if (pl != -1)
            rotar_exacto(fa, pl, 2);
    }
}

void MainWindow::on_actionRotar_91_triggered()
{
    int fa= foto_activa();
    if (fa != -1) {
        int pl= comprobar_primera_libre();
        if (pl != -1)
            rotar_exacto(fa, pl, 3);
    }
}

void MainWindow::on_actionBrillo_contraste_triggered()
{
    if (foto_activa() != -1) {
        brillocontraste bc(foto_activa(), this);
        bc.exec();
    }
}

void MainWindow::on_actionGausiano_triggered()
{
    if (foto_activa() !=- 1) {
        suavizados sg(foto_activa(), 1, this);
        sg.exec();
    }
}

void MainWindow::on_actionMedia_triggered()
{
    if (foto_activa() != -1) {
        suavizados sg(foto_activa(), 2, this);
        sg.exec();
    }
}

void MainWindow::on_actionMedia_ponderada_triggered()
{
    if (foto_activa() != -1) {
        int pl= comprobar_primera_libre();
        if (pl != -1) {
            mediaponderada mp(this);
            mp.exec();
        }
    }
}

void MainWindow::on_actionRotar_imagen_triggered()
{
    if (foto_activa() != -1) {
        rotaravideo rv;
        rv.exec();
    }
}

void MainWindow::on_actionAcerca_de_triggered()
{
    acercade ad;
    ad.exec();
}

void MainWindow::on_actionImagen_media_triggered()
{
    mediadevideo mv(this);
    mv.exec();
}

void MainWindow::on_toolButton_7_clicked()
{
    herr_actual=HER_RECTANGULO;
}

void MainWindow::on_actionRectangulo_triggered()
{
    herr_actual=HER_RECTANGULO;
    ui->toolButton_7->setChecked(true);
}

void MainWindow::on_actionMediana_triggered()
{
    if (foto_activa() != -1) {
        suavizados sg(foto_activa(), 3, this);
        sg.exec();
    }
}

void MainWindow::on_actionCopiar_a_nueva_triggered()
{
    if(foto_activa()!=-1 && primera_libre()!=-1){

        int num=foto_activa();
        Mat imgres = foto[num].img(foto[num].roi);
        crear_nueva(primera_libre(),imgres);

    }
}


void MainWindow::on_actionCaptura_de_c_mara_triggered()
{
    if(primera_libre()!=-1)
        capturar_camara(primera_libre());
}

void MainWindow::on_toolButton_8_clicked()
{
    herr_actual=HER_ARCO_IRIS;

}

void MainWindow::on_actionArcoiris_triggered()
{
    qDebug("entro");
    ui->toolButton_8->setChecked(true);
    herr_actual=HER_ARCO_IRIS;

}

void MainWindow::on_actionGrises_triggered()
{
    if(foto_activa()!=-1 && primera_libre()!=-1){
        ver_histograma(foto_activa(),primera_libre(),3);
    }
}

void MainWindow::on_actionAzul_triggered()
{

    if(foto_activa()!=-1 && primera_libre()!=-1){
        ver_histograma(foto_activa(),primera_libre(),0);
    }

}

void MainWindow::on_actionRojo_triggered()
{
    if(foto_activa()!=-1 && primera_libre()!=-1){
        ver_histograma(foto_activa(),primera_libre(),2);
    }
}




void MainWindow::on_actionVerde_triggered()
{
    if(foto_activa()!=-1 && primera_libre()!=-1){
        ver_histograma(foto_activa(),primera_libre(),1);
    }
}

void MainWindow::on_actionBajorrelieve_triggered()
{
    if(foto_activa()!=-1 && primera_libre()!=-1){
        Bajorrelieve b(foto_activa());
        b.exec();
    }
}

void MainWindow::on_actionAjuste_lineal_triggered()
{
    if(foto_activa()!=-1){
        Ajustelineal al(foto_activa());
        al.exec();
    }
}

void MainWindow::on_actionCapturar_de_video_triggered()
{
    QString nombre=QFileDialog::getOpenFileName();
    if(!nombre.isEmpty()){
        Capturarvideo cv(nombre);
        cv.exec();
    }
}


void MainWindow::on_actionEscala_de_color_triggered()
{
    if(foto_activa()!=-1 && primera_libre()!=-1){
        escala_color(foto_activa(),primera_libre());
    }
}

void MainWindow::on_actionPinchar_Estirar_triggered()
{
    if(foto_activa()!=-1 ){
        pinchar_estirar pe(foto_activa());
        pe.exec();
    }
}

void MainWindow::on_actionMatiz_saturaci_n_luminosidad_triggered()
{
    if(foto_activa()!=-1 ){

        Matsatlum msl(foto_activa());
        msl.exec();

    }


}

void MainWindow::on_actionPerfilar_triggered()
{
    if(foto_activa()!=-1 ){

        Perfilado pf(foto_activa());
        pf.exec();
    }
}

void MainWindow::on_actionPerspectiva_triggered()
{
    if(foto_activa()!=-1){
        Perspectiva p;
        p.exec();
    }
}

void MainWindow::on_actionMovimiento_triggered()
{
    if(primera_libre()!=-1){

        QString nombre=QFileDialog::getOpenFileName();
        if(nombre.isEmpty()){

            Movimiento mv(nombre,primera_libre());
            if(mv.isOpened())
                mv.exec();

        }

    }
}

void MainWindow::on_actionCopiar_triggered()
{
    herr_actual=HER_COPIAR;
}

void MainWindow::on_actionColor_Falso_triggered()
{
    if(foto_activa()!=-1 && primera_libre()!=-1){
        Color_falso c(foto_activa());
        c.exec();
    }
}

void MainWindow::on_actionRellenar_triggered()
{
    ui->toolButton_10->setChecked(true);
    herr_actual=HER_RELLENAR;
}

void MainWindow::on_actionBalance_de_blancos_triggered()
{
    if(foto_activa()!=-1 && primera_libre()!=-1){
        ver_balance_blancos(foto_activa());
    }
}

void MainWindow::on_actionEcualizacion_del_histograma_triggered()
{
    int canales[3]={0,1};
    if(foto_activa()!=-1 && primera_libre()!=-1){
        Ecualizar_histograma e(foto_activa(),primera_libre());
        e.exec();
    }
}

void MainWindow::on_actionEspectro_de_intensidad_triggered()
{
    if(foto_activa()!=-1 && primera_libre()!=-1){
        espectro_imagen(foto_activa(),primera_libre());
    }
}

void MainWindow::on_actionTrazos_triggered()
{
     ui->toolButton_10->setChecked(true);
    herr_actual=HER_TRAZAR;
}

void MainWindow::on_actionEcualizacion_local_triggered()
{
    int canales[3]={0,1,2};
    if(foto_activa()!=-1 && primera_libre()!=-1){
        //ecualizar_histograma_local(foto_activa(),primera_libre(),canales,3,true);
        Ecualizacion_local e(foto_activa());
        e.exec();
    }
}

void MainWindow::on_actionCambiar_modelo_de_color_triggered()
{

    if(foto_activa()!=-1){
        Modelo_color m(foto_activa());
        m.exec();
    }

}

void MainWindow::on_actionCopiar_a_portapapeles_triggered()
{
    if(foto_activa()!=-1){
       copiar_portapapeles(foto_activa());
    }
}

void MainWindow::on_actionRotar_y_reescalar_triggered()
{
    if(foto_activa()!=-1 && primera_libre()!=-1){

        rotar_escalar r(foto_activa());
        r.exec();
    }

}
void MainWindow::on_actionAjuste_rojo_azul_verde_triggered()
{
    if(foto_activa()!=-1 && primera_libre()!=-1){
        Ajuste_rojo_verde_azul a(foto_activa());
        a.exec();
    }
}


void MainWindow::on_actionElipse_triggered()
{
    ui->toolButton_9->setChecked(true);
    herr_actual=HER_ELIPSE;

}

void MainWindow::on_toolButton_9_clicked()
{
    herr_actual=HER_ELIPSE;
}

void MainWindow::on_toolButton_10_clicked()
{
    herr_actual=HER_TRAZAR;
}

void MainWindow::on_toolButton_11_clicked()
{
     herr_actual=HER_RELLENAR;
}

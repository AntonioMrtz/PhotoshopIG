//---------------------------------------------------------------------------

#include "imagenes.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QFileDialog>
#include <QClipboard>
#include <assert.h>

///////////////////////////////////////////////////////////////////
/////////  VARIABLES GLOBALES                        //////////////
///////////////////////////////////////////////////////////////////

ventana foto[MAX_VENTANAS];

tipo_herramienta herr_actual= HER_PUNTO;

int radio_pincel= 10;

Scalar color_pincel= CV_RGB(255, 255, 255);

int difum_pincel= 10;

bool preguntar_guardar= true;

bool imagen_copiada = false;

Mat imagen_a_copiar;

Point punto_anterior=Point(-1,-1);

static int numpos= 0; // Número actual en el orden de posición de las ventanas


///////////////////////////////////////////////////////////////////
/////////  FUNCIONES DE MANEJO DE VENTANAS           //////////////
///////////////////////////////////////////////////////////////////

void callback (int event, int x, int y, int flags, void *_nfoto);

//---------------------------------------------------------------------------

void inic_fotos (void)
{
    for (int i= 0; i<MAX_VENTANAS; i++)
        foto[i].usada= false;
}

//---------------------------------------------------------------------------

void fin_fotos (void)
{
    for (int i= 0; i<MAX_VENTANAS; i++) {
        if (foto[i].usada) {
            destroyWindow(foto[i].nombre);
            foto[i].usada= false;
        }
    }
}

//---------------------------------------------------------------------------

int primera_libre (void)
{
    for (int i= 0; i<MAX_VENTANAS; i++)
        if (!foto[i].usada)
            return i;
    return -1;
}

//---------------------------------------------------------------------------

void escribir_barra_estado (void)
{
    int usadas, modificadas;
    num_fotos(usadas, modificadas);
    w->setStatusBarText(QString::number(usadas)+" fotos abiertas, "+
                        QString::number(modificadas)+" modificadas.");
}

//---------------------------------------------------------------------------

void crear_nueva (int nfoto, int ancho, int alto, Scalar color)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && !foto[nfoto].usada);
    foto[nfoto].nombre= "nueva-"+to_string(nfoto)+".png";
    foto[nfoto].nombref= foto[nfoto].nombre;
    foto[nfoto].img.create(alto, ancho, CV_8UC3);
    foto[nfoto].img=  color;
    namedWindow(foto[nfoto].nombre, WINDOW_NO_POPUP+WINDOW_MOVE_RIGHT);
    foto[nfoto].orden= numpos++;
    imshow(foto[nfoto].nombre, foto[nfoto].img);
    foto[nfoto].usada= true;
    foto[nfoto].modificada= true;
    foto[nfoto].roi= Rect(0, 0, ancho, alto);
    setMouseCallback(foto[nfoto].nombre, callback, reinterpret_cast<void*>(nfoto));
    escribir_barra_estado();
}

//---------------------------------------------------------------------------

void crear_nueva (int nfoto, Mat img)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && !foto[nfoto].usada && !img.empty());
    foto[nfoto].nombre= "nueva-"+to_string(nfoto)+".png";
    foto[nfoto].nombref= foto[nfoto].nombre;
    foto[nfoto].img= img;
    namedWindow(foto[nfoto].nombre, WINDOW_NO_POPUP+WINDOW_MOVE_RIGHT);
    foto[nfoto].orden= numpos++;
    imshow(foto[nfoto].nombre, foto[nfoto].img);
    foto[nfoto].usada= true;
    foto[nfoto].modificada= true;
    foto[nfoto].roi= Rect(0, 0, img.cols, img.rows);
    setMouseCallback(foto[nfoto].nombre, callback, reinterpret_cast<void*>(nfoto));
    escribir_barra_estado();
}

//---------------------------------------------------------------------------

void crear_nueva (int nfoto, string nombre)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && !foto[nfoto].usada);
    foto[nfoto].nombre= nombre;
    foto[nfoto].nombref= Lt1(nombre);
    foto[nfoto].img= imread(foto[nfoto].nombref);
    if (foto[nfoto].img.empty())
        return;
    namedWindow(foto[nfoto].nombre, WINDOW_NO_POPUP+WINDOW_MOVE_RIGHT);
    foto[nfoto].orden= numpos++;
    imshow(foto[nfoto].nombre, foto[nfoto].img);
    foto[nfoto].usada= true;
    foto[nfoto].modificada= false;
    foto[nfoto].roi= Rect(0, 0, foto[nfoto].img.cols, foto[nfoto].img.rows);
    setMouseCallback(foto[nfoto].nombre, callback, reinterpret_cast<void*>(nfoto));
    escribir_barra_estado();
}

//---------------------------------------------------------------------------

void guardar_foto (int nfoto, string nombre)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada);
    foto[nfoto].modificada= false;
    // 1. Guardar la imagen con el mismo nombre que tiene
    if (nombre=="")
        imwrite(foto[nfoto].nombref, foto[nfoto].img);
    // 2. Guardar la imagen con un nombre distinto al actual
    else {
        imwrite(Lt1(nombre), foto[nfoto].img);
        setWindowTitle(foto[nfoto].nombre, nombre);
    }
    escribir_barra_estado();
}

//---------------------------------------------------------------------------

void cerrar_foto (int nfoto, bool destruir_ventana)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada);
    if (destruir_ventana)
        destroyWindow(foto[nfoto].nombre);
    foto[nfoto].usada= false;
    escribir_barra_estado();
}

//---------------------------------------------------------------------------

void mostrar (int nfoto)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada);
    imshow(foto[nfoto].nombre, foto[nfoto].img);
    escribir_barra_estado();
}

//---------------------------------------------------------------------------

int nombre_a_numero (string nombre)
{
    for (int i= 0; i<MAX_VENTANAS; i++)
        if (foto[i].usada && foto[i].nombre==nombre)
            return i;
    return -1;
}

//---------------------------------------------------------------------------

int foto_activa (void)
{
    int maxorden= -1, maxpos= -1;
    for (int i= 0; i<MAX_VENTANAS; i++) {
        if (foto[i].usada && foto[i].orden>maxorden) {
            maxorden= foto[i].orden;
            maxpos= i;
        }
    }
    return maxpos;
}

//---------------------------------------------------------------------------

int num_fotos (int &usadas, int &modificadas)
{
    usadas= 0;
    modificadas= 0;
    for (int i= 0; i<MAX_VENTANAS; i++) {
        if (foto[i].usada) {
            usadas++;
            if (foto[i].modificada)
                modificadas++;
        }
    }
    return usadas;
}

//---------------------------------------------------------------------------

void set_callback_foto (int nfoto, bool activo)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada);
    if (!activo)
        setMouseCallback(foto[nfoto].nombre, nullptr);
    else
        setMouseCallback(foto[nfoto].nombre, callback, reinterpret_cast<void*>(nfoto));
}

///////////////////////////////////////////////////////////////////
/////////  FUNCIONES DEL CALLBACK PRINCIPAL          //////////////
///////////////////////////////////////////////////////////////////

static int downx, downy;
// Posición inicial del ratón al pinchar sobre la imagen actual

//---------------------------------------------------------------------------

void ninguna_accion (int factual, int x, int y)
{
    Mat res= foto[factual].img.clone();
    circle(res, Point(x, y), radio_pincel, CV_RGB(255,255,255), 2, LINE_AA);
    imshow(foto[factual].nombre, res);
}

//---------------------------------------------------------------------------

void cb_close (int factual)
{
    if (foto[factual].usada && !foto[factual].img.empty()) {
        if (foto[factual].modificada && preguntar_guardar) {
            QString cadena= "El archivo " + QString::fromStdString(foto[factual].nombre) +
                    " ha sido modificado.\n¿Desea guardarlo?";
            int resp= QMessageBox::question(w, "Archivo modificado", cadena,
                                            QMessageBox::Yes | QMessageBox::No );
            if (resp==QMessageBox::Yes)
                guardar_foto(factual);
        }
        cerrar_foto(factual, false);
    }
}

//---------------------------------------------------------------------------

void cb_punto (int factual, int x, int y)
{
    Mat im= foto[factual].img;  // Ojo: esto no es una copia, sino a la misma imagen
    if (difum_pincel==0)
        circle(im, Point(x, y), radio_pincel, color_pincel, -1, LINE_AA);
    else {
        Mat res(im.size(), im.type(), color_pincel);
        Mat cop(im.size(), im.type(), CV_RGB(0,0,0));
        circle(cop, Point(x, y), radio_pincel, CV_RGB(255,255,255), -1, LINE_AA);
        blur(cop, cop, Size(difum_pincel*2+1, difum_pincel*2+1));
        multiply(res, cop, res, 1.0/255.0);
        bitwise_not(cop, cop);
        multiply(im, cop, im, 1.0/255.0);
        im= res + im;
    }
    imshow(foto[factual].nombre, im);
    foto[factual].modificada= true;
}

//---------------------------------------------------------------------------

void cb_linea (int factual, int x, int y)
{
    Mat im= foto[factual].img;  // Ojo: esto no es una copia, sino a la misma imagen
    if (difum_pincel==0)
        line(im, Point(downx, downy), Point(x,y), color_pincel, radio_pincel*2+1);
    else {
        Mat res(im.size(), im.type(), color_pincel);
        Mat cop(im.size(), im.type(), CV_RGB(0,0,0));
        line(cop, Point(downx, downy), Point(x,y), CV_RGB(255,255,255), radio_pincel*2+1);
        blur(cop, cop, Size(difum_pincel*2+1, difum_pincel*2+1));
        multiply(res, cop, res, 1.0/255.0);
        bitwise_not(cop, cop);
        multiply(im, cop, im, 1.0/255.0);
        im= res + im;
    }
    imshow(foto[factual].nombre, im);
    foto[factual].modificada= true;
}

//---------------------------------------------------------------------------

void cb_trazo (int factual, int x, int y)
{
    qDebug("%d %d",x,y);
    Mat im= foto[factual].img;  // Ojo: esto no es una copia, sino a la misma imagen
    if(punto_anterior.x>-1){
        if (difum_pincel==0)
            line(im, punto_anterior, Point(x,y), color_pincel, radio_pincel*2+1);
        else {
            Mat res(im.size(), im.type(), color_pincel);
            Mat cop(im.size(), im.type(), CV_RGB(0,0,0));
            line(cop, punto_anterior, Point(x,y), CV_RGB(255,255,255), radio_pincel*2+1);
            blur(cop, cop, Size(difum_pincel*2+1, difum_pincel*2+1));
            multiply(res, cop, res, 1.0/255.0);
            bitwise_not(cop, cop);
            multiply(im, cop, im, 1.0/255.0);
            im= res + im;
        }
    }else{
        cb_punto(factual,x,y);
    }
    punto_anterior=Point(x,y);
    imshow(foto[factual].nombre, im);
    foto[factual].modificada= true;
}

//---------------------------------------------------------------------------

void cb_rectangulo (int factual, int x, int y)
{
    Mat im= foto[factual].img;  // Ojo: esto no es una copia, sino a la misma imagen
    if (difum_pincel==0)
        rectangle(im, Point(downx, downy), Point(x,y), color_pincel, radio_pincel*2-1);
    else {
        Mat res(im.size(), im.type(), color_pincel);
        Mat cop(im.size(), im.type(), CV_RGB(0,0,0));
        rectangle(cop, Point(downx, downy), Point(x,y), CV_RGB(255,255,255), radio_pincel*2-1);
        blur(cop, cop, Size(difum_pincel*2+1, difum_pincel*2+1));
        multiply(res, cop, res, 1.0/255.0);
        bitwise_not(cop, cop);
        multiply(im, cop, im, 1.0/255.0);
        im= res + im;
    }
    imshow(foto[factual].nombre, im);
    foto[factual].modificada= true;
}

//---------------------------------------------------------------------------

void cb_ver_linea (int factual, int x, int y)
{
    Mat res= foto[factual].img.clone();
    line(res, Point(downx, downy), Point(x,y), color_pincel, radio_pincel*2+1);
    imshow(foto[factual].nombre, res);
}

//---------------------------------------------------------------------------

void cb_ver_rectangulo (int factual, int x, int y)
{
    Mat res= foto[factual].img.clone();
    rectangle(res, Point(downx, downy), Point(x,y), color_pincel, radio_pincel*2+1);
    imshow(foto[factual].nombre, res);
}

//---------------------------------------------------------------------------

void cb_seleccionar (int factual, int x, int y)
{
    Mat im= foto[factual].img;
    Rect nuevo= Rect(min(downx, x), min(downy, y),
                     max(downx, x)-min(downx, x)+1, max(downy, y)-min(downy, y)+1);
    if (nuevo.x<0)
        nuevo.x= 0;
    if (nuevo.y<0)
        nuevo.y= 0;
    if (nuevo.x+nuevo.width>im.size().width)
        nuevo.width= im.size().width-nuevo.x;
    if (nuevo.y+nuevo.height>im.size().height)
        nuevo.height= im.size().height-nuevo.y;
    foto[factual].roi= nuevo;
}

//---------------------------------------------------------------------------

void cb_ver_seleccion (int factual, int x, int y, bool foto_roi)
{
    Mat res= foto[factual].img.clone();
    Point p1, p2;
    if (foto_roi) {
        p1.x= foto[factual].roi.x;
        p1.y= foto[factual].roi.y;
        p2.x= foto[factual].roi.x+foto[factual].roi.width-1;
        p2.y= foto[factual].roi.y+foto[factual].roi.height-1;
    }
    else {
        p1= Point(downx, downy);
        p2= Point(x, y);
    }
    rectangle(res, p1, p2, CV_RGB(255,foto_roi?0:255,0),2);
    imshow(foto[factual].nombre, res);
}

//---------------------------------------------------------------------------

void cb_copiar (int factual, int x, int y)
{
    Mat im= foto[factual].img;
    Rect copiarRegion= Rect(min(downx, x), min(downy, y),
                     max(downx, x)-min(downx, x)+1, max(downy, y)-min(downy, y)+1);
    imagen_a_copiar = im(copiarRegion);
}

//---------------------------------------------------------------------------

void cb_pegar (int factual, int x, int y)
{
    Mat im= foto[factual].img;  // Ojo: esto no es una copia, sino a la misma imagen
    Mat destImg;
    int tamX = 400;
    int tamY = 400;
    if(x+400>im.cols){
        tamX=im.cols-x;
    }
    if(y+400>im.rows){
        tamY=im.rows-y;
    }

    resize(imagen_a_copiar,destImg,Size(tamX,tamY),0,0);


    Mat res(Size(tamX,tamY), destImg.type(), color_pincel);
    Mat cop(Size(tamX,tamY), destImg.type(), CV_RGB(0,0,0));
    circle(cop, Point(tamX/2, tamY/2), min(tamX,tamY)/4, CV_RGB(255,255,255), -1, LINE_AA);
    blur(cop, cop, Size(difum_pincel*2+1, difum_pincel*2+1));
    multiply(destImg, cop, destImg, 1.0/255.0);

    Mat nueva2(im.size(), im.type(),CV_RGB(0,0,0));
    Mat nueva(im.size(), im.type(),CV_RGB(0,0,0));
    destImg.copyTo(nueva(Rect(x,y,tamX,tamY)));
    circle(nueva2, Point(x+tamX/2, y+tamY/2), min(tamX,tamY)/4, CV_RGB(255,255,255), -1, LINE_AA);
    bitwise_not(nueva2, nueva2);
    multiply(im, nueva2, im, 1.0/255.0);


    im = nueva + im;
    imshow(foto[factual].nombre, im);
    foto[factual].modificada= true;
}

//---------------------------------------------------------------------------

Scalar ColorArcoIris(){

    static Scalar colorActual= CV_RGB(255,0,0);
    static int estado=0;
    switch(estado){

    case 0:
            colorActual.val[1]+=8;   //TODO OPCIONAL
            if(colorActual.val[1]==255) estado=1;
            break;

    case 1: if(--colorActual.val[2]==0) estado=2;
            break;

    case 2: if (++colorActual.val[0]==255) estado=3;
            break;

    case 3:if (--colorActual.val[1]==0) estado=4;
            break;

    case 4 :if(++colorActual[2]==255) estado=5;
            break;

    case 5: if(--colorActual[0]==0) estado=0;


    }

    return colorActual;
}


void cb_arco_iris (int factual, int x, int y)
{
    Mat im= foto[factual].img;  // Ojo: esto no es una copia, sino a la misma imagen
    if (difum_pincel==0)
        circle(im, Point(x, y), radio_pincel, ColorArcoIris(), -1, LINE_AA);
    else {
        Mat res(im.size(), im.type(), ColorArcoIris());
        Mat cop(im.size(), im.type(), CV_RGB(0,0,0));
        circle(cop, Point(x, y), radio_pincel, CV_RGB(255,255,255), -1, LINE_AA);
        blur(cop, cop, Size(difum_pincel*2+1, difum_pincel*2+1));
        multiply(res, cop, res, 1.0/255.0);
        bitwise_not(cop, cop);
        multiply(im, cop, im, 1.0/255.0);
        im= res + im;
    }
    imshow(foto[factual].nombre, im);
    foto[factual].modificada= true;
}


//---------------------------------------------------------------------------

void callback (int event, int x, int y, int flags, void *_nfoto)
{
    int factual= reinterpret_cast<int>(_nfoto);

    // 1. Eventos y casos especiales
    // 1.1. Evento cerrar ventana
    if (event==EVENT_CLOSE) {
        cb_close(factual);
        return;
    }
    // 1.2. Evento obtiene el foco
    if (event==EVENT_FOCUS) {
        foto[factual].orden= numpos++;
    }
    // 1.3. El ratón se sale de la ventana
    if (x<0 || x>=foto[factual].img.size().width || y<0 || y>=foto[factual].img.size().height){
        punto_anterior= Point(-1,-1);
        return;
     }
    // 1.4. Se inicia la pulsación del ratón
    if (event==EVENT_LBUTTONDOWN) {
        downx= x;
        downy= y;
    }

    if(imagen_copiada && herr_actual!=HER_COPIAR){
        imagen_copiada=false;
    }

    // 2. Según la herramienta actual
    switch (herr_actual) {

    // 2.1. Herramienta PUNTO
    case HER_PUNTO:
        if (flags==EVENT_FLAG_LBUTTON)
            cb_punto(factual, x, y);
        else
            ninguna_accion(factual, x, y);
        break;

        // 2.2. Herramienta LINEA
    case HER_LINEA:
        if (event==EVENT_LBUTTONUP)
            cb_linea(factual, x, y);
        else if (event==EVENT_MOUSEMOVE && flags==EVENT_FLAG_LBUTTON)
            cb_ver_linea(factual, x, y);
        else
            ninguna_accion(factual, x, y);
        break;

        // 2.3. Herramienta SELECCION
    case HER_SELECCION:
        if (event==EVENT_LBUTTONUP)
            cb_seleccionar(factual, x, y);
        else if (event==EVENT_MOUSEMOVE)
            cb_ver_seleccion(factual, x, y, flags!=EVENT_FLAG_LBUTTON);
        break;
        //2.4 Herramienta RECTANGULO
    case HER_RECTANGULO:
        if (event==EVENT_LBUTTONUP)
            cb_rectangulo(factual, x, y);
        else if (event==EVENT_MOUSEMOVE && flags==EVENT_FLAG_LBUTTON)
            cb_ver_rectangulo(factual, x, y);
        else
            ninguna_accion(factual, x, y);
        break;
    case HER_ARCO_IRIS:
        if (flags==EVENT_FLAG_LBUTTON)
            cb_arco_iris(factual, x, y);
        else
            ninguna_accion(factual, x, y);
        break;
    case HER_RELLENAR:
        if (flags==EVENT_FLAG_LBUTTON)
            ver_rellenar(factual, x, y);
        else
            ninguna_accion(factual, x, y);
        break;
    case HER_TRAZAR:
        if (event==EVENT_LBUTTONUP){
            ninguna_accion(factual, x, y);
            punto_anterior= Point(-1,-1);
        }
        else if (event==EVENT_MOUSEMOVE && flags==EVENT_FLAG_LBUTTON)

            cb_trazo(factual,x,y);
        else
            punto_anterior= Point(-1,-1);
            ninguna_accion(factual, x, y);
        break;
    case HER_COPIAR:

        if (event==EVENT_LBUTTONUP){
            qDebug("Button Up");
            if(!imagen_copiada){
                qDebug("copiada");
                cb_copiar(factual, x, y);
                imagen_copiada=true;
            }
            else{
                qDebug("sinCopi");
                cb_pegar(factual, x, y);
            }
        }
        else if (!imagen_copiada && event==EVENT_MOUSEMOVE && flags==EVENT_FLAG_LBUTTON)
            cb_ver_rectangulo(factual, x, y);
        else
            ninguna_accion(factual, x, y);
        break;


    }
    escribir_barra_estado();
}


///////////////////////////////////////////////////////////////////
/////////  FUNCIONES DE PROCESAMIENTO DE IMAGENES    //////////////
///////////////////////////////////////////////////////////////////

void invertir (int nfoto, int nres)
{
    Mat img(foto[nfoto].img.size(), foto[nfoto].img.type());
    bitwise_not(foto[nfoto].img, img);
    crear_nueva(nres, img);
}

//---------------------------------------------------------------------------

void rotar_angulo (Mat imagen, Mat &imgRes, double angulo, double escala, int modo)
{
    double w= imagen.size().width, h= imagen.size().height;
    Size sres;
    if (modo==0) {     // Reescalar con proporción al original
        sres.width= int(w*escala);
        sres.height= int(h*escala);
    }
    else if (modo==1)  // Reescalar y ampliar para caber entera
        sres.width= sres.height= int(sqrt(w*w + h*h)*escala);

    else               // Reescalar y recortar para no mostrar borde
        sres.width= sres.height= int(min(w, h)*escala/sqrt(2.0));
    imgRes.create(sres, imagen.type());
    double sa= sin(angulo*M_PI/180), ca= cos(angulo*M_PI/180);
    double cx= -w/2*ca-h/2*sa, cy= w/2*sa-h/2*ca;
    Mat M= getRotationMatrix2D(Point2f(0,0), angulo, escala);
    M.at<double>(0,2)= sres.width/2+cx*escala;
    M.at<double>(1,2)= sres.height/2+cy*escala;
    imgRes= color_pincel;
    warpAffine(imagen, imgRes, M, sres, INTER_CUBIC);
}

//---------------------------------------------------------------------------

void rotar_exacto (int nfoto, int nres, int grado)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada);
    assert(nres>=0 && nres<MAX_VENTANAS && !foto[nres].usada);
    Mat entrada= foto[nfoto].img;
    Mat salida;
    if (grado == 0)
        salida= entrada.clone();
    else if (grado == 1) {
        transpose(entrada, salida);
        flip(salida, salida, 1);
    }
    else if (grado == 2)
        flip(entrada, salida, -1);
    else if (grado == 3) {
        transpose(entrada, salida);
        flip(salida, salida, 0);
    }
    crear_nueva(nres, salida);
}

//---------------------------------------------------------------------------

void ver_brillo_contraste (int nfoto, double suma, double prod, bool guardar)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada);
    Mat img;
    foto[nfoto].img.convertTo(img, CV_8UC3, prod, suma);
    imshow(foto[nfoto].nombre, img);
    if (guardar) {
        img.copyTo(foto[nfoto].img);
        foto[nfoto].modificada= true;
    }
}

//---------------------------------------------------------------------------

void ver_suavizado (int nfoto, int ntipo, int tamx, int tamy, bool guardar)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada);
    assert(tamx>0 && tamx&1 && tamy>0 && tamy&1);
    Mat img = foto[nfoto].img.clone();
    Rect2d roi = foto[nfoto].roi;
    Mat img2 = img(roi);

    if (ntipo == 1)
        GaussianBlur(img2, img, Size(tamx, tamy), 0);
    else if (ntipo == 2)
        blur(img2, img, Size(tamx, tamy));
    else if (ntipo == 3)
        medianBlur(img2, img, tamx*tamy);

    imshow(foto[nfoto].nombre, img);
    if (guardar) {
        img.copyTo(foto[nfoto].img);
        foto[nfoto].modificada= true;
    }
}

//---------------------------------------------------------------------------

void ver_bajorelieve(int nfoto, double angulo, double grado, int fondo,
                     bool guardar)
{
    QString nombres[4]= {":/imagenes/arena.jpg",":/imagenes/cielo.jpg",":/imagenes/gris_fondo.jpg",":/imagenes/madera.jpg"};
    QImage imq = QImage(nombres[fondo]);
    Mat imgfondo(imq.height(),imq.width(),CV_8UC4,imq.scanLine(0));
    cvtColor(imgfondo,imgfondo,COLOR_RGBA2RGB);
    resize(imgfondo,imgfondo,foto[nfoto].img.size());
    imshow("Fondo",imgfondo);


    Mat gris;
    cvtColor(foto[nfoto].img, gris, COLOR_BGR2GRAY);
    Mat rotada;
    rotar_angulo(gris,rotada,angulo,1.0,1);
    Mat sobel;
    Sobel(rotada,sobel,CV_8U,1,0,3,grado,128);
    rotar_angulo(sobel,rotada,-angulo,1.0,0);
    gris = rotada(Rect((rotada.cols-gris.cols)/2,(rotada.rows-gris.rows)/2,gris.cols,gris.rows));

    Mat array[3] = {gris,gris,gris};
    Mat res;
    merge(array,3,res);

    addWeighted(imgfondo,1.0,res,1.0,-128,res);
    if(guardar){
        crear_nueva(primera_libre(),res);
    }
    else{
        imshow("Bajorrelieve",res);
    }

}

//---------------------------------------------------------------------------

void ver_perspectiva(int nfoto1, int nfoto2, Point2f pt1[], Point2f pt2[], bool guardar)
{
    Mat M = getPerspectiveTransform(pt1,pt2);
    Mat imres = foto[nfoto2].img.clone();
    warpPerspective(foto[nfoto1].img,imres,M,imres.size(),INTER_LINEAR,BORDER_TRANSPARENT);
    imshow("Perspectiva",imres);

    if(guardar){
        imres.copyTo(foto[nfoto2].img);
        foto[nfoto2].modificada=true;
        mostrar(nfoto2);
    }
    else{
        for(int i=0; i<4; i++){
            line(imres,pt2[i],pt2[(i+1)%4], CV_RGB(0,0,0),2);
        }
        for(int i=0; i<4; i++){
            circle(imres,pt2[i], 8 , CV_RGB(0,255,0),-1);
        }
        imshow("Perspectiva", imres);
    }
}

//---------------------------------------------------------------------------

void rotar_y_reescalar(int nfoto, double angulo, double escala,bool guarda){



    Mat img = foto[nfoto].img.clone();
    //Obtenemos el centro para rotar la imagen desde este
    Point2f center(((img.cols-1)/2.0),((img.rows-1)/2.0));
    //Creamos matriz de rotacion que emplearemos para aplicar la rotacion
    Mat M= getRotationMatrix2D(center, -angulo, escala);
    //Creamos un Rectangulo con el tamaño de la imagen aplicandole la escala y se
    //le aplica una rotacion de "angulo" grados
    Rect2f tamanoNecesarioSalida = RotatedRect(Point2f(),Size(escala*img.size().width,escala*img.size().height),angulo).boundingRect2f();
    //Ajustamos la matriz de rotacion al nuevo luegar donde se
    //encuentra el centro, cosa que sabemos gracias al rectangulo
    //calculado anteriormente
    M.at<double>(0,2)+=((tamanoNecesarioSalida.width/2.0)) - img.cols/2.0;
    M.at<double>(1,2)+=((tamanoNecesarioSalida.height/2.0)) - img.rows/2.0;
    Mat res;
    //Aplicamos la matriz de rotacion sobre img obteniendo el resultado deseado
    //especificandole el tamaño de la imagen resultando basandonos en el rectangulo
    //creado anteriormente
    warpAffine(img,res,M,tamanoNecesarioSalida.size());
    imshow("modo 0",res);


    if(guarda){
        res.copyTo(foto[nfoto].img);
        mostrar(nfoto);
        foto[nfoto].modificada=true;
    }


}


void ver_ajuste_lineal (int nfoto, double pmin, double pmax,bool guardar)
{

    Mat gris;
    cvtColor(foto[nfoto].img,gris,COLOR_BGR2GRAY);

    int canales[1]={0};
    int bins[1]={256};
    float rango[2]={0,256};
    const float *rangos[]={rango};
    Mat hist;

    calcHist(&gris,1,canales,noArray(),hist,1,bins,rangos);
    normalize(hist,hist,100,0,NORM_L1);
    double acum=0;
    int vmin=0;

    for(;vmin<256 && acum<pmin;vmin++){

        acum+=hist.at<float>(vmin);
    }

    acum=0;
    int vmax=255;

    for(;vmax>=0 && acum<pmax;vmax--){

        acum+=hist.at<float>(vmax);
    }

    if(vmin>=vmax) vmax=vmin+1;

    double a=255.0/(vmax-vmin);
    double b=-vmin*a;

    Mat res;

    foto[nfoto].img.convertTo(res,CV_8U,a,b);
    imshow(foto[nfoto].nombre,res);

    if(guardar){

        res.copyTo(foto[nfoto].img);
        foto[nfoto].modificada=true;
    }


}

//---------------------------------------------------------------------------

void ver_rellenar(int nfoto, int x, int y)
{

    Mat originalImage = foto[nfoto].img;
    Mat imres = foto[nfoto].img.clone();
    Rect r;

    floodFill(imres,Point(x,y),color_pincel,&r,Scalar(radio_pincel,radio_pincel,radio_pincel),Scalar(radio_pincel,radio_pincel,radio_pincel),FLOODFILL_FIXED_RANGE);
    double transparencia = (difum_pincel+1)/121.0;
    addWeighted(originalImage,transparencia,imres,1-transparencia,0,originalImage);
    foto[nfoto].modificada=true;
}


//---------------------------------------------------------------------------

void escala_color(int nfoto, int nres)
{
    Mat gris;
    cvtColor(foto[nfoto].img,gris,COLOR_BGR2GRAY);
    cvtColor(gris,gris,COLOR_GRAY2BGR);
    Mat lut(1,256,CV_8UC3);
    int vb = color_pincel.val[0];
    int vg = color_pincel.val[1];
    int vr = color_pincel.val[2];
    for(int A=0; A<256;A++){
        //mejora a realizar que este 128 no sea fijo, revisar segun color objetivo
        if(A<128){
            lut.at<Vec3b>(A) = Vec3b(vb*A/128, vg*A/128,vr*A/128);
        }else{
            lut.at<Vec3b>(A) = Vec3b(vb+(255-vb)*(A-128)/128, vg+(255-vg)*(A-128)/128, vr+(255-vr)*(A-128)/128);
        }
    }
    Mat res;
    LUT(gris,lut,res);
    crear_nueva(nres,res);
}

//---------------------------------------------------------------------------

void color_falso(int nfoto, int nres,int type)
{
    Mat res;
    Mat im = foto[nfoto].img;

    // JET = 0
    // WINTER = 1
    // SPRING = 2
    // HSV = 3


    if(type==0)
        applyColorMap(im,res,COLORMAP_JET);

    else if(type==1)
        applyColorMap(im,res,COLORMAP_WINTER);

    else if(type==2)
        applyColorMap(im,res,COLORMAP_SPRING);

    else if(type==3)
        applyColorMap(im,res,COLORMAP_HSV);

    crear_nueva(nres,res);
}

//---------------------------------------------------------------------------

void transformar_modelo_color(int nfoto,int type,bool guardar)
{
    Mat res;
    Mat im = foto[nfoto].img;

    //RGB, HLS, HSV, XYZ, YUV

    if(type==0)

        cvtColor(im,res,COLOR_BGR2RGB);

    else if(type==1)
        cvtColor(im,res,COLOR_BGR2HLS);

    else if(type==2)
        cvtColor(im,res,COLOR_BGR2HSV);

    else if(type==3)
        cvtColor(im,res,COLOR_BGR2XYZ);

    else if(type==4)
        cvtColor(im,res,COLOR_BGR2YUV);

    Mat canales[3];
    split(res,canales);

    imshow("canal 0",canales[0]);
    imshow("canal 1",canales[1]);
    imshow("canal 2",canales[2]);

    if(guardar){
        res.copyTo(foto[nfoto].img);
        mostrar(nfoto);
        foto[nfoto].modificada=true;
    }

}

void ajuste_rojo_verde_azul(int nfoto,double azul,double verde,double rojo,int type,bool guardar){

    Mat img=foto[nfoto].img;
    Mat res;

    Mat canales[3];
    split(img,canales);

    // type 0 = sumar
    // type 1 = multiplicar

    //comprobar no pasarse  de 0 - 255


    if(type==0){

        canales[0]+=azul;
        canales[1]+=verde;
        canales[2]+=rojo;


    }

    else if(type==1){

        canales[0]*=azul;
        canales[1]*=verde;
        canales[2]*=rojo;


    }


    merge(canales,3,res);


   imshow("Ajuste Rojo Azul Verde",res);


   if (guardar) {

       qDebug("holasaddddddddddddddddd");
       imshow(foto[nfoto].nombre, img);

           res.copyTo(foto[nfoto].img);
           foto[nfoto].modificada= true;

   }


}

void copiar_portapapeles(int nfoto){

    Mat img=foto[nfoto].img;
    Mat res;


    QClipboard *clipboard = QApplication::clipboard();
    cvtColor(img, res,COLOR_BGR2RGB); // pasamos a RGB primero porque si no no coge los colores bien
    QImage dest((const uchar *) res.data, res.cols, res.rows, res.step, QImage::Format_RGB888);
    dest.bits(); // enforce deep copy, see documentation // Sacado de internet , si no los valores son corruptos ( se cambian los colores)


    clipboard->setImage(dest); // put current image on the clipboard.

}

void ver_balance_blancos(int nfoto)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada);
    Mat res;
    cvtColor(foto[nfoto].img,res,COLOR_RGB2YCrCb);

    Scalar media = mean(res);
    res+= Scalar( 0 , 128-media[1], 128-media[2]);


    cvtColor(res,res,COLOR_YCrCb2RGB);
    imshow("res",res);

    crear_nueva(primera_libre(),res);


}
//---------------------------------------------------------------------------

void ver_pinchar_estirar_onda(int nfoto, int cx, int cy, double radio, double grado, bool guardar){

    // grado deformacion, fase y frecuencia se necesitarian añadir, centro x y cento y, no modificar grado con radio
    Mat S(foto[nfoto].img.rows, foto[nfoto].img.cols, CV_32FC1);
    for(int y=0;y<S.rows;y++){
        for(int x=0;x<S.cols;x++){
            S.at<float>(y,x)= sin(sqrt((x-cx)*(x-cx)+(y-cy)*(y-cy))/100.0+radio/100.0);
        }
    }
    Mat Gx,Gy;
    Sobel(S,Gx,CV_32F, 1,0,3,grado,0,BORDER_REFLECT);
    Sobel(S,Gy,CV_32F, 0,1,3,grado,0,BORDER_REFLECT);
    multiply(S,Gx,Gx);
    multiply(S,Gy,Gy);


    for(int y=0; y<S.rows;y++)
        for(int x=0;x<S.cols;x++){
            Gx.at<float>(y,x)+=x;
            Gy.at<float>(y,x)+=y;
        }
    Mat res;
    remap(foto[nfoto].img, res, Gx,Gy,INTER_LINEAR,BORDER_REFLECT);
    imshow("Pinchar/Estirar",res);
    if(guardar){
        res.copyTo(foto[nfoto].img);
        mostrar(nfoto);
        foto[nfoto].modificada=true;
    }
}

//---------------------------------------------------------------------------

void ver_pinchar_estirar(int nfoto, int cx, int cy, double radio, double grado, bool guardar){
    Mat S(foto[nfoto].img.rows, foto[nfoto].img.cols, CV_32FC1);
    for(int y=0;y<S.rows;y++){
        for(int x=0;x<S.cols;x++){
            S.at<float>(y,x)= exp(-((x-cx)*(x-cx)+(y-cy)*(y-cy))/(radio*radio));
        }
    }
    Mat Gx,Gy;
    Sobel(S,Gx,CV_32F, 1,0,3,grado,0,BORDER_REFLECT);
    Sobel(S,Gy,CV_32F, 0,1,3,grado,0,BORDER_REFLECT);
    multiply(S,Gx,Gx);
    multiply(S,Gy,Gy);


    for(int y=0; y<S.rows;y++)
        for(int x=0;x<S.cols;x++){
            Gx.at<float>(y,x)+=x;
            Gy.at<float>(y,x)+=y;
        }
    Mat res;
    remap(foto[nfoto].img, res, Gx,Gy,INTER_LINEAR,BORDER_REFLECT);
    imshow("Pinchar/Estirar",res);
    if(guardar){
        res.copyTo(foto[nfoto].img);
        mostrar(nfoto);
        foto[nfoto].modificada=true;
    }
}

//---------------------------------------------------------------------------


void ver_matiz_saturacion_luminosidad(int nfoto,int matiz,double satu,double lumi,bool guardar)
{
    Mat hls;
    cvtColor(foto[nfoto].img,hls,COLOR_BGR2HLS_FULL);
    Mat canales[3];
    split(hls,canales);
    canales[0].convertTo(canales[0],CV_16S,1,matiz);
    bitwise_and(canales[0],255,canales[0]);
    canales[0].convertTo(canales[0],CV_8U);
    canales[1]*=lumi;
    canales[2]+=satu;
    merge(canales,3,hls);
    Mat res;
    cvtColor(hls,res,COLOR_HLS2BGR_FULL);
    imshow(foto[nfoto].nombre,res);
    if(guardar){

        res.copyTo(foto[nfoto].img);
        foto[nfoto].modificada=true;
    }


}

//---------------------------------------------------------------------------


void ver_perfilado(int nfoto,int tam,double grado,bool guardar){

    Mat laplace;
    Laplacian(foto[nfoto].img,laplace,CV_16S,tam,-grado,0,BORDER_REFLECT);

    Mat img16;
    foto[nfoto].img.convertTo(img16,CV_16S);
    img16=img16+laplace;

    Mat res;
    img16.convertTo(res,CV_8U);
    imshow(foto[nfoto].nombre,res);
    if(guardar){

        res.copyTo(foto[nfoto].img);
        foto[nfoto].modificada=true;
    }

}




//---------------------------------------------------------------------------

void media_ponderada (int nf1, int nf2, int nueva, double peso)
{
    assert(nf1>=0 && nf1<MAX_VENTANAS && foto[nf1].usada);
    assert(nf2>=0 && nf2<MAX_VENTANAS && foto[nf2].usada);
    assert(nueva>=0 && nueva<MAX_VENTANAS && !foto[nueva].usada);
    Mat img= foto[nf1].img.clone();
    Mat cop;
    resize(foto[nf2].img, cop, img.size());
    addWeighted(img, peso, cop, 1.0-peso, 0, img);
    crear_nueva(nueva, img);
}

//---------------------------------------------------------------------------

string Lt1(string cadena)
{
    QString temp= QString::fromUtf8(cadena.c_str());
    return temp.toLatin1().data();
}

//---------------------------------------------------------------------------

void ver_histograma(int nfotos,int nres,int canal){



    QImage imq= QImage(":/imagenes/histbase.png");
    Mat imghist(imq.height(),imq.width(),CV_8UC4,imq.scanLine(0));
    cvtColor(imghist, imghist, COLOR_RGBA2RGB);

    Mat gris;
    Mat hist;
    cvtColor(foto[nfotos].img, gris, COLOR_BGR2GRAY);  // Conversión a gris
    int canales[1]= {0};
    int bins[1]= {256};
    float rango[2]= {0, 256};
    const float *rangos[]= {rango};
    double vmin,vmax;

    if(canal==3){

        calcHist(&gris, 1, canales, noArray(), hist, 1, bins, rangos);
    }
    else{

        calcHist(&foto[nfotos].img, 1, &canal, noArray(), hist, 1, bins, rangos);
    }


    minMaxLoc(hist,&vmin,&vmax);
    for (int i= 0; i<256; i++){

        float poshist= 185 - hist.at<float>(i)/vmax*182;
        rectangle(imghist,Point(3+i*391.0/256,185),Point(3+(i+1)*391.0/256,poshist),CV_RGB(canal==2?255:0,canal==1?255:0,canal==0?255:0),-1);
        //qDebug("Celda %d: %g", i, hist.at<float>(i));
    }

    crear_nueva(nres,imghist);
}



//---------------------------------------------------------------------------

void ecualizar_histograma(int nfotos,int nres, int canales[],int numCanales,bool ecualizacionConjunta){

    Mat img = foto[nfotos].img;
    Mat res;

    if(!ecualizacionConjunta)
    {
    vector<Mat> channels;

    split(img,channels);

    for(int i=0;i<numCanales;i++){
        if(canales[i]<4){
            equalizeHist(channels[canales[i]],channels[canales[i]]);
        }
    }
    merge(channels,res);
    }else{
        Mat gris, hist;
        cvtColor(img,gris,COLOR_BGR2GRAY);
        int canales[1]={0}, bins[1]={256};
        float rango[2]={0,256};
        const float *rangos[]={rango};
        calcHist(&gris,1,canales,noArray(),hist,1,bins,rangos);
        hist*= 255.0/norm(hist,NORM_L1);
        Mat lut(1,256,CV_8UC1);
        float acum=0.0;
        for(int i = 0;i<256;i++){
            lut.at<uchar>(0,i)=acum;
            acum+=hist.at<float>(i);
        }
        LUT(img,lut,res);
    }
    crear_nueva(nres,res);
}

void espectro_imagen(int nfotos,int nres){

    //Mat I = imread("D:/Descargas/1.png", IMREAD_GRAYSCALE);
    Mat image = foto[nfotos].img;
    cvtColor(image,image,COLOR_BGR2GRAY);
    Mat escala;
    image.convertTo(escala,CV_32FC1,1.0/255);
    Mat imagenDFT;
    dft(escala, imagenDFT,DFT_COMPLEX_OUTPUT);
    vector<Mat> canales;
    split(imagenDFT,canales);
    pow(canales[0],2,canales[0]);
    pow(canales[1],2,canales[1]);
    pow(canales[0]+canales[1],0.5,imagenDFT);
    Mat res;
    imagenDFT.convertTo(res,CV_8UC1,-1,255);

    int cx = res.cols/2;
    int cy = res.rows/2;
    Mat q0(res, Rect(0, 0, cx, cy));   // Top-Left - Create a ROI per quadrant
    Mat q1(res, Rect(cx, 0, cx, cy));  // Top-Right
    Mat q2(res, Rect(0, cy, cx, cy));  // Bottom-Left
    Mat q3(res, Rect(cx, cy, cx, cy)); // Bottom-Right
    Mat tmp;                           // swap quadrants (Top-Left with Bottom-Right)
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);
    q1.copyTo(tmp);                    // swap quadrant (Top-Right with Bottom-Left)
    q2.copyTo(q1);
    tmp.copyTo(q2);

    imshow("magnitud",res);

//    crear_nueva(nres,I);
}

void ecualizar_histograma_local(int nfotos,int nres, int canales[],int numCanales,bool ecualizacionConjunta){

    Mat img = foto[nfotos].img;
    int vecindad = 50;
    Mat res = foto[nfotos].img.clone();
    Mat hist;
    int bins[1]= {256};
    float rango[2]= {0, 256};
    const float *rangos[]= {rango};

    vector<Mat> channels;
    vector<Mat> channelsRes;
    double percentil=0;
    Point puntoEnPorcion;
    //Dividimos la imagen objetivo en sus distintos canales
    split(res,channelsRes);

    int posInicioX, posInicioY, posAncho, posLargo;
    //Para cada pixel
    for(int i= 0; i< img.cols-1;i++){
        for(int j=0;j<img.rows-1;j++){
            //Porcion de la imagen
            Mat porcionImagen;
            //En esta variable almacenaremos el lugar en el que
            //estara el pixel que estamos tratando dentro de la
            //imagen
            puntoEnPorcion=Point(vecindad,vecindad);
            //Establecemos los valores del rectangulo
            posInicioX=i-vecindad;
            posInicioY=j-vecindad;
            posAncho=vecindad*2;
            posLargo=vecindad*2;
            //Tratamos los valores para que sean validos
            if(posInicioX<0){
                //en caso de modificar esta posicion
                //deberemos cambiar el ancho de la imagen
                //ya que el punto de inicio sera mas cercano
                //al punto a analizar
                //Tambien cambiamos la posicion del pixel dentro
                //del rectangulo
                puntoEnPorcion.x=vecindad+posInicioX;
                posAncho=posAncho+(posInicioX);
                posInicioX=0;
            }
            if(posInicioY<0){
                puntoEnPorcion.y=vecindad+posInicioY;
                posLargo=posLargo+(posInicioY);
                posInicioY=0;
            }
            if((posAncho+posInicioX)>=img.cols){
                posAncho=img.cols-2-posInicioX;
            }
            if((posLargo+posInicioY)>=img.rows){
                posLargo=img.rows-2-posInicioY;
            }

            //Obtenemos la porcion de la imagen
            porcionImagen= img(Rect(posInicioX,posInicioY,posAncho,posLargo));


            if(ecualizacionConjunta){
                //En caso de ser ecualizacion pasamos la seccion de la imagen a
                //Grises y calculamos su histograma
                int canalesGris[1]={0};
                Mat porcionEnGris;
                cvtColor(porcionImagen,porcionEnGris,COLOR_BGR2GRAY);
                calcHist(&porcionEnGris, 1, canalesGris, noArray(), hist, 1, bins, rangos);
            }else{
                //Sino dividimos la porcion de la imagen en sus distintos canales R, G y B
                split(porcionImagen,channels);
            }


            //Iteramos por los distintos canales R, G y B
            for(int can=0;can<numCanales;can++){

                    //Variable usada como contador
                    percentil=0;

                    //Calculamos el histograma de un canal concreto, ya sea R o G o B en caso
                    //de no ser ecualización conjunta, ya que sino emplearemos el histograma
                    //de los grises
                    if(!ecualizacionConjunta){

                        calcHist(&channels[canales[can]], 1, 0, noArray(), hist, 1, bins, rangos);
                    }
                    //Iteramos desde 0 hasta el valor del pixel que estamos tratando Pixel(i,j) del canal R o G o B de la imagen original en "channelRes"
                    for (int bit= 0; bit<=(int)channelsRes[canales[can]].at<uchar>(j,i); bit++){
                        //Sumamos esos valores
                        percentil+= hist.at<float>(bit);

                    }
                    //Dividimos el valor obtenido entre el numero de pixeles del rectangulo ancho+1 * alto+1
                    percentil=percentil/((posLargo+1)*(posAncho+1));

                    //Al canal correspondiente de la imagen de salida se sustituye su valor por percentil*255
                    channelsRes[canales[can]].at<uchar>(j,i)=  (int)(percentil*255);
            }

        }
    }

    //juntamos los canales calculados
    merge(channelsRes,res);


    imshow("nueva",res);
}





























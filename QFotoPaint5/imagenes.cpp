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
        int tam = radio_pincel+difum_pincel;
        int posx= tam, posy=tam;
        Rect roi(x-tam, y-tam, 2*tam+1, 2*tam+1);
        if(roi.x<0){
            roi.width+= roi.x;
            posx+= roi.x;
            roi.x=0;
        }
        if(roi.y<0){
            roi.height+= roi.y;
            posy+= roi.y;
            roi.y=0;
        }
        if(roi.x+roi.width > im.cols){
            roi.width= im.cols-roi.x;
        }
        if(roi.y+roi.height > im.rows){
            roi.height= im.rows -roi.y;
        }

        Mat frag = im(roi);

        Mat res(frag.size(), frag.type(), color_pincel);
        Mat cop(frag.size(), frag.type(), CV_RGB(0,0,0));
        circle(cop, Point(posx, posy), radio_pincel, CV_RGB(255,255,255), -1, LINE_AA);
        blur(cop, cop, Size(difum_pincel*2+1, difum_pincel*2+1));
        multiply(res, cop, res, 1.0/255.0);
        bitwise_not(cop, cop);
        multiply(frag, cop, frag, 1.0/255.0);
        frag= res + frag;
    }
    imshow(foto[factual].nombre, im);
    foto[factual].modificada= true;
}

//---------------------------------------------------------------------------



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

void cb_elipse(int factual, int x, int y)
{
    Mat im= foto[factual].img;  // Ojo: esto no es una copia, sino a la misma imagen
    if (difum_pincel==0)
        ellipse(im, Point(downx, downy), Size(abs(x-downx),abs(y-downy)),0,0,360,color_pincel, radio_pincel*2+1);
    else {
        Mat res(im.size(), im.type(), color_pincel);
        Mat cop(im.size(), im.type(), CV_RGB(0,0,0));
        ellipse(cop, Point(downx, downy), Size(abs(x-downx),abs(y-downy)),0,0,360,CV_RGB(255,255,255), radio_pincel*2+1);
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
    Mat im= foto[factual].img;
    //Si no hay punto anterior dibujamos un punto
    if(punto_anterior.x>-1){
        if (difum_pincel==0)
            line(im, punto_anterior, Point(x,y), color_pincel, radio_pincel*2+1);
        else {
            //Si se quiere realizar suavizado calculamos el ROI para no
            //hacer las operaciones sobre la imagen completa cuando no es
            //necesario
            int tam = radio_pincel+difum_pincel;
            Point nuevoPunto_anterior;
            Point nuevoPunto_actual;
            Point start_Punto = Point(0,0);

            int height, width;
            //Calculos necesarios para obtener el ROI para dibujar
            //la linea
            if(x<punto_anterior.x){
                //el ancho sera la diferencia de ambos puntos mas
                //2 veces el tamano del radio y difuminado aplicados
                width=punto_anterior.x-x+2*tam;
                //La posicion X del punto anterior vendra dado
                //por el ancho menos el tamaño de los efectos del
                //pincel, ya que el rectangulo tiene el tamano justo
                //y sabemos que el punto anterior esta al final.
                nuevoPunto_anterior.x=width-tam;
                //El punto en el que comienza el rectangulo del ROI
                //viene dado por el punto mas a la izquierda menos
                //el tamano de los efectos del pincel
                start_Punto.x=x-tam;
                //La posicion x del punto actual vendra dado por la
                //posicion inicial del rectangulo que es siempre 0
                //mas el tamano de los efectos del pincel
                nuevoPunto_actual.x=0+tam;
                //Tenemos que tratar que el rectangulo quede fuera
                //de la imagen
                if(width+start_Punto.x>im.cols){
                    width=im.cols-start_Punto.x;
                    nuevoPunto_anterior.x=width-tam;
                }
            }else{
                width=x-punto_anterior.x+2*tam;
                nuevoPunto_actual.x=width-tam;
                start_Punto.x=punto_anterior.x-tam;
                nuevoPunto_anterior.x=0+tam;
                if(width+start_Punto.x>im.cols){
                    width=im.cols-start_Punto.x;
                    nuevoPunto_actual.x=width-tam;
                }
            }

            //En caso de que se salga fuera de la imagen original
            //deberemos tenerlo en cuenta para la posicion de los
            //puntos en el nuevo rectangulo
            if(start_Punto.x<0){
                nuevoPunto_actual.x+=start_Punto.x;
                nuevoPunto_anterior.x+=start_Punto.x;
                start_Punto.x=0;
            }


            if(y<punto_anterior.y){
                start_Punto.y=y-tam;
                height=punto_anterior.y-y+2*tam;
                nuevoPunto_anterior.y=height-tam;
                nuevoPunto_actual.y=0+tam;
                if(height+start_Punto.y>im.rows){
                    height=im.rows-start_Punto.y;
                    nuevoPunto_anterior.y=height-tam;
                }
            }else{
                start_Punto.y=punto_anterior.y-tam;
                height=y-punto_anterior.y+2*tam;
                nuevoPunto_actual.y=height-tam;
                nuevoPunto_anterior.y=0+tam;
                if(height+start_Punto.y>im.rows){
                    height=im.rows-start_Punto.y;
                    nuevoPunto_actual.y=height-tam;
                }
            }


            if(start_Punto.y<0){
                nuevoPunto_actual.y+=start_Punto.y;
                nuevoPunto_anterior.y+=start_Punto.y;
                start_Punto.y=0;
            }

            //Creamos el rectangulo basandonos en los calculos
            //realizados
            Rect roi(start_Punto.x,start_Punto.y,width,height);
            Mat frag = im(roi);
            //Hacemos los calculos sobre el fragmento de la imagen
            //en vez de la imagen completa
            Mat res(frag.size(), frag.type(), color_pincel);
            Mat cop(frag.size(), frag.type(), CV_RGB(0,0,0));
            line(cop, nuevoPunto_anterior, nuevoPunto_actual, CV_RGB(255,255,255), radio_pincel*2+1);
            blur(cop, cop, Size(difum_pincel*2+1, difum_pincel*2+1));
            multiply(res, cop, res, 1.0/255.0);
            bitwise_not(cop, cop);
            multiply(frag, cop, frag, 1.0/255.0);
            frag= res + frag;
        }
    }else{
        cb_punto(factual,x,y);
    }
    //Actualizamos el nuevo punto anterior
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


void cb_ver_elipse(int factual, int x, int y)
{
    Mat res= foto[factual].img.clone();
    ellipse(res, Point(downx, downy), Size(abs(x-downx),abs(y-downy)),0,0,360,color_pincel, radio_pincel*2+1);
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
    int incr=8;
    switch(estado){

    case 0:
            colorActual.val[1]+=incr;   //TODO OPCIONAL
            if(colorActual.val[1]>=255) estado=1;
            break;

    case 1:
        colorActual.val[2]-=incr;
        if(colorActual.val[2]<=0) estado=2;
            break;

    case 2:
        colorActual.val[0]+=incr;
        if(colorActual.val[0]>=255) estado=3;
            break;

    case 3:
        colorActual.val[1]-=incr;
        if(colorActual.val[1]<=0) estado=4;
            break;

    case 4 :
        colorActual.val[2]+=incr;
        if(colorActual.val[2]>=255) estado=5;
            break;
    case 5:
        colorActual.val[0]-=incr;
        if(colorActual.val[0]<=0) estado=0;
            break;
    }

    return colorActual;
}


void cb_arco_iris (int factual, int x, int y)
{
    Mat im= foto[factual].img;  // Ojo: esto no es una copia, sino a la misma imagen
    if (difum_pincel==0)
        circle(im, Point(x, y), radio_pincel, ColorArcoIris(), -1, LINE_AA);
    else {
        int tam = radio_pincel+difum_pincel;
        int posx= tam, posy=tam;
        Rect roi(x-tam, y-tam, 2*tam+1, 2*tam+1);
        if(roi.x<0){
            roi.width+= roi.x;
            posx+= roi.x;
            roi.x=0;
        }
        if(roi.y<0){
            roi.height+= roi.y;
            posy+= roi.y;
            roi.y=0;
        }
        if(roi.x+roi.width > im.cols){
            roi.width= im.cols-roi.x;
        }
        if(roi.y+roi.height > im.rows){
            roi.height= im.rows -roi.y;
        }

        Mat frag = im(roi);

        Mat res(frag.size(), frag.type(), ColorArcoIris());
        Mat cop(frag.size(), frag.type(), CV_RGB(0,0,0));
        circle(cop, Point(posx, posy), radio_pincel, CV_RGB(255,255,255), -1, LINE_AA);
        blur(cop, cop, Size(difum_pincel*2+1, difum_pincel*2+1));
        multiply(res, cop, res, 1.0/255.0);
        bitwise_not(cop, cop);
        multiply(frag, cop, frag, 1.0/255.0);
        frag= res + frag;
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
        else if ((event==EVENT_MOUSEMOVE || event==EVENT_LBUTTONDOWN) && flags==EVENT_FLAG_LBUTTON)

            cb_trazo(factual,x,y);
        else
            punto_anterior= Point(-1,-1);
            ninguna_accion(factual, x, y);
        break;

    case HER_ELIPSE:

        if (event==EVENT_LBUTTONUP)
            cb_elipse(factual, x, y);
        else if (event==EVENT_MOUSEMOVE && flags==EVENT_FLAG_LBUTTON)
            cb_ver_elipse(factual, x, y);
        else
            ninguna_accion(factual, x, y);
        break;
    case HER_COPIAR:

        if (event==EVENT_LBUTTONUP){
            if(!imagen_copiada){
                cb_copiar(factual, x, y);
                imagen_copiada=true;
            }
            else{
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
        medianBlur(img2, img, min(tamx,301));

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
    //Usamos "floodFill", funcion que inunda los pixeles con el color del pincel
    //a partir del punto indicado si los valores proximos estan dentro del rango
    //de tolerancia
    floodFill(imres,Point(x,y),color_pincel,&r,Scalar(radio_pincel,radio_pincel,radio_pincel),Scalar(radio_pincel,radio_pincel,radio_pincel),FLOODFILL_FIXED_RANGE);
    //Calculamos el porcentaje(de 0 a 1)
    double transparencia = (difum_pincel+1)/121.0;
    //Con el porcentaje de transparencia juntamos la imagen original y la obtenida
    //tras aplicarle "floodFill"
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

    // Mostramos los diferentes valores de los canales en el nuevo tipo de imagen

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

void ajuste_rojo_verde_azul(int nfoto,double azul,double verde,double rojo,int type[],bool guardar){

    Mat img=foto[nfoto].img;
    Mat res;

    Mat canales[3];
    split(img,canales);

    // type 0 = sumar
    // type 1 = multiplicar

    // ajustamos el canal dependiendo del valor de entrada


    if(type[0]==0){
       //canales[0].convertTo(canales[0], CV_8UC3,1, azul);
        canales[0]+=azul;
    }else{
        //canales[0].convertTo(canales[0], CV_8UC3,azul, 0);
        canales[0]*=azul;
    }

    if(type[1]==0){
        //canales[1].convertTo(canales[1], CV_8UC3,1, verde);
        canales[1]+=verde;
    }else{
        //canales[1].convertTo(canales[1], CV_8UC3,verde, 0);
        canales[1]*=verde;
    }

    if(type[2]==0){
        //canales[2].convertTo(canales[2], CV_8UC3,1, rojo);
        canales[2]+=rojo;
    }else{
        //canales[2].convertTo(canales[2], CV_8UC3,rojo, 0);
        canales[2]*=rojo;
    }

    // juntamos los canales para formar la imagen
    merge(canales,3,res);


   imshow("Ajuste Rojo Azul Verde",res);


   if (guardar) {

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
    // obtenemos la imagen en el formato YCrCb para poder manejar los canales Cr y Cb ( luminancia rojo y azul )
    cvtColor(foto[nfoto].img,res,COLOR_RGB2YCrCb);

    // obtenemos la media de los canales y ajustamos los canales para que tengan un valor de 128-media_canal
    Scalar media = mean(res);
    res+= Scalar( 0 , 128-media[1], 128-media[2]);


    cvtColor(res,res,COLOR_YCrCb2RGB);

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

    }

    crear_nueva(nres,imghist);
}



//---------------------------------------------------------------------------

void ecualizar_histograma(int nfotos,int nres, int canales[],int numCanales,bool ecualizacionConjunta){

    Mat img = foto[nfotos].img;
    Mat res;

    //Si no es ecualizacion conjunta tratamos los canales por separado
    if(!ecualizacionConjunta)
    {
    vector<Mat> channels;
    //separamos los distintos canales de la imagen original
    split(img,channels);
    //Ecualizamos cada uno de los canales indicados en el array
    //"canales" usando la funcion "equalizeHist" de openCV
    for(int i=0;i<numCanales;i++){
        if(canales[i]<4){
            equalizeHist(channels[canales[i]],channels[canales[i]]);
        }
    }
    //Volvemos a juntar los canales separados
    merge(channels,res);
    }else{
        Mat gris, hist;
        //Convertimos la imagen a grises, teniendo solo 1 canal
        cvtColor(img,gris,COLOR_BGR2GRAY);
        //Definimos los parametros para el calculo del histograma
        int canales[1]={0}, bins[1]={256};
        float rango[2]={0,256};
        const float *rangos[]={rango};
        //Calculamos el histograma de grises
        calcHist(&gris,1,canales,noArray(),hist,1,bins,rangos);
        //escalamos los valores con 255/(número de pixeles de la imagen)
        hist*= 255.0/norm(hist,NORM_L1);
        Mat lut(1,256,CV_8UC1);
        float acum=0.0;
        //Calculamos los valores de la matriz para calcular la funcion de
        //ecualizacion del histograma
        for(int i = 0;i<256;i++){
            lut.at<uchar>(0,i)=acum;
            acum+=hist.at<float>(i);
        }
        //Aplicamos esa funcion a la imagen objetibo
        LUT(img,lut,res);
    }
    crear_nueva(nres,res);
}

void espectro_imagen(int nfotos,int nres){

    Mat image = foto[nfotos].img;
    //Convertimos a escala de grises la imagen
    cvtColor(image,image,COLOR_BGR2GRAY);
    Mat escala;
    // convertimos a 32 bits con un solo canal
    //y ajustamos los valores entre 0.0 y 1.0
    //al dividir entre 255
    image.convertTo(escala,CV_32FC1,1.0/255);
    Mat imagenDFT;
    //Obtenemos la transformada de Fourier indicando
    //que estamos operando con una senal compleja,
    //retornando una imagen compleja
    dft(escala, imagenDFT,DFT_COMPLEX_OUTPUT);
    vector<Mat> canales;
    //Dividimos los canales obtenidos separando
    //la parte real de la imaginaria
    split(imagenDFT,canales);
    //Realizamos el modulo de la parte real e imaginaria
    //destacando las frecuencias mas elevadas obteniendo
    //la magnitud de la transformada
    pow(canales[0],2,canales[0]);
    pow(canales[1],2,canales[1]);
    pow(canales[0]+canales[1],0.5,imagenDFT);
    Mat res;
    //Convertimos la imagen a una con valores de
    //8 bits, obteniend valores entre 0 y 255
    imagenDFT.convertTo(res,CV_8UC1,-1,255);


    //Por ultimo centramos los resultados obtenidos
    int cx = res.cols/2;
    int cy = res.rows/2;
    // Arriba a la izquierda
    Mat arribaIzq(res, Rect(0, 0, cx, cy));
    // Arriba a la derecha
    Mat arribaDer(res, Rect(cx, 0, cx, cy));
    // Abajo a la izquierda
    Mat abajoIzq(res, Rect(0, cy, cx, cy));
    // Abajo a la derecha
    Mat abajoDer(res, Rect(cx, cy, cx, cy));
    Mat tmp;
    // Cambiar estos rectangulos de lugar
    arribaIzq.copyTo(tmp);
    abajoDer.copyTo(arribaIzq);
    tmp.copyTo(abajoDer);
    arribaDer.copyTo(tmp);
    abajoIzq.copyTo(arribaDer);
    tmp.copyTo(abajoIzq);

    crear_nueva(nres,res);
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





























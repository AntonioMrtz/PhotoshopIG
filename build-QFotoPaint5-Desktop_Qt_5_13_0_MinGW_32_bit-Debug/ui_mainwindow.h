/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNueva_imagen;
    QAction *actionAbrir_imagen;
    QAction *actionGuardar;
    QAction *actionGuardar_como;
    QAction *actionCerrar;
    QAction *actionSalir;
    QAction *actionPunto;
    QAction *actionLinea;
    QAction *actionSeleccionar;
    QAction *actionSeleccionar_todo;
    QAction *actionColor_del_pincel;
    QAction *actionPreguntar_si_guardar;
    QAction *actionBrillo_contraste;
    QAction *actionInvertir;
    QAction *actionRotar_90;
    QAction *actionRotar_91;
    QAction *actionMedia_ponderada;
    QAction *actionRotar_180;
    QAction *actionGausiano;
    QAction *actionMedia;
    QAction *actionV_deo_a_video;
    QAction *actionRotar_imagen;
    QAction *actionAcerca_de;
    QAction *actionImagen_media;
    QAction *actionRectangulo;
    QAction *actionMediana;
    QAction *actionCopiar_a_nueva;
    QAction *actionCaptura_de_c_mara;
    QAction *actionArcoiris;
    QAction *actionGrises;
    QAction *actionVerde;
    QAction *actionRojo;
    QAction *actionAzul;
    QAction *actionBajorrelieve;
    QAction *actionAjuste_lineal;
    QAction *actionCapturar_de_video;
    QAction *actionEscala_de_color;
    QAction *actionPinchar_Estirar;
    QAction *actionMatiz_saturaci_n_luminosidad;
    QAction *actionPerfilar;
    QAction *actionPerspectiva;
    QAction *actionMovimiento;
    QAction *actionCopiar;
    QAction *actionColor_Falso;
    QAction *actionRellenar;
    QAction *actionBalance_de_blancos;
    QAction *actionEcualizacion_del_histograma;
    QAction *actionEspectro_de_intensidad;
    QAction *actionTrazos;
    QAction *actionEcualizacion_local;
    QAction *actionCambiar_modelo_de_color;
    QAction *actionCopiar_a_portapapeles;
<<<<<<< HEAD
    QAction *actionRotar_y_reescalar;
=======
    QAction *actionAjuste_rojo_azul_verde;
>>>>>>> 2157d57 (ajustar rojo verde azul interfaz sin guardar imagen)
    QWidget *centralWidget;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QLabel *label;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QSlider *horizontalSlider_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QPushButton *pushButton;
    QToolButton *toolButton_7;
    QToolButton *toolButton_8;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuEdici_n;
    QMenu *menuOpciones;
    QMenu *menuHistograma;
    QMenu *menuHerramientas;
    QMenu *menuTransformar;
    QMenu *menuRotar;
    QMenu *menuEfectos;
    QMenu *menuSuavizado;
    QMenu *menuV_deo;
    QMenu *menuImagen_a_v_deo;
    QMenu *menuV_deo_a_imagen;
    QMenu *menuAyuda;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(544, 140);
        MainWindow->setMinimumSize(QSize(544, 140));
        MainWindow->setMaximumSize(QSize(544, 140));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imagenes/icono.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionNueva_imagen = new QAction(MainWindow);
        actionNueva_imagen->setObjectName(QString::fromUtf8("actionNueva_imagen"));
        actionAbrir_imagen = new QAction(MainWindow);
        actionAbrir_imagen->setObjectName(QString::fromUtf8("actionAbrir_imagen"));
        actionGuardar = new QAction(MainWindow);
        actionGuardar->setObjectName(QString::fromUtf8("actionGuardar"));
        actionGuardar_como = new QAction(MainWindow);
        actionGuardar_como->setObjectName(QString::fromUtf8("actionGuardar_como"));
        actionCerrar = new QAction(MainWindow);
        actionCerrar->setObjectName(QString::fromUtf8("actionCerrar"));
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QString::fromUtf8("actionSalir"));
        actionPunto = new QAction(MainWindow);
        actionPunto->setObjectName(QString::fromUtf8("actionPunto"));
        actionLinea = new QAction(MainWindow);
        actionLinea->setObjectName(QString::fromUtf8("actionLinea"));
        actionSeleccionar = new QAction(MainWindow);
        actionSeleccionar->setObjectName(QString::fromUtf8("actionSeleccionar"));
        actionSeleccionar_todo = new QAction(MainWindow);
        actionSeleccionar_todo->setObjectName(QString::fromUtf8("actionSeleccionar_todo"));
        actionColor_del_pincel = new QAction(MainWindow);
        actionColor_del_pincel->setObjectName(QString::fromUtf8("actionColor_del_pincel"));
        actionPreguntar_si_guardar = new QAction(MainWindow);
        actionPreguntar_si_guardar->setObjectName(QString::fromUtf8("actionPreguntar_si_guardar"));
        actionPreguntar_si_guardar->setCheckable(true);
        actionPreguntar_si_guardar->setChecked(true);
        actionBrillo_contraste = new QAction(MainWindow);
        actionBrillo_contraste->setObjectName(QString::fromUtf8("actionBrillo_contraste"));
        actionInvertir = new QAction(MainWindow);
        actionInvertir->setObjectName(QString::fromUtf8("actionInvertir"));
        actionRotar_90 = new QAction(MainWindow);
        actionRotar_90->setObjectName(QString::fromUtf8("actionRotar_90"));
        actionRotar_91 = new QAction(MainWindow);
        actionRotar_91->setObjectName(QString::fromUtf8("actionRotar_91"));
        actionMedia_ponderada = new QAction(MainWindow);
        actionMedia_ponderada->setObjectName(QString::fromUtf8("actionMedia_ponderada"));
        actionRotar_180 = new QAction(MainWindow);
        actionRotar_180->setObjectName(QString::fromUtf8("actionRotar_180"));
        actionGausiano = new QAction(MainWindow);
        actionGausiano->setObjectName(QString::fromUtf8("actionGausiano"));
        actionMedia = new QAction(MainWindow);
        actionMedia->setObjectName(QString::fromUtf8("actionMedia"));
        actionV_deo_a_video = new QAction(MainWindow);
        actionV_deo_a_video->setObjectName(QString::fromUtf8("actionV_deo_a_video"));
        actionRotar_imagen = new QAction(MainWindow);
        actionRotar_imagen->setObjectName(QString::fromUtf8("actionRotar_imagen"));
        actionAcerca_de = new QAction(MainWindow);
        actionAcerca_de->setObjectName(QString::fromUtf8("actionAcerca_de"));
        actionImagen_media = new QAction(MainWindow);
        actionImagen_media->setObjectName(QString::fromUtf8("actionImagen_media"));
        actionRectangulo = new QAction(MainWindow);
        actionRectangulo->setObjectName(QString::fromUtf8("actionRectangulo"));
        actionMediana = new QAction(MainWindow);
        actionMediana->setObjectName(QString::fromUtf8("actionMediana"));
        actionCopiar_a_nueva = new QAction(MainWindow);
        actionCopiar_a_nueva->setObjectName(QString::fromUtf8("actionCopiar_a_nueva"));
        actionCaptura_de_c_mara = new QAction(MainWindow);
        actionCaptura_de_c_mara->setObjectName(QString::fromUtf8("actionCaptura_de_c_mara"));
        actionArcoiris = new QAction(MainWindow);
        actionArcoiris->setObjectName(QString::fromUtf8("actionArcoiris"));
        actionGrises = new QAction(MainWindow);
        actionGrises->setObjectName(QString::fromUtf8("actionGrises"));
        actionVerde = new QAction(MainWindow);
        actionVerde->setObjectName(QString::fromUtf8("actionVerde"));
        actionRojo = new QAction(MainWindow);
        actionRojo->setObjectName(QString::fromUtf8("actionRojo"));
        actionAzul = new QAction(MainWindow);
        actionAzul->setObjectName(QString::fromUtf8("actionAzul"));
        actionBajorrelieve = new QAction(MainWindow);
        actionBajorrelieve->setObjectName(QString::fromUtf8("actionBajorrelieve"));
        actionAjuste_lineal = new QAction(MainWindow);
        actionAjuste_lineal->setObjectName(QString::fromUtf8("actionAjuste_lineal"));
        actionCapturar_de_video = new QAction(MainWindow);
        actionCapturar_de_video->setObjectName(QString::fromUtf8("actionCapturar_de_video"));
        actionEscala_de_color = new QAction(MainWindow);
        actionEscala_de_color->setObjectName(QString::fromUtf8("actionEscala_de_color"));
        actionPinchar_Estirar = new QAction(MainWindow);
        actionPinchar_Estirar->setObjectName(QString::fromUtf8("actionPinchar_Estirar"));
        actionMatiz_saturaci_n_luminosidad = new QAction(MainWindow);
        actionMatiz_saturaci_n_luminosidad->setObjectName(QString::fromUtf8("actionMatiz_saturaci_n_luminosidad"));
        actionPerfilar = new QAction(MainWindow);
        actionPerfilar->setObjectName(QString::fromUtf8("actionPerfilar"));
        actionPerspectiva = new QAction(MainWindow);
        actionPerspectiva->setObjectName(QString::fromUtf8("actionPerspectiva"));
        actionMovimiento = new QAction(MainWindow);
        actionMovimiento->setObjectName(QString::fromUtf8("actionMovimiento"));
        actionCopiar = new QAction(MainWindow);
        actionCopiar->setObjectName(QString::fromUtf8("actionCopiar"));
        actionColor_Falso = new QAction(MainWindow);
        actionColor_Falso->setObjectName(QString::fromUtf8("actionColor_Falso"));
        actionRellenar = new QAction(MainWindow);
        actionRellenar->setObjectName(QString::fromUtf8("actionRellenar"));
        actionBalance_de_blancos = new QAction(MainWindow);
        actionBalance_de_blancos->setObjectName(QString::fromUtf8("actionBalance_de_blancos"));
        actionEcualizacion_del_histograma = new QAction(MainWindow);
        actionEcualizacion_del_histograma->setObjectName(QString::fromUtf8("actionEcualizacion_del_histograma"));
        actionEspectro_de_intensidad = new QAction(MainWindow);
        actionEspectro_de_intensidad->setObjectName(QString::fromUtf8("actionEspectro_de_intensidad"));
        actionTrazos = new QAction(MainWindow);
        actionTrazos->setObjectName(QString::fromUtf8("actionTrazos"));
        actionEcualizacion_local = new QAction(MainWindow);
        actionEcualizacion_local->setObjectName(QString::fromUtf8("actionEcualizacion_local"));
        actionCambiar_modelo_de_color = new QAction(MainWindow);
        actionCambiar_modelo_de_color->setObjectName(QString::fromUtf8("actionCambiar_modelo_de_color"));
        actionCopiar_a_portapapeles = new QAction(MainWindow);
        actionCopiar_a_portapapeles->setObjectName(QString::fromUtf8("actionCopiar_a_portapapeles"));
<<<<<<< HEAD
        actionRotar_y_reescalar = new QAction(MainWindow);
        actionRotar_y_reescalar->setObjectName(QString::fromUtf8("actionRotar_y_reescalar"));
=======
        actionAjuste_rojo_azul_verde = new QAction(MainWindow);
        actionAjuste_rojo_azul_verde->setObjectName(QString::fromUtf8("actionAjuste_rojo_azul_verde"));
>>>>>>> 2157d57 (ajustar rojo verde azul interfaz sin guardar imagen)
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(40, 0, 41, 41));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imagenes/abrir.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon1);
        toolButton->setIconSize(QSize(32, 32));
        toolButton->setAutoRaise(true);
        toolButton_2 = new QToolButton(centralWidget);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(0, 0, 41, 41));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imagenes/nuevo.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon2);
        toolButton_2->setIconSize(QSize(32, 32));
        toolButton_2->setAutoRaise(true);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 50, 241, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(126, 126, 126);"));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(false);
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 70, 241, 21));
        horizontalSlider->setMaximum(120);
        horizontalSlider->setValue(10);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(10);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(260, 50, 241, 16));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(126, 126, 126);"));
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(false);
        horizontalSlider_2 = new QSlider(centralWidget);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(260, 70, 241, 21));
        horizontalSlider_2->setMaximum(120);
        horizontalSlider_2->setValue(10);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_2->setTickInterval(10);
        toolButton_3 = new QToolButton(centralWidget);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setGeometry(QRect(80, 0, 41, 41));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imagenes/guardar.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon3);
        toolButton_3->setIconSize(QSize(32, 32));
        toolButton_3->setAutoRaise(true);
        toolButton_4 = new QToolButton(centralWidget);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setGeometry(QRect(130, 0, 41, 41));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/imagenes/punto.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon4);
        toolButton_4->setIconSize(QSize(32, 32));
        toolButton_4->setCheckable(true);
        toolButton_4->setChecked(true);
        toolButton_4->setAutoExclusive(true);
        toolButton_5 = new QToolButton(centralWidget);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        toolButton_5->setGeometry(QRect(170, 0, 41, 41));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/imagenes/linea.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon5);
        toolButton_5->setIconSize(QSize(32, 32));
        toolButton_5->setCheckable(true);
        toolButton_5->setAutoExclusive(true);
        toolButton_6 = new QToolButton(centralWidget);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        toolButton_6->setGeometry(QRect(250, 0, 41, 41));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/imagenes/seleccionar.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon6);
        toolButton_6->setIconSize(QSize(32, 32));
        toolButton_6->setCheckable(true);
        toolButton_6->setAutoExclusive(true);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(500, 0, 41, 41));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        toolButton_7 = new QToolButton(centralWidget);
        toolButton_7->setObjectName(QString::fromUtf8("toolButton_7"));
        toolButton_7->setGeometry(QRect(290, 0, 41, 41));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/imagenes/rectangulo.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_7->setIcon(icon7);
        toolButton_7->setCheckable(true);
        toolButton_7->setAutoExclusive(true);
        toolButton_8 = new QToolButton(centralWidget);
        toolButton_8->setObjectName(QString::fromUtf8("toolButton_8"));
        toolButton_8->setGeometry(QRect(210, 0, 41, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 544, 26));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
        menuEdici_n = new QMenu(menuBar);
        menuEdici_n->setObjectName(QString::fromUtf8("menuEdici_n"));
        menuOpciones = new QMenu(menuEdici_n);
        menuOpciones->setObjectName(QString::fromUtf8("menuOpciones"));
        menuHistograma = new QMenu(menuEdici_n);
        menuHistograma->setObjectName(QString::fromUtf8("menuHistograma"));
        menuHerramientas = new QMenu(menuBar);
        menuHerramientas->setObjectName(QString::fromUtf8("menuHerramientas"));
        menuTransformar = new QMenu(menuBar);
        menuTransformar->setObjectName(QString::fromUtf8("menuTransformar"));
        menuRotar = new QMenu(menuTransformar);
        menuRotar->setObjectName(QString::fromUtf8("menuRotar"));
        menuEfectos = new QMenu(menuBar);
        menuEfectos->setObjectName(QString::fromUtf8("menuEfectos"));
        menuSuavizado = new QMenu(menuEfectos);
        menuSuavizado->setObjectName(QString::fromUtf8("menuSuavizado"));
        menuV_deo = new QMenu(menuBar);
        menuV_deo->setObjectName(QString::fromUtf8("menuV_deo"));
        menuImagen_a_v_deo = new QMenu(menuV_deo);
        menuImagen_a_v_deo->setObjectName(QString::fromUtf8("menuImagen_a_v_deo"));
        menuV_deo_a_imagen = new QMenu(menuV_deo);
        menuV_deo_a_imagen->setObjectName(QString::fromUtf8("menuV_deo_a_imagen"));
        menuAyuda = new QMenu(menuBar);
        menuAyuda->setObjectName(QString::fromUtf8("menuAyuda"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menuEdici_n->menuAction());
        menuBar->addAction(menuHerramientas->menuAction());
        menuBar->addAction(menuTransformar->menuAction());
        menuBar->addAction(menuEfectos->menuAction());
        menuBar->addAction(menuV_deo->menuAction());
        menuBar->addAction(menuAyuda->menuAction());
        menuArchivo->addAction(actionNueva_imagen);
        menuArchivo->addAction(actionAbrir_imagen);
        menuArchivo->addAction(actionCapturar_de_video);
        menuArchivo->addAction(actionCaptura_de_c_mara);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionGuardar);
        menuArchivo->addAction(actionGuardar_como);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionCerrar);
        menuArchivo->addAction(actionSalir);
        menuEdici_n->addAction(actionSeleccionar_todo);
        menuEdici_n->addSeparator();
        menuEdici_n->addAction(menuOpciones->menuAction());
        menuEdici_n->addAction(actionCopiar_a_nueva);
        menuEdici_n->addAction(menuHistograma->menuAction());
        menuEdici_n->addAction(actionCopiar_a_portapapeles);
        menuOpciones->addAction(actionColor_del_pincel);
        menuOpciones->addAction(actionPreguntar_si_guardar);
        menuHistograma->addAction(actionGrises);
        menuHistograma->addAction(actionRojo);
        menuHistograma->addAction(actionVerde);
        menuHistograma->addAction(actionAzul);
        menuHerramientas->addAction(actionPunto);
        menuHerramientas->addAction(actionLinea);
        menuHerramientas->addAction(actionRectangulo);
        menuHerramientas->addAction(actionSeleccionar);
        menuHerramientas->addAction(actionArcoiris);
        menuHerramientas->addAction(actionCopiar);
        menuHerramientas->addAction(actionRellenar);
        menuHerramientas->addAction(actionTrazos);
        menuTransformar->addAction(actionBrillo_contraste);
        menuTransformar->addAction(actionInvertir);
        menuTransformar->addAction(menuRotar->menuAction());
        menuTransformar->addAction(actionMatiz_saturaci_n_luminosidad);
        menuTransformar->addAction(actionMedia_ponderada);
        menuTransformar->addAction(actionAjuste_lineal);
        menuTransformar->addAction(actionEscala_de_color);
        menuTransformar->addAction(actionPerspectiva);
        menuTransformar->addAction(actionColor_Falso);
        menuTransformar->addAction(actionEcualizacion_del_histograma);
        menuTransformar->addAction(actionEspectro_de_intensidad);
        menuTransformar->addAction(actionEcualizacion_local);
        menuTransformar->addAction(actionCambiar_modelo_de_color);
<<<<<<< HEAD
        menuTransformar->addAction(actionRotar_y_reescalar);
=======
        menuTransformar->addAction(actionAjuste_rojo_azul_verde);
>>>>>>> 2157d57 (ajustar rojo verde azul interfaz sin guardar imagen)
        menuRotar->addAction(actionRotar_90);
        menuRotar->addAction(actionRotar_180);
        menuRotar->addAction(actionRotar_91);
        menuEfectos->addAction(menuSuavizado->menuAction());
        menuEfectos->addAction(actionPerfilar);
        menuEfectos->addAction(actionBajorrelieve);
        menuEfectos->addAction(actionPinchar_Estirar);
        menuEfectos->addAction(actionBalance_de_blancos);
        menuSuavizado->addAction(actionGausiano);
        menuSuavizado->addAction(actionMedia);
        menuSuavizado->addAction(actionMediana);
        menuV_deo->addAction(menuImagen_a_v_deo->menuAction());
        menuV_deo->addAction(menuV_deo_a_imagen->menuAction());
        menuV_deo->addAction(actionV_deo_a_video);
        menuImagen_a_v_deo->addAction(actionRotar_imagen);
        menuV_deo_a_imagen->addAction(actionImagen_media);
        menuV_deo_a_imagen->addAction(actionMovimiento);
        menuAyuda->addAction(actionAcerca_de);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "QFotoPaint4", nullptr));
        actionNueva_imagen->setText(QCoreApplication::translate("MainWindow", "Nueva imagen...", nullptr));
        actionAbrir_imagen->setText(QCoreApplication::translate("MainWindow", "Abrir imagen...", nullptr));
        actionGuardar->setText(QCoreApplication::translate("MainWindow", "Guardar", nullptr));
        actionGuardar_como->setText(QCoreApplication::translate("MainWindow", "Guardar como...", nullptr));
        actionCerrar->setText(QCoreApplication::translate("MainWindow", "Cerrar", nullptr));
        actionSalir->setText(QCoreApplication::translate("MainWindow", "Salir", nullptr));
        actionPunto->setText(QCoreApplication::translate("MainWindow", "Punto", nullptr));
        actionLinea->setText(QCoreApplication::translate("MainWindow", "L\303\255nea", nullptr));
        actionSeleccionar->setText(QCoreApplication::translate("MainWindow", "Seleccionar", nullptr));
        actionSeleccionar_todo->setText(QCoreApplication::translate("MainWindow", "Seleccionar todo", nullptr));
        actionColor_del_pincel->setText(QCoreApplication::translate("MainWindow", "Color del pincel...", nullptr));
        actionPreguntar_si_guardar->setText(QCoreApplication::translate("MainWindow", "Preguntar si guardar", nullptr));
        actionBrillo_contraste->setText(QCoreApplication::translate("MainWindow", "Brillo/Contraste...", nullptr));
        actionInvertir->setText(QCoreApplication::translate("MainWindow", "Invertir", nullptr));
        actionRotar_90->setText(QCoreApplication::translate("MainWindow", "Rotar 90\302\272", nullptr));
        actionRotar_91->setText(QCoreApplication::translate("MainWindow", "Rotar 270\302\272", nullptr));
        actionMedia_ponderada->setText(QCoreApplication::translate("MainWindow", "Media ponderada...", nullptr));
        actionRotar_180->setText(QCoreApplication::translate("MainWindow", "Rotar 180\302\272", nullptr));
        actionGausiano->setText(QCoreApplication::translate("MainWindow", "Gausiano...", nullptr));
        actionMedia->setText(QCoreApplication::translate("MainWindow", "Media...", nullptr));
        actionV_deo_a_video->setText(QCoreApplication::translate("MainWindow", "V\303\255deo a video", nullptr));
        actionRotar_imagen->setText(QCoreApplication::translate("MainWindow", "Rotar imagen...", nullptr));
        actionAcerca_de->setText(QCoreApplication::translate("MainWindow", "Acerca de...", nullptr));
        actionImagen_media->setText(QCoreApplication::translate("MainWindow", "Imagen media...", nullptr));
        actionRectangulo->setText(QCoreApplication::translate("MainWindow", "Rectangulo", nullptr));
        actionMediana->setText(QCoreApplication::translate("MainWindow", "Mediana", nullptr));
        actionCopiar_a_nueva->setText(QCoreApplication::translate("MainWindow", "Copiar a nueva", nullptr));
        actionCaptura_de_c_mara->setText(QCoreApplication::translate("MainWindow", "Captura de c\303\241mara", nullptr));
        actionArcoiris->setText(QCoreApplication::translate("MainWindow", "Arcoiris", nullptr));
        actionGrises->setText(QCoreApplication::translate("MainWindow", "Grises", nullptr));
        actionVerde->setText(QCoreApplication::translate("MainWindow", "Verde", nullptr));
        actionRojo->setText(QCoreApplication::translate("MainWindow", "Rojo", nullptr));
        actionAzul->setText(QCoreApplication::translate("MainWindow", "Azul", nullptr));
        actionBajorrelieve->setText(QCoreApplication::translate("MainWindow", "Bajorrelieve...", nullptr));
        actionAjuste_lineal->setText(QCoreApplication::translate("MainWindow", "Ajuste lineal", nullptr));
        actionCapturar_de_video->setText(QCoreApplication::translate("MainWindow", "Capturar de video...", nullptr));
        actionEscala_de_color->setText(QCoreApplication::translate("MainWindow", "Escala de color", nullptr));
        actionPinchar_Estirar->setText(QCoreApplication::translate("MainWindow", "Pinchar/Estirar...", nullptr));
        actionMatiz_saturaci_n_luminosidad->setText(QCoreApplication::translate("MainWindow", "Matiz/saturaci\303\263n/luminosidad...", nullptr));
        actionPerfilar->setText(QCoreApplication::translate("MainWindow", "Perfilar...", nullptr));
        actionPerspectiva->setText(QCoreApplication::translate("MainWindow", "Perspectiva...", nullptr));
        actionMovimiento->setText(QCoreApplication::translate("MainWindow", "Movimiento...", nullptr));
        actionCopiar->setText(QCoreApplication::translate("MainWindow", "Copiar", nullptr));
        actionColor_Falso->setText(QCoreApplication::translate("MainWindow", "Color Falso", nullptr));
        actionRellenar->setText(QCoreApplication::translate("MainWindow", "Rellenar", nullptr));
        actionBalance_de_blancos->setText(QCoreApplication::translate("MainWindow", "Balance de blancos", nullptr));
        actionEcualizacion_del_histograma->setText(QCoreApplication::translate("MainWindow", "Ecualizacion del histograma", nullptr));
        actionEspectro_de_intensidad->setText(QCoreApplication::translate("MainWindow", "Espectro de intensidad", nullptr));
        actionTrazos->setText(QCoreApplication::translate("MainWindow", "Trazos", nullptr));
        actionEcualizacion_local->setText(QCoreApplication::translate("MainWindow", "Ecualizacion local", nullptr));
        actionCambiar_modelo_de_color->setText(QCoreApplication::translate("MainWindow", "Cambiar modelo de color", nullptr));
        actionCopiar_a_portapapeles->setText(QCoreApplication::translate("MainWindow", "Copiar a portapapeles", nullptr));
<<<<<<< HEAD
        actionRotar_y_reescalar->setText(QCoreApplication::translate("MainWindow", "Rotar y reescalar", nullptr));
=======
        actionAjuste_rojo_azul_verde->setText(QCoreApplication::translate("MainWindow", "Ajuste rojo/azul/verde", nullptr));
>>>>>>> 2157d57 (ajustar rojo verde azul interfaz sin guardar imagen)
        toolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        toolButton_2->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; color:#ffffff;\">Radio del pincel</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; color:#ffffff;\">Suavizado del pincel</span></p></body></html>", nullptr));
        toolButton_3->setText(QString());
        toolButton_4->setText(QString());
        toolButton_5->setText(QString());
        toolButton_6->setText(QString());
        pushButton->setText(QString());
        toolButton_7->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        toolButton_8->setText(QCoreApplication::translate("MainWindow", "Arcoiris", nullptr));
        menuArchivo->setTitle(QCoreApplication::translate("MainWindow", "Archivo", nullptr));
        menuEdici_n->setTitle(QCoreApplication::translate("MainWindow", "Edici\303\263n", nullptr));
        menuOpciones->setTitle(QCoreApplication::translate("MainWindow", "Opciones", nullptr));
        menuHistograma->setTitle(QCoreApplication::translate("MainWindow", "Histograma", nullptr));
        menuHerramientas->setTitle(QCoreApplication::translate("MainWindow", "Herramientas", nullptr));
        menuTransformar->setTitle(QCoreApplication::translate("MainWindow", "Transformar", nullptr));
        menuRotar->setTitle(QCoreApplication::translate("MainWindow", "Rotar", nullptr));
        menuEfectos->setTitle(QCoreApplication::translate("MainWindow", "Efectos", nullptr));
        menuSuavizado->setTitle(QCoreApplication::translate("MainWindow", "Suavizado", nullptr));
        menuV_deo->setTitle(QCoreApplication::translate("MainWindow", "V\303\255deo", nullptr));
        menuImagen_a_v_deo->setTitle(QCoreApplication::translate("MainWindow", "Imagen a v\303\255deo", nullptr));
        menuV_deo_a_imagen->setTitle(QCoreApplication::translate("MainWindow", "V\303\255deo a imagen", nullptr));
        menuAyuda->setTitle(QCoreApplication::translate("MainWindow", "Ayuda", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

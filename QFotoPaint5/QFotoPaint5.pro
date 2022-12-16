#-------------------------------------------------
#
# Project created by QtCreator 2022-09-01T12:00:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QFotoPaint5

TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
    ajustelineal.cpp \
    bajorrelieve.cpp \
    capturarvideo.cpp \
    color_falso.cpp \
    mainwindow.cpp \
    imagenes.cpp \
    dialognueva.cpp \
    brillocontraste.cpp \
    matsatlum.cpp \
    modelo_color.cpp \
    movimiento.cpp \
    perfilado.cpp \
    perspectiva.cpp \
    pinchar_estirar.cpp \
    suavizados.cpp \
    video.cpp \
    rotaravideo.cpp \
    mediaponderada.cpp \
    acercade.cpp \
    mediadevideo.cpp

HEADERS  += mainwindow.h \
    ajustelineal.h \
    bajorrelieve.h \
    capturarvideo.h \
    color_falso.h \
    imagenes.h \
    dialognueva.h \
    brillocontraste.h \
    matsatlum.h \
    modelo_color.h \
    movimiento.h \
    perfilado.h \
    perspectiva.h \
    pinchar_estirar.h \
    suavizados.h \
    video.h \
    rotaravideo.h \
    mediaponderada.h \
    acercade.h \
    mediadevideo.h

FORMS    += mainwindow.ui \
    ajustelineal.ui \
    bajorrelieve.ui \
    capturarvideo.ui \
    color_falso.ui \
    dialognueva.ui \
    brillocontraste.ui \
    matsatlum.ui \
    modelo_color.ui \
    movimiento.ui \
    perfilado.ui \
    perspectiva.ui \
    pinchar_estirar.ui \
    suavizados.ui \
    rotaravideo.ui \
    mediaponderada.ui \
    acercade.ui \
    mediadevideo.ui

INCLUDEPATH += "C:\OpenCV\OpenCV4.6.0G\include"

LIBS += -L"C:\OpenCV\OpenCV4.6.0G\lib"\
        -llibopencv_world460

RESOURCES += recursos.qrc

RC_ICONS = imagenes/icono.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

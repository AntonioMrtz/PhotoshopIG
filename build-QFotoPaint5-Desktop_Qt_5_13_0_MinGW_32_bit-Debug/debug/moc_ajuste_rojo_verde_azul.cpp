/****************************************************************************
** Meta object code from reading C++ file 'ajuste_rojo_verde_azul.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../QFotoPaint5/ajuste_rojo_verde_azul.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ajuste_rojo_verde_azul.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Ajuste_rojo_verde_azul_t {
    QByteArrayData data[8];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Ajuste_rojo_verde_azul_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Ajuste_rojo_verde_azul_t qt_meta_stringdata_Ajuste_rojo_verde_azul = {
    {
QT_MOC_LITERAL(0, 0, 22), // "Ajuste_rojo_verde_azul"
QT_MOC_LITERAL(1, 23, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(2, 56, 0), // ""
QT_MOC_LITERAL(3, 57, 5), // "value"
QT_MOC_LITERAL(4, 63, 23), // "on_spinBox_valueChanged"
QT_MOC_LITERAL(5, 87, 4), // "arg1"
QT_MOC_LITERAL(6, 92, 34), // "on_horizontalSlider_2_valueCh..."
QT_MOC_LITERAL(7, 127, 34) // "on_horizontalSlider_3_valueCh..."

    },
    "Ajuste_rojo_verde_azul\0"
    "on_horizontalSlider_valueChanged\0\0"
    "value\0on_spinBox_valueChanged\0arg1\0"
    "on_horizontalSlider_2_valueChanged\0"
    "on_horizontalSlider_3_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ajuste_rojo_verde_azul[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       4,    1,   37,    2, 0x08 /* Private */,
       6,    1,   40,    2, 0x08 /* Private */,
       7,    1,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void Ajuste_rojo_verde_azul::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Ajuste_rojo_verde_azul *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_spinBox_valueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_horizontalSlider_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_horizontalSlider_3_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Ajuste_rojo_verde_azul::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_Ajuste_rojo_verde_azul.data,
    qt_meta_data_Ajuste_rojo_verde_azul,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Ajuste_rojo_verde_azul::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ajuste_rojo_verde_azul::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Ajuste_rojo_verde_azul.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Ajuste_rojo_verde_azul::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'bajorrelieve.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../QFotoPaint5/bajorrelieve.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bajorrelieve.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Bajorrelieve_t {
    QByteArrayData data[11];
    char stringdata0[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Bajorrelieve_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Bajorrelieve_t qt_meta_stringdata_Bajorrelieve = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Bajorrelieve"
QT_MOC_LITERAL(1, 13, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 5), // "value"
QT_MOC_LITERAL(4, 53, 20), // "on_dial_valueChanged"
QT_MOC_LITERAL(5, 74, 22), // "on_radioButton_clicked"
QT_MOC_LITERAL(6, 97, 24), // "on_radioButton_2_clicked"
QT_MOC_LITERAL(7, 122, 24), // "on_radioButton_4_clicked"
QT_MOC_LITERAL(8, 147, 24), // "on_radioButton_3_clicked"
QT_MOC_LITERAL(9, 172, 24), // "on_Bajorrelieve_accepted"
QT_MOC_LITERAL(10, 197, 24) // "on_Bajorrelieve_rejected"

    },
    "Bajorrelieve\0on_horizontalSlider_valueChanged\0"
    "\0value\0on_dial_valueChanged\0"
    "on_radioButton_clicked\0on_radioButton_2_clicked\0"
    "on_radioButton_4_clicked\0"
    "on_radioButton_3_clicked\0"
    "on_Bajorrelieve_accepted\0"
    "on_Bajorrelieve_rejected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Bajorrelieve[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x08 /* Private */,
       4,    1,   57,    2, 0x08 /* Private */,
       5,    0,   60,    2, 0x08 /* Private */,
       6,    0,   61,    2, 0x08 /* Private */,
       7,    0,   62,    2, 0x08 /* Private */,
       8,    0,   63,    2, 0x08 /* Private */,
       9,    0,   64,    2, 0x08 /* Private */,
      10,    0,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Bajorrelieve::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Bajorrelieve *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_dial_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_radioButton_clicked(); break;
        case 3: _t->on_radioButton_2_clicked(); break;
        case 4: _t->on_radioButton_4_clicked(); break;
        case 5: _t->on_radioButton_3_clicked(); break;
        case 6: _t->on_Bajorrelieve_accepted(); break;
        case 7: _t->on_Bajorrelieve_rejected(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Bajorrelieve::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_Bajorrelieve.data,
    qt_meta_data_Bajorrelieve,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Bajorrelieve::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Bajorrelieve::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Bajorrelieve.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Bajorrelieve::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

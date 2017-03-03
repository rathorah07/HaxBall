/****************************************************************************
** Meta object code from reading C++ file 'gamelobby.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/gamelobby.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamelobby.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_gamelobby_t {
    QByteArrayData data[8];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gamelobby_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gamelobby_t qt_meta_stringdata_gamelobby = {
    {
QT_MOC_LITERAL(0, 0, 9), // "gamelobby"
QT_MOC_LITERAL(1, 10, 12), // "startclicked"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 14), // "connecting_msg"
QT_MOC_LITERAL(4, 39, 21), // "on_namebutton_clicked"
QT_MOC_LITERAL(5, 61, 24), // "on_radioButton_2_clicked"
QT_MOC_LITERAL(6, 86, 22), // "on_radioButton_clicked"
QT_MOC_LITERAL(7, 109, 6) // "update"

    },
    "gamelobby\0startclicked\0\0connecting_msg\0"
    "on_namebutton_clicked\0on_radioButton_2_clicked\0"
    "on_radioButton_clicked\0update"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gamelobby[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void gamelobby::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        gamelobby *_t = static_cast<gamelobby *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startclicked(); break;
        case 1: _t->connecting_msg(); break;
        case 2: _t->on_namebutton_clicked(); break;
        case 3: _t->on_radioButton_2_clicked(); break;
        case 4: _t->on_radioButton_clicked(); break;
        case 5: _t->update(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (gamelobby::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gamelobby::startclicked)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject gamelobby::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_gamelobby.data,
      qt_meta_data_gamelobby,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *gamelobby::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gamelobby::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_gamelobby.stringdata0))
        return static_cast<void*>(const_cast< gamelobby*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int gamelobby::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void gamelobby::startclicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

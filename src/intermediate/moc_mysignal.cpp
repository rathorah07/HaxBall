/****************************************************************************
** Meta object code from reading C++ file 'mysignal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/mysignal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mysignal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MySignal_t {
    QByteArrayData data[11];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MySignal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MySignal_t qt_meta_stringdata_MySignal = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MySignal"
QT_MOC_LITERAL(1, 9, 12), // "newpeeradded"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 16), // "peerdisconnected"
QT_MOC_LITERAL(4, 40, 7), // "dragged"
QT_MOC_LITERAL(5, 48, 9), // "startgame"
QT_MOC_LITERAL(6, 58, 10), // "goal_score"
QT_MOC_LITERAL(7, 69, 15), // "message_receive"
QT_MOC_LITERAL(8, 85, 4), // "draw"
QT_MOC_LITERAL(9, 90, 9), // "first_hit"
QT_MOC_LITERAL(10, 100, 10) // "self_added"

    },
    "MySignal\0newpeeradded\0\0peerdisconnected\0"
    "dragged\0startgame\0goal_score\0"
    "message_receive\0draw\0first_hit\0"
    "self_added"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MySignal[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    1,   63,    2, 0x06 /* Public */,
       7,    1,   66,    2, 0x06 /* Public */,
       8,    0,   69,    2, 0x06 /* Public */,
       9,    0,   70,    2, 0x06 /* Public */,
      10,    0,   71,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MySignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MySignal *_t = static_cast<MySignal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newpeeradded(); break;
        case 1: _t->peerdisconnected(); break;
        case 2: _t->dragged(); break;
        case 3: _t->startgame(); break;
        case 4: _t->goal_score((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->message_receive((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->draw(); break;
        case 7: _t->first_hit(); break;
        case 8: _t->self_added(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MySignal::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MySignal::newpeeradded)) {
                *result = 0;
            }
        }
        {
            typedef void (MySignal::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MySignal::peerdisconnected)) {
                *result = 1;
            }
        }
        {
            typedef void (MySignal::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MySignal::dragged)) {
                *result = 2;
            }
        }
        {
            typedef void (MySignal::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MySignal::startgame)) {
                *result = 3;
            }
        }
        {
            typedef void (MySignal::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MySignal::goal_score)) {
                *result = 4;
            }
        }
        {
            typedef void (MySignal::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MySignal::message_receive)) {
                *result = 5;
            }
        }
        {
            typedef void (MySignal::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MySignal::draw)) {
                *result = 6;
            }
        }
        {
            typedef void (MySignal::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MySignal::first_hit)) {
                *result = 7;
            }
        }
        {
            typedef void (MySignal::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MySignal::self_added)) {
                *result = 8;
            }
        }
    }
}

const QMetaObject MySignal::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MySignal.data,
      qt_meta_data_MySignal,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MySignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MySignal::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MySignal.stringdata0))
        return static_cast<void*>(const_cast< MySignal*>(this));
    return QObject::qt_metacast(_clname);
}

int MySignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MySignal::newpeeradded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MySignal::peerdisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MySignal::dragged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MySignal::startgame()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MySignal::goal_score(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MySignal::message_receive(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MySignal::draw()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void MySignal::first_hit()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void MySignal::self_added()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

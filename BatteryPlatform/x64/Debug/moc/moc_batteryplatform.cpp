/****************************************************************************
** Meta object code from reading C++ file 'batteryplatform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../batteryplatform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'batteryplatform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BatteryPlatform_t {
    QByteArrayData data[11];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BatteryPlatform_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BatteryPlatform_t qt_meta_stringdata_BatteryPlatform = {
    {
QT_MOC_LITERAL(0, 0, 15), // "BatteryPlatform"
QT_MOC_LITERAL(1, 16, 8), // "sendPort"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "port"
QT_MOC_LITERAL(4, 31, 13), // "brandPactType"
QT_MOC_LITERAL(5, 45, 5), // "index"
QT_MOC_LITERAL(6, 51, 12), // "startAnalyze"
QT_MOC_LITERAL(7, 64, 3), // "val"
QT_MOC_LITERAL(8, 68, 11), // "startVerify"
QT_MOC_LITERAL(9, 80, 12), // "startSaveLog"
QT_MOC_LITERAL(10, 93, 8) // "filepath"

    },
    "BatteryPlatform\0sendPort\0\0port\0"
    "brandPactType\0index\0startAnalyze\0val\0"
    "startVerify\0startSaveLog\0filepath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BatteryPlatform[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       6,    1,   45,    2, 0x06 /* Public */,
       8,    1,   48,    2, 0x06 /* Public */,
       9,    2,   51,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    7,   10,

       0        // eod
};

void BatteryPlatform::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BatteryPlatform *_t = static_cast<BatteryPlatform *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendPort((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: _t->brandPactType((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->startAnalyze((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->startVerify((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->startSaveLog((*reinterpret_cast< const bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (BatteryPlatform::*_t)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BatteryPlatform::sendPort)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (BatteryPlatform::*_t)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BatteryPlatform::brandPactType)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (BatteryPlatform::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BatteryPlatform::startAnalyze)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (BatteryPlatform::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BatteryPlatform::startVerify)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (BatteryPlatform::*_t)(const bool , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BatteryPlatform::startSaveLog)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject BatteryPlatform::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_BatteryPlatform.data,
      qt_meta_data_BatteryPlatform,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BatteryPlatform::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BatteryPlatform::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BatteryPlatform.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int BatteryPlatform::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void BatteryPlatform::sendPort(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BatteryPlatform::brandPactType(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BatteryPlatform::startAnalyze(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void BatteryPlatform::startVerify(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void BatteryPlatform::startSaveLog(const bool _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

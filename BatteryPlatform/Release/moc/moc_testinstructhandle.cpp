/****************************************************************************
** Meta object code from reading C++ file 'testinstructhandle.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../testinstructhandle.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testinstructhandle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestInstructHandle_t {
    QByteArrayData data[13];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestInstructHandle_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestInstructHandle_t qt_meta_stringdata_TestInstructHandle = {
    {
QT_MOC_LITERAL(0, 0, 18), // "TestInstructHandle"
QT_MOC_LITERAL(1, 19, 17), // "sendInstructArray"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 5), // "array"
QT_MOC_LITERAL(4, 44, 18), // "sendHysteresisData"
QT_MOC_LITERAL(5, 63, 10), // "QList<int>"
QT_MOC_LITERAL(6, 74, 4), // "data"
QT_MOC_LITERAL(7, 79, 26), // "write_execl_test_condition"
QT_MOC_LITERAL(8, 106, 19), // "testing_name_father"
QT_MOC_LITERAL(9, 126, 5), // "state"
QT_MOC_LITERAL(10, 132, 18), // "testing_name_child"
QT_MOC_LITERAL(11, 151, 20), // "testing_name_logsave"
QT_MOC_LITERAL(12, 172, 4) // "name"

    },
    "TestInstructHandle\0sendInstructArray\0"
    "\0array\0sendHysteresisData\0QList<int>\0"
    "data\0write_execl_test_condition\0"
    "testing_name_father\0state\0testing_name_child\0"
    "testing_name_logsave\0name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestInstructHandle[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       7,    1,   50,    2, 0x06 /* Public */,
       8,    1,   53,    2, 0x06 /* Public */,
      10,    1,   56,    2, 0x06 /* Public */,
      11,    2,   59,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   12,    9,

       0        // eod
};

void TestInstructHandle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestInstructHandle *_t = static_cast<TestInstructHandle *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendInstructArray((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->sendHysteresisData((*reinterpret_cast< QList<int>(*)>(_a[1]))); break;
        case 2: _t->write_execl_test_condition((*reinterpret_cast< const QList<int>(*)>(_a[1]))); break;
        case 3: _t->testing_name_father((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->testing_name_child((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->testing_name_logsave((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (TestInstructHandle::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestInstructHandle::sendInstructArray)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TestInstructHandle::*_t)(QList<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestInstructHandle::sendHysteresisData)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (TestInstructHandle::*_t)(const QList<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestInstructHandle::write_execl_test_condition)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (TestInstructHandle::*_t)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestInstructHandle::testing_name_father)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (TestInstructHandle::*_t)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestInstructHandle::testing_name_child)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (TestInstructHandle::*_t)(const QString , const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestInstructHandle::testing_name_logsave)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject TestInstructHandle::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TestInstructHandle.data,
      qt_meta_data_TestInstructHandle,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TestInstructHandle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestInstructHandle::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestInstructHandle.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TestInstructHandle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void TestInstructHandle::sendInstructArray(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TestInstructHandle::sendHysteresisData(QList<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TestInstructHandle::write_execl_test_condition(const QList<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TestInstructHandle::testing_name_father(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TestInstructHandle::testing_name_child(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TestInstructHandle::testing_name_logsave(const QString _t1, const int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

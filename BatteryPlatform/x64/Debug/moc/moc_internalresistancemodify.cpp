/****************************************************************************
** Meta object code from reading C++ file 'internalresistancemodify.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../internalresistancemodify.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'internalresistancemodify.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InternalResistanceModify_t {
    QByteArrayData data[8];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InternalResistanceModify_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InternalResistanceModify_t qt_meta_stringdata_InternalResistanceModify = {
    {
QT_MOC_LITERAL(0, 0, 24), // "InternalResistanceModify"
QT_MOC_LITERAL(1, 25, 11), // "dataAnalyze"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 15), // "InstructingData"
QT_MOC_LITERAL(4, 54, 4), // "data"
QT_MOC_LITERAL(5, 59, 19), // "newInstructionArray"
QT_MOC_LITERAL(6, 79, 14), // "returnTestList"
QT_MOC_LITERAL(7, 94, 3) // "val"

    },
    "InternalResistanceModify\0dataAnalyze\0"
    "\0InstructingData\0data\0newInstructionArray\0"
    "returnTestList\0val"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InternalResistanceModify[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       5,    1,   32,    2, 0x06 /* Public */,
       6,    1,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::Bool,    7,

       0        // eod
};

void InternalResistanceModify::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        InternalResistanceModify *_t = static_cast<InternalResistanceModify *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataAnalyze((*reinterpret_cast< const InstructingData(*)>(_a[1]))); break;
        case 1: _t->newInstructionArray((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->returnTestList((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (InternalResistanceModify::*_t)(const InstructingData );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InternalResistanceModify::dataAnalyze)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (InternalResistanceModify::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InternalResistanceModify::newInstructionArray)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (InternalResistanceModify::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InternalResistanceModify::returnTestList)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject InternalResistanceModify::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_InternalResistanceModify.data,
      qt_meta_data_InternalResistanceModify,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *InternalResistanceModify::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InternalResistanceModify::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_InternalResistanceModify.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int InternalResistanceModify::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void InternalResistanceModify::dataAnalyze(const InstructingData _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void InternalResistanceModify::newInstructionArray(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void InternalResistanceModify::returnTestList(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

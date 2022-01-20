/****************************************************************************
** Meta object code from reading C++ file 'dataanalyze.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dataanalyze.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dataanalyze.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataAnalyze_t {
    QByteArrayData data[14];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataAnalyze_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataAnalyze_t qt_meta_stringdata_DataAnalyze = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DataAnalyze"
QT_MOC_LITERAL(1, 12, 19), // "analyzeOver_pactOne"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 10), // "Data_Zhili"
QT_MOC_LITERAL(4, 44, 4), // "data"
QT_MOC_LITERAL(5, 49, 19), // "analyzeOver_pactTwo"
QT_MOC_LITERAL(6, 69, 11), // "Data_lishen"
QT_MOC_LITERAL(7, 81, 12), // "checked_info"
QT_MOC_LITERAL(8, 94, 14), // "QList<QString>"
QT_MOC_LITERAL(9, 109, 4), // "list"
QT_MOC_LITERAL(10, 114, 14), // "test_soc_Value"
QT_MOC_LITERAL(11, 129, 3), // "val"
QT_MOC_LITERAL(12, 133, 12), // "warning_data"
QT_MOC_LITERAL(13, 146, 4) // "type"

    },
    "DataAnalyze\0analyzeOver_pactOne\0\0"
    "Data_Zhili\0data\0analyzeOver_pactTwo\0"
    "Data_lishen\0checked_info\0QList<QString>\0"
    "list\0test_soc_Value\0val\0warning_data\0"
    "type"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataAnalyze[] = {

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
       5,    1,   42,    2, 0x06 /* Public */,
       7,    1,   45,    2, 0x06 /* Public */,
      10,    1,   48,    2, 0x06 /* Public */,
      12,    2,   51,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    4,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    4,   13,

       0        // eod
};

void DataAnalyze::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataAnalyze *_t = static_cast<DataAnalyze *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->analyzeOver_pactOne((*reinterpret_cast< const Data_Zhili(*)>(_a[1]))); break;
        case 1: _t->analyzeOver_pactTwo((*reinterpret_cast< const Data_lishen(*)>(_a[1]))); break;
        case 2: _t->checked_info((*reinterpret_cast< QList<QString>(*)>(_a[1]))); break;
        case 3: _t->test_soc_Value((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 4: _t->warning_data((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (DataAnalyze::*_t)(const Data_Zhili );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAnalyze::analyzeOver_pactOne)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DataAnalyze::*_t)(const Data_lishen );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAnalyze::analyzeOver_pactTwo)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (DataAnalyze::*_t)(QList<QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAnalyze::checked_info)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (DataAnalyze::*_t)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAnalyze::test_soc_Value)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (DataAnalyze::*_t)(const QString , const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAnalyze::warning_data)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject DataAnalyze::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DataAnalyze.data,
      qt_meta_data_DataAnalyze,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DataAnalyze::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataAnalyze::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataAnalyze.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataAnalyze::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void DataAnalyze::analyzeOver_pactOne(const Data_Zhili _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DataAnalyze::analyzeOver_pactTwo(const Data_lishen _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DataAnalyze::checked_info(QList<QString> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DataAnalyze::test_soc_Value(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DataAnalyze::warning_data(const QString _t1, const int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

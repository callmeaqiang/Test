/****************************************************************************
** Meta object code from reading C++ file 'dataanalyze.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../dataanalyze.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
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
    QByteArrayData data[15];
    char stringdata0[237];
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
QT_MOC_LITERAL(7, 81, 31), // "analyzeOver_pactThree_simiulate"
QT_MOC_LITERAL(8, 113, 13), // "Data_peicheng"
QT_MOC_LITERAL(9, 127, 29), // "analyzeOver_pactThree_warning"
QT_MOC_LITERAL(10, 157, 21), // "Data_peicheng_warning"
QT_MOC_LITERAL(11, 179, 14), // "checkSumResult"
QT_MOC_LITERAL(12, 194, 14), // "checkDataValue"
QT_MOC_LITERAL(13, 209, 23), // "resistanceTst_socStatus"
QT_MOC_LITERAL(14, 233, 3) // "val"

    },
    "DataAnalyze\0analyzeOver_pactOne\0\0"
    "Data_Zhili\0data\0analyzeOver_pactTwo\0"
    "Data_lishen\0analyzeOver_pactThree_simiulate\0"
    "Data_peicheng\0analyzeOver_pactThree_warning\0"
    "Data_peicheng_warning\0checkSumResult\0"
    "checkDataValue\0resistanceTst_socStatus\0"
    "val"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataAnalyze[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       5,    1,   52,    2, 0x06 /* Public */,
       7,    1,   55,    2, 0x06 /* Public */,
       9,    1,   58,    2, 0x06 /* Public */,
      11,    1,   61,    2, 0x06 /* Public */,
      12,    1,   64,    2, 0x06 /* Public */,
      13,    1,   67,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    4,
    QMetaType::Void, 0x80000000 | 8,    4,
    QMetaType::Void, 0x80000000 | 10,    4,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,   14,

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
        case 2: _t->analyzeOver_pactThree_simiulate((*reinterpret_cast< const Data_peicheng(*)>(_a[1]))); break;
        case 3: _t->analyzeOver_pactThree_warning((*reinterpret_cast< const Data_peicheng_warning(*)>(_a[1]))); break;
        case 4: _t->checkSumResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->checkDataValue((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->resistanceTst_socStatus((*reinterpret_cast< const int(*)>(_a[1]))); break;
        default: ;
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
            typedef void (DataAnalyze::*_t)(const Data_peicheng );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAnalyze::analyzeOver_pactThree_simiulate)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (DataAnalyze::*_t)(const Data_peicheng_warning );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAnalyze::analyzeOver_pactThree_warning)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (DataAnalyze::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAnalyze::checkSumResult)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (DataAnalyze::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAnalyze::checkDataValue)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (DataAnalyze::*_t)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAnalyze::resistanceTst_socStatus)) {
                *result = 6;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
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
void DataAnalyze::analyzeOver_pactThree_simiulate(const Data_peicheng _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DataAnalyze::analyzeOver_pactThree_warning(const Data_peicheng_warning _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DataAnalyze::checkSumResult(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DataAnalyze::checkDataValue(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void DataAnalyze::resistanceTst_socStatus(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

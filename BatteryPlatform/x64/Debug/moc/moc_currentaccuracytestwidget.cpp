/****************************************************************************
** Meta object code from reading C++ file 'currentaccuracytestwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../currentaccuracytestwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'currentaccuracytestwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CurrentAccuracyTestWidget_t {
    QByteArrayData data[7];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CurrentAccuracyTestWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CurrentAccuracyTestWidget_t qt_meta_stringdata_CurrentAccuracyTestWidget = {
    {
QT_MOC_LITERAL(0, 0, 25), // "CurrentAccuracyTestWidget"
QT_MOC_LITERAL(1, 26, 14), // "returnTestList"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 3), // "val"
QT_MOC_LITERAL(4, 46, 22), // "returnAccuracyInstruct"
QT_MOC_LITERAL(5, 69, 15), // "InstructingData"
QT_MOC_LITERAL(6, 85, 4) // "data"

    },
    "CurrentAccuracyTestWidget\0returnTestList\0"
    "\0val\0returnAccuracyInstruct\0InstructingData\0"
    "data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CurrentAccuracyTestWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       4,    1,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void CurrentAccuracyTestWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CurrentAccuracyTestWidget *_t = static_cast<CurrentAccuracyTestWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->returnTestList((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->returnAccuracyInstruct((*reinterpret_cast< const InstructingData(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (CurrentAccuracyTestWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurrentAccuracyTestWidget::returnTestList)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CurrentAccuracyTestWidget::*_t)(const InstructingData );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurrentAccuracyTestWidget::returnAccuracyInstruct)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject CurrentAccuracyTestWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CurrentAccuracyTestWidget.data,
      qt_meta_data_CurrentAccuracyTestWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CurrentAccuracyTestWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CurrentAccuracyTestWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CurrentAccuracyTestWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CurrentAccuracyTestWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CurrentAccuracyTestWidget::returnTestList(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CurrentAccuracyTestWidget::returnAccuracyInstruct(const InstructingData _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

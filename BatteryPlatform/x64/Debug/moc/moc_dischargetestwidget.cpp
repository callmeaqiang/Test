/****************************************************************************
** Meta object code from reading C++ file 'dischargetestwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../dischargetestwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dischargetestwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DischargeTestWidget_t {
    QByteArrayData data[7];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DischargeTestWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DischargeTestWidget_t qt_meta_stringdata_DischargeTestWidget = {
    {
QT_MOC_LITERAL(0, 0, 19), // "DischargeTestWidget"
QT_MOC_LITERAL(1, 20, 12), // "returnBefore"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 3), // "val"
QT_MOC_LITERAL(4, 38, 27), // "modify_instrction_discharge"
QT_MOC_LITERAL(5, 66, 10), // "QList<int>"
QT_MOC_LITERAL(6, 77, 20) // "instrction_discharge"

    },
    "DischargeTestWidget\0returnBefore\0\0val\0"
    "modify_instrction_discharge\0QList<int>\0"
    "instrction_discharge"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DischargeTestWidget[] = {

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
       4,    1,   32,    2, 0x06 /* Public */,
       6,    1,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 5,    2,

       0        // eod
};

void DischargeTestWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DischargeTestWidget *_t = static_cast<DischargeTestWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->returnBefore((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->modify_instrction_discharge((*reinterpret_cast< QList<int>(*)>(_a[1]))); break;
        case 2: _t->instrction_discharge((*reinterpret_cast< QList<int>(*)>(_a[1]))); break;
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
            typedef void (DischargeTestWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DischargeTestWidget::returnBefore)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DischargeTestWidget::*_t)(QList<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DischargeTestWidget::modify_instrction_discharge)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (DischargeTestWidget::*_t)(QList<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DischargeTestWidget::instrction_discharge)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject DischargeTestWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DischargeTestWidget.data,
      qt_meta_data_DischargeTestWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DischargeTestWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DischargeTestWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DischargeTestWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DischargeTestWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void DischargeTestWidget::returnBefore(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DischargeTestWidget::modify_instrction_discharge(QList<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DischargeTestWidget::instrction_discharge(QList<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

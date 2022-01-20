/****************************************************************************
** Meta object code from reading C++ file 'voltageaccuracytestdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../voltageaccuracytestdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'voltageaccuracytestdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VoltageAccuracyTestDialog_t {
    QByteArrayData data[13];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VoltageAccuracyTestDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VoltageAccuracyTestDialog_t qt_meta_stringdata_VoltageAccuracyTestDialog = {
    {
QT_MOC_LITERAL(0, 0, 25), // "VoltageAccuracyTestDialog"
QT_MOC_LITERAL(1, 26, 12), // "returnBefore"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 3), // "val"
QT_MOC_LITERAL(4, 44, 14), // "construct_data"
QT_MOC_LITERAL(5, 59, 8), // "testname"
QT_MOC_LITERAL(6, 68, 9), // "WhatsThis"
QT_MOC_LITERAL(7, 78, 10), // "QList<int>"
QT_MOC_LITERAL(8, 89, 4), // "list"
QT_MOC_LITERAL(9, 94, 11), // "modify_data"
QT_MOC_LITERAL(10, 106, 18), // "on_SaveBtn_clicked"
QT_MOC_LITERAL(11, 125, 20), // "on_ModifyBtn_clicked"
QT_MOC_LITERAL(12, 146, 20) // "on_ReturnBtn_clicked"

    },
    "VoltageAccuracyTestDialog\0returnBefore\0"
    "\0val\0construct_data\0testname\0WhatsThis\0"
    "QList<int>\0list\0modify_data\0"
    "on_SaveBtn_clicked\0on_ModifyBtn_clicked\0"
    "on_ReturnBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VoltageAccuracyTestDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    3,   47,    2, 0x06 /* Public */,
       9,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   57,    2, 0x08 /* Private */,
      11,    0,   58,    2, 0x08 /* Private */,
      12,    0,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 7,    5,    6,    8,
    QMetaType::Void, 0x80000000 | 7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VoltageAccuracyTestDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VoltageAccuracyTestDialog *_t = static_cast<VoltageAccuracyTestDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->returnBefore((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 1: _t->construct_data((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QList<int>(*)>(_a[3]))); break;
        case 2: _t->modify_data((*reinterpret_cast< const QList<int>(*)>(_a[1]))); break;
        case 3: _t->on_SaveBtn_clicked(); break;
        case 4: _t->on_ModifyBtn_clicked(); break;
        case 5: _t->on_ReturnBtn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
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
            typedef void (VoltageAccuracyTestDialog::*_t)(const bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoltageAccuracyTestDialog::returnBefore)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (VoltageAccuracyTestDialog::*_t)(const QString , const QString , QList<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoltageAccuracyTestDialog::construct_data)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (VoltageAccuracyTestDialog::*_t)(const QList<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoltageAccuracyTestDialog::modify_data)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject VoltageAccuracyTestDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_VoltageAccuracyTestDialog.data,
      qt_meta_data_VoltageAccuracyTestDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *VoltageAccuracyTestDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VoltageAccuracyTestDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VoltageAccuracyTestDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int VoltageAccuracyTestDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void VoltageAccuracyTestDialog::returnBefore(const bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VoltageAccuracyTestDialog::construct_data(const QString _t1, const QString _t2, QList<int> _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void VoltageAccuracyTestDialog::modify_data(const QList<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

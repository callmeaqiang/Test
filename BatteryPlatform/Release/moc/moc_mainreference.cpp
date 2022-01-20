/****************************************************************************
** Meta object code from reading C++ file 'mainreference.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainreference.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainreference.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainReference_t {
    QByteArrayData data[23];
    char stringdata0[444];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainReference_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainReference_t qt_meta_stringdata_MainReference = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MainReference"
QT_MOC_LITERAL(1, 14, 16), // "instructDataList"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 18), // "QList<QList<int> >"
QT_MOC_LITERAL(4, 51, 4), // "data"
QT_MOC_LITERAL(5, 56, 15), // "execl_save_path"
QT_MOC_LITERAL(6, 72, 8), // "filepath"
QT_MOC_LITERAL(7, 81, 18), // "send_test_typelist"
QT_MOC_LITERAL(8, 100, 4), // "test"
QT_MOC_LITERAL(9, 105, 22), // "update_event_loop_pass"
QT_MOC_LITERAL(10, 128, 3), // "val"
QT_MOC_LITERAL(11, 132, 12), // "end_all_test"
QT_MOC_LITERAL(12, 145, 23), // "on_TestStartBtn_clicked"
QT_MOC_LITERAL(13, 169, 23), // "on_TestPauseBtn_clicked"
QT_MOC_LITERAL(14, 193, 27), // "on_TestTerminateBtn_clicked"
QT_MOC_LITERAL(15, 221, 21), // "on_comboBox_activated"
QT_MOC_LITERAL(16, 243, 5), // "index"
QT_MOC_LITERAL(17, 249, 41), // "on_tableWidget_customContextM..."
QT_MOC_LITERAL(18, 291, 3), // "pos"
QT_MOC_LITERAL(19, 295, 38), // "on_listView_customContextMenu..."
QT_MOC_LITERAL(20, 334, 29), // "on_pushButtons_scrool_clicked"
QT_MOC_LITERAL(21, 364, 39), // "on_pushButton_export_paramete..."
QT_MOC_LITERAL(22, 404, 39) // "on_pushButton_import_paramete..."

    },
    "MainReference\0instructDataList\0\0"
    "QList<QList<int> >\0data\0execl_save_path\0"
    "filepath\0send_test_typelist\0test\0"
    "update_event_loop_pass\0val\0end_all_test\0"
    "on_TestStartBtn_clicked\0on_TestPauseBtn_clicked\0"
    "on_TestTerminateBtn_clicked\0"
    "on_comboBox_activated\0index\0"
    "on_tableWidget_customContextMenuRequested\0"
    "pos\0on_listView_customContextMenuRequested\0"
    "on_pushButtons_scrool_clicked\0"
    "on_pushButton_export_parameters_clicked\0"
    "on_pushButton_import_parameters_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainReference[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       5,    1,   87,    2, 0x06 /* Public */,
       7,    1,   90,    2, 0x06 /* Public */,
       9,    1,   93,    2, 0x06 /* Public */,
      11,    0,   96,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   97,    2, 0x08 /* Private */,
      13,    0,   98,    2, 0x08 /* Private */,
      14,    0,   99,    2, 0x08 /* Private */,
      15,    1,  100,    2, 0x08 /* Private */,
      17,    1,  103,    2, 0x08 /* Private */,
      19,    1,  106,    2, 0x08 /* Private */,
      20,    0,  109,    2, 0x08 /* Private */,
      21,    0,  110,    2, 0x08 /* Private */,
      22,    0,  111,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QStringList,    8,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::QPoint,   18,
    QMetaType::Void, QMetaType::QPoint,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainReference::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainReference *_t = static_cast<MainReference *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->instructDataList((*reinterpret_cast< const QList<QList<int> >(*)>(_a[1]))); break;
        case 1: _t->execl_save_path((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->send_test_typelist((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 3: _t->update_event_loop_pass((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->end_all_test(); break;
        case 5: _t->on_TestStartBtn_clicked(); break;
        case 6: _t->on_TestPauseBtn_clicked(); break;
        case 7: _t->on_TestTerminateBtn_clicked(); break;
        case 8: _t->on_comboBox_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_tableWidget_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 10: _t->on_listView_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 11: _t->on_pushButtons_scrool_clicked(); break;
        case 12: _t->on_pushButton_export_parameters_clicked(); break;
        case 13: _t->on_pushButton_import_parameters_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QList<int> > >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MainReference::*_t)(const QList<QList<int>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainReference::instructDataList)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainReference::*_t)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainReference::execl_save_path)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainReference::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainReference::send_test_typelist)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainReference::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainReference::update_event_loop_pass)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainReference::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainReference::end_all_test)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject MainReference::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainReference.data,
      qt_meta_data_MainReference,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainReference::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainReference::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainReference.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MainReference::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MainReference::instructDataList(const QList<QList<int>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainReference::execl_save_path(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainReference::send_test_typelist(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainReference::update_event_loop_pass(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainReference::end_all_test()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

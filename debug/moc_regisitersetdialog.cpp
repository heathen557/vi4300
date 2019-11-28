/****************************************************************************
** Meta object code from reading C++ file 'regisitersetdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../regisitersetdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'regisitersetdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RegisiterSetDialog_t {
    QByteArrayData data[10];
    char stringdata0[196];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RegisiterSetDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RegisiterSetDialog_t qt_meta_stringdata_RegisiterSetDialog = {
    {
QT_MOC_LITERAL(0, 0, 18), // "RegisiterSetDialog"
QT_MOC_LITERAL(1, 19, 16), // "sendSerialSignal"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 31), // "on_loadLocal_pushButton_clicked"
QT_MOC_LITERAL(4, 69, 31), // "on_saveLocal_pushButton_clicked"
QT_MOC_LITERAL(5, 101, 26), // "on_send_pushButton_clicked"
QT_MOC_LITERAL(6, 128, 26), // "on_read_pushButton_clicked"
QT_MOC_LITERAL(7, 155, 9), // "clearItem"
QT_MOC_LITERAL(8, 165, 8), // "showItem"
QT_MOC_LITERAL(9, 174, 21) // "on_toolButton_clicked"

    },
    "RegisiterSetDialog\0sendSerialSignal\0"
    "\0on_loadLocal_pushButton_clicked\0"
    "on_saveLocal_pushButton_clicked\0"
    "on_send_pushButton_clicked\0"
    "on_read_pushButton_clicked\0clearItem\0"
    "showItem\0on_toolButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RegisiterSetDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   57,    2, 0x08 /* Private */,
       4,    0,   58,    2, 0x08 /* Private */,
       5,    0,   59,    2, 0x08 /* Private */,
       6,    0,   60,    2, 0x08 /* Private */,
       7,    0,   61,    2, 0x08 /* Private */,
       8,    0,   62,    2, 0x08 /* Private */,
       9,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RegisiterSetDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RegisiterSetDialog *_t = static_cast<RegisiterSetDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendSerialSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_loadLocal_pushButton_clicked(); break;
        case 2: _t->on_saveLocal_pushButton_clicked(); break;
        case 3: _t->on_send_pushButton_clicked(); break;
        case 4: _t->on_read_pushButton_clicked(); break;
        case 5: _t->clearItem(); break;
        case 6: _t->showItem(); break;
        case 7: _t->on_toolButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RegisiterSetDialog::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RegisiterSetDialog::sendSerialSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject RegisiterSetDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RegisiterSetDialog.data,
      qt_meta_data_RegisiterSetDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RegisiterSetDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RegisiterSetDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RegisiterSetDialog.stringdata0))
        return static_cast<void*>(const_cast< RegisiterSetDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int RegisiterSetDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void RegisiterSetDialog::sendSerialSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

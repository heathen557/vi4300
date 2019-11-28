/****************************************************************************
** Meta object code from reading C++ file 'mcuupgradedialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mcuupgradedialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mcuupgradedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_McuUpgradeDialog_t {
    QByteArrayData data[10];
    char stringdata0[175];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_McuUpgradeDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_McuUpgradeDialog_t qt_meta_stringdata_McuUpgradeDialog = {
    {
QT_MOC_LITERAL(0, 0, 16), // "McuUpgradeDialog"
QT_MOC_LITERAL(1, 17, 16), // "sendSerialSignal"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 30), // "on_openFile_pushButton_clicked"
QT_MOC_LITERAL(4, 66, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 88, 29), // "on_upgrade_pushButton_clicked"
QT_MOC_LITERAL(6, 118, 15), // "sendCmdMsg_slot"
QT_MOC_LITERAL(7, 134, 20), // "AckCmdUpgrade_signal"
QT_MOC_LITERAL(8, 155, 12), // "returnCmdStr"
QT_MOC_LITERAL(9, 168, 6) // "cmdAck"

    },
    "McuUpgradeDialog\0sendSerialSignal\0\0"
    "on_openFile_pushButton_clicked\0"
    "on_pushButton_clicked\0"
    "on_upgrade_pushButton_clicked\0"
    "sendCmdMsg_slot\0AckCmdUpgrade_signal\0"
    "returnCmdStr\0cmdAck"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_McuUpgradeDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   47,    2, 0x08 /* Private */,
       4,    0,   48,    2, 0x08 /* Private */,
       5,    0,   49,    2, 0x08 /* Private */,
       6,    0,   50,    2, 0x08 /* Private */,
       7,    2,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    8,    9,

       0        // eod
};

void McuUpgradeDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        McuUpgradeDialog *_t = static_cast<McuUpgradeDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendSerialSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_openFile_pushButton_clicked(); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_upgrade_pushButton_clicked(); break;
        case 4: _t->sendCmdMsg_slot(); break;
        case 5: _t->AckCmdUpgrade_signal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (McuUpgradeDialog::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&McuUpgradeDialog::sendSerialSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject McuUpgradeDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_McuUpgradeDialog.data,
      qt_meta_data_McuUpgradeDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *McuUpgradeDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *McuUpgradeDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_McuUpgradeDialog.stringdata0))
        return static_cast<void*>(const_cast< McuUpgradeDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int McuUpgradeDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void McuUpgradeDialog::sendSerialSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

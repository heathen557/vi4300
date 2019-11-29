/****************************************************************************
** Meta object code from reading C++ file 'receserial_msg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../receserial_msg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'receserial_msg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_receSerial_msg_t {
    QByteArrayData data[17];
    char stringdata0[243];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_receSerial_msg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_receSerial_msg_t qt_meta_stringdata_receSerial_msg = {
    {
QT_MOC_LITERAL(0, 0, 14), // "receSerial_msg"
QT_MOC_LITERAL(1, 15, 17), // "dealedData_signal"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 14), // "vector<double>"
QT_MOC_LITERAL(4, 49, 20), // "showResultMsg_signal"
QT_MOC_LITERAL(5, 70, 21), // "returnLinkInfo_signal"
QT_MOC_LITERAL(6, 92, 20), // "AckCmdUpgrade_signal"
QT_MOC_LITERAL(7, 113, 21), // "AckCmdRegister_signal"
QT_MOC_LITERAL(8, 135, 17), // "AckCmdMain_signal"
QT_MOC_LITERAL(9, 153, 12), // "readDataSlot"
QT_MOC_LITERAL(10, 166, 8), // "msgCheck"
QT_MOC_LITERAL(11, 175, 3), // "msg"
QT_MOC_LITERAL(12, 179, 22), // "openOrCloseSerial_slot"
QT_MOC_LITERAL(13, 202, 14), // "sendSerialSlot"
QT_MOC_LITERAL(14, 217, 8), // "addCheck"
QT_MOC_LITERAL(15, 226, 12), // "StringToByte"
QT_MOC_LITERAL(16, 239, 3) // "str"

    },
    "receSerial_msg\0dealedData_signal\0\0"
    "vector<double>\0showResultMsg_signal\0"
    "returnLinkInfo_signal\0AckCmdUpgrade_signal\0"
    "AckCmdRegister_signal\0AckCmdMain_signal\0"
    "readDataSlot\0msgCheck\0msg\0"
    "openOrCloseSerial_slot\0sendSerialSlot\0"
    "addCheck\0StringToByte\0str"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_receSerial_msg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   74,    2, 0x06 /* Public */,
       4,    1,   81,    2, 0x06 /* Public */,
       5,    2,   84,    2, 0x06 /* Public */,
       6,    2,   89,    2, 0x06 /* Public */,
       7,    2,   94,    2, 0x06 /* Public */,
       8,    2,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  104,    2, 0x0a /* Public */,
      10,    1,  105,    2, 0x0a /* Public */,
      12,    1,  108,    2, 0x0a /* Public */,
      13,    1,  111,    2, 0x0a /* Public */,
      14,    1,  114,    2, 0x0a /* Public */,
      15,    1,  117,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 3, 0x80000000 | 3,    2,    2,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::QString, QMetaType::QString,    2,
    QMetaType::QByteArray, QMetaType::QString,   16,

       0        // eod
};

void receSerial_msg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        receSerial_msg *_t = static_cast<receSerial_msg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dealedData_signal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< vector<double>(*)>(_a[2])),(*reinterpret_cast< vector<double>(*)>(_a[3]))); break;
        case 1: _t->showResultMsg_signal((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->returnLinkInfo_signal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->AckCmdUpgrade_signal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->AckCmdRegister_signal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->AckCmdMain_signal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->readDataSlot(); break;
        case 7: { bool _r = _t->msgCheck((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: _t->openOrCloseSerial_slot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->sendSerialSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: { QString _r = _t->addCheck((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 11: { QByteArray _r = _t->StringToByte((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (receSerial_msg::*_t)(QString , vector<double> , vector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&receSerial_msg::dealedData_signal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (receSerial_msg::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&receSerial_msg::showResultMsg_signal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (receSerial_msg::*_t)(QString , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&receSerial_msg::returnLinkInfo_signal)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (receSerial_msg::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&receSerial_msg::AckCmdUpgrade_signal)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (receSerial_msg::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&receSerial_msg::AckCmdRegister_signal)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (receSerial_msg::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&receSerial_msg::AckCmdMain_signal)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject receSerial_msg::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_receSerial_msg.data,
      qt_meta_data_receSerial_msg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *receSerial_msg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *receSerial_msg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_receSerial_msg.stringdata0))
        return static_cast<void*>(const_cast< receSerial_msg*>(this));
    return QObject::qt_metacast(_clname);
}

int receSerial_msg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void receSerial_msg::dealedData_signal(QString _t1, vector<double> _t2, vector<double> _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void receSerial_msg::showResultMsg_signal(QStringList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void receSerial_msg::returnLinkInfo_signal(QString _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void receSerial_msg::AckCmdUpgrade_signal(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void receSerial_msg::AckCmdRegister_signal(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void receSerial_msg::AckCmdMain_signal(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

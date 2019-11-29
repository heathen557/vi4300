/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[44];
    char stringdata0[1082];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 24), // "openOrCloseSerial_signal"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 19), // "calHistogram_signal"
QT_MOC_LITERAL(4, 57, 14), // "vector<double>"
QT_MOC_LITERAL(5, 72, 16), // "sendSerialSignal"
QT_MOC_LITERAL(6, 89, 26), // "on_save_pushButton_clicked"
QT_MOC_LITERAL(7, 116, 33), // "on_plotSet_on_radioButton_cli..."
QT_MOC_LITERAL(8, 150, 34), // "on_plotSet_off_radioButton_cl..."
QT_MOC_LITERAL(9, 185, 30), // "on_openPort_pushButton_clicked"
QT_MOC_LITERAL(10, 216, 29), // "on_Transform_checkBox_clicked"
QT_MOC_LITERAL(11, 246, 15), // "dealedData_slot"
QT_MOC_LITERAL(12, 262, 13), // "showTimerSlot"
QT_MOC_LITERAL(13, 276, 10), // "beginTimer"
QT_MOC_LITERAL(14, 287, 9), // "stopTimer"
QT_MOC_LITERAL(15, 297, 35), // "on_selectSavePathtoolButton_c..."
QT_MOC_LITERAL(16, 333, 19), // "oneSecondTimer_slot"
QT_MOC_LITERAL(17, 353, 30), // "on_TimingSave_checkBox_clicked"
QT_MOC_LITERAL(18, 384, 27), // "on_clear_pushButton_clicked"
QT_MOC_LITERAL(19, 412, 39), // "on_timeInnterval_lineEdit_ret..."
QT_MOC_LITERAL(20, 452, 30), // "on_portScan_pushButton_clicked"
QT_MOC_LITERAL(21, 483, 18), // "showResultMsg_slot"
QT_MOC_LITERAL(22, 502, 18), // "plotShowTimer_slot"
QT_MOC_LITERAL(23, 521, 26), // "on_TOF_radioButton_clicked"
QT_MOC_LITERAL(24, 548, 32), // "on_Histogram_radioButton_clicked"
QT_MOC_LITERAL(25, 581, 19), // "returnLinkInfo_slot"
QT_MOC_LITERAL(26, 601, 20), // "toShowHistogram_slot"
QT_MOC_LITERAL(27, 622, 15), // "QVector<double>"
QT_MOC_LITERAL(28, 638, 16), // "QVector<QString>"
QT_MOC_LITERAL(29, 655, 33), // "on_savePicture_pushButton_cli..."
QT_MOC_LITERAL(30, 689, 22), // "on_actionMCU_triggered"
QT_MOC_LITERAL(31, 712, 28), // "on_Register_action_triggered"
QT_MOC_LITERAL(32, 741, 35), // "on_singleMeasure_pushButton_c..."
QT_MOC_LITERAL(33, 777, 34), // "on_delayMeasure_pushButton_cl..."
QT_MOC_LITERAL(34, 812, 33), // "on_stopMeasure_pushButton_cli..."
QT_MOC_LITERAL(35, 846, 33), // "on_calibration_pushButton_cli..."
QT_MOC_LITERAL(36, 880, 32), // "on_outSetting_pushButton_clicked"
QT_MOC_LITERAL(37, 913, 19), // "keepSendMeasureSlot"
QT_MOC_LITERAL(38, 933, 37), // "on_read_outFactory_pushButton..."
QT_MOC_LITERAL(39, 971, 37), // "on_send_outFactory_pushButton..."
QT_MOC_LITERAL(40, 1009, 15), // "AckCmdMain_slot"
QT_MOC_LITERAL(41, 1025, 12), // "returnCmdStr"
QT_MOC_LITERAL(42, 1038, 6), // "cmdAck"
QT_MOC_LITERAL(43, 1045, 36) // "on_reStoreFactory_pushButton_..."

    },
    "MainWindow\0openOrCloseSerial_signal\0"
    "\0calHistogram_signal\0vector<double>\0"
    "sendSerialSignal\0on_save_pushButton_clicked\0"
    "on_plotSet_on_radioButton_clicked\0"
    "on_plotSet_off_radioButton_clicked\0"
    "on_openPort_pushButton_clicked\0"
    "on_Transform_checkBox_clicked\0"
    "dealedData_slot\0showTimerSlot\0beginTimer\0"
    "stopTimer\0on_selectSavePathtoolButton_clicked\0"
    "oneSecondTimer_slot\0on_TimingSave_checkBox_clicked\0"
    "on_clear_pushButton_clicked\0"
    "on_timeInnterval_lineEdit_returnPressed\0"
    "on_portScan_pushButton_clicked\0"
    "showResultMsg_slot\0plotShowTimer_slot\0"
    "on_TOF_radioButton_clicked\0"
    "on_Histogram_radioButton_clicked\0"
    "returnLinkInfo_slot\0toShowHistogram_slot\0"
    "QVector<double>\0QVector<QString>\0"
    "on_savePicture_pushButton_clicked\0"
    "on_actionMCU_triggered\0"
    "on_Register_action_triggered\0"
    "on_singleMeasure_pushButton_clicked\0"
    "on_delayMeasure_pushButton_clicked\0"
    "on_stopMeasure_pushButton_clicked\0"
    "on_calibration_pushButton_clicked\0"
    "on_outSetting_pushButton_clicked\0"
    "keepSendMeasureSlot\0"
    "on_read_outFactory_pushButton_clicked\0"
    "on_send_outFactory_pushButton_clicked\0"
    "AckCmdMain_slot\0returnCmdStr\0cmdAck\0"
    "on_reStoreFactory_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      37,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  199,    2, 0x06 /* Public */,
       3,    1,  202,    2, 0x06 /* Public */,
       5,    1,  205,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,  208,    2, 0x08 /* Private */,
       7,    0,  209,    2, 0x08 /* Private */,
       8,    0,  210,    2, 0x08 /* Private */,
       9,    0,  211,    2, 0x08 /* Private */,
      10,    0,  212,    2, 0x08 /* Private */,
      11,    3,  213,    2, 0x08 /* Private */,
      12,    0,  220,    2, 0x08 /* Private */,
      13,    0,  221,    2, 0x08 /* Private */,
      14,    0,  222,    2, 0x08 /* Private */,
      15,    0,  223,    2, 0x08 /* Private */,
      16,    0,  224,    2, 0x08 /* Private */,
      17,    0,  225,    2, 0x08 /* Private */,
      18,    0,  226,    2, 0x08 /* Private */,
      19,    0,  227,    2, 0x08 /* Private */,
      20,    0,  228,    2, 0x08 /* Private */,
      21,    1,  229,    2, 0x08 /* Private */,
      22,    0,  232,    2, 0x08 /* Private */,
      23,    0,  233,    2, 0x08 /* Private */,
      24,    0,  234,    2, 0x08 /* Private */,
      25,    2,  235,    2, 0x08 /* Private */,
      26,    5,  240,    2, 0x08 /* Private */,
      29,    0,  251,    2, 0x08 /* Private */,
      30,    0,  252,    2, 0x08 /* Private */,
      31,    0,  253,    2, 0x08 /* Private */,
      32,    0,  254,    2, 0x08 /* Private */,
      33,    0,  255,    2, 0x08 /* Private */,
      34,    0,  256,    2, 0x08 /* Private */,
      35,    0,  257,    2, 0x08 /* Private */,
      36,    0,  258,    2, 0x08 /* Private */,
      37,    0,  259,    2, 0x08 /* Private */,
      38,    0,  260,    2, 0x08 /* Private */,
      39,    0,  261,    2, 0x08 /* Private */,
      40,    2,  262,    2, 0x08 /* Private */,
      43,    0,  267,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 4,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    2,    2,
    QMetaType::Void, 0x80000000 | 27, 0x80000000 | 27, 0x80000000 | 28, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   41,   42,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openOrCloseSerial_signal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->calHistogram_signal((*reinterpret_cast< vector<double>(*)>(_a[1]))); break;
        case 2: _t->sendSerialSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_save_pushButton_clicked(); break;
        case 4: _t->on_plotSet_on_radioButton_clicked(); break;
        case 5: _t->on_plotSet_off_radioButton_clicked(); break;
        case 6: _t->on_openPort_pushButton_clicked(); break;
        case 7: _t->on_Transform_checkBox_clicked(); break;
        case 8: _t->dealedData_slot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< vector<double>(*)>(_a[2])),(*reinterpret_cast< vector<double>(*)>(_a[3]))); break;
        case 9: _t->showTimerSlot(); break;
        case 10: _t->beginTimer(); break;
        case 11: _t->stopTimer(); break;
        case 12: _t->on_selectSavePathtoolButton_clicked(); break;
        case 13: _t->oneSecondTimer_slot(); break;
        case 14: _t->on_TimingSave_checkBox_clicked(); break;
        case 15: _t->on_clear_pushButton_clicked(); break;
        case 16: _t->on_timeInnterval_lineEdit_returnPressed(); break;
        case 17: _t->on_portScan_pushButton_clicked(); break;
        case 18: _t->showResultMsg_slot((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 19: _t->plotShowTimer_slot(); break;
        case 20: _t->on_TOF_radioButton_clicked(); break;
        case 21: _t->on_Histogram_radioButton_clicked(); break;
        case 22: _t->returnLinkInfo_slot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 23: _t->toShowHistogram_slot((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< QVector<QString>(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 24: _t->on_savePicture_pushButton_clicked(); break;
        case 25: _t->on_actionMCU_triggered(); break;
        case 26: _t->on_Register_action_triggered(); break;
        case 27: _t->on_singleMeasure_pushButton_clicked(); break;
        case 28: _t->on_delayMeasure_pushButton_clicked(); break;
        case 29: _t->on_stopMeasure_pushButton_clicked(); break;
        case 30: _t->on_calibration_pushButton_clicked(); break;
        case 31: _t->on_outSetting_pushButton_clicked(); break;
        case 32: _t->keepSendMeasureSlot(); break;
        case 33: _t->on_read_outFactory_pushButton_clicked(); break;
        case 34: _t->on_send_outFactory_pushButton_clicked(); break;
        case 35: _t->AckCmdMain_slot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 36: _t->on_reStoreFactory_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 23:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::openOrCloseSerial_signal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(vector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::calHistogram_signal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sendSerialSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::openOrCloseSerial_signal(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::calHistogram_signal(vector<double> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::sendSerialSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Connect_TCP/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[38];
    char stringdata0[829];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 18), // "signalSendToServer"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 6), // "string"
QT_MOC_LITERAL(4, 38, 13), // "signalGetData"
QT_MOC_LITERAL(5, 52, 18), // "signalGetSweepData"
QT_MOC_LITERAL(6, 71, 16), // "signalGetModData"
QT_MOC_LITERAL(7, 88, 13), // "slotReadyRead"
QT_MOC_LITERAL(8, 102, 9), // "slotError"
QT_MOC_LITERAL(9, 112, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(10, 141, 16), // "slotSendToServer"
QT_MOC_LITERAL(11, 158, 13), // "slotConnected"
QT_MOC_LITERAL(12, 172, 16), // "slotDisconnected"
QT_MOC_LITERAL(13, 189, 16), // "slotRunFreqSweep"
QT_MOC_LITERAL(14, 206, 4), // "data"
QT_MOC_LITERAL(15, 211, 16), // "slotGetSweepData"
QT_MOC_LITERAL(16, 228, 14), // "slotGetModData"
QT_MOC_LITERAL(17, 243, 18), // "on_pb_Send_clicked"
QT_MOC_LITERAL(18, 262, 24), // "on_pb_Connection_clicked"
QT_MOC_LITERAL(19, 287, 24), // "on_pb_Disconnect_clicked"
QT_MOC_LITERAL(20, 312, 27), // "on_le_Command_returnPressed"
QT_MOC_LITERAL(21, 340, 31), // "on_le_Frequency_editingFinished"
QT_MOC_LITERAL(22, 372, 40), // "on_cb_FrequencyUnits_currentI..."
QT_MOC_LITERAL(23, 413, 4), // "arg1"
QT_MOC_LITERAL(24, 418, 25), // "on_le_PEP_editingFinished"
QT_MOC_LITERAL(25, 444, 27), // "on_le_Level_editingFinished"
QT_MOC_LITERAL(26, 472, 29), // "on_action_FreqSweep_triggered"
QT_MOC_LITERAL(27, 502, 28), // "on_tw_Settings_tabBarClicked"
QT_MOC_LITERAL(28, 531, 5), // "index"
QT_MOC_LITERAL(29, 537, 38), // "on_cb_SweepSpacing_currentInd..."
QT_MOC_LITERAL(30, 576, 28), // "on_pb_StartFreqSweep_clicked"
QT_MOC_LITERAL(31, 605, 27), // "on_pb_StopFreqSweep_clicked"
QT_MOC_LITERAL(32, 633, 28), // "on_pb_ResetFreqSweep_clicked"
QT_MOC_LITERAL(33, 662, 45), // "on_cb_AccordingToStandard_cur..."
QT_MOC_LITERAL(34, 708, 43), // "on_lw_AccordingToStandard_cur..."
QT_MOC_LITERAL(35, 752, 10), // "currentRow"
QT_MOC_LITERAL(36, 763, 33), // "on_cb_ModType_currentIndexCha..."
QT_MOC_LITERAL(37, 797, 31) // "on_lw_ModType_currentRowChanged"

    },
    "MainWindow\0signalSendToServer\0\0string\0"
    "signalGetData\0signalGetSweepData\0"
    "signalGetModData\0slotReadyRead\0slotError\0"
    "QAbstractSocket::SocketError\0"
    "slotSendToServer\0slotConnected\0"
    "slotDisconnected\0slotRunFreqSweep\0"
    "data\0slotGetSweepData\0slotGetModData\0"
    "on_pb_Send_clicked\0on_pb_Connection_clicked\0"
    "on_pb_Disconnect_clicked\0"
    "on_le_Command_returnPressed\0"
    "on_le_Frequency_editingFinished\0"
    "on_cb_FrequencyUnits_currentIndexChanged\0"
    "arg1\0on_le_PEP_editingFinished\0"
    "on_le_Level_editingFinished\0"
    "on_action_FreqSweep_triggered\0"
    "on_tw_Settings_tabBarClicked\0index\0"
    "on_cb_SweepSpacing_currentIndexChanged\0"
    "on_pb_StartFreqSweep_clicked\0"
    "on_pb_StopFreqSweep_clicked\0"
    "on_pb_ResetFreqSweep_clicked\0"
    "on_cb_AccordingToStandard_currentIndexChanged\0"
    "on_lw_AccordingToStandard_currentRowChanged\0"
    "currentRow\0on_cb_ModType_currentIndexChanged\0"
    "on_lw_ModType_currentRowChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  164,    2, 0x06 /* Public */,
       4,    1,  167,    2, 0x06 /* Public */,
       5,    0,  170,    2, 0x06 /* Public */,
       6,    0,  171,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  172,    2, 0x08 /* Private */,
       8,    1,  173,    2, 0x08 /* Private */,
      10,    1,  176,    2, 0x08 /* Private */,
      11,    0,  179,    2, 0x08 /* Private */,
      12,    0,  180,    2, 0x08 /* Private */,
      13,    1,  181,    2, 0x08 /* Private */,
      15,    0,  184,    2, 0x08 /* Private */,
      16,    0,  185,    2, 0x08 /* Private */,
      17,    0,  186,    2, 0x08 /* Private */,
      18,    0,  187,    2, 0x08 /* Private */,
      19,    0,  188,    2, 0x08 /* Private */,
      20,    0,  189,    2, 0x08 /* Private */,
      21,    0,  190,    2, 0x08 /* Private */,
      22,    1,  191,    2, 0x08 /* Private */,
      24,    0,  194,    2, 0x08 /* Private */,
      25,    0,  195,    2, 0x08 /* Private */,
      26,    0,  196,    2, 0x08 /* Private */,
      27,    1,  197,    2, 0x08 /* Private */,
      29,    1,  200,    2, 0x08 /* Private */,
      30,    0,  203,    2, 0x08 /* Private */,
      31,    0,  204,    2, 0x08 /* Private */,
      32,    0,  205,    2, 0x08 /* Private */,
      33,    1,  206,    2, 0x08 /* Private */,
      34,    1,  209,    2, 0x08 /* Private */,
      36,    1,  212,    2, 0x08 /* Private */,
      37,    1,  215,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void, QMetaType::Int,   35,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalSendToServer((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 1: _t->signalGetData((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->signalGetSweepData(); break;
        case 3: _t->signalGetModData(); break;
        case 4: _t->slotReadyRead(); break;
        case 5: _t->slotError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 6: _t->slotSendToServer((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 7: _t->slotConnected(); break;
        case 8: _t->slotDisconnected(); break;
        case 9: _t->slotRunFreqSweep((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 10: _t->slotGetSweepData(); break;
        case 11: _t->slotGetModData(); break;
        case 12: _t->on_pb_Send_clicked(); break;
        case 13: _t->on_pb_Connection_clicked(); break;
        case 14: _t->on_pb_Disconnect_clicked(); break;
        case 15: _t->on_le_Command_returnPressed(); break;
        case 16: _t->on_le_Frequency_editingFinished(); break;
        case 17: _t->on_cb_FrequencyUnits_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 18: _t->on_le_PEP_editingFinished(); break;
        case 19: _t->on_le_Level_editingFinished(); break;
        case 20: _t->on_action_FreqSweep_triggered(); break;
        case 21: _t->on_tw_Settings_tabBarClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->on_cb_SweepSpacing_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 23: _t->on_pb_StartFreqSweep_clicked(); break;
        case 24: _t->on_pb_StopFreqSweep_clicked(); break;
        case 25: _t->on_pb_ResetFreqSweep_clicked(); break;
        case 26: _t->on_cb_AccordingToStandard_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->on_lw_AccordingToStandard_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->on_cb_ModType_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->on_lw_ModType_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalSendToServer)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalGetData)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalGetSweepData)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalGetModData)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::signalSendToServer(string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::signalGetData(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::signalGetSweepData()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::signalGetModData()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

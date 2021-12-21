/****************************************************************************
** Meta object code from reading C++ file 'form_client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Connect_TCP/form_client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form_client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Form_Client_t {
    QByteArrayData data[9];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Form_Client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Form_Client_t qt_meta_stringdata_Form_Client = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Form_Client"
QT_MOC_LITERAL(1, 12, 18), // "on_pb_Send_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 24), // "on_pb_Connection_clicked"
QT_MOC_LITERAL(4, 57, 24), // "on_pb_Disconnect_clicked"
QT_MOC_LITERAL(5, 82, 13), // "slotReadyRead"
QT_MOC_LITERAL(6, 96, 9), // "slotError"
QT_MOC_LITERAL(7, 106, 16), // "slotSendToServer"
QT_MOC_LITERAL(8, 123, 13) // "slotConnected"

    },
    "Form_Client\0on_pb_Send_clicked\0\0"
    "on_pb_Connection_clicked\0"
    "on_pb_Disconnect_clicked\0slotReadyRead\0"
    "slotError\0slotSendToServer\0slotConnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Form_Client[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

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

void Form_Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Form_Client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pb_Send_clicked(); break;
        case 1: _t->on_pb_Connection_clicked(); break;
        case 2: _t->on_pb_Disconnect_clicked(); break;
        case 3: _t->slotReadyRead(); break;
        case 4: _t->slotError(); break;
        case 5: _t->slotSendToServer(); break;
        case 6: _t->slotConnected(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Form_Client::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Form_Client.data,
    qt_meta_data_Form_Client,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Form_Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Form_Client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Form_Client.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Form_Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

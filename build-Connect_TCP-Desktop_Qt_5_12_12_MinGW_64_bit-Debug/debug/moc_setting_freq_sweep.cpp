/****************************************************************************
** Meta object code from reading C++ file 'setting_freq_sweep.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Connect_TCP/setting_freq_sweep.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setting_freq_sweep.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Setting_Freq_Sweep_t {
    QByteArrayData data[8];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Setting_Freq_Sweep_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Setting_Freq_Sweep_t qt_meta_stringdata_Setting_Freq_Sweep = {
    {
QT_MOC_LITERAL(0, 0, 18), // "Setting_Freq_Sweep"
QT_MOC_LITERAL(1, 19, 17), // "sign_RunFreqSweep"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 11), // "slotGetData"
QT_MOC_LITERAL(4, 50, 4), // "data"
QT_MOC_LITERAL(5, 55, 28), // "on_pb_StartFreqSweep_clicked"
QT_MOC_LITERAL(6, 84, 38), // "on_cb_SweepSpacing_currentInd..."
QT_MOC_LITERAL(7, 123, 4) // "arg1"

    },
    "Setting_Freq_Sweep\0sign_RunFreqSweep\0"
    "\0slotGetData\0data\0on_pb_StartFreqSweep_clicked\0"
    "on_cb_SweepSpacing_currentIndexChanged\0"
    "arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Setting_Freq_Sweep[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   37,    2, 0x0a /* Public */,
       5,    0,   40,    2, 0x08 /* Private */,
       6,    1,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void Setting_Freq_Sweep::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Setting_Freq_Sweep *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sign_RunFreqSweep((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->slotGetData((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->on_pb_StartFreqSweep_clicked(); break;
        case 3: _t->on_cb_SweepSpacing_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Setting_Freq_Sweep::*)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Setting_Freq_Sweep::sign_RunFreqSweep)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Setting_Freq_Sweep::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_Setting_Freq_Sweep.data,
    qt_meta_data_Setting_Freq_Sweep,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Setting_Freq_Sweep::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Setting_Freq_Sweep::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Setting_Freq_Sweep.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Setting_Freq_Sweep::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Setting_Freq_Sweep::sign_RunFreqSweep(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

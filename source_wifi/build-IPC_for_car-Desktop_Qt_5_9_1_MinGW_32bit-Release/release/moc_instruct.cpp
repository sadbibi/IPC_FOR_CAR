/****************************************************************************
** Meta object code from reading C++ file 'instruct.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../IPC_for_car/instruct.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'instruct.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Instruct_t {
    QByteArrayData data[16];
    char stringdata0[289];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Instruct_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Instruct_t qt_meta_stringdata_Instruct = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Instruct"
QT_MOC_LITERAL(1, 9, 16), // "Send_instruction"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 4), // "data"
QT_MOC_LITERAL(4, 32, 19), // "on_btn_read_clicked"
QT_MOC_LITERAL(5, 52, 25), // "on_btn_write_name_clicked"
QT_MOC_LITERAL(6, 78, 19), // "on_btn_load_clicked"
QT_MOC_LITERAL(7, 98, 25), // "on_btn_write_mode_clicked"
QT_MOC_LITERAL(8, 124, 25), // "on_btn_write_baud_clicked"
QT_MOC_LITERAL(9, 150, 25), // "on_btn_write_size_clicked"
QT_MOC_LITERAL(10, 176, 25), // "on_btn_write_code_clicked"
QT_MOC_LITERAL(11, 202, 28), // "on_btn_write_address_clicked"
QT_MOC_LITERAL(12, 231, 24), // "on_btn_write_com_clicked"
QT_MOC_LITERAL(13, 256, 14), // "rec_time_count"
QT_MOC_LITERAL(14, 271, 12), // "Receive_data"
QT_MOC_LITERAL(15, 284, 4) // "temp"

    },
    "Instruct\0Send_instruction\0\0data\0"
    "on_btn_read_clicked\0on_btn_write_name_clicked\0"
    "on_btn_load_clicked\0on_btn_write_mode_clicked\0"
    "on_btn_write_baud_clicked\0"
    "on_btn_write_size_clicked\0"
    "on_btn_write_code_clicked\0"
    "on_btn_write_address_clicked\0"
    "on_btn_write_com_clicked\0rec_time_count\0"
    "Receive_data\0temp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Instruct[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   77,    2, 0x08 /* Private */,
       5,    0,   78,    2, 0x08 /* Private */,
       6,    0,   79,    2, 0x08 /* Private */,
       7,    0,   80,    2, 0x08 /* Private */,
       8,    0,   81,    2, 0x08 /* Private */,
       9,    0,   82,    2, 0x08 /* Private */,
      10,    0,   83,    2, 0x08 /* Private */,
      11,    0,   84,    2, 0x08 /* Private */,
      12,    0,   85,    2, 0x08 /* Private */,
      13,    0,   86,    2, 0x08 /* Private */,
      14,    1,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,

 // slots: parameters
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
    QMetaType::Void, QMetaType::QByteArray,   15,

       0        // eod
};

void Instruct::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Instruct *_t = static_cast<Instruct *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Send_instruction((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->on_btn_read_clicked(); break;
        case 2: _t->on_btn_write_name_clicked(); break;
        case 3: _t->on_btn_load_clicked(); break;
        case 4: _t->on_btn_write_mode_clicked(); break;
        case 5: _t->on_btn_write_baud_clicked(); break;
        case 6: _t->on_btn_write_size_clicked(); break;
        case 7: _t->on_btn_write_code_clicked(); break;
        case 8: _t->on_btn_write_address_clicked(); break;
        case 9: _t->on_btn_write_com_clicked(); break;
        case 10: _t->rec_time_count(); break;
        case 11: _t->Receive_data((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Instruct::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Instruct::Send_instruction)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Instruct::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Instruct.data,
      qt_meta_data_Instruct,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Instruct::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Instruct::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Instruct.stringdata0))
        return static_cast<void*>(const_cast< Instruct*>(this));
    return QWidget::qt_metacast(_clname);
}

int Instruct::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void Instruct::Send_instruction(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

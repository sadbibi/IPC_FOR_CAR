/****************************************************************************
** Meta object code from reading C++ file 'udpthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../IPC_for_car/udpthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'udpthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UdpThread_t {
    QByteArrayData data[8];
    char stringdata0[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UdpThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UdpThread_t qt_meta_stringdata_UdpThread = {
    {
QT_MOC_LITERAL(0, 0, 9), // "UdpThread"
QT_MOC_LITERAL(1, 10, 9), // "sigRecvOk"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 4), // "data"
QT_MOC_LITERAL(4, 26, 7), // "Ip_send"
QT_MOC_LITERAL(5, 34, 7), // "address"
QT_MOC_LITERAL(6, 42, 8), // "slotRecv"
QT_MOC_LITERAL(7, 51, 7) // "flagset"

    },
    "UdpThread\0sigRecvOk\0\0data\0Ip_send\0"
    "address\0slotRecv\0flagset"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UdpThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   40,    2, 0x0a /* Public */,
       7,    0,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UdpThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UdpThread *_t = static_cast<UdpThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigRecvOk((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->Ip_send((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->slotRecv(); break;
        case 3: _t->flagset(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UdpThread::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UdpThread::sigRecvOk)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (UdpThread::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UdpThread::Ip_send)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject UdpThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_UdpThread.data,
      qt_meta_data_UdpThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *UdpThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UdpThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UdpThread.stringdata0))
        return static_cast<void*>(const_cast< UdpThread*>(this));
    return QThread::qt_metacast(_clname);
}

int UdpThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void UdpThread::sigRecvOk(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UdpThread::Ip_send(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

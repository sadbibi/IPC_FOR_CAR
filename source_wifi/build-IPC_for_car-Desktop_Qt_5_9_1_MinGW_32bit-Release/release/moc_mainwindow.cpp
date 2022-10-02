/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../IPC_for_car/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[25];
    char stringdata0[378];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "serialDataSend"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 4), // "data"
QT_MOC_LITERAL(4, 32, 16), // "sendResultToWave"
QT_MOC_LITERAL(5, 49, 15), // "sendDatatoImage"
QT_MOC_LITERAL(6, 65, 18), // "sendDatatoInstruct"
QT_MOC_LITERAL(7, 84, 22), // "on_btn_seacher_clicked"
QT_MOC_LITERAL(8, 107, 19), // "on_btn_open_clicked"
QT_MOC_LITERAL(9, 127, 24), // "on_btn_sendstart_clicked"
QT_MOC_LITERAL(10, 152, 23), // "on_btn_sendstop_clicked"
QT_MOC_LITERAL(11, 176, 13), // "handleResults"
QT_MOC_LITERAL(12, 190, 6), // "result"
QT_MOC_LITERAL(13, 197, 12), // "setStatusBar"
QT_MOC_LITERAL(14, 210, 1), // "x"
QT_MOC_LITERAL(15, 212, 1), // "y"
QT_MOC_LITERAL(16, 214, 23), // "on_actionwave_triggered"
QT_MOC_LITERAL(17, 238, 24), // "on_actionimage_triggered"
QT_MOC_LITERAL(18, 263, 27), // "on_actioninstruct_triggered"
QT_MOC_LITERAL(19, 291, 23), // "on_actionhelp_triggered"
QT_MOC_LITERAL(20, 315, 19), // "on_checkBox_clicked"
QT_MOC_LITERAL(21, 335, 7), // "checked"
QT_MOC_LITERAL(22, 343, 7), // "Ip_show"
QT_MOC_LITERAL(23, 351, 7), // "address"
QT_MOC_LITERAL(24, 359, 18) // "Instruct_To_Serial"

    },
    "MainWindow\0serialDataSend\0\0data\0"
    "sendResultToWave\0sendDatatoImage\0"
    "sendDatatoInstruct\0on_btn_seacher_clicked\0"
    "on_btn_open_clicked\0on_btn_sendstart_clicked\0"
    "on_btn_sendstop_clicked\0handleResults\0"
    "result\0setStatusBar\0x\0y\0on_actionwave_triggered\0"
    "on_actionimage_triggered\0"
    "on_actioninstruct_triggered\0"
    "on_actionhelp_triggered\0on_checkBox_clicked\0"
    "checked\0Ip_show\0address\0Instruct_To_Serial"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       4,    1,  102,    2, 0x06 /* Public */,
       5,    1,  105,    2, 0x06 /* Public */,
       6,    1,  108,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  111,    2, 0x08 /* Private */,
       8,    0,  112,    2, 0x08 /* Private */,
       9,    0,  113,    2, 0x08 /* Private */,
      10,    0,  114,    2, 0x08 /* Private */,
      11,    1,  115,    2, 0x0a /* Public */,
      13,    2,  118,    2, 0x08 /* Private */,
      16,    0,  123,    2, 0x08 /* Private */,
      17,    0,  124,    2, 0x08 /* Private */,
      18,    0,  125,    2, 0x08 /* Private */,
      19,    0,  126,    2, 0x08 /* Private */,
      20,    1,  127,    2, 0x08 /* Private */,
      22,    1,  130,    2, 0x08 /* Private */,
      24,    1,  133,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QByteArray,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QByteArray,    3,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->serialDataSend((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 1: _t->sendResultToWave((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->sendDatatoImage((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->sendDatatoInstruct((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->on_btn_seacher_clicked(); break;
        case 5: _t->on_btn_open_clicked(); break;
        case 6: _t->on_btn_sendstart_clicked(); break;
        case 7: _t->on_btn_sendstop_clicked(); break;
        case 8: _t->handleResults((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 9: _t->setStatusBar((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->on_actionwave_triggered(); break;
        case 11: _t->on_actionimage_triggered(); break;
        case 12: _t->on_actioninstruct_triggered(); break;
        case 13: _t->on_actionhelp_triggered(); break;
        case 14: _t->on_checkBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->Ip_show((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->Instruct_To_Serial((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(const QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::serialDataSend)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sendResultToWave)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sendDatatoImage)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sendDatatoInstruct)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::serialDataSend(const QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::sendResultToWave(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::sendDatatoImage(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::sendDatatoInstruct(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'imageshow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../IPC_for_car/imageshow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageshow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_imageshow_t {
    QByteArrayData data[27];
    char stringdata0[406];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_imageshow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_imageshow_t qt_meta_stringdata_imageshow = {
    {
QT_MOC_LITERAL(0, 0, 9), // "imageshow"
QT_MOC_LITERAL(1, 10, 12), // "sendPosToGui"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 1), // "x"
QT_MOC_LITERAL(4, 26, 1), // "y"
QT_MOC_LITERAL(5, 28, 11), // "DataToImage"
QT_MOC_LITERAL(6, 40, 4), // "data"
QT_MOC_LITERAL(7, 45, 9), // "getPixPos"
QT_MOC_LITERAL(8, 55, 2), // "pt"
QT_MOC_LITERAL(9, 58, 24), // "on_btn_imagesave_clicked"
QT_MOC_LITERAL(10, 83, 24), // "on_btn_imageread_clicked"
QT_MOC_LITERAL(11, 108, 24), // "on_btn_videosave_clicked"
QT_MOC_LITERAL(12, 133, 24), // "on_btn_videoread_clicked"
QT_MOC_LITERAL(13, 158, 24), // "on_btn_videoshow_clicked"
QT_MOC_LITERAL(14, 183, 9), // "VideoShow"
QT_MOC_LITERAL(15, 193, 25), // "on_PicSlider_valueChanged"
QT_MOC_LITERAL(16, 219, 5), // "value"
QT_MOC_LITERAL(17, 225, 26), // "on_PicSlider_sliderPressed"
QT_MOC_LITERAL(18, 252, 28), // "on_PicSlider_actionTriggered"
QT_MOC_LITERAL(19, 281, 6), // "action"
QT_MOC_LITERAL(20, 288, 24), // "on_PicSlider_sliderMoved"
QT_MOC_LITERAL(21, 313, 8), // "position"
QT_MOC_LITERAL(22, 322, 19), // "on_checkBox_clicked"
QT_MOC_LITERAL(23, 342, 7), // "checked"
QT_MOC_LITERAL(24, 350, 10), // "time_count"
QT_MOC_LITERAL(25, 361, 23), // "on_Pic_01_check_clicked"
QT_MOC_LITERAL(26, 385, 20) // "on_btn_atlas_clicked"

    },
    "imageshow\0sendPosToGui\0\0x\0y\0DataToImage\0"
    "data\0getPixPos\0pt\0on_btn_imagesave_clicked\0"
    "on_btn_imageread_clicked\0"
    "on_btn_videosave_clicked\0"
    "on_btn_videoread_clicked\0"
    "on_btn_videoshow_clicked\0VideoShow\0"
    "on_PicSlider_valueChanged\0value\0"
    "on_PicSlider_sliderPressed\0"
    "on_PicSlider_actionTriggered\0action\0"
    "on_PicSlider_sliderMoved\0position\0"
    "on_checkBox_clicked\0checked\0time_count\0"
    "on_Pic_01_check_clicked\0on_btn_atlas_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_imageshow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,  104,    2, 0x0a /* Public */,
       7,    1,  107,    2, 0x0a /* Public */,
       9,    0,  110,    2, 0x08 /* Private */,
      10,    0,  111,    2, 0x08 /* Private */,
      11,    0,  112,    2, 0x08 /* Private */,
      12,    0,  113,    2, 0x08 /* Private */,
      13,    0,  114,    2, 0x08 /* Private */,
      14,    0,  115,    2, 0x08 /* Private */,
      15,    1,  116,    2, 0x08 /* Private */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    1,  120,    2, 0x08 /* Private */,
      20,    1,  123,    2, 0x08 /* Private */,
      22,    1,  126,    2, 0x08 /* Private */,
      24,    0,  129,    2, 0x08 /* Private */,
      25,    1,  130,    2, 0x08 /* Private */,
      26,    0,  133,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Int, QMetaType::QByteArray,    6,
    QMetaType::Int, QMetaType::QPointF,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void,

       0        // eod
};

void imageshow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        imageshow *_t = static_cast<imageshow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->sendPosToGui((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->DataToImage((*reinterpret_cast< QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->getPixPos((*reinterpret_cast< QPointF(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->on_btn_imagesave_clicked(); break;
        case 4: _t->on_btn_imageread_clicked(); break;
        case 5: _t->on_btn_videosave_clicked(); break;
        case 6: _t->on_btn_videoread_clicked(); break;
        case 7: _t->on_btn_videoshow_clicked(); break;
        case 8: _t->VideoShow(); break;
        case 9: _t->on_PicSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_PicSlider_sliderPressed(); break;
        case 11: _t->on_PicSlider_actionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_PicSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_checkBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->time_count(); break;
        case 15: _t->on_Pic_01_check_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->on_btn_atlas_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef int (imageshow::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&imageshow::sendPosToGui)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject imageshow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_imageshow.data,
      qt_meta_data_imageshow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *imageshow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *imageshow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_imageshow.stringdata0))
        return static_cast<void*>(const_cast< imageshow*>(this));
    return QWidget::qt_metacast(_clname);
}

int imageshow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
int imageshow::sendPosToGui(int _t1, int _t2)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

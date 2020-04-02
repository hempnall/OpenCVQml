/****************************************************************************
** Meta object code from reading C++ file 'blur.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "blur.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'blur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Blur_t {
    QByteArrayData data[8];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Blur_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Blur_t qt_meta_stringdata_Blur = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Blur"
QT_MOC_LITERAL(1, 5, 13), // "heightChanged"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 12), // "widthChanged"
QT_MOC_LITERAL(4, 33, 11), // "sizeChanged"
QT_MOC_LITERAL(5, 45, 4), // "size"
QT_MOC_LITERAL(6, 50, 5), // "width"
QT_MOC_LITERAL(7, 56, 6) // "height"

    },
    "Blur\0heightChanged\0\0widthChanged\0"
    "sizeChanged\0size\0width\0height"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Blur[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       3,   32, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,
       4,    0,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       5, QMetaType::QRect, 0x00495103,
       6, QMetaType::Int, 0x00495103,
       7, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       2,
       1,
       0,

       0        // eod
};

void Blur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Blur *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->heightChanged(); break;
        case 1: _t->widthChanged(); break;
        case 2: _t->sizeChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Blur::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Blur::heightChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Blur::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Blur::widthChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Blur::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Blur::sizeChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Blur *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QRect*>(_v) = _t->size(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->width(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->height(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Blur *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSize(*reinterpret_cast< QRect*>(_v)); break;
        case 1: _t->setWidth(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setHeight(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Blur::staticMetaObject = { {
    &LinearFilter::staticMetaObject,
    qt_meta_stringdata_Blur.data,
    qt_meta_data_Blur,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Blur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Blur::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Blur.stringdata0))
        return static_cast<void*>(this);
    return LinearFilter::qt_metacast(_clname);
}

int Blur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LinearFilter::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Blur::heightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Blur::widthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Blur::sizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

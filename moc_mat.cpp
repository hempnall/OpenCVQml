/****************************************************************************
** Meta object code from reading C++ file 'mat.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mat.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Mat_t {
    QByteArrayData data[11];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Mat_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Mat_t qt_meta_stringdata_Mat = {
    {
QT_MOC_LITERAL(0, 0, 3), // "Mat"
QT_MOC_LITERAL(1, 4, 16), // "baseImageChanged"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 12), // "imageChanged"
QT_MOC_LITERAL(4, 35, 13), // "filterChanged"
QT_MOC_LITERAL(5, 49, 15), // "filenameChanged"
QT_MOC_LITERAL(6, 65, 15), // "invalidateImage"
QT_MOC_LITERAL(7, 81, 8), // "filename"
QT_MOC_LITERAL(8, 90, 5), // "image"
QT_MOC_LITERAL(9, 96, 6), // "filter"
QT_MOC_LITERAL(10, 103, 13) // "LinearFilter*"

    },
    "Mat\0baseImageChanged\0\0imageChanged\0"
    "filterChanged\0filenameChanged\0"
    "invalidateImage\0filename\0image\0filter\0"
    "LinearFilter*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mat[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       3,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,
       5,    0,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags
       7, QMetaType::QString, 0x00495103,
       8, QMetaType::QImage, 0x00495103,
       9, 0x80000000 | 10, 0x0049510b,

 // properties: notify_signal_id
       3,
       1,
       2,

       0        // eod
};

void Mat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Mat *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->baseImageChanged(); break;
        case 1: _t->imageChanged(); break;
        case 2: _t->filterChanged(); break;
        case 3: _t->filenameChanged(); break;
        case 4: _t->invalidateImage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Mat::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Mat::baseImageChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Mat::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Mat::imageChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Mat::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Mat::filterChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Mat::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Mat::filenameChanged)) {
                *result = 3;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< LinearFilter* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Mat *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->filename(); break;
        case 1: *reinterpret_cast< QImage*>(_v) = _t->image(); break;
        case 2: *reinterpret_cast< LinearFilter**>(_v) = _t->filter(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Mat *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setFilename(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setImage(*reinterpret_cast< QImage*>(_v)); break;
        case 2: _t->setFilter(*reinterpret_cast< LinearFilter**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Mat::staticMetaObject = { {
    &QQuickPaintedItem::staticMetaObject,
    qt_meta_stringdata_Mat.data,
    qt_meta_data_Mat,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Mat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mat::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Mat.stringdata0))
        return static_cast<void*>(this);
    return QQuickPaintedItem::qt_metacast(_clname);
}

int Mat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickPaintedItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
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
void Mat::baseImageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Mat::imageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Mat::filterChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Mat::filenameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

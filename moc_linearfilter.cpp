/****************************************************************************
** Meta object code from reading C++ file 'linearfilter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "linearfilter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'linearfilter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LinearFilter_t {
    QByteArrayData data[5];
    char stringdata0[48];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LinearFilter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LinearFilter_t qt_meta_stringdata_LinearFilter = {
    {
QT_MOC_LITERAL(0, 0, 12), // "LinearFilter"
QT_MOC_LITERAL(1, 13, 13), // "sourceChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 12), // "imageChanged"
QT_MOC_LITERAL(4, 41, 6) // "redraw"

    },
    "LinearFilter\0sourceChanged\0\0imageChanged\0"
    "redraw"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LinearFilter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    1,   30,    2, 0x06 /* Public */,
       4,    0,   33,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void,

       0        // eod
};

void LinearFilter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LinearFilter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sourceChanged(); break;
        case 1: _t->imageChanged((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 2: _t->redraw(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LinearFilter::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LinearFilter::sourceChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LinearFilter::*)(const QImage & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LinearFilter::imageChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LinearFilter::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LinearFilter::redraw)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LinearFilter::staticMetaObject = { {
    &QQuickItem::staticMetaObject,
    qt_meta_stringdata_LinearFilter.data,
    qt_meta_data_LinearFilter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LinearFilter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LinearFilter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LinearFilter.stringdata0))
        return static_cast<void*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int LinearFilter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void LinearFilter::sourceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LinearFilter::imageChanged(const QImage & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LinearFilter::redraw()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

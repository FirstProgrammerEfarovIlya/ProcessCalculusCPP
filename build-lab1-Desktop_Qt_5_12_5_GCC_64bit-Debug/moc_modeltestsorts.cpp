/****************************************************************************
** Meta object code from reading C++ file 'modeltestsorts.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../lab1/modeltestsorts.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modeltestsorts.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ModelTestSorts_t {
    QByteArrayData data[10];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModelTestSorts_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModelTestSorts_t qt_meta_stringdata_ModelTestSorts = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ModelTestSorts"
QT_MOC_LITERAL(1, 15, 8), // "progress"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 3), // "val"
QT_MOC_LITERAL(4, 29, 13), // "progress_data"
QT_MOC_LITERAL(5, 43, 49), // "QPair<QVector<double>,QVector..."
QT_MOC_LITERAL(6, 93, 1), // "d"
QT_MOC_LITERAL(7, 95, 8), // "finished"
QT_MOC_LITERAL(8, 104, 4), // "test"
QT_MOC_LITERAL(9, 109, 9) // "stop_test"

    },
    "ModelTestSorts\0progress\0\0val\0progress_data\0"
    "QPair<QVector<double>,QVector<QVector<double> > >\0"
    "d\0finished\0test\0stop_test"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModelTestSorts[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       7,    0,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   46,    2, 0x0a /* Public */,
       9,    0,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ModelTestSorts::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ModelTestSorts *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->progress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->progress_data((*reinterpret_cast< const QPair<QVector<double>,QVector<QVector<double> > >(*)>(_a[1]))); break;
        case 2: _t->finished(); break;
        case 3: _t->test(); break;
        case 4: _t->stop_test(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ModelTestSorts::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModelTestSorts::progress)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ModelTestSorts::*)(const QPair<QVector<double>,QVector<QVector<double>> > & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModelTestSorts::progress_data)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ModelTestSorts::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModelTestSorts::finished)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ModelTestSorts::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ModelTestSorts.data,
    qt_meta_data_ModelTestSorts,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ModelTestSorts::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModelTestSorts::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModelTestSorts.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ModelTestSorts::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void ModelTestSorts::progress(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ModelTestSorts::progress_data(const QPair<QVector<double>,QVector<QVector<double>> > & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ModelTestSorts::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

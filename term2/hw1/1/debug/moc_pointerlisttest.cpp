/****************************************************************************
** Meta object code from reading C++ file 'pointerlisttest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pointerlisttest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pointerlisttest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PointerListTest_t {
    QByteArrayData data[10];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PointerListTest_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PointerListTest_t qt_meta_stringdata_PointerListTest = {
    {
QT_MOC_LITERAL(0, 0, 15), // "PointerListTest"
QT_MOC_LITERAL(1, 16, 4), // "init"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 5), // "clean"
QT_MOC_LITERAL(4, 28, 13), // "testEmptyList"
QT_MOC_LITERAL(5, 42, 14), // "testSizeOfList"
QT_MOC_LITERAL(6, 57, 14), // "testAddElement"
QT_MOC_LITERAL(7, 72, 15), // "testAddElements"
QT_MOC_LITERAL(8, 88, 17), // "testRemoveElement"
QT_MOC_LITERAL(9, 106, 18) // "testRemoveElements"

    },
    "PointerListTest\0init\0\0clean\0testEmptyList\0"
    "testSizeOfList\0testAddElement\0"
    "testAddElements\0testRemoveElement\0"
    "testRemoveElements"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PointerListTest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PointerListTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PointerListTest *_t = static_cast<PointerListTest *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->init(); break;
        case 1: _t->clean(); break;
        case 2: _t->testEmptyList(); break;
        case 3: _t->testSizeOfList(); break;
        case 4: _t->testAddElement(); break;
        case 5: _t->testAddElements(); break;
        case 6: _t->testRemoveElement(); break;
        case 7: _t->testRemoveElements(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject PointerListTest::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PointerListTest.data,
      qt_meta_data_PointerListTest,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PointerListTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PointerListTest::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PointerListTest.stringdata0))
        return static_cast<void*>(const_cast< PointerListTest*>(this));
    return QObject::qt_metacast(_clname);
}

int PointerListTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

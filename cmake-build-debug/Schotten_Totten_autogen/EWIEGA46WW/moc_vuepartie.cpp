/****************************************************************************
** Meta object code from reading C++ file 'vuepartie.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../vuepartie.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vuepartie.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSVuePartieENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSVuePartieENDCLASS = QtMocHelpers::stringData(
    "VuePartie",
    "onCardClicked",
    "",
    "VueCarte*",
    "vc",
    "onPiocheClicked",
    "VuePioche*",
    "p",
    "onBorneClicked",
    "VueBorne*",
    "b"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSVuePartieENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[10];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[3];
    char stringdata5[16];
    char stringdata6[11];
    char stringdata7[2];
    char stringdata8[15];
    char stringdata9[10];
    char stringdata10[2];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSVuePartieENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSVuePartieENDCLASS_t qt_meta_stringdata_CLASSVuePartieENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "VuePartie"
        QT_MOC_LITERAL(10, 13),  // "onCardClicked"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 9),  // "VueCarte*"
        QT_MOC_LITERAL(35, 2),  // "vc"
        QT_MOC_LITERAL(38, 15),  // "onPiocheClicked"
        QT_MOC_LITERAL(54, 10),  // "VuePioche*"
        QT_MOC_LITERAL(65, 1),  // "p"
        QT_MOC_LITERAL(67, 14),  // "onBorneClicked"
        QT_MOC_LITERAL(82, 9),  // "VueBorne*"
        QT_MOC_LITERAL(92, 1)   // "b"
    },
    "VuePartie",
    "onCardClicked",
    "",
    "VueCarte*",
    "vc",
    "onPiocheClicked",
    "VuePioche*",
    "p",
    "onBorneClicked",
    "VueBorne*",
    "b"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSVuePartieENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x08,    1 /* Private */,
       5,    1,   35,    2, 0x08,    3 /* Private */,
       8,    1,   38,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

Q_CONSTINIT const QMetaObject VuePartie::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSVuePartieENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSVuePartieENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSVuePartieENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<VuePartie, std::true_type>,
        // method 'onCardClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<VueCarte *, std::false_type>,
        // method 'onPiocheClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<VuePioche *, std::false_type>,
        // method 'onBorneClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<VueBorne *, std::false_type>
    >,
    nullptr
} };

void VuePartie::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VuePartie *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onCardClicked((*reinterpret_cast< std::add_pointer_t<VueCarte*>>(_a[1]))); break;
        case 1: _t->onPiocheClicked((*reinterpret_cast< std::add_pointer_t<VuePioche*>>(_a[1]))); break;
        case 2: _t->onBorneClicked((*reinterpret_cast< std::add_pointer_t<VueBorne*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< VueCarte* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< VuePioche* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< VueBorne* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *VuePartie::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VuePartie::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSVuePartieENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int VuePartie::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP

/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created: Sat Apr 20 02:08:17 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/MainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   12,   11,   11, 0x08,
      31,   28,   11,   11, 0x08,
      52,   49,   11,   11, 0x08,
      75,   71,   11,   11, 0x08,
      89,   11,   11,   11, 0x08,
     100,   97,   11,   11, 0x08,
     116,   97,   11,   11, 0x08,
     135,  132,   11,   11, 0x08,
     151,   11,   11,   11, 0x08,
     166,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0_v\0setK(double)\0_l\0"
    "setLength(double)\0_d\0setDamping(double)\0"
    "_dt\0setDT(double)\0reset()\0_f\0"
    "setAFixed(bool)\0setBFixed(bool)\0_s\0"
    "toggleSim(bool)\0setAPosition()\0"
    "setBPosition()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->setK((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->setLength((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->setDamping((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->setDT((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->reset(); break;
        case 5: _t->setAFixed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->setBFixed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->toggleSim((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->setAPosition(); break;
        case 9: _t->setBPosition(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

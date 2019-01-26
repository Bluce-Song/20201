/****************************************************************************
** Meta object code from reading C++ file 'MyCanThread.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../aip-update/MyCanThread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyCanThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyCanThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   13,   12,   12, 0x05,
      40,   36,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      59,   12,   12,   12, 0x0a,
      74,   12,   69,   12, 0x0a,
      84,   12,   12,   12, 0x0a,
     102,   96,   69,   12, 0x0a,
     124,   12,   69,   12, 0x0a,
     136,   36,   12,   12, 0x0a,
     158,   12,   12,   12, 0x0a,
     169,   12,   12,   12, 0x0a,
     182,   36,   12,   12, 0x0a,
     207,  202,   12,   12, 0x0a,
     225,   13,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyCanThread[] = {
    "MyCanThread\0\0dev\0DevInsert(QString)\0"
    "msg\0MsgInsert(QString)\0CanInit()\0bool\0"
    "CanOpen()\0KeepAlive()\0TxMsg\0"
    "WriteFrame(can_frame)\0ReadFrame()\0"
    "WritePage(QByteArray)\0ReadPage()\0"
    "ExecuteCmd()\0SendMsg(QByteArray)\0name\0"
    "SendText(QString)\0DevReset(int)\0"
};

void MyCanThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyCanThread *_t = static_cast<MyCanThread *>(_o);
        switch (_id) {
        case 0: _t->DevInsert((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->MsgInsert((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->CanInit(); break;
        case 3: { bool _r = _t->CanOpen();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: _t->KeepAlive(); break;
        case 5: { bool _r = _t->WriteFrame((*reinterpret_cast< can_frame(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->ReadFrame();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: _t->WritePage((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 8: _t->ReadPage(); break;
        case 9: _t->ExecuteCmd(); break;
        case 10: _t->SendMsg((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 11: _t->SendText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->DevReset((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyCanThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyCanThread::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MyCanThread,
      qt_meta_data_MyCanThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyCanThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyCanThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyCanThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyCanThread))
        return static_cast<void*>(const_cast< MyCanThread*>(this));
    return QObject::qt_metacast(_clname);
}

int MyCanThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MyCanThread::DevInsert(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyCanThread::MsgInsert(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE

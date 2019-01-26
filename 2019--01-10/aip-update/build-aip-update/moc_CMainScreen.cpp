/****************************************************************************
** Meta object code from reading C++ file 'CMainScreen.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../aip-update/CMainScreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CMainScreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CMainScreen[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      33,   12,   12,   12, 0x05,
      55,   51,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      69,   12,   12,   12, 0x08,
      79,   51,   12,   12, 0x08,
     102,   98,   12,   12, 0x08,
     130,  121,   12,   12, 0x08,
     157,  152,   12,   12, 0x08,
     180,   12,   12,   12, 0x08,
     203,   12,   12,   12, 0x08,
     224,   12,   12,   12, 0x08,
     255,  244,   12,   12, 0x08,
     291,   12,   12,   12, 0x08,
     314,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CMainScreen[] = {
    "CMainScreen\0\0SendMsg(QByteArray)\0"
    "SendText(QString)\0dev\0DevReset(int)\0"
    "CanInit()\0DevInsert(QString)\0msg\0"
    "MsgInsert(QString)\0hardware\0"
    "ShowFirmware(QString)\0path\0"
    "CheckFirmware(QString)\0on_btnUpdate_clicked()\0"
    "on_btnExit_clicked()\0on_btnRun_clicked()\0"
    "row,column\0on_tabSoftware_cellClicked(int,int)\0"
    "on_btnDelete_clicked()\0on_KeyReset_clicked()\0"
};

void CMainScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CMainScreen *_t = static_cast<CMainScreen *>(_o);
        switch (_id) {
        case 0: _t->SendMsg((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->SendText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->DevReset((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->CanInit(); break;
        case 4: _t->DevInsert((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->MsgInsert((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->ShowFirmware((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->CheckFirmware((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->on_btnUpdate_clicked(); break;
        case 9: _t->on_btnExit_clicked(); break;
        case 10: _t->on_btnRun_clicked(); break;
        case 11: _t->on_tabSoftware_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->on_btnDelete_clicked(); break;
        case 13: _t->on_KeyReset_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CMainScreen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CMainScreen::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CMainScreen,
      qt_meta_data_CMainScreen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CMainScreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CMainScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CMainScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CMainScreen))
        return static_cast<void*>(const_cast< CMainScreen*>(this));
    return QWidget::qt_metacast(_clname);
}

int CMainScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void CMainScreen::SendMsg(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CMainScreen::SendText(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CMainScreen::DevReset(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

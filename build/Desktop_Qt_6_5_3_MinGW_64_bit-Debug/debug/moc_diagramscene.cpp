/****************************************************************************
** Meta object code from reading C++ file 'diagramscene.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../diagramscene.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'diagramscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
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
struct qt_meta_stringdata_CLASSDiagramSceneENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSDiagramSceneENDCLASS = QtMocHelpers::stringData(
    "DiagramScene",
    "itemInserted",
    "",
    "DiagramItem*",
    "item",
    "textInserted",
    "QGraphicsTextItem*",
    "itemSelected",
    "QGraphicsItem*",
    "setMode",
    "Mode",
    "mode",
    "setItemType",
    "DiagramItem::DiagramType",
    "type",
    "editorLostFocus",
    "DiagramTextItem*"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSDiagramSceneENDCLASS_t {
    uint offsetsAndSizes[34];
    char stringdata0[13];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[5];
    char stringdata5[13];
    char stringdata6[19];
    char stringdata7[13];
    char stringdata8[15];
    char stringdata9[8];
    char stringdata10[5];
    char stringdata11[5];
    char stringdata12[12];
    char stringdata13[25];
    char stringdata14[5];
    char stringdata15[16];
    char stringdata16[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSDiagramSceneENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSDiagramSceneENDCLASS_t qt_meta_stringdata_CLASSDiagramSceneENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "DiagramScene"
        QT_MOC_LITERAL(13, 12),  // "itemInserted"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 12),  // "DiagramItem*"
        QT_MOC_LITERAL(40, 4),  // "item"
        QT_MOC_LITERAL(45, 12),  // "textInserted"
        QT_MOC_LITERAL(58, 18),  // "QGraphicsTextItem*"
        QT_MOC_LITERAL(77, 12),  // "itemSelected"
        QT_MOC_LITERAL(90, 14),  // "QGraphicsItem*"
        QT_MOC_LITERAL(105, 7),  // "setMode"
        QT_MOC_LITERAL(113, 4),  // "Mode"
        QT_MOC_LITERAL(118, 4),  // "mode"
        QT_MOC_LITERAL(123, 11),  // "setItemType"
        QT_MOC_LITERAL(135, 24),  // "DiagramItem::DiagramType"
        QT_MOC_LITERAL(160, 4),  // "type"
        QT_MOC_LITERAL(165, 15),  // "editorLostFocus"
        QT_MOC_LITERAL(181, 16)   // "DiagramTextItem*"
    },
    "DiagramScene",
    "itemInserted",
    "",
    "DiagramItem*",
    "item",
    "textInserted",
    "QGraphicsTextItem*",
    "itemSelected",
    "QGraphicsItem*",
    "setMode",
    "Mode",
    "mode",
    "setItemType",
    "DiagramItem::DiagramType",
    "type",
    "editorLostFocus",
    "DiagramTextItem*"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDiagramSceneENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x06,    1 /* Public */,
       5,    1,   53,    2, 0x06,    3 /* Public */,
       7,    1,   56,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    1,   59,    2, 0x0a,    7 /* Public */,
      12,    1,   62,    2, 0x0a,    9 /* Public */,
      15,    1,   65,    2, 0x0a,   11 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    4,
    QMetaType::Void, 0x80000000 | 8,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 16,    4,

       0        // eod
};

Q_CONSTINIT const QMetaObject DiagramScene::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsScene::staticMetaObject>(),
    qt_meta_stringdata_CLASSDiagramSceneENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDiagramSceneENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDiagramSceneENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DiagramScene, std::true_type>,
        // method 'itemInserted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<DiagramItem *, std::false_type>,
        // method 'textInserted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QGraphicsTextItem *, std::false_type>,
        // method 'itemSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QGraphicsItem *, std::false_type>,
        // method 'setMode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Mode, std::false_type>,
        // method 'setItemType'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<DiagramItem::DiagramType, std::false_type>,
        // method 'editorLostFocus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<DiagramTextItem *, std::false_type>
    >,
    nullptr
} };

void DiagramScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DiagramScene *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->itemInserted((*reinterpret_cast< std::add_pointer_t<DiagramItem*>>(_a[1]))); break;
        case 1: _t->textInserted((*reinterpret_cast< std::add_pointer_t<QGraphicsTextItem*>>(_a[1]))); break;
        case 2: _t->itemSelected((*reinterpret_cast< std::add_pointer_t<QGraphicsItem*>>(_a[1]))); break;
        case 3: _t->setMode((*reinterpret_cast< std::add_pointer_t<Mode>>(_a[1]))); break;
        case 4: _t->setItemType((*reinterpret_cast< std::add_pointer_t<DiagramItem::DiagramType>>(_a[1]))); break;
        case 5: _t->editorLostFocus((*reinterpret_cast< std::add_pointer_t<DiagramTextItem*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QGraphicsTextItem* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QGraphicsItem* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< DiagramTextItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DiagramScene::*)(DiagramItem * );
            if (_t _q_method = &DiagramScene::itemInserted; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DiagramScene::*)(QGraphicsTextItem * );
            if (_t _q_method = &DiagramScene::textInserted; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DiagramScene::*)(QGraphicsItem * );
            if (_t _q_method = &DiagramScene::itemSelected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *DiagramScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DiagramScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDiagramSceneENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int DiagramScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void DiagramScene::itemInserted(DiagramItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DiagramScene::textInserted(QGraphicsTextItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DiagramScene::itemSelected(QGraphicsItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP

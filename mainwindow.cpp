#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "arrow.h"
#include "diagramitem.h"
#include "diagramscene.h"
#include "diagramtextitem.h"
#include <QtWidgets>
#include <QFileDialog>
#include <QSvgGenerator>


const int InsertTextButton = 10;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    createActions();
    createToolBox();
    createMenus();

    scene = new DiagramScene(itemMenu, this);
    scene->setSceneRect(QRectF(0, 0, 5000, 5000));
    connect(scene, &DiagramScene::itemInserted,
            this, &MainWindow::itemInserted);
    connect(scene, &DiagramScene::textInserted,
            this, &MainWindow::textInserted);
    connect(scene, &DiagramScene::itemSelected,
            this, &MainWindow::itemSelected);

    createToolbars();

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(toolBox);

    view = new QGraphicsView(scene);
    view->setDragMode(QGraphicsView::RubberBandDrag);
    layout->addWidget(view);

    QWidget *widget = new QWidget;
    widget->setLayout(layout);

    setCentralWidget(widget);
    setWindowTitle(tr("流程图编辑器"));
    setUnifiedTitleAndToolBarOnMac(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::contextMenuEvent(QContextMenuEvent*event)
{
    QMenu *menu = new QMenu(this);

    auto action_del = new QAction("save",this);
    auto action_copy = new QAction("copy",this);
    auto action_export = new QAction("export",this);

    connect(action_del,&QAction::triggered,this, &MainWindow::save);
    menu->addAction(action_del);
    menu->exec(this->cursor().pos());
}

void MainWindow::createActions()
{
    UpAction = new QAction(QIcon("D:/Qt/qtcode/Project/homework/images/picture (1).png"),
                           tr("&前置"), this);
    UpAction->setShortcut(tr("Ctrl+F"));
    UpAction->setStatusTip(tr("将所选图元前置"));
    connect(UpAction, &QAction::triggered, this, &MainWindow::bringToFront);


    DownAction = new QAction(QIcon("D:/Qt/qtcode/Project/homework/images/picture (2).png"),
                             tr("&后置"), this);
    DownAction->setShortcut(tr("Ctrl+T"));
    DownAction->setStatusTip(tr("将所选图元后置"));
    connect(DownAction, &QAction::triggered, this, &MainWindow::sendToBack);

    DeleteAction = new QAction(QIcon("D:/Qt/qtcode/Project/homework/images/picture (11).png"),
                               tr("&删除"), this);
    DeleteAction->setShortcut(tr("Delete"));
    DeleteAction->setStatusTip(tr("将所选图元删除"));
    connect(DeleteAction, &QAction::triggered, this, &MainWindow::deleteItem);

    ExitAction = new QAction(QIcon("D:/Qt/qtcode/Project/homework/images/picture (13).png"),
                             tr("退出"), this);
    ExitAction->setShortcuts(QKeySequence::Quit);
    ExitAction->setStatusTip(tr("退出流程图！！！"));
    connect(ExitAction, &QAction::triggered, this, &QWidget::close);

    BoldAction = new QAction(tr("加粗"), this);
    BoldAction->setCheckable(true);
    QPixmap pixmap("D:/Qt/qtcode/Project/homework/images/fontbig.png");
    BoldAction->setIcon(QIcon(pixmap));
    BoldAction->setShortcut(tr("Ctrl+B"));
    connect(BoldAction, &QAction::triggered, this, &MainWindow::handleFontChange);


    UnderlineAction = new QAction(QIcon("D:/Qt/qtcode/Project/homework/images/underline.png"),
                                  tr("下划线"), this);
    UnderlineAction->setCheckable(true);
    UnderlineAction->setShortcut(tr("Ctrl+U"));
    connect(UnderlineAction, &QAction::triggered, this, &MainWindow::handleFontChange);

    XietiAction = new QAction(QIcon("D:/Qt/qtcode/Project/homework/images/xieti.png"),
                              tr("斜体"), this);
    XietiAction->setCheckable(true);
    XietiAction->setShortcut(tr("Ctrl+I"));
    connect(XietiAction, &QAction::triggered, this, &MainWindow::handleFontChange);

    BigAction = new QAction(QIcon("D:/Qt/qtcode/Project/homework/images/picture (7).png"),
                            tr("放大"), this);
    connect(BigAction, &QAction::triggered, this, &MainWindow::bigchange);

    SmallAction = new QAction(QIcon("D:/Qt/qtcode/Project/homework/images/picture (12).png"),
                              tr("缩小"), this);
    connect(SmallAction, &QAction::triggered, this, &MainWindow::smallchange);

    SaveSvgAction = new QAction(QIcon("D:/Qt/qtcode/Project/homework/images/save.png"),
                                tr("保存"), this);
    connect(SaveSvgAction, &QAction::triggered, this, &MainWindow::saveAsSvg);

}
void MainWindow::createToolBox()
{
    buttonGroup = new QButtonGroup(this);
    buttonGroup->setExclusive(false);
    connect(buttonGroup, &QButtonGroup::buttonClicked, this, [this](QAbstractButton* button) {
        int id = buttonGroup->id(button);
        buttonGroupClicked(id);
    });


    QGridLayout *layout = new QGridLayout;

    layout->addWidget(createCellWidget(tr("判断"), DiagramItem::Conditional), 0, 0);
    layout->addWidget(createCellWidget(tr("进程"), DiagramItem::Step),0, 1);
    layout->addWidget(createCellWidget(tr("数据"), DiagramItem::Io), 1, 0);
    layout->addWidget(createCellWidget(tr("联系"), DiagramItem::circle), 2, 0);
    layout->addWidget(createCellWidget(tr("控制传递"), DiagramItem::triangle), 2, 1);


    QToolButton *textButton = new QToolButton;
    textButton->setCheckable(true);
    buttonGroup->addButton(textButton, InsertTextButton);
    textButton->setText("文字");
    textButton->setIcon(QIcon(QPixmap("D:/Qt/qtcode/Project/homework/images/wenzi.png")));
    textButton->setIconSize(QSize(50, 50));

    QGridLayout *textLayout = new QGridLayout;
    textLayout->addWidget(textButton, 0, 0, Qt::AlignHCenter);

    textLayout->addWidget(new QLabel(tr("文字")), 1, 0, Qt::AlignCenter);
    QWidget *textWidget = new QWidget;
    textWidget->setLayout(textLayout);

    layout->addWidget(textWidget, 1, 1);
    layout->setRowStretch(3, 10);
    layout->setColumnStretch(2, 10);

    QWidget *itemWidget = new QWidget;
    itemWidget->setLayout(layout);

    backgroundButtonGroup = new QButtonGroup(this);
    connect(backgroundButtonGroup, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),
            this, &MainWindow::backgroundButtonGroupClicked);

    QGridLayout *backgroundLayout = new QGridLayout;
    backgroundLayout->addWidget(createBackgroundCellWidget(tr("蓝白间隔"),
                                                           "D:/Qt/qtcode/Project/homework/images/background1.jpg"), 0, 0);
    backgroundLayout->addWidget(createBackgroundCellWidget(tr("格子背景"),
                                                           "D:/Qt/qtcode/Project/homework/images/background2.png"), 0, 1);
    backgroundLayout->addWidget(createBackgroundCellWidget(tr("灰白间隔"),
                                                           "D:/Qt/qtcode/Project/homework/images/background3.png"), 1, 0);
    backgroundLayout->addWidget(createBackgroundCellWidget(tr("空白背景"),
                                                           "D:/Qt/qtcode/Project/homework/images/background4.png"), 1, 1);

    backgroundLayout->setRowStretch(2, 10);
    backgroundLayout->setColumnStretch(2, 10);

    QWidget *backgroundWidget = new QWidget;
    backgroundWidget->setLayout(backgroundLayout);

    toolBox = new QToolBox;
    toolBox->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Ignored));
    toolBox->setMinimumWidth(itemWidget->sizeHint().width());
    toolBox->addItem(itemWidget, tr("选择流程图图元"));
    toolBox->addItem(backgroundWidget, tr("背景选取"));

}
void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&文件"));
    fileMenu->addAction(SaveSvgAction);  // 新增保存SVG的菜单项
    fileMenu->addAction(ExitAction);

    itemMenu = menuBar()->addMenu(tr("&操作事件"));
    itemMenu->addAction(DeleteAction);
    itemMenu->addSeparator();
    itemMenu->addAction(UpAction);
    itemMenu->addAction(DownAction);

}



void MainWindow::createToolbars()
{
    //关于工具栏的创建
    editToolBar = addToolBar(tr("工具栏"));
    editToolBar->addAction(DeleteAction);
    editToolBar->addAction(UpAction);
    editToolBar->addAction(DownAction);
    editToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    //关于颜色修改栏的创建
    FontColorToolButton = new QToolButton;
    FontColorToolButton->setPopupMode(QToolButton::MenuButtonPopup);
    FontColorToolButton->setMenu(createColorMenu(SLOT(textColorChanged()), Qt::black));
    TextAction = FontColorToolButton->menu()->defaultAction();
    FontColorToolButton->setIcon(createColorToolButtonIcon(
        "D:/Qt/qtcode/Project/homework/images/textpointer.png", Qt::black));
    FontColorToolButton->setAutoFillBackground(true);
    connect(FontColorToolButton, &QAbstractButton::clicked,
            this, &MainWindow::textButtonTriggered);

    FillColorToolButton = new QToolButton;
    FillColorToolButton->setPopupMode(QToolButton::MenuButtonPopup);
    FillColorToolButton->setMenu(createColorMenu(SLOT(itemColorChanged()), Qt::black));
    FillAction = FillColorToolButton->menu()->defaultAction();
    FillColorToolButton->setIcon(createColorToolButtonIcon(
        "D:/Qt/qtcode/Project/homework/images/floodfill.png", Qt::black));
    connect(FillColorToolButton, &QAbstractButton::clicked,
            this, &MainWindow::fillButtonTriggered);

    LineColorToolButton = new QToolButton;
    LineColorToolButton->setPopupMode(QToolButton::MenuButtonPopup);
    LineColorToolButton->setMenu(createColorMenu(SLOT(lineColorChanged()), Qt::black));
    LineAction = LineColorToolButton->menu()->defaultAction();
    LineColorToolButton->setIcon(createColorToolButtonIcon(
        "D:/Qt/qtcode/Project/homework/images/linecolor.png", Qt::black));
    connect(LineColorToolButton, &QAbstractButton::clicked,
            this, &MainWindow::lineButtonTriggered);

    colorToolBar = addToolBar(tr("颜色栏"));
    colorToolBar->addWidget(FontColorToolButton);
    colorToolBar->addWidget(FillColorToolButton);
    colorToolBar->addWidget(LineColorToolButton);
    colorToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    //关于文字修改栏的创建
    fontCombo = new QFontComboBox();
    connect(fontCombo, &QFontComboBox::currentFontChanged,
            this, &MainWindow::currentFontChanged);

    fontSizeCombo = new QComboBox;
    fontSizeCombo->setEditable(true);
    for (int i = 8; i < 30; i = i + 2)
        fontSizeCombo->addItem(QString().setNum(i));
    QIntValidator *validator = new QIntValidator(2, 64, this);
    fontSizeCombo->setValidator(validator);
    connect(fontSizeCombo, &QComboBox::currentTextChanged,
            this, &MainWindow::fontSizeChanged);

    fontToolBar = addToolBar(tr("文字工具栏"));
    fontToolBar->addWidget(fontCombo);
    fontToolBar->addWidget(fontSizeCombo);
    fontToolBar->addAction(BoldAction);
    fontToolBar->addAction(UnderlineAction);
    fontToolBar->addAction(XietiAction);
    fontToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    QToolButton *pointerButton = new QToolButton;
    pointerButton->setCheckable(true);
    pointerButton->setChecked(true);
    pointerButton->setIcon(QIcon("D:/Qt/qtcode/Project/homework/images/mouse.png"));
    QToolButton *linePointerButton = new QToolButton;
    linePointerButton->setCheckable(true);
    linePointerButton->setIcon(QIcon("D:/Qt/qtcode/Project/homework/images/line.png"));

    pointerTypeGroup = new QButtonGroup(this);
    pointerTypeGroup->addButton(pointerButton, int(DiagramScene::MoveItem));
    pointerTypeGroup->addButton(linePointerButton, int(DiagramScene::InsertLine));
    connect(pointerTypeGroup, &QButtonGroup::buttonClicked, this, &MainWindow::pointerGroupClicked);


    sceneScaleCombo = new QComboBox;
    QStringList scales;
    scales << tr("50%") << tr("75%") << tr("100%") << tr("125%") << tr("150%");
    sceneScaleCombo->addItems(scales);
    sceneScaleCombo->setCurrentIndex(2);
    connect(sceneScaleCombo, &QComboBox::currentTextChanged,
            this, &MainWindow::sceneScaleChanged);

    pointerToolbar = addToolBar(tr("主要操作栏"));
    pointerToolbar->addWidget(pointerButton);
    pointerToolbar->addWidget(linePointerButton);
    pointerToolbar->addWidget(sceneScaleCombo);


    styleToolbar = addToolBar(tr("图形形状栏"));
    styleToolbar->addAction(BigAction);
    styleToolbar->addAction(SmallAction);
    styleToolbar->addAction(SaveAction);
    styleToolbar->addAction(ExitAction);
    styleToolbar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);



}

QMenu *MainWindow::createColorMenu(const char *slot, QColor defaultColor)
{
    QList<QColor> colors;
    colors << Qt::black << Qt::green << Qt::red << Qt::blue << Qt::yellow;
    QStringList names;
    names << tr("黑色") << tr("绿色") << tr("红色") << tr("蓝色")
          << tr("黄色");
    QMenu *colorMenu = new QMenu(this);
    for (int i = 0; i < colors.count(); ++i) {
        QAction *action = new QAction(names.at(i), this);
        action->setData(colors.at(i));
        action->setIcon(createColorIcon(colors.at(i)));
        connect(action, SIGNAL(triggered()), this, slot);
        colorMenu->addAction(action);
        if (colors.at(i) == defaultColor)
            colorMenu->setDefaultAction(action);
    }
    return colorMenu;
}

QIcon MainWindow::createColorIcon(QColor color)
{
    QPixmap pixmap(20, 20);
    QPainter painter(&pixmap);
    painter.setPen(Qt::NoPen);
    painter.fillRect(QRect(0, 0, 20, 20), color);
    return QIcon(pixmap);
}

QIcon MainWindow::createColorToolButtonIcon(const QString &imageFile, QColor color)
{
    QPixmap pixmap(50, 80);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    QPixmap image(imageFile);
    QRect target(4, 0, 42, 43);
    QRect source(0, 0, 42, 43);
    painter.fillRect(QRect(0, 60, 50, 80), color);
    painter.drawPixmap(target, image, source);
    return QIcon(pixmap);
}

QWidget *MainWindow::createBackgroundCellWidget(const QString &text, const QString &image)
{
    QToolButton *button = new QToolButton;

    button->setText(text);
    button->setIcon(QIcon(image));
    button->setIconSize(QSize(50, 50));
    button->setCheckable(true);
    backgroundButtonGroup->addButton(button);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(button, 0, 0, Qt::AlignHCenter);
    layout->addWidget(new QLabel(text), 1, 0, Qt::AlignCenter);

    QWidget *widget = new QWidget;
    widget->setLayout(layout);

    return widget;
}

QWidget *MainWindow::createCellWidget(const QString &text, DiagramItem::DiagramType type)
{
    DiagramItem item(type, itemMenu);
    QIcon icon(item.image());

    QToolButton *button = new QToolButton;
    button->setIcon(icon);
    button->setIconSize(QSize(50, 50));
    button->setCheckable(true);
    buttonGroup->addButton(button, int(type));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(button, 0, 0, Qt::AlignHCenter);
    layout->addWidget(new QLabel(text), 1, 0, Qt::AlignCenter);

    QWidget *widget = new QWidget;
    widget->setLayout(layout);

    return widget;
}

void MainWindow::buttonGroupClicked(int id)
{
    const QList<QAbstractButton *> buttons = buttonGroup->buttons();
    for (QAbstractButton *button : buttons) {
        if (buttonGroup->button(id) != button)
            button->setChecked(false);
    }
    if (id == InsertTextButton) {
        scene->setMode(DiagramScene::InsertText);
    } else {
        scene->setItemType(DiagramItem::DiagramType(id));
        scene->setMode(DiagramScene::InsertItem);
    }
}

void MainWindow::backgroundButtonGroupClicked(QAbstractButton *button)
{
    const QList<QAbstractButton *> buttons = backgroundButtonGroup->buttons();
    for (QAbstractButton *myButton : buttons) {
        if (myButton != button)
            button->setChecked(false);
    }
    QString text = button->text();
    if (text == tr("蓝白间隔"))
        scene->setBackgroundBrush(QPixmap("D:/Qt/qtcode/Project/homework/images/background1.jpg"));
    else if (text == tr("格子背景"))
        scene->setBackgroundBrush(QPixmap("D:/Qt/qtcode/Project/homework/images/background2.png"));
    else if (text == tr("灰白间隔"))
        scene->setBackgroundBrush(QPixmap("D:/Qt/qtcode/Project/homework/images/background3.png"));
    else
        scene->setBackgroundBrush(QPixmap("D:/Qt/qtcode/Project/homework/images/background4.png"));
    scene->update();
    view->update();
}

void MainWindow::itemInserted(DiagramItem *item)
{
    pointerTypeGroup->button(int(DiagramScene::MoveItem))->setChecked(true);
    scene->setMode(DiagramScene::Mode(pointerTypeGroup->checkedId()));
    buttonGroup->button(int(item->diagramType()))->setChecked(false);
}

void MainWindow::textInserted(QGraphicsTextItem *item)
{
    buttonGroup->button(InsertTextButton)->setChecked(false);
    scene->setMode(DiagramScene::Mode(pointerTypeGroup->checkedId()));
}

void MainWindow::itemSelected(QGraphicsItem *item)
{
    DiagramTextItem *textItem =
        qgraphicsitem_cast<DiagramTextItem *>(item);

    QFont font = textItem->font();
    fontCombo->setCurrentFont(font);
    fontSizeCombo->setEditText(QString().setNum(font.pointSize()));
    BoldAction->setChecked(font.weight() == QFont::Bold);
    XietiAction->setChecked(font.italic());
    UnderlineAction->setChecked(font.underline());
}

void MainWindow::bringToFront()
{
    if (scene->selectedItems().isEmpty())
        return;

    QGraphicsItem *selectedItem = scene->selectedItems().first();
    QList<QGraphicsItem *> overlapItems = selectedItem->collidingItems();

    qreal zValue = 0;
    foreach (QGraphicsItem *item, overlapItems) {
        if (item->zValue() >= zValue && item->type() == DiagramItem::Type)
            zValue = item->zValue() + 0.1;
    }
    selectedItem->setZValue(zValue);
}

void MainWindow::sendToBack()
{
    if (scene->selectedItems().isEmpty())
        return;

    QGraphicsItem *selectedItem = scene->selectedItems().first();
    QList<QGraphicsItem *> overlapItems = selectedItem->collidingItems();

    qreal zValue = 0;
    foreach (QGraphicsItem *item, overlapItems) {
        if (item->zValue() <= zValue && item->type() == DiagramItem::Type)
            zValue = item->zValue() - 0.1;
    }
    selectedItem->setZValue(zValue);
}

void MainWindow::deleteItem()
{
    foreach (QGraphicsItem *item, scene->selectedItems()) {
        if (item->type() == Arrow::Type) {
            scene->removeItem(item);
            Arrow *arrow = qgraphicsitem_cast<Arrow *>(item);
            arrow->startItem()->removeArrow(arrow);
            arrow->endItem()->removeArrow(arrow);
            delete item;
        }
    }

    foreach (QGraphicsItem *item, scene->selectedItems()) {
        if (item->type() == DiagramItem::Type)
            qgraphicsitem_cast<DiagramItem *>(item)->removeArrows();
        scene->removeItem(item);
        delete item;
    }
}

void MainWindow::handleFontChange()
{
    QFont font = fontCombo->currentFont();
    font.setPointSize(fontSizeCombo->currentText().toInt());
    font.setWeight(BoldAction->isChecked() ? QFont::Bold : QFont::Normal);
    font.setItalic(XietiAction->isChecked());
    font.setUnderline(UnderlineAction->isChecked());
    scene->setFont(font);
}

void MainWindow::currentFontChanged()
{
    handleFontChange();
}

void MainWindow::fontSizeChanged()
{
    handleFontChange();
}

void MainWindow::textButtonTriggered()
{
    scene->setTextColor(qvariant_cast<QColor>(TextAction->data()));
}

void MainWindow::fillButtonTriggered()
{
    scene->setItemColor(qvariant_cast<QColor>(FillAction->data()));
}

void MainWindow::lineButtonTriggered()
{
    scene->setLineColor(qvariant_cast<QColor>(LineAction->data()));
}

void MainWindow::pointerGroupClicked()
{
    scene->setMode(DiagramScene::Mode(pointerTypeGroup->checkedId()));
}

void MainWindow::sceneScaleChanged(const QString &scale)
{
    double newScale = scale.left(scale.indexOf(tr("%"))).toDouble() / 100.0;
    QTransform oldMatrix = view->transform();

    view->resetTransform();

    view->translate(oldMatrix.dx(), oldMatrix.dy());

    view->scale(newScale, newScale);
}

void MainWindow::textColorChanged()
{
    TextAction = qobject_cast<QAction *>(sender());
    FontColorToolButton->setIcon(createColorToolButtonIcon(
        "D:/Qt/qtcode/Project/homework/images/textpointer.png",
        qvariant_cast<QColor>(TextAction->data())));
    textButtonTriggered();
}

void MainWindow::itemColorChanged()
{
    FillAction = qobject_cast<QAction *>(sender());
    FillColorToolButton->setIcon(createColorToolButtonIcon(
        "D:/Qt/qtcode/Project/homework/images/floodfill.png",
        qvariant_cast<QColor>(FillAction->data())));
    fillButtonTriggered();
}

void MainWindow::lineColorChanged()
{
    LineAction = qobject_cast<QAction *>(sender());
    LineColorToolButton->setIcon(createColorToolButtonIcon(
        "D:/Qt/qtcode/Project/homework/images/linecolor.png",
        qvariant_cast<QColor>(LineAction->data())));
    lineButtonTriggered();
}

void MainWindow::bigchange()
{
    int cnt = scene->selectedItems().count();
    if(cnt==0){
        return;
    }
    for(int i=0;i<cnt;i++){
        QGraphicsItem * item=scene->selectedItems().at(i);
        item->setScale(0.1+item->scale());
    }
}

void MainWindow::smallchange()
{
    int cnt = scene->selectedItems().count();
    if(cnt==0){
        return;
    }
    for(int i=0;i<cnt;i++){
        QGraphicsItem * item=scene->selectedItems().at(i);
        item->setScale(-0.1+item->scale());
    }
}

void MainWindow::save()
{
    QString strDir = QCoreApplication::applicationDirPath() + "\\ScreenShot";
    QDir dir(strDir);
    if(!dir.exists())
    {
        dir.mkdir(strDir);
    }

    QString strFile = strDir + "\\流程图" + QDateTime::currentDateTime().toString("yyyyMMddHHmmss") + ".png";
    QPixmap pix = view->grab();

    QString fileName = QFileDialog::getSaveFileName(this,"保存图片",strFile,"PNG (*.png);;BMP (*.bmp);;JPEG (*.jpg *.jpeg)");
    if (!fileName.isNull())
    {
        pix.save(fileName);
    }
}

void MainWindow::saveAsSvg()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("导出为SVG"),
                                                    QString(), tr("SVG 文件 (*.svg)"));

    if (!fileName.isEmpty()) {
        QSvgGenerator generator;
        generator.setFileName(fileName);
        generator.setSize(view->viewport()->size());
        generator.setViewBox(view->viewport()->rect());

        QPainter painter;
        painter.begin(&generator);
        scene->render(&painter);
        painter.end();
    }
}

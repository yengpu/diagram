#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "diagramitem.h"
#include "chart_base.h"

class DiagramScene;
QT_BEGIN_NAMESPACE
class QAction;
class QToolBox;
class QSpinBox;
class QComboBox;
class QFontComboBox;
class QButtonGroup;
class QLineEdit;
class QGraphicsTextItem;
class QFont;
class QToolButton;
class QAbstractButton;
class QGraphicsView;
QT_END_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void contextMenuEvent(QContextMenuEvent* event) override;

private:
    // 关于UI界面函数的创建
    void createToolBox();
    void createActions();
    void createMenus();
    void createToolbars();

    QMenu *createColorMenu(const char *slot, QColor defaultColor);
    QIcon createColorIcon(QColor color);
    QIcon createColorToolButtonIcon(const QString &imageFile, QColor color);
    QWidget *createBackgroundCellWidget(const QString &text,
                                        const QString &image);
    QWidget *createCellWidget(const QString &text,
                              DiagramItem::DiagramType type);

    DiagramScene *scene;
    QGraphicsView *view;

    // 活动的创建
    QAction *UpAction;
    QAction *DownAction;
    QAction *DeleteAction;
    QAction *ExitAction;
    QAction *BoldAction;
    QAction *UnderlineAction;
    QAction *XietiAction;
    QAction *TextAction;
    QAction *FillAction;
    QAction *LineAction;
    QAction *BigAction;
    QAction *SmallAction;
    QAction *SaveAction;
    QAction *SaveSvgAction;  // 添加用于保存为SVG的action

    // 颜色按钮的创建
    QToolButton *FontColorToolButton;
    QToolButton *FillColorToolButton;
    QToolButton *LineColorToolButton;

    // 各种工具栏的创建
    QToolBar *editToolBar;
    QToolBar *fontToolBar;
    QToolBar *colorToolBar;
    QToolBar *pointerToolbar;
    QToolBar *styleToolbar;

    // 文字栏的组成
    QComboBox *fontSizeCombo;
    QFontComboBox *fontCombo;

    QButtonGroup *buttonGroup;
    QButtonGroup *backgroundButtonGroup;
    QButtonGroup *pointerTypeGroup;

    // 菜单栏的创建
    QMenu *fileMenu;
    QMenu *itemMenu;

    QComboBox *sceneScaleCombo;

    QToolBox *toolBox;

private slots:
    void buttonGroupClicked(int id);
    void backgroundButtonGroupClicked(QAbstractButton *button);
    void itemInserted(DiagramItem *item);
    void textInserted(QGraphicsTextItem *item);
    void itemSelected(QGraphicsItem *item);
    void bringToFront();
    void sendToBack();
    void deleteItem();
    void handleFontChange();
    void currentFontChanged();
    void fontSizeChanged();
    void textButtonTriggered();
    void fillButtonTriggered();
    void lineButtonTriggered();
    void pointerGroupClicked();
    void sceneScaleChanged(const QString &scale);
    void textColorChanged();
    void itemColorChanged();
    void lineColorChanged();
    void bigchange();
    void smallchange();
    void save();
    void saveAsSvg();  // 添加保存为SVG的槽函数声明


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

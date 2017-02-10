#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsTextItem>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "flashitem.h"
#include "startitem.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene;
    scene->setSceneRect(-200, -200, 400, 400);
    initScene();

    QGraphicsView *view = new QGraphicsView;
    view->setScene(scene);
    view->setMinimumSize(400, 400);
    view->show();

    setCentralWidget(view);
    resize(550, 450);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initScene()
{
    for (int i = 0; i < 3; ++i) {

    }
}

void MainWindow::on_actionNew_triggered()
{
    on_actionClear_triggered();
    initScene();

    MainWindow *newWin = new MainWindow;
    newWin->show();
}

void MainWindow::on_actionClear_triggered()
{
    QList<QGraphicsItem*> listItem = scene->items();
    while (!listItem.isEmpty()) {
        scene->removeItem(listItem.at(0));
        listItem.removeAt(0);
    }
}

void MainWindow::on_actionAddEllipse_triggered()
{
    QGraphicsEllipseItem *item = new QGraphicsEllipseItem(QRectF(0, 0, 80, 60));
    item->setPen(Qt::NoPen);
    item->setBrush(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
    item->setFlag(QGraphicsItem::ItemIsMovable);

    scene->addItem(item);
    item->setPos(qrand() % int(scene->sceneRect().width()) - 200, qrand() % int(scene->sceneRect().height()) - 200);
}

void MainWindow::on_actionAddText_triggered()
{
    QFont font("Times", 16);
    QGraphicsTextItem *item = new QGraphicsTextItem("Hello, QT!");
    item->setFont(font);
//    item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsFocusScope | QGraphicsItem::ItemIsMovable);
    item->setDefaultTextColor(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
    scene->addItem(item);
    item->setPos(qrand() % int(scene->sceneRect().width()) - 200, qrand() % int(scene->sceneRect().height()) - 200);
}

void MainWindow::on_actionAddRect_triggered()
{
    QGraphicsRectItem *item = new QGraphicsRectItem(QRectF(0, 0, 60, 60));
    QPen pen;
    pen.setWidth(3);
    pen.setColor(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
    item->setPen(pen);
    item->setBrush(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
    item->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsFocusScope | QGraphicsItem::ItemIsMovable);

    scene->addItem(item);
    item->setPos(qrand() % int(scene->sceneRect().width()) - 200, qrand() % int(scene->sceneRect().height()) - 200);
}

void MainWindow::on_actionAddPolygon_triggered()
{
    QVector<QPoint> v;
    v << QPoint(30, 15) << QPoint(0, -30) << QPoint(-30, 15) << QPoint(-30, 15) << QPoint(0, 30) << QPoint(30, 15);

    QGraphicsPolygonItem *item = new QGraphicsPolygonItem(QPolygonF(v));
    item->setBrush(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
    item->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsFocusScope | QGraphicsItem::ItemIsMovable);

    scene->addItem(item);
    item->setPos(qrand() % int(scene->sceneRect().width()) - 200, qrand() % int(scene->sceneRect().height()) - 200);
}

void MainWindow::on_actionAddAlpha_triggered()
{
    QGraphicsPixmapItem *item = scene->addPixmap(QPixmap("/Users/moto2yang/cpp/qt/panties.png"));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setPos(qrand() % int(scene->sceneRect().width()) - 200, qrand() % int(scene->sceneRect().height()) - 200);
}

void MainWindow::on_actionAddFlash_triggered()
{
    FlashItem* item = new FlashItem;
    scene->addItem(item);
    item->setPos(qrand() % int(scene->sceneRect().width()) - 200, qrand() % int(scene->sceneRect().height()) - 200);
}

void MainWindow::on_actionAddAnim_triggered()
{
    auto *item = new StartItem;
    auto *anim = new QGraphicsItemAnimation;
    anim->setItem(item);
    QTimeLine *timeLine = new QTimeLine(4000);
    timeLine->setCurveShape(QTimeLine::SineCurve);
    timeLine->setLoopCount(0);
    anim->setTimeLine(timeLine);

    int y = qrand() % 400 -200;
    for (int i = 0; i < 400; ++i) {
        anim->setPosAt(i/400.0, QPointF(i-200, y));
    }

    timeLine->start();
    scene->addItem(item);
}

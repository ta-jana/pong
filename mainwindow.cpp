#include "mainwindow.h"
#include "pong.h"
#include "ui_mainwindow.h"
#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(this);

    QGraphicsRectItem *p1 = new QGraphicsRectItem(0, 0, 80, 20);
    p1->setBrush(QBrush(Qt::blue));
    QGraphicsRectItem *p2 = new QGraphicsRectItem(0, 0, 80, 20);
    p2->setBrush(QBrush(Qt::green));

    QGraphicsEllipseItem *ball = new QGraphicsEllipseItem(0, 0, 30, 30);
    ball->setBrush(QBrush(Qt::magenta));

    ui->graphicsView->setScene(scene);

    game = new pong(*scene, p1, p2, ball, this);






}


void MainWindow::catchTheMouse()
{
        QPoint p = this->mapFromGlobal(QCursor::pos());
        int x = p.x();
        int y = p.y();
        qDebug() << "Mouse pos y is: " << x << "y: " << y ;
}

MainWindow::~MainWindow()
{
    delete ui;
}



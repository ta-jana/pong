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

    QGraphicsRectItem *paddle1 = new QGraphicsRectItem(0, 0, 20, 60);
    paddle1->setBrush(QBrush(Qt::blue));
    QGraphicsRectItem *paddle2 = new QGraphicsRectItem(0, 0, 20, 60);
    paddle2->setBrush(QBrush(Qt::green));

    QGraphicsEllipseItem *ball = new QGraphicsEllipseItem(0, 0, 15, 15);
    ball->setBrush(QBrush(Qt::red));



    ui->graphicsView->setScene(scene);
    game = new pong(*scene, paddle1, paddle2, ball, this);

    QSize m(scene->sceneRect().size().width() + 10, scene->sceneRect().size().height() + 10);

     qDebug() << "Scene size is : " << scene->sceneRect().size().width() << "..." ;

    ui->graphicsView->setMaximumSize(m);
    ui->graphicsView->setMinimumSize(m);









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



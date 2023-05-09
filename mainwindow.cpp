#include "mainwindow.h"
#include "qboxlayout.h"
#include "ui_mainwindow.h"
#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    gameTimer = new QTimer(this);
    gameTimer->setInterval(300);
    gameTimer->start();

    QObject::connect(gameTimer, SIGNAL(timeout()), this,
                     SLOT(catchTheMouse()));

    paddle1 = new QGraphicsRectItem(0,0,20,80);
    paddle1->setBrush(QBrush(Qt::blue));

    paddle2 = new QGraphicsRectItem(100,0,20,80);
    paddle2->setBrush(QBrush(Qt::yellow));

    ball = new QGraphicsEllipseItem(100, 0, 15, 15);
    ball->setBrush(QBrush(Qt::magenta));


    scene->addItem(paddle1);
    scene->addItem(paddle2);
    scene->addItem(ball);



    ui->graphicsView->setScene(scene);


}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
   ui->mousePosition->setText( "Mouse pos x is: "
             + QString::number(event->position().x()) + "y>" +
                QString::number(event->position().y()) + "..." );

   qDebug() << "Mouse pos x is: " << event->position().x() << "..." ;
   qDebug() << "Mouse pos y is: " << event->position().y() << "..." ;
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



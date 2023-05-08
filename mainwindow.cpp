#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsRectItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    gameTimer = new QTimer(this);

    paddle1 = new QGraphicsRectItem(0,0,80,20);
    paddle1->setBrush(QBrush(Qt::blue));

    paddle2 = new QGraphicsRectItem(0,0,80,20);
    paddle2->setBrush(QBrush(Qt::yellow));

    ball = new QGraphicsEllipseItem(0, 0, 15, 15);
    ball->setBrush(QBrush(Qt::magenta));


    scene->addItem(paddle1);
    scene->addItem(paddle2);
    scene->addItem(ball);

    ui->graphicsView->setScene(scene);


}

MainWindow::~MainWindow()
{
    delete ui;
}


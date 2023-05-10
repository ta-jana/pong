#include "mainwindow.h"
#include "pong.h"
#include "ui_mainwindow.h"
#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QDebug>

class pong;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      scorePlayer(0),
      scorePC(0)
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
    game = new pong(*ui->graphicsView ,*ui->pauseButton, *scene, paddle1, paddle2, ball, this);

    QSize m(scene->sceneRect().size().width() + 10, scene->sceneRect().size().height() + 10);

    qDebug() << "Scene size is : " << scene->sceneRect().size().width() << "..." ;

    ui->graphicsView->setMaximumSize(m);
    ui->graphicsView->setMinimumSize(m);

    QObject::connect(game, SIGNAL(goal(int)),
                     this, SLOT(score(int)));


}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::score(int count)
{
    QString score;

    if(count > 0){
        // pc looser
        scorePlayer += 1;
        score = QString::number(scorePlayer);
        ui->usersWins->setText(score);
    }
    else if (count < 0){
        //user lost
        scorePC += 1;
        score = QString::number(scorePC);
        ui->pcWins->setText(score);

    }
}




void MainWindow::on_pauseButton_clicked()
{
    game->pauseOrResume();

}


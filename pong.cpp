#include "pong.h"
#include "qgraphicsitem.h"
#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QGraphicsView>

pong::pong(QGraphicsView &view, QPushButton &button, QGraphicsScene &scene, QGraphicsItem *p1,
           QGraphicsItem *p2, QGraphicsItem *ball0,QObject *parent)
    : QObject(parent),
      gameView(view),
      pauseButton(button),
      gameScene(scene),
      paddle1(p1),
      paddle2(p2),
      ball(ball0),    
      paddle1Dir(0),
      paddle2Dir(0),
      ballDir(-5, 5)

{

    gameScene.setSceneRect(0, 0, 520, 270);

    gameScene.addItem(paddle1);
    gameScene.addItem(paddle2);
    gameScene.addItem(ball);

    paddle1->setPos(5, 105);
    paddle2->setPos(500, 105);
    ball->setPos(100, 100);

    gameTimer = new QTimer(this);
    gameTimer->setInterval(30);
    gameTimer->start();

    QObject::connect(gameTimer, SIGNAL(timeout()), this,
                     SLOT(play()));
    QObject::connect(gameTimer, SIGNAL(timeout()), this,
                     SLOT(getPlayerMouseMovement()));
}

void pong::play()
{

    // Moving ball

    int newX = ball->pos().x() + ballDir.x();
    int newY = ball->pos().y() + ballDir.y();

    if ( ( newX < 0 ) || ( newX + ball->boundingRect().right() > gameScene.sceneRect().right() ) )
    {
        emit goal(ballDir.rx());
        ballDir.rx() *= -1;
        qDebug() << "Ball Direction x  is: " << ballDir.rx() << "..." ;


    }
    if ( ( newY < 0 ) || ( newY + ball->boundingRect().bottom() > gameScene.sceneRect().bottom() ) )
    {
        ballDir.ry() *= -1;
        qDebug() << " Ball Direction y is: " << ballDir.ry() << "..." ;

    }


    //check for collision with paddles

    if ( ( paddle1->collidesWithItem(ball) ) && ( ballDir.x() < 0 ) )
    {
        ballDir.rx() *= -1;

    }

    if ( ( paddle2->collidesWithItem(ball) ) && ( ballDir.x() > 0 ) )
    {
        ballDir.rx() *= -1;

    }

    // stopping paddles from going out of bounds

    int p1NewY = paddle1->pos().x() + paddle1Dir;
    int p2NewY = paddle2->pos().x() + paddle2Dir;

    if ( ( p1NewY < 0 ) || ( p1NewY + paddle1->boundingRect().bottom() > gameScene.sceneRect().bottom() ) )
    {
        paddle1Dir = 0;

    }

    if ( ( p2NewY < 0 ) || ( p2NewY + paddle2->boundingRect().bottom() > gameScene.sceneRect().bottom() ) )
    {
        paddle2Dir = 0;
    }

    // calling paddle2 movement

    if( rand() % 2 == 0){
         paddle2Dir = calculatePaddle2Direction();
    }

    ball->moveBy(ballDir.x(), ballDir.y());
    paddle1->moveBy(0, paddle1Dir);
    paddle2->moveBy(0, paddle2Dir);

}

void pong::getPlayerMouseMovement()
{

    QPoint p = gameView.mapFromGlobal(QCursor::pos());
    int y = p.y();

    if( y < 30 || y > 260){
        //do nothing
        return;
    }
    paddle1->setPos(0,y-30);
}

int pong::calculatePaddle2Direction()
{
    int dir = 0;

    if ( ball->pos().y() + ballDir.y() > paddle2->sceneBoundingRect().bottom() )
    {
        // move down
        dir = 10;
    }
    else if ( ball->pos().y() + ballDir.y() < paddle2->sceneBoundingRect().top() )
    {
        // move up
        dir = -10;
    }
    return dir;
}

void pong::pauseOrResume()
{
    if (gameTimer->isActive()) {
        // If the timer is running, stop it and change the button text to "Resume"
        gameTimer->stop();
        pauseButton.setText("Resume");
    } else {
        // If the timer is stopped, start it and change the button text to "Pause"
        gameTimer->start();
        pauseButton.setText("Pause");
    }
}


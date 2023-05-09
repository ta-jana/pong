#include "pong.h"
#include "qgraphicsitem.h"
#include <QGraphicsRectItem>



pong::pong(QGraphicsScene & scene, QGraphicsItem *p1,
           QGraphicsItem *p2, QGraphicsItem *ball0,QObject *parent)
    : QObject(parent),
      gameScene(scene),
      paddle1(p1),
      paddle2(p2),
      ball(ball0),
      ballDir(-2, 2)
{

    gameScene.setSceneRect(0, 0, 350, 350);

    gameScene.addItem(paddle1);
    gameScene.addItem(paddle2);
    gameScene.addItem(ball);

    gameTimer = new QTimer(this);
    gameTimer->setInterval(300);
    gameTimer->start();

    QObject::connect(gameTimer, SIGNAL(timeout()), this,
                     SLOT(play()));

}

void pong::play()
{

    // Moving ball

    int newX = ball->pos().x() + ballDir.x();
    int newY = ball->pos().y() + ballDir.y();

    if ( ( newX < 0 ) || ( newX + ball->boundingRect().right() > gameScene.sceneRect().right() ) )
    {
        ballDir.rx() *= -1;
        qDebug() << "Ball Direction x  is: " << ballDir.rx() << "..." ;
        qDebug() << "newX is: " << newX << "..."<<
                    ball->boundingRect().right() << "right()..." << gameScene.sceneRect().right() << " ...";
    }
    if ( ( newY < 0 ) || ( newY + ball->boundingRect().bottom() > gameScene.sceneRect().bottom() ) )
    {
        ballDir.ry() *= -1;
        qDebug() << " Ball Direction y is: " << ballDir.ry() << "..." ;

    }

    ball->moveBy(ballDir.x(), ballDir.y());
}

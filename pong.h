#ifndef PONG_H
#define PONG_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QPushButton>

class pong : public QObject
{
    Q_OBJECT
public:
    explicit pong(QGraphicsView &view, QPushButton &pauseButton, QGraphicsScene& scene, QGraphicsItem *paddle1, QGraphicsItem *paddle2, QGraphicsItem *ball,QObject *parent = nullptr);

        int x, y;

signals:
    void goal(int player);

private slots:
    void play();
    void getPlayerMouseMovement();

public slots:
    void pauseOrResume();

private:
    int calculatePaddle2Direction();

    QTimer *gameTimer;

    QGraphicsView &gameView;
    QPushButton &pauseButton;
    QGraphicsScene &gameScene;
    QGraphicsItem *paddle1, *paddle2, *ball;
    int paddle1Dir, paddle2Dir;
    QPointF ballDir;


};

#endif // PONG_H

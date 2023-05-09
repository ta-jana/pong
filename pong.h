#ifndef PONG_H
#define PONG_H

#include <QObject>
#include <QGraphicsScene>

class pong : public QObject
{
    Q_OBJECT
public:
    explicit pong(QGraphicsScene & scene, QGraphicsItem *paddle1, QGraphicsItem *paddle2, QGraphicsItem *ball,QObject *parent = nullptr);

signals:

};

#endif // PONG_H

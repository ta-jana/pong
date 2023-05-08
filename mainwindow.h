#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "scene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *gameTimer;

    QGraphicsScene *scene;

    QGraphicsRectItem *paddle1;
    QGraphicsRectItem *paddle2;
    QGraphicsEllipseItem *ball;

};
#endif // MAINWINDOW_H

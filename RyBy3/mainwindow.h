#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "player.h"
#include "statusbar.h"
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QGraphicsScene * scene1;
    QGraphicsScene * scene2;

    QGraphicsView * view;


    QGraphicsScene* getScene1() {return scene1;}
    QGraphicsScene* getScene2() {return scene2;}

    QGraphicsView* getView() {return view;}


private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H

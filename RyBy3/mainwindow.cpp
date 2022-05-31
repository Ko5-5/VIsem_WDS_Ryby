#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene1 = new QGraphicsScene();
    scene2 = new QGraphicsScene();

    view = new QGraphicsView();
    view->setScene(scene2);

    this->setCentralWidget(view);

    installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


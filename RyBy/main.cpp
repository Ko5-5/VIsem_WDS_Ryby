#include "mainwindow.h"
#include <QApplication>
#include <QStackedWidget>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    qApp->setStyleSheet("MainWindow {background-image:url(/home/hubert/Wedka/VIsem_WDS_Ryby/RyBy/fishing_background.png)}");

    w.setFixedSize(1000,700);


    w.show();


    return a.exec();
}

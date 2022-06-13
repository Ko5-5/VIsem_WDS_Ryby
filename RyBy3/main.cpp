#include <QApplication>
#include <QSlider>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QGraphicsGridLayout>
#include <QGraphicsWidget>
#include <QTranslator>
#include <QTime>
#include "game.h"


Game* game;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    qsrand(QTime::currentTime().msec());

    //gTranslator.load(":/english.qm");
    //a.installTranslator(&gTranslator);

    game = new Game(&a);
    game->show();


        return a.exec();
}

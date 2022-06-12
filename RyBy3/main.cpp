#include <QApplication>
#include <QSlider>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QGraphicsGridLayout>
#include <QGraphicsWidget>
#include <QTranslator>
#include "game.h"


Game* game;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    //gTranslator.load(":/english.qm");
    //a.installTranslator(&gTranslator);

    game = new Game(&a);
    game->show();


        return a.exec();
}

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

    game = new Game();
    //game->gameTranslator->load(":/english.qm");
    QTranslator gTranslator;
    gTranslator.load(":/english.qm");
    a.installTranslator(&gTranslator);
    //a.installTranslator(game->gameTranslator);

    game->show();


        return a.exec();
}

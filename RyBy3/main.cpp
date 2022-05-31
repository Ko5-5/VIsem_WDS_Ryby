#include <QApplication>
#include <QSlider>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QGraphicsGridLayout>
#include <QGraphicsWidget>
#include "game.h"


Game* game;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    game = new Game();
    game->show();


        return a.exec();
}

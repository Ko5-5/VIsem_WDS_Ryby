#ifndef BAIT_H
#define BAIT_H

#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include "game.h"

class Bait : public QGraphicsWidget
{
    Q_OBJECT

public:
    QTimer * tim1;

    bool isFishCaught;

    bool isCasted;

    Bait();

    void fishedOut();

    void castRod();

public slots:



    void fishCaught();


};

#endif // BAIT_H

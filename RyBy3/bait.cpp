#include "bait.h"

extern Game * game;

Bait::Bait()
{
    isFishCaught = false;
    isCasted = false;
    tim1 = new QTimer();
    connect(tim1, SIGNAL(timeout()), this, SLOT(fishCaught()));
}

void Bait::fishCaught()
{
    if(isCasted)
    {
        game->caughtLabel->setVisible(true);
        isFishCaught = true;
        tim1->stop();
    }
}

void Bait::fishedOut()
{
    game->caughtLabel->setVisible(false);
    isFishCaught = false;
    isCasted = false;
    game->castedLabel->setVisible(false);
}

void Bait::castRod()
{
    isCasted = true;
    tim1->start(8000);
    game->castedLabel->setVisible(true);
}

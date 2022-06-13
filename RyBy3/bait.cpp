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
        game->retrievalTim->singleShot(3000, game, SLOT(startRetrievalTim()));
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
    int randomTime = qrand() % 8000 + 8000;
    tim1->start(randomTime);
    game->castedLabel->setVisible(true);
}

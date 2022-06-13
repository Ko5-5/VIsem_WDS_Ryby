#include "key_press_event_filter.h"
#include <QDebug>
#include "game.h"
#include "settings.h"

extern Game * game;
extern Settings * settings;

KeyPressEventFilter::KeyPressEventFilter(QObject *parent)
    : QObject(parent)
{

}

bool KeyPressEventFilter::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() != QEvent::KeyPress)
        return QObject::eventFilter(watched, event);

    QKeyEvent * keyEvent = static_cast<QKeyEvent*>(event);
    if(game->scene() == game->gameScene){
    switch(keyEvent->key())
    {
    case Qt::Key_1:
        qDebug() << "Key 1 pressed";
        //game->currentSceneImage->swap(*(game->casualFishing));
        game->currentSceneImage = game->casualFishing;
        game->resetCachedContent();
        game->show();
    break;
    case Qt::Key_2:
        qDebug() << "Key 2 pressed";
        //game->currentSceneImage->swap(*(game->szarlotkaFishing));
        game->currentSceneImage = game->szarlotkaFishing;
        game->resetCachedContent();

        game->show();
    break;
    case Qt::Key_3:
        qDebug() << "Key 3 pressed";
        //game->currentSceneImage->swap(*(game->palmaFishing));
        game->currentSceneImage = game->palmaFishing;
        game->resetCachedContent();

        game->show();

    break;
    case Qt::Key_4:
        qDebug() << "Key 4 pressed";
        //game->currentSceneImage->swap(*(game->lawaFishing));

        game->currentSceneImage = game->lawaFishing;
        game->resetCachedContent();

        game->show();
    break;

    case Qt::Key_5:
        game->translateGame();
        break;

    case Qt::Key_6:
        game->retranslateGame();
        break;
    case Qt::Key_Up:
        if(game->scene() == game->gameScene)
            game->updateText();
        break;
    case Qt::Key_Left:
        if(game->scene() == game->gameScene)
            game->bait->castRod();
        break;
    default:
    qDebug() << "Invalid key pressed";
    break;
    }

    }
    return true;
}

#include "key_press_event_filter.h"
#include <QDebug>
#include "game.h"

extern Game * game;

KeyPressEventFilter::KeyPressEventFilter(QObject *parent)
    : QObject(parent)
{

}

bool KeyPressEventFilter::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() != QEvent::KeyPress)
        return QObject::eventFilter(watched, event);

    QKeyEvent * keyEvent = static_cast<QKeyEvent*>(event);
    switch(keyEvent->key())
    {
    case Qt::Key_1:
        qDebug() << "Key 1 pressed";
        //game->currentSceneImage->swap(*(game->casualFishing));
        game->currentSceneImage = game->casualFishing;
        game->show();
    break;
    case Qt::Key_2:
        qDebug() << "Key 2 pressed";
        //game->currentSceneImage->swap(*(game->szarlotkaFishing));
        game->currentSceneImage = game->szarlotkaFishing;

        game->show();
    break;
    case Qt::Key_3:
        qDebug() << "Key 3 pressed";
        //game->currentSceneImage->swap(*(game->palmaFishing));
        game->currentSceneImage = game->palmaFishing;

        game->show();

    break;
    case Qt::Key_4:
        qDebug() << "Key 4 pressed";
        //game->currentSceneImage->swap(*(game->lawaFishing));

        game->currentSceneImage = game->lawaFishing;

        game->show();



    break;
    default:
    qDebug() << "Invalid key pressed";
    break;
    }
    return true;
}

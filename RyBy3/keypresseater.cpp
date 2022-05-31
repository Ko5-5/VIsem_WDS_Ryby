#include "keypresseater.h"

bool KEYPRESSEATER::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::KeyPressed)
    {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        qDebug("Key pressed: %d", keyEvent->key());
        return true;
    } else
    {
        return QObject::eventFilter(obj, event);
    }
}

#include "keypresseater.h"

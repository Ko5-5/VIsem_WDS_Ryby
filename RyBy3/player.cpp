#include "player.h"

void Player::keyPressEvent(QKeyEvent * event)
{
    if(event->key() == Qt::Key_Right)
    {
        setPos(x() - 10, y() );
    }
}

#include "statusbar.h"

void StatusBar::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Qt::Key_Up)
    {
        this->setSliderPosition(this->sliderPosition()+5);
        qDebug() <<"Key_up pressed";
    }
}


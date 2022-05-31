#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QSlider>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QDebug>

class StatusBar : public QSlider
{
public:
    void keyPressEvent(QKeyEvent* event);
};

#endif // STATUSBAR_H

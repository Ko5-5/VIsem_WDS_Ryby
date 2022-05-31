#ifndef KEYPRESSEATER_H
#define KEYPRESSEATER_H

#include <QDebug>
#include <QObject>

class KEYPRESSEATER : public QObject
{
    Q_OBJECT

    protected:

    bool eventFilter(QObject* obj, QEvent* event) override;
};

#endif // KEYPRESSEATER_H

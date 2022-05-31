#ifndef KEY_PRESS_EVENT_FILTER_H
#define KEY_PRESS_EVENT_FILTER_H
#include <QObject>
#include <QKeyEvent>


class KeyPressEventFilter : public QObject
{
  Q_OBJECT
public:
    explicit KeyPressEventFilter(QObject * parent = nullptr);

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;
};

#endif // KEY_PRESS_EVENT_FILTER_H

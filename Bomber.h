#ifndef BOMBER_H
#define BOMBER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Bomber:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bomber(QGraphicsItem * parent = 0);
public slots:
    void move_forward();
private:
    int health;
};

#endif // BOMBER_H

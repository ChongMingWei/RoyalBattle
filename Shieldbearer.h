#ifndef SHIELDBEARER_H
#define SHIELDBEARER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Shieldbearer:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Shieldbearer(QGraphicsItem * parent = 0);
public slots:
    void move_forward();
private:
    int health;
};

#endif // SHIELDBEARER_H

#ifndef HEAVYSHIELDBEARER_H
#define HEAVYSHIELDBEARER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Heavyshieldbearer:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Heavyshieldbearer(QGraphicsItem * parent = 0);
public slots:
    void move_forward();
private:
    int health;
};

#endif // HEAVYSHIELDBEARER_H

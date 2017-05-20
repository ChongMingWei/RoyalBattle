#ifndef SNIPER_H
#define SNIPER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Sniper:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Sniper(QGraphicsItem * parent = 0);
    //void rotateToPoint(QPointF p);
public slots:
    void move_forward();
private:
    //QList<QPointF> points;
    //QPointF dest;
    //int point_index;
    int health;
};

#endif // SNIPER_H

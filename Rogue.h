#ifndef ROGUE_H
#define ROGUE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Rogue:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Rogue(QGraphicsItem * parent = 0);
    //void rotateToPoint(QPointF p);
public slots:
    void move_forward();
private:
    //QList<QPointF> points;
   // QPointF dest;
   // int point_index;
    int health;
};

#endif // ROGUE_H

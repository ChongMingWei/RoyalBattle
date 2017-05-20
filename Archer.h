#ifndef ARCHER_H
#define ARCHER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Archer:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Archer(QGraphicsItem * parent = 0);
    //void rotateToPoint(QPointF p);
public slots:
    void move_forward();
private:
    //QList<QPointF> points;
    //QPointF dest;
    //int point_index;
    int health;
};

#endif // ARCHER_H

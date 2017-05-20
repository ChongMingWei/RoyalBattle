#ifndef KNIGHT_H
#define KNIGHT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Knight:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Knight(QGraphicsItem * parent = 0);
    //void rotateToPoint(QPointF p);
public slots:
    void move_forward();
private:
   // QList<QPointF> points;
   // QPointF dest;
   // int point_index;
    int health;
};

#endif // KNIGHT_H

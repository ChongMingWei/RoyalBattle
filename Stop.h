#ifndef STOP_H
#define STOP_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Stop:public QGraphicsPixmapItem
{
public:
   Stop(QGraphicsItem * parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // STOP_H

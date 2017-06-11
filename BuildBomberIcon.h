#ifndef BUILDBOMBERICON_H
#define BUILDBOMBERICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildBomberIcon:public QGraphicsPixmapItem
{
public:
    BuildBomberIcon(QGraphicsItem * parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDBOMBERICON_H

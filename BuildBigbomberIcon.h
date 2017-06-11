#ifndef BUILDBIGBOMBERICON_H
#define BUILDBIGBOMBERICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildBigbomberIcon:public QGraphicsPixmapItem
{
public:
    BuildBigbomberIcon(QGraphicsItem * parent = 0);
     void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDBIGBOMBERICON_H

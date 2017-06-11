#ifndef BUILDDRAGONICON_H
#define BUILDDRAGONICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildDragonIcon:public QGraphicsPixmapItem
{
public:
    BuildDragonIcon(QGraphicsItem * parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDDRAGONICON_H

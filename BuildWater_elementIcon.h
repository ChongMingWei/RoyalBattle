#ifndef BUILDWATER_ELEMENTICON_H
#define BUILDWATER_ELEMENTICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildWater_elementIcon:public QGraphicsPixmapItem
{
public:
    BuildWater_elementIcon(QGraphicsItem * parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDWATER_ELEMENTICON_H

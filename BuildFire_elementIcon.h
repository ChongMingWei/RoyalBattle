#ifndef BUILDFIRE_ELEMENTICON_H
#define BUILDFIRE_ELEMENTICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildFire_elementIcon:public QGraphicsPixmapItem
{
public:
    BuildFire_elementIcon(QGraphicsItem * parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDFIRE_ELEMENTICON_H

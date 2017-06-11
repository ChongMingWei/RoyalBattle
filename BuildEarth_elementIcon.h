#ifndef BUILDEARTH_ELEMENTICON_H
#define BUILDEARTH_ELEMENTICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildEarth_elementIcon:public QGraphicsPixmapItem
{
public:
    BuildEarth_elementIcon(QGraphicsItem * parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDEARTH_ELEMENTICON_H

#ifndef BUILDSHIELDBEARERICON_H
#define BUILDSHIELDBEARERICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildShieldbearerIcon:public QGraphicsPixmapItem
{
public:
    BuildShieldbearerIcon(QGraphicsItem * parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDSHIELDBEARERICON_H

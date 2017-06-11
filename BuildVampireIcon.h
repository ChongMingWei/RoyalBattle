#ifndef BUILDVAMPIREICON_H
#define BUILDVAMPIREICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildVampireIcon:public QGraphicsPixmapItem
{
public:
    BuildVampireIcon(QGraphicsItem * parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDVAMPIREICON_H

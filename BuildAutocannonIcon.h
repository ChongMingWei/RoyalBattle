#ifndef BUILDAUTOCANNONICON_H
#define BUILDAUTOCANNONICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildAutocannonIcon:public QGraphicsPixmapItem
{
public:
    BuildAutocannonIcon(QGraphicsItem * parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDAUTOCANNONICON_H

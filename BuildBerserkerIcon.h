#ifndef BUILDBERSERKERICON_H
#define BUILDBERSERKERICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildBerserkerIcon:public QGraphicsPixmapItem
{
public:
    BuildBerserkerIcon(QGraphicsItem * parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDBERSERKERICON_H

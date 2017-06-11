#ifndef BUILDPALADINICON_H
#define BUILDPALADINICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildPaladinIcon:public QGraphicsPixmapItem
{
public:
    BuildPaladinIcon(QGraphicsItem * parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDPALADINICON_H

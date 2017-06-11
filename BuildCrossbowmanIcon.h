#ifndef BUILDCROSSBOWMANICON_H
#define BUILDCROSSBOWMANICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildCrossbowmanIcon:public QGraphicsPixmapItem
{
public:
    BuildCrossbowmanIcon(QGraphicsItem * parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDCROSSBOWMANICON_H

#ifndef BUILDSPEARMANICON_H
#define BUILDSPEARMANICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildSpearmanIcon:public QGraphicsPixmapItem
{
public:
    BuildSpearmanIcon(QGraphicsItem * parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDSPEARMANICON_H

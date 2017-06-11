#ifndef BUILDHEAVYSPEARMANICON_H
#define BUILDHEAVYSPEARMANICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildHeavyspearmanIcon:public QGraphicsPixmapItem
{
public:
    BuildHeavyspearmanIcon(QGraphicsItem * parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDHEAVYSPEARMANICON_H

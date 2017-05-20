#ifndef BUILDROGUEICON_H
#define BUILDROGUEICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>


class BuildRogueIcon:public QGraphicsPixmapItem
{
public:
    BuildRogueIcon(QGraphicsItem * parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};
#endif // BUILDROGUEICON_H

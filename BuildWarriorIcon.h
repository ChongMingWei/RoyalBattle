#ifndef BUILDWARRIORICON_H
#define BUILDWARRIORICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildWarriorIcon:public QGraphicsPixmapItem
{
public:
    BuildWarriorIcon(QGraphicsItem * parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDWARRIORICON_H

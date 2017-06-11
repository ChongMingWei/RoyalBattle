#ifndef BUILDMACHINEGUNICON_H
#define BUILDMACHINEGUNICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildMachinegunIcon:public QGraphicsPixmapItem
{
public:
    BuildMachinegunIcon(QGraphicsItem * parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDMACHINEGUNICON_H

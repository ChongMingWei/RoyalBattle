#ifndef BUILDACHERICON_H
#define BUILDACHERICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>


class BuildArcherIcon:public QGraphicsPixmapItem
{
public:
    BuildArcherIcon(QGraphicsItem * parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};
#endif // BUILDACHERICON_H

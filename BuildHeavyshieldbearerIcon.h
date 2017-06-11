#ifndef BUILDHEAVYSHIELDBEARERICON_H
#define BUILDHEAVYSHIELDBEARERICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildHeavyshieldbearerIcon:public QGraphicsPixmapItem
{
public:
    BuildHeavyshieldbearerIcon(QGraphicsItem * parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDHEAVYSHIELDBEARERICON_H

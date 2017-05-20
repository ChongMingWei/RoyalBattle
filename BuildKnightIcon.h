#ifndef BUILDCHAMPIONICON_H
#define BUILDCHAMPIONICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>


class BuildKnightIcon:public QGraphicsPixmapItem
{
public:
    BuildKnightIcon(QGraphicsItem * parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};
#endif // BUILDCHAMPIONICON_H

#ifndef BUILDSNIPERICON_H
#define BUILDSNIPERICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>


class BuildSniperIcon:public QGraphicsPixmapItem
{
public:
    BuildSniperIcon(QGraphicsItem * parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};
#endif // BUILDSNIPERICON_H

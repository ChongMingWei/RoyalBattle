#ifndef HERO_H
#define HERO_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Hero:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Hero(QGraphicsItem * parent = 0);
    void keyPressEvent(QKeyEvent *event);
};
#endif // HERO_H

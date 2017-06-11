#ifndef PALADIN_H
#define PALADIN_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Paladin:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Paladin(QGraphicsItem * parent = 0);
public slots:
    void move_forward();
private:
    int health;
};

#endif // PALADIN_H

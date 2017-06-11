#ifndef WARRIOR_H
#define WARRIOR_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Warrior:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Warrior(QGraphicsItem * parent = 0);
public slots:
    void move_forward();
private:
    int health;
};

#endif // WARRIOR_H

#ifndef FIRE_ELEMENT_H
#define FIRE_ELEMENT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Fire_element:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Fire_element(QGraphicsItem * parent = 0);
public slots:
    void move_forward();
private:
    int health;
};

#endif // FIRE_ELEMENT_H

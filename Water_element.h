#ifndef WATER_ELEMENT_H
#define WATER_ELEMENT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Water_element:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Water_element(QGraphicsItem * parent = 0);
public slots:
    void move_forward();
private:
    int health;
};

#endif // WATER_ELEMENT_H

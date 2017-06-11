#ifndef EARTH_ELEMENT_H
#define EARTH_ELEMENT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Earth_element:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Earth_element(QGraphicsItem * parent = 0);
public slots:
    void move_forward();
private:
    int health;
};

#endif // EARTH_ELEMENT_H

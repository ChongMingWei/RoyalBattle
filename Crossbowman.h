#ifndef CROSSBOWMAN_H
#define CROSSBOWMAN_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Crossbowman:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Crossbowman(QGraphicsItem * parent = 0);
public slots:
    void move_forward();
private:
    int health;
};

#endif // CROSSBOWMAN_H

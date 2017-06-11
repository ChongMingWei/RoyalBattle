#ifndef HEAVYSPEARMAN_H
#define HEAVYSPEARMAN_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Heavyspearman:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Heavyspearman(QGraphicsItem * parent = 0);
public slots:
    void move_forward();
private:
    int health;
};

#endif // HEAVYSPEARMAN_H

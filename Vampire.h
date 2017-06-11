#ifndef VAMPIRE_H
#define VAMPIRE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Vampire:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Vampire(QGraphicsItem * parent = 0);
public slots:
    void move_forward();
private:
    int health;
};

#endif // VAMPIRE_H

#ifndef DRAGON_H
#define DRAGON_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Dragon:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Dragon(QGraphicsItem * parent = 0);
public slots:
    void move_forward();
private:
    int health;
};

#endif // DRAGON_H

#ifndef COM_ARCHER_H
#define COM_ARCHER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Com_Archer:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Com_Archer(QGraphicsItem * parent = 0);
public slots:
    void move_forward();
private:
    int health;
};

#endif // COM_ARCHER_H

#ifndef COM_SNIPER_H
#define COM_SNIPER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Com_Sniper:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Com_Sniper(QGraphicsItem * parent = 0);
public slots:
    void move_forward();
private:
    int health;
};

#endif // COM_SNIPER_H

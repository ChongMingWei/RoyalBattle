#ifndef COM_ROGUE_H
#define COM_ROGUE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Com_Rogue:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Com_Rogue(QGraphicsItem * parent = 0);
public slots:
    void move_forward();
private:
    int health;
};

#endif // COM_ROGUE_H

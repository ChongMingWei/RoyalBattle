#ifndef COM_KNIGHT_H
#define COM_KNIGHT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPointF>

class Com_Knight:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Com_Knight(QGraphicsItem * parent = 0);
public slots:
    void move_forward();
private:
    int health;
};
#endif // COM_KNIGHT_H

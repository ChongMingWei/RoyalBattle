#ifndef BIGBOMBER_H
#define BIGBOMBER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Bigbomber:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bigbomber(QGraphicsItem * parent = 0);
public slots:
    void move_forward();
private:
    int health;
};

#endif // BIGBOMBER_H

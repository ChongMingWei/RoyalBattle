#ifndef BERSERKER_H
#define BERSERKER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Berserker:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Berserker(QGraphicsItem * parent = 0);
public slots:
    void move_forward();
private:
    int health;
};

#endif // BERSERKER_H

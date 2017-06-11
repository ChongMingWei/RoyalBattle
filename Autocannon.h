#ifndef AUTOCANNON_H
#define AUTOCANNON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include <QGraphicsView>

class Autocannon:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
   Autocannon(QGraphicsItem * parent = 0);
  double distanceTo(QGraphicsItem * item);
  void fire();
public slots:
   void acquire_target();
private:
    QGraphicsPolygonItem *attack_area; //when enter in, attack
    QPointF attack_dest;
    bool has_target;
    int health;
};

#endif // AUTOCANNON_H

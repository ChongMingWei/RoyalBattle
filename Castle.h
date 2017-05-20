#ifndef CASTLE_H
#define CASTLE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include <QGraphicsView>

class Castle:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
   Castle(QGraphicsItem * parent = 0);
  double distanceTo(QGraphicsItem * item);
  void fire();
  void endgame();
public slots:
   void acquire_target();
private:
    QGraphicsPolygonItem *attack_area; //when enter in, attack
    QPointF attack_dest;
    bool has_target;
    int health;
};

#endif // CASTLE_H

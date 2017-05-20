#ifndef COM_CASTLE_H
#define COM_CASTLE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include <QGraphicsView>

class Com_Castle:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
   Com_Castle(QGraphicsItem * parent = 0);
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

#endif // COM_CASTLE_H

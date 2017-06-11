#ifndef SPEARMAN_H
#define SPEARMAN_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Spearman:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Spearman(QGraphicsItem * parent = 0);
public slots:
    void move_forward();
private:
    int health;
};

#endif // SPEARMAN_H

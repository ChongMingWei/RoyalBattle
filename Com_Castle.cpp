#include "Com_Castle.h"
#include "Arrow.h"
#include "Game.h"
#include "Knight.h"
#include "Archer.h"
#include "Rogue.h"
#include "Sniper.h"
#include "btn.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QLineF>
#include <QTimer>
#include <QGraphicsScene>
extern Game * game;

Com_Castle::Com_Castle(QGraphicsItem * parent):QObject(),QGraphicsPixmapItem(parent)
{
    //set the health of the castle
        health = 20;
        setPixmap(QPixmap(":/image/castle_user.png"));

        //creates points vector
        QVector<QPointF> points;
        points << QPoint(1,0)<< QPoint(2,0)
                     << QPoint(3,1)<< QPoint(3,2)
                     << QPoint(2,3)<< QPoint(1,3)
                     << QPoint(0,2)<< QPoint(0,1);

        //scale points
        int SCALE_FACTOR =160;
        for(size_t i = 0,n = points.size();i < n;++i)
            points[i] *= SCALE_FACTOR;

        //create the QGraphicsPolygonItem
        attack_area = new QGraphicsPolygonItem(QPolygonF(points),this);

        //move the polygon
        QPointF poly_center(1.5,1.5);
        poly_center *= SCALE_FACTOR;
        poly_center = mapToScene(poly_center);
        QPointF castle_center(x()+120,y()+120);
        QLineF ln(poly_center,castle_center);
        attack_area->setPos(x()+ln.dx(),y()+ln.dy());

        //connect a timer to attack_target
        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(acquire_target()));
        timer->start(1000); //1s

        //set attack_dest
        attack_dest = QPointF(0,0);
}

double Com_Castle::distanceTo(QGraphicsItem *item)
{
    QLineF ln(pos(),item->pos());
    return ln.length();
}

void Com_Castle::fire()
{
    Arrow * arrow= new Arrow();
    arrow->setPos(x()+180,y()+160);
    QLineF ln(QPointF(x()+120,y()+120),attack_dest);
    int angle = -1 * ln.angle();

    arrow->setRotation(angle);
    game->scene->addItem(arrow);
}

void Com_Castle::endgame()
{
   Btn *end = new Btn();
    game->scene->addItem(end);
}

void Com_Castle::acquire_target()
{
    QList<QGraphicsItem *>colliding_champions = collidingItems();
    for(int i = 0,n=colliding_champions.size();i<n;++i)
    {
        if(typeid(*(colliding_champions[i])) == typeid(Arrow))
        {
            --health;
        }
        else if (typeid(*(colliding_champions[i])) == typeid(Archer))
        {
            health--;
        }
        else if (typeid(*(colliding_champions[i])) == typeid(Knight))
        {
            health-=2;
        }
        else if (typeid(*(colliding_champions[i])) == typeid(Sniper))
        {
            health--;
        }
        else if (typeid(*(colliding_champions[i])) == typeid(Rogue))
        {
            health-=2;
        }
        if(health == 0)
        {
               endgame();
                scene()->removeItem(this);
                return;
        }
    }
    // get a list of all items colliding with attack_area
    QList<QGraphicsItem *> colliding_items = attack_area ->collidingItems();

   if(colliding_items.size() == 1) // only the castle
   {
        has_target = false;
        return;
    }
    double closest_dist = 300;
    QPointF closest_pt = QPointF(0,0);
    for(size_t i = 0,n = colliding_items.size();i < n;++i)
    {
        Knight *knight = dynamic_cast<Knight *>(colliding_items[i]);
        Archer *archer = dynamic_cast<Archer *>(colliding_items[i]);
        Rogue *rogue = dynamic_cast< Rogue *>(colliding_items[i]);
        Sniper *sniper = dynamic_cast< Sniper *>(colliding_items[i]);
        if (knight)
        {
            double this_dist = distanceTo(knight);
            if(this_dist < closest_dist)
            {
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
        else if(archer)
        {
            double this_dist = distanceTo(archer);
            if(this_dist < closest_dist)
            {
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
        else if(rogue)
        {
            double this_dist = distanceTo(rogue);
            if(this_dist < closest_dist)
            {
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
        else if(sniper)
        {
            double this_dist = distanceTo(sniper);
            if(this_dist < closest_dist)
            {
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }

    }
    if(has_target)
    {
        attack_dest = closest_pt;
        fire();
    }
}

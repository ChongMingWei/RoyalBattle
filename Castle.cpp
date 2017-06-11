#include "Castle.h"
#include "Earth_element.h"
#include "Arrow.h"
#include "Game.h"
#include "Com_Knight.h"
#include "Com_Archer.h"
#include "Com_Rogue.h"
#include "Com_Sniper.h"
#include "gameover.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QLineF>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>

extern Game * game;

Castle::Castle(QGraphicsItem * parent):QObject(),QGraphicsPixmapItem(parent)
{
    //set the health of the castle
    health =30;
    setPixmap(QPixmap(":/image/castle_com.png"));

    //creates points vector
    QVector<QPointF> points;
 points    << QPoint(1,0)<< QPoint(2,0)
                 << QPoint(3,1)<< QPoint(3,2)
                 << QPoint(2,3)<< QPoint(1,3);


    //scale points
    int SCALE_FACTOR =140;
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
    attack_dest = QPointF(800,600);
}

double Castle::distanceTo(QGraphicsItem *item)
{
    QLineF ln(pos(),item->pos());
    return ln.length();
}

void Castle::fire()
{
    Arrow * arrow= new Arrow();
    arrow->setPos(x()+120,y()+120);
    QLineF ln(QPointF(x()+120,y()+120),attack_dest);
    int angle = -1 * ln.angle();

    arrow->setRotation(angle);
    game->scene->addItem(arrow);
}

void Castle::endgame()
{
    Gameover *end = new Gameover();
    game->scene->addItem(end);
}
void Castle::acquire_target()
{
    QList<QGraphicsItem *>colliding_champions = collidingItems();
    for(int i = 0,n=colliding_champions.size();i<n;++i)
    {

         if(typeid(*(colliding_champions[i])) == typeid(Com_Knight))
        {
            --health;
        }
        else if(typeid(*(colliding_champions[i])) == typeid(Com_Archer))
        {
            --health;
        }
        else if(typeid(*(colliding_champions[i])) == typeid(Com_Rogue))
        {
            health-=2;
        }
        else if(typeid(*(colliding_champions[i])) == typeid(Com_Sniper))
        {
            --health;
        }
         else if(typeid(*(colliding_champions[i])) == typeid(Earth_element))
         {
             ++health;
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
        Com_Knight *knight = dynamic_cast<Com_Knight *>(colliding_items[i]);
        Com_Archer *archer = dynamic_cast<Com_Archer *>(colliding_items[i]);
        Com_Rogue *rogue = dynamic_cast< Com_Rogue *>(colliding_items[i]);
        Com_Sniper *sniper = dynamic_cast<Com_Sniper *>(colliding_items[i]);
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

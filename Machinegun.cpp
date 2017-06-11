#include "Machinegun.h"
#include "Earth_element.h"
#include "Bullet.h"
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

Machinegun::Machinegun(QGraphicsItem * parent):QObject(),QGraphicsPixmapItem(parent)
{
    //set the health
    health =20;
    setPixmap(QPixmap(":/image/champions2/machinegun.png"));

    //creates points vector
    QVector<QPointF> points;
    points << QPoint(1,0)<< QPoint(2,0)<< QPoint(3,1)
                 << QPoint(3,2) << QPoint(2,3)<< QPoint(1,3)
                 << QPoint(0,2)<< QPoint(0,1) ;

    //scale points
    int SCALE_FACTOR =50;
    for(size_t i = 0,n = points.size();i < n;++i)
        points[i] *= SCALE_FACTOR;

    //create the QGraphicsPolygonItem
    attack_area = new QGraphicsPolygonItem(QPolygonF(points),this);

    //move the polygon
    QPointF poly_center(1.5,1.5);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);
    QPointF machinegun_center(x()+35,y()+40);
    QLineF ln(poly_center,machinegun_center);
    attack_area->setPos(x()+ln.dx(),y()+ln.dy());

    //connect a timer to attack_target
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(acquire_target()));
    timer->start(250); //0.25s

    //set attack_dest
    attack_dest = QPointF(800,600);
}

double Machinegun::distanceTo(QGraphicsItem *item)
{
    QLineF ln(pos(),item->pos());
    return ln.length();
}

void Machinegun::fire()
{
    Bullet * bullet= new Bullet();
    bullet->setPos(x()+25,y()+25);
    QLineF ln(QPointF(x()+120,y()+120),attack_dest);
    int angle = -1 * ln.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void Machinegun::acquire_target()
{
    QList<QGraphicsItem *>colliding_champions = collidingItems();
    for(int i = 0,n=colliding_champions.size();i<n;++i)
    {

         if(typeid(*(colliding_champions[i])) == typeid(Com_Knight))
        {
            health-=3;
        }
        else if(typeid(*(colliding_champions[i])) == typeid(Com_Archer))
        {
            health-=2;
        }
        else if(typeid(*(colliding_champions[i])) == typeid(Com_Rogue))
        {
            health-=1;
        }
        else if(typeid(*(colliding_champions[i])) == typeid(Com_Sniper))
        {
            health-=4;
        }
         else if(typeid(*(colliding_champions[i])) == typeid(Earth_element))
         {
             ++health;
         }

        if(health <= 0)
        {
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
    double closest_dist = 80;
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

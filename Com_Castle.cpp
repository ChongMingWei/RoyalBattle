#include "Com_Castle.h"
#include "Berserker.h"
#include "Bomber.h"
#include "Bigbomber.h"
#include "Crossbowman.h"
#include "Dragon.h"
#include "Earth_element.h"
#include "Fire_element.h"
#include "Heavyshieldbearer.h"
#include "Heavyspearman.h"
#include "Paladin.h"
#include "Spearman.h"
#include "Shieldbearer.h"
#include "Vampire.h"
#include "Water_element.h"
#include "Warrior.h"
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
        health =30;
        setPixmap(QPixmap(":/image/castle_user.png"));

        //creates points vector
        QVector<QPointF> points;
        points << QPoint(1,0)<< QPoint(2,0)
                     << QPoint(2,3)<< QPoint(1,3)
                     << QPoint(0,2)<< QPoint(0,1);

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
        else if (typeid(*(colliding_champions[i])) == typeid(Bomber))
        {
            health-=2;
        }
        else if (typeid(*(colliding_champions[i])) == typeid(Bigbomber))
        {
            health-=4;
        }
        else if (typeid(*(colliding_champions[i])) == typeid(Warrior))
        {
            health-=3;
        }
        else if (typeid(*(colliding_champions[i])) == typeid(Berserker))
        {
            health-=3;
        }
        else if (typeid(*(colliding_champions[i])) == typeid(Dragon))
        {
            health-=2;
        }
        else if (typeid(*(colliding_champions[i])) == typeid(Crossbowman))
        {
            health-=3;
        }
        else if (typeid(*(colliding_champions[i])) == typeid(Paladin))
        {
            health-=4;
        }
        else if (typeid(*(colliding_champions[i])) == typeid(Spearman))
        {
            health-=2;
        }
        else if (typeid(*(colliding_champions[i])) == typeid(Heavyspearman))
        {
            health-=3;
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
        Warrior *warrior = dynamic_cast< Warrior *>(colliding_items[i]);
        Berserker *berserker = dynamic_cast< Berserker  *>(colliding_items[i]);
        Fire_element *fire_element = dynamic_cast< Fire_element *>(colliding_items[i]);
        Earth_element *earth_element = dynamic_cast< Earth_element *>(colliding_items[i]);
        Water_element *water_element = dynamic_cast< Water_element *>(colliding_items[i]);
        Dragon *dragon = dynamic_cast< Dragon *>(colliding_items[i]);
        Crossbowman *crossbowman = dynamic_cast<Crossbowman *>(colliding_items[i]);
        Paladin *paladin = dynamic_cast< Paladin *>(colliding_items[i]);
        Spearman *spearman = dynamic_cast<Spearman *>(colliding_items[i]);
        Heavyshieldbearer *heavyspearman = dynamic_cast<  Heavyshieldbearer *>(colliding_items[i]);
        Shieldbearer *shieldbearer = dynamic_cast< Shieldbearer *>(colliding_items[i]);
        Heavyshieldbearer *heavyshieldbearer = dynamic_cast< Heavyshieldbearer *>(colliding_items[i]);
        Vampire *vampire = dynamic_cast< Vampire *>(colliding_items[i]);
        Bomber *bomber = dynamic_cast< Bomber *>(colliding_items[i]);
        Bigbomber *bigbomber = dynamic_cast< Bigbomber *>(colliding_items[i]);
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
        else if(warrior)
        {
            double this_dist = distanceTo(warrior);
            if(this_dist < closest_dist)
            {
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
        else if(berserker)
        {
            double this_dist = distanceTo(berserker);
            if(this_dist < closest_dist)
            {
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
        else if(fire_element)
        {
            double this_dist = distanceTo(fire_element);
            if(this_dist < closest_dist)
            {
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
        else if(earth_element)
        {
            double this_dist = distanceTo(earth_element);
            if(this_dist < closest_dist)
            {
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
        else if(water_element)
        {
            double this_dist = distanceTo(water_element);
            if(this_dist < closest_dist)
            {
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
        else if(dragon)
        {
            double this_dist = distanceTo(dragon);
            if(this_dist < closest_dist)
            {
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
        else if(crossbowman)
        {
            double this_dist = distanceTo(crossbowman);
            if(this_dist < closest_dist)
            {
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
        else if(paladin)
        {
            double this_dist = distanceTo(paladin);
            if(this_dist < closest_dist)
            {
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
        else if(spearman)
        {
            double this_dist = distanceTo(spearman);
            if(this_dist < closest_dist)
            {
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
        else if(heavyspearman)
        {
            double this_dist = distanceTo(heavyspearman);
            if(this_dist < closest_dist)
            {
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
        else if(shieldbearer)
        {
            double this_dist = distanceTo(shieldbearer);
            if(this_dist < closest_dist)
            {
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
        else if(heavyshieldbearer)
        {
            double this_dist = distanceTo(heavyshieldbearer);
            if(this_dist < closest_dist)
            {
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
        else if(vampire)
        {
            double this_dist = distanceTo(vampire);
            if(this_dist < closest_dist)
            {
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
        else if(bomber)
        {
            double this_dist = distanceTo(bomber);
            if(this_dist < closest_dist)
            {
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
        else if(bigbomber)
        {
            double this_dist = distanceTo(bigbomber);
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

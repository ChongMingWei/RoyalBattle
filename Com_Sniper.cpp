#include "Com_Sniper.h"
#include "Castle.h"
#include <QPixmap>
#include <QTimer>
#include <QList>
#include "Arrow.h"
#include "Bullet.h"
#include <QGraphicsScene>
#include "Knight.h"
#include "Archer.h"
#include "Rogue.h"
#include "Sniper.h"
#include "Hero.h"
#include "Berserker.h"
#include "Crossbowman.h"
#include "Dragon.h"
#include "Fire_element.h"
#include "Heavyspearman.h"
#include "Paladin.h"
#include "Spearman.h"
#include "Vampire.h"
#include "Warrior.h"
#include "Hero.h"
Com_Sniper::Com_Sniper(QGraphicsItem *parent)
{
    //set the health of a sniper
    health =10;
    //set graph
    setPixmap(QPixmap(":/image/sniper_c.png"));
    setPos(1000,220);

     //connect timer to move_forward
     QTimer * timer = new QTimer(this);
     connect(timer,SIGNAL(timeout()),this,SLOT(move_forward()));
     timer->start(200); //200ms
}

void Com_Sniper::move_forward()
{
    QList<QGraphicsItem *>colliding_items = collidingItems();
    for(int i = 0,n=colliding_items.size();i<n;++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Arrow))
        {
            --health;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Bullet))
        {
            health-=2;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Castle))
        {
            health--;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Archer))
        {
            health--;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Knight))
        {
            health-=2;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Sniper))
        {
            health-=2;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Rogue))
        {
            health--;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Hero))
        {
            health--;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Fire_element))
        {
            health--;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Warrior))
        {
            health-=3;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Berserker))
        {
            health-=4;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Dragon))
        {
            health-=3;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Crossbowman))
        {
            health-=4;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Paladin))
        {
            health-=5;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Spearman))
        {
            health-=3;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Heavyspearman))
        {
            health-=4;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Vampire))
        {
            health-=3;
        }

        if(health <= 0)
        {
            scene()->removeItem(this);
            delete this;
            return;
         }

        if(this->x()>=750 &&this->x()<=820)
                --health;

        if(this->x()>=680)
            setPos(x()-5,y());
        else if(this->y()<430)
             setPos(x()-3,y()+4);
        else if(this->y()>430)
               setPos(x()-3,y()-4);
        else if(this->y()==430&&this->x()>220)
            setPos(x()-5,y());
    }
}


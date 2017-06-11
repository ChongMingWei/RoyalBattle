#include "Water_element.h"
#include "Com_Castle.h"
#include "Berserker.h"
#include "Crossbowman.h"
#include "Dragon.h"
#include "Heavyshieldbearer.h"
#include "Heavyspearman.h"
#include "Paladin.h"
#include "Shieldbearer.h"
#include "Spearman.h"
#include "Vampire.h"
#include "Warrior.h"
#include "Knight.h"
#include "Archer.h"
#include "Rogue.h"
#include "Sniper.h"
#include <QPixmap>
#include <QTimer>
#include <QList>
#include "Arrow.h"
#include <QGraphicsScene>
#include "Com_Knight.h"
#include "Com_Archer.h"
#include "Com_Rogue.h"
#include "Com_Sniper.h"

Water_element::Water_element(QGraphicsItem *parent)
{
    //set the health
    health =1;

    //set graph
    setPixmap(QPixmap(":/image/champions2/water_element.png"));
    setPos(0,0);

     //connect timer to move_forward
     QTimer * timer = new QTimer(this);
     connect(timer,SIGNAL(timeout()),this,SLOT(move_forward()));
     timer->start(200); //200ms
}

void Water_element::move_forward()
{
    QList<QGraphicsItem *>colliding_items = collidingItems();
    for(int i = 0,n=colliding_items.size();i<n;++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Arrow))
        {
            --health;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Com_Castle))
        {
            --health;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Com_Archer))
        {
            --health;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Com_Knight))
        {
            --health;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Com_Sniper))
        {
           -- health;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Com_Rogue))
        {
            --health;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Warrior))
        {
            --health;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Berserker))
        {
            --health;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Dragon))
        {
            --health;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Crossbowman))
        {
            --health;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Paladin))
        {
            --health;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Spearman))
        {
            --health;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Heavyspearman))
        {
            --health;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Shieldbearer))
        {
            --health;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Heavyshieldbearer))
        {
            --health;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Vampire))
        {
            --health;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Archer))
        {
            --health;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Knight))
        {
            --health;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Rogue))
        {
            --health;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Sniper))
        {
            --health;
        }

        if(health == 0)
        {
            scene()->removeItem(this);
            delete this;
            return;
         }
    }

    if(this->x()<650)
    {
        if(this->y()<80)
            setPos(x()+12,y()+16);
        else if(this->y()<360&&this->y()>=80)
            setPos(x()+20,y());
        else if(this->y()<475&&this->y()>=360)
            setPos(x()+12,y()+16);
        else if(this->y()<700&&this->y()>=475)
            setPos(x()+20,y());
        else if(this->y()>=700)
            setPos(x()+12,y()-16);
    }
    else if(this->x()>=650&&this->x()<750)
        setPos(x()+20,y());
    else if(x()>=750&&x()<1200)
    {
         if(this->y()>=80&&this->y()<400)
             setPos(x()+12,y()+16);
         else if(this->y() >= 400 && this->y()<450)
            setPos(x()+20,y());
        else  if(this->y()>=450&&this->y()<=700)
             setPos(x()+12,y()-16);
    }
}





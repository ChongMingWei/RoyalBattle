#include "Heavyspearman.h"
#include "Water_element.h"
#include "Com_Castle.h"
#include <QPixmap>
#include <QTimer>
#include <QList>
#include "Arrow.h"
#include <QGraphicsScene>
#include "Com_Knight.h"
#include "Com_Archer.h"
#include "Com_Rogue.h"
#include "Com_Sniper.h"

Heavyspearman::Heavyspearman(QGraphicsItem *parent)
{
    //set the health
    health =16;

    //set graph
    setPixmap(QPixmap(":/image/champions2/heavyspearman.png"));
    setPos(0,0);

     //connect timer to move_forward
     QTimer * timer = new QTimer(this);
     connect(timer,SIGNAL(timeout()),this,SLOT(move_forward()));
     timer->start(200); //200ms
}

void Heavyspearman::move_forward()
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
            health-=2;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Com_Archer))
        {
            health-=3;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Com_Knight))
        {
            health-=4;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Com_Sniper))
        {
            health-=5;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Com_Rogue))
        {
            health-=2;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Water_element))
        {
            ++health;
        }
        if(health <= 0)
        {
            scene()->removeItem(this);
            delete this;
            return;
         }
    }

    if(this->x()<650)
    {
        if(this->y()<80)
            setPos(x()+3,y()+4);
        else if(this->y()<360&&this->y()>=80)
            setPos(x()+5,y());
        else if(this->y()<475&&this->y()>=360)
            setPos(x()+3,y()+4);
        else if(this->y()<700&&this->y()>=475)
            setPos(x()+5,y());
        else if(this->y()>=700)
            setPos(x()+3,y()-4);
    }
    else if(this->x()>=650&&this->x()<750)
        setPos(x()+5,y());
    else if(x()>=750&&x()<1200)
    {
         if(this->y()>=80&&this->y()<400)
             setPos(x()+3,y()+4);
         else if(this->y() >= 400 && this->y()<450)
            setPos(x()+5,y());
        else  if(this->y()>=450&&this->y()<=700)
             setPos(x()+3,y()-4);
    }
}



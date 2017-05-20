#include "Sniper.h"
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

Sniper::Sniper(QGraphicsItem *parent)
{
    //set the health of a sniper
    health =8;

    //set graph
    setPixmap(QPixmap(":/image/sniper.png"));
    setPos(0,0);

     //connect timer to move_forward
     QTimer * timer = new QTimer(this);
     connect(timer,SIGNAL(timeout()),this,SLOT(move_forward()));
     timer->start(200); //200ms
}

void Sniper::move_forward()
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
            health--;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Com_Archer))
        {
            health--;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Com_Knight))
        {
            health-=2;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Com_Sniper))
        {
            health-=2;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Com_Rogue))
        {
            health--;
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
            setPos(x()+6,y()+8);
        else if(this->y()<360&&this->y()>=80)
            setPos(x()+10,y());
        else if(this->y()<475&&this->y()>=360)
            setPos(x()+6,y()+8);
        else if(this->y()<700&&this->y()>=475)
            setPos(x()+10,y());
        else if(this->y()>=700)
            setPos(x()+6,y()-8);
    }
    else if(this->x()>=650&&this->x()<750)
        setPos(x()+10,y());
    else if(x()>=750&&x()<1200)
    {
         if(this->y()>=80&&this->y()<400)
             setPos(x()+6,y()+8);
         else if(this->y() >= 400 && this->y()<450)
            setPos(x()+10,y());
        else  if(this->y()>=450&&this->y()<=700)
             setPos(x()+6,y()-8);
    }
}

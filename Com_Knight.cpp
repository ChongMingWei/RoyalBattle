#include "Com_Knight.h"
#include "Castle.h"
#include <QPixmap>
#include <QTimer>
#include <QList>
#include "Arrow.h"
#include <QGraphicsScene>
#include "Knight.h"
#include "Archer.h"
#include "Rogue.h"
#include "Sniper.h"

Com_Knight::Com_Knight(QGraphicsItem *parent)
{
        //set the health of a knight
        health =10;
        //set graph
        setPixmap(QPixmap(":/image/knight_c.png"));
        setPos(1000,220);

         //connect timer to move_forward
         QTimer * timer = new QTimer(this);
         connect(timer,SIGNAL(timeout()),this,SLOT(move_forward()));
         timer->start(200); //200ms
}

void Com_Knight::move_forward()
{
    QList<QGraphicsItem *>colliding_items = collidingItems();
    for(int i = 0,n=colliding_items.size();i<n;++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Arrow))
        {
            --health;
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
            health--;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Sniper))
        {
            health--;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Rogue))
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
    if(this->x()>=680)
        setPos(x()-15,y());
    else if(this->y()<430)
         setPos(x()-9,y()+12);
    else if(this->y()>430)
           setPos(x()-9,y()-12);
    else if(this->y()==430&&this->x()>220)
        setPos(x()-15,y());
}

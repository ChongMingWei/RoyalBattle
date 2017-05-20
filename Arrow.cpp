#include "Arrow.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QList>
#include "Knight.h"
#include "Archer.h"
#include "Rogue.h"
#include "Sniper.h"
#include "Com_Knight.h"
#include "Com_Archer.h"
#include "Com_Rogue.h"
#include "Com_Sniper.h"
#include "Castle.h"
//#include "Suffer.h"
#include <QGraphicsScene>

Arrow::Arrow(QGraphicsItem * parent)
{
    //set graph
    setPixmap(QPixmap(":/image/arrow_r.png"));
    //connect a timer to move()
    QTimer * move_timer = new QTimer (this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50);  //every 50ms
}

void Arrow::move()
{
    //if arrow collides with any object,destroy arrow
    QList<QGraphicsItem *>colliding_items = collidingItems();
    for(int i = 0,n=colliding_items.size();i<n;++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Knight))
        {
            scene()->removeItem(this); //remove arrow
            delete this;                                 //delete arrow
            return;
        }
        else if(typeid(*(colliding_items[i])) == typeid(Archer))
        {
            scene()->removeItem(this); //remove arrow
            delete this;                                 //delete arrow
            return;
        }
        else if(typeid(*(colliding_items[i])) == typeid(Rogue))
        {
            scene()->removeItem(this); //remove arrow
            delete this;                                 //delete arrow
            return;
        }
        else if(typeid(*(colliding_items[i])) == typeid(Sniper))
        {
            scene()->removeItem(this); //remove arrow
            delete this;                                 //delete arrow
            return;
        }
        else if(typeid(*(colliding_items[i])) == typeid(Com_Knight))
        {
            scene()->removeItem(this); //remove arrow
            delete this;                                 //delete arrow
            return;
        }
        else if(typeid(*(colliding_items[i])) == typeid(Com_Archer))
        {
            scene()->removeItem(this); //remove arrow
            delete this;                                 //delete arrow
            return;
        }
        else if(typeid(*(colliding_items[i])) == typeid(Com_Rogue))
        {
            scene()->removeItem(this); //remove arrow
            delete this;                                 //delete arrow
            return;
        }
        else if(typeid(*(colliding_items[i])) == typeid(Com_Sniper))
        {
            scene()->removeItem(this); //remove arrow
            delete this;                                 //delete arrow
            return;
        }      
    }
    //arrow data
    int STEP_SIZE = 50;
    double theta = rotation();//degrees
    double dx,dy;
    dx = STEP_SIZE * qCos(qDegreesToRadians(theta));
    dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    setPos(x()+dx,y()+dy);
}

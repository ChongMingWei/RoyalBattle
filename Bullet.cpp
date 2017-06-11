#include "Bullet.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QList>
#include "Com_Knight.h"
#include "Com_Archer.h"
#include "Com_Rogue.h"
#include "Com_Sniper.h"
#include <QGraphicsScene>

Bullet::Bullet(QGraphicsItem * parent)
{
    //set graph
    setPixmap(QPixmap(":/image/champions2/bullet.png"));
    //connect a timer to move()
    QTimer *move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50);//every 50ms
}

void Bullet::move()
{
    QList<QGraphicsItem*>colliding_items = collidingItems();
    for(int i = 0,n=colliding_items.size();i<n;++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Com_Knight))
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
    //bullet data
    int STEP_SIZE = 75;
    double theta = rotation();//degrees
    double dx,dy;
    dx = STEP_SIZE * qCos(qDegreesToRadians(theta));
    dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    setPos(x()+dx,y()+dy);
}

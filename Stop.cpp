#include "Stop.h"
#include "Game.h"
#include "QDebug"

extern int factor;

Stop::Stop(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/image/fire.gif"));
    setPos(500,500);
}
void Stop::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->scenePos().x()>500 && event->scenePos().x()<550)
        if(event->scenePos().y()>500 && event->scenePos().y() <550)
        {factor = 1;
            qDebug()<<"SUCESS";
              }
}

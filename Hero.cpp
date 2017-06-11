#include "Hero.h"
#include <QKeyEvent>
Hero::Hero(QGraphicsItem *parent)
{
   setPixmap(QPixmap(":/image/deadpool.png"));
}

void Hero::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Up:setPos(x(),y()-20);
        break;
        case Qt::Key_Down:setPos(x(),y()+20);
        break;
        case Qt::Key_Left:setPos(x()-20,y());
        break;
        case Qt::Key_Right:setPos(x()+20,y());
        break;
    default:setPos(x(),y());
    }
}

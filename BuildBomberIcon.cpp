#include "BuildBomberIcon.h"
#include "Game.h"

extern Game * game;

BuildBomberIcon::BuildBomberIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/image/championicon/bomber_icon.png"));
}
void BuildBomberIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->summon_bomber)
    {
        //game->setCursor(QString(":/image/archer.png"));
        game->summon_bomber = new Bomber();
    }
}

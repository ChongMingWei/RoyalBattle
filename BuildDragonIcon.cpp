#include "BuildDragonIcon.h"
#include "Game.h"

extern Game * game;

BuildDragonIcon::BuildDragonIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/image/championicon/dragon_icon.png"));
}
void BuildDragonIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->summon_dragon)
    {
        //game->setCursor(QString(":/image/archer.png"));
        game->summon_dragon = new Dragon();
    }
}

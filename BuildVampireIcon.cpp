#include "BuildVampireIcon.h"
#include "Game.h"

extern Game * game;

BuildVampireIcon::BuildVampireIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/image/championicon/vampire_icon.png"));
}
void BuildVampireIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->summon_vampire)
    {
        //game->setCursor(QString(":/image/archer.png"));
        game->summon_vampire = new Vampire();
    }
}

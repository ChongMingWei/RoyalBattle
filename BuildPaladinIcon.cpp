#include "BuildPaladinIcon.h"
#include "Game.h"

extern Game * game;

BuildPaladinIcon::BuildPaladinIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/image/championicon/paladin_icon.png"));
}
void BuildPaladinIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->summon_paladin)
    {
        //game->setCursor(QString(":/image/archer.png"));
        game->summon_paladin = new Paladin();
    }
}

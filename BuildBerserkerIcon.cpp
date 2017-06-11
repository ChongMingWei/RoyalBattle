#include "BuildBerserkerIcon.h"
#include "Game.h"

extern Game * game;

BuildBerserkerIcon::BuildBerserkerIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/image/championicon/berserker_icon.png"));
}
void BuildBerserkerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->summon_berserker)
    {
        //game->setCursor(QString(":/image/archer.png"));
        game->summon_berserker = new Berserker();
    }
}

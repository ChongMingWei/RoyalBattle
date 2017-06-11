#include "BuildWater_elementIcon.h"
#include "Game.h"

extern Game * game;

BuildWater_elementIcon::BuildWater_elementIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/image/championicon/water_element_icon.png"));
}
void BuildWater_elementIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->summon_water_element)
    {
        //game->setCursor(QString(":/image/archer.png"));
        game->summon_water_element = new Water_element();
    }
}

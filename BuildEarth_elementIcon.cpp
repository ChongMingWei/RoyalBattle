#include "BuildEarth_elementIcon.h"
#include "Game.h"

extern Game * game;

BuildEarth_elementIcon::BuildEarth_elementIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/image/championicon/earth_element_icon.png"));
}
void BuildEarth_elementIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->summon_earth_element)
    {
        //game->setCursor(QString(":/image/archer.png"));
        game->summon_earth_element = new Earth_element();
    }
}

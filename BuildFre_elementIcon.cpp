#include "BuildFire_elementIcon.h"
#include "Game.h"

extern Game * game;

BuildFire_elementIcon::BuildFire_elementIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/image/championicon/fire_element_icon.png"));
}
void BuildFire_elementIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->summon_fire_element)
    {
        //game->setCursor(QString(":/image/archer.png"));
        game->summon_fire_element = new Fire_element();
    }
}

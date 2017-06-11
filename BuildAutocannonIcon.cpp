#include "BuildAutocannonIcon.h"
#include "Game.h"

extern Game * game;

BuildAutocannonIcon::BuildAutocannonIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/image/championicon/autocannon_icon.png"));
}
void BuildAutocannonIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        if(!game->summon_autocannon)
        {
            //game->setCursor(QString(":/image/champions2/autocannon.png"));
            game->summon_autocannon = new Autocannon();
        }
    }

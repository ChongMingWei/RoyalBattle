#include "BuildShieldbearerIcon.h"
#include "Game.h"

extern Game * game;

BuildShieldbearerIcon::BuildShieldbearerIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/image/championicon/shieldbearer_icon.png"));
}
void BuildShieldbearerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->summon_shieldbearer)
    {
        //game->setCursor(QString(":/image/archer.png"));
        game->summon_shieldbearer = new Shieldbearer();
    }
}

#include "BuildHeavyshieldbearerIcon.h"
#include "Game.h"

extern Game * game;

BuildHeavyshieldbearerIcon::BuildHeavyshieldbearerIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/image/championicon/heavyshieldbearer_icon.png"));
}
void BuildHeavyshieldbearerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->summon_heavyshieldbearer)
    {
        //game->setCursor(QString(":/image/archer.png"));
        game->summon_heavyshieldbearer = new Heavyshieldbearer();
    }
}

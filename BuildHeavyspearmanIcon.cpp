#include "BuildHeavyspearmanIcon.h"
#include "Game.h"

extern Game * game;

BuildHeavyspearmanIcon::BuildHeavyspearmanIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/image/championicon/heavyspearman_icon.png"));
}
void BuildHeavyspearmanIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->summon_heavyspearman)
    {
        //game->setCursor(QString(":/image/archer.png"));
        game->summon_heavyspearman = new Heavyspearman();
    }
}

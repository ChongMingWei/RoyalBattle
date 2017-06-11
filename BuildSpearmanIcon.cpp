#include "BuildSpearmanIcon.h"
#include "Game.h"

extern Game * game;

BuildSpearmanIcon::BuildSpearmanIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/image/championicon/spearman_icon.png"));
}
void BuildSpearmanIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->summon_spearman)
    {
        //game->setCursor(QString(":/image/archer.png"));
        game->summon_spearman = new Spearman();
    }
}

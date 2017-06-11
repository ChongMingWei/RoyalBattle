#include "BuildCrossbowmanIcon.h"
#include "Game.h"

extern Game * game;

BuildCrossbowmanIcon::BuildCrossbowmanIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/image/championicon/crossbowman_icon.png"));
}
void BuildCrossbowmanIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->summon_crossbowman)
    {
        //game->setCursor(QString(":/image/archer.png"));
        game->summon_crossbowman = new Crossbowman();
    }
}

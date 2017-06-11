#include "BuildBigbomberIcon.h"
#include "Game.h"

extern Game * game;

BuildBigbomberIcon::BuildBigbomberIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/image/championicon/bigbomber_icon.png"));
}
void BuildBigbomberIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->summon_bigbomber)
    {
        //game->setCursor(QString(":/image/archer.png"));
        game->summon_bigbomber = new Bigbomber();
    }
}

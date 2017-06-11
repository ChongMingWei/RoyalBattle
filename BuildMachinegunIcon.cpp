#include "BuildMachinegunIcon.h"
#include "Game.h"

extern Game * game;

BuildMachinegunIcon::BuildMachinegunIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/image/championicon/machinegun_icon.png"));
}
void BuildMachinegunIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->summon_machinegun)
    {
        //game->setCursor(QString(":/image/archer.png"));
        game->summon_machinegun = new Machinegun();
    }
}


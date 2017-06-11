#include "BuildWarriorIcon.h"
#include "Game.h"

extern Game * game;

BuildWarriorIcon::BuildWarriorIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/image/championicon/warrior_icon.png"));
}
void BuildWarriorIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->summon_warrior)
    {
        //game->setCursor(QString(":/image/archer.png"));
        game->summon_warrior = new Warrior();
    }
}

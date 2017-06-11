#include "BuildArcherIcon.h"
#include "Game.h"

extern Game * game;

BuildArcherIcon::BuildArcherIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
    {
        setPixmap(QPixmap(":/image/championicon/archer_icon.png"));
    }
void BuildArcherIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        if(!game->summon_archer)
        {
            //game->setCursor(QString(":/image/archer.png"));
            game->summon_archer = new Archer();
        }
    }

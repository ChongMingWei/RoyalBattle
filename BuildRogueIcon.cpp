#include "BuildRogueIcon.h"
#include "Game.h"

extern Game * game;

BuildRogueIcon::BuildRogueIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
    {
        setPixmap(QPixmap(":/image/championicon/rogue_icon.png"));
    }
void BuildRogueIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        if(!game->summon_rogue)
        {
            //game->setCursor(QString(":/image/rogue.png"));
            game->summon_rogue = new Rogue();
        }
    }

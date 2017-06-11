#include "BuildKnightIcon.h"
#include "Game.h"

extern Game * game;

BuildKnightIcon::BuildKnightIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
    {
        setPixmap(QPixmap(":/image/championicon/knight_icon.png"));
    }
void BuildKnightIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        if(!game->summon_knight)
        {
            //game->setCursor(QString(":/image/knight.png"));
            game->summon_knight = new Knight();
        }
    }

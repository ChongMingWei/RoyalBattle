#include "BuildSniperIcon.h"
#include "Game.h"

extern Game * game;

BuildSniperIcon::BuildSniperIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
    {
        setPixmap(QPixmap(":/image/sniper_icon.png"));
    }
void BuildSniperIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        if(!game->summon_sniper)
        {
            //game->setCursor(QString(":/image/snipert.png"));
            game->summon_sniper = new Sniper();
        }
    }

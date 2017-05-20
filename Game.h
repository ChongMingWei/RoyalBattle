#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include "Knight.h"
#include "Archer.h"
#include "Rogue.h"
#include "Sniper.h"
#include "Com_Knight.h"
#include "Com_Archer.h"
#include "Com_Rogue.h"
#include "Com_Sniper.h"
#include <QTimer>
#include <QObject>

class Game:public QGraphicsView
{
    Q_OBJECT
public:
    //member functions
    Game();
    void setCursor(QString filename);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void createChampions(int numberOfChampions);
    //member attributes
    QGraphicsScene *scene;
    QGraphicsPixmapItem * cursor;
    Knight * summon_knight;
    Archer *summon_archer;
    Rogue * summon_rogue;
    Sniper * summon_sniper;

     QTimer * spawnTimer;
     int ChampionsSpawned;
     int maxNumberOfChampions;
public slots:
    void spawn();
};
#endif // GAME_H

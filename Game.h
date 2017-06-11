#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include "Knight.h"
#include "Archer.h"
#include "Rogue.h"
#include "Sniper.h"
#include "Berserker.h"
#include "Bomber.h"
#include "Bigbomber.h"
#include "Crossbowman.h"
#include "Dragon.h"
#include "Earth_element.h"
#include "Fire_element.h"
#include "Heavyshieldbearer.h"
#include "Heavyspearman.h"
#include "Paladin.h"
#include "Spearman.h"
#include "Shieldbearer.h"
#include "Vampire.h"
#include "Water_element.h"
#include "Warrior.h"
#include "Com_Knight.h"
#include "Com_Archer.h"
#include "Com_Rogue.h"
#include "Com_Sniper.h"
#include "Autocannon.h"
#include "Machinegun.h"
#include <QTimer>
//#include <Fire.h>


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
    Autocannon * summon_autocannon;
    Berserker * summon_berserker;
    Bomber * summon_bomber;
    Bigbomber * summon_bigbomber;
    Crossbowman * summon_crossbowman;
    Dragon * summon_dragon;
    Earth_element * summon_earth_element;
    Fire_element * summon_fire_element;
    Heavyshieldbearer * summon_heavyshieldbearer;
    Heavyspearman * summon_heavyspearman;
    Machinegun * summon_machinegun;
    Paladin * summon_paladin;
    Shieldbearer * summon_shieldbearer;
    Spearman * summon_spearman;
    Vampire * summon_vampire;
    Warrior * summon_warrior;
    Water_element * summon_water_element;

     QTimer * spawnTimer;
     int ChampionsSpawned;
     int maxNumberOfChampions;
public slots:
    void spawn();
};
#endif // GAME_H

#include "Game.h"
#include <QGraphicsScene>
#include "Castle.h"
#include "Com_Castle.h"
#include "Arrow.h"
#include "BuildArcherIcon.h"
#include "BuildKnightIcon.h"
#include "BuildRogueIcon.h"
#include "BuildSniperIcon.h"
#include <QMediaPlayer>


Game::Game(): QGraphicsView()
{
    //create a scene
    scene= new QGraphicsScene(this);
    scene->setSceneRect(0,0,1500,1000);

    //set background
    QImage background;
    background.load(":/image/battlemap2.jpg");
    background = background.scaled(1500,875);
    setBackgroundBrush(QBrush(background));

    //set the scene
    setScene(scene);

    //create castle
    Castle * user =new Castle();
    user->setPos(167,298);
    Com_Castle * com =new Com_Castle();
    com->setPos(1077,298);

    //add the castle to the scene
    scene->addItem(user);
    scene->addItem(com);

    //set cursor
    cursor = nullptr;
    summon_knight = nullptr;
    summon_archer = nullptr;
    summon_rogue= nullptr;
    summon_sniper = nullptr;
    setMouseTracking(true);

    //set the window
    setFixedSize(1500,1000);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //spawn champions
    ChampionsSpawned = 0;
    maxNumberOfChampions = 0;
    createChampions(10);

    //play background music
    QMediaPlayer * music = new QMediaPlayer();
    music -> setMedia(QUrl("qrc:/image/bgm.mp3"));
    music->play();

    //set icon
    BuildKnightIcon * sk = new BuildKnightIcon();
    BuildArcherIcon * sa = new BuildArcherIcon();
    BuildRogueIcon * sr = new BuildRogueIcon();
    BuildSniperIcon * ss= new BuildSniperIcon();
    sa->setPos(x()+170,y()+5);
    sr->setPos(x(),y()+700);
    ss->setPos(x()+170,y()+700);
    scene->addItem(sk);
    scene->addItem(sa);
    scene->addItem(sr);
    scene->addItem(ss);


}

void Game::setCursor(QString filename)
{
    if(cursor)
    {
        scene->removeItem(cursor);
        delete cursor;
    }
    cursor = new QGraphicsPixmapItem();
    cursor -> setPixmap(QPixmap(filename));
    scene->addItem(cursor);
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
     if(cursor)
     {
         cursor->setPos(event->pos());
     }
}

void Game::mousePressEvent(QMouseEvent *event)
    {
        if(summon_knight)
        {
            scene->addItem(summon_knight);
            summon_knight->setPos(event->pos());
            summon_knight = nullptr;
            cursor = nullptr;
        }
        else if(summon_archer)
        {
            scene->addItem(summon_archer);
            summon_archer->setPos(event->pos());
            summon_archer = nullptr;
            cursor = nullptr;
        }
        else if(summon_rogue)
        {
            scene->addItem(summon_rogue);
            summon_rogue->setPos(event->pos());
            summon_rogue = nullptr;
            cursor = nullptr;
        }
        else if(summon_sniper)
        {
            scene->addItem(summon_sniper);
            summon_sniper->setPos(event->pos());
            summon_sniper = nullptr;
            cursor = nullptr;
        }
        else
        {
            QGraphicsView::mousePressEvent(event);
        }
    }

void Game::createChampions(int numberOfChampions)
{
    ChampionsSpawned = 0;
    maxNumberOfChampions = numberOfChampions;
    spawnTimer = new QTimer(this);
    connect(spawnTimer,SIGNAL(timeout()),this,SLOT(spawn()));
    spawnTimer->start(1000);
}

void Game::spawn()
{
    // spawn an champion
    Com_Archer * a = new Com_Archer();
    a->setPos(1077,300);
    scene->addItem(a);
     if(ChampionsSpawned>=3)
     {
        Com_Sniper * s= new Com_Sniper();
        s->setPos(1057,500);
        scene->addItem(s);
     }
    if(ChampionsSpawned>=5)
    {
        Com_Rogue * r = new Com_Rogue();
        r->setPos(1057,500);
        scene->addItem(r);
    }
    if(ChampionsSpawned>=8)
    {
        Com_Knight * k = new Com_Knight();
        k->setPos(1057,250);
        scene->addItem(k);
    }

    ChampionsSpawned += 1;

    if (ChampionsSpawned >= maxNumberOfChampions)
    {
        spawnTimer->disconnect();
    }
}

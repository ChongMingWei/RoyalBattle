#include "Game.h"
#include <QGraphicsScene>
#include "Castle.h"
#include "Com_Castle.h"
#include "Arrow.h"
#include "Bullet.h"
#include "BuildArcherIcon.h"
#include "BuildKnightIcon.h"
#include "BuildRogueIcon.h"
#include "BuildSniperIcon.h"
#include "BuildAutocannonIcon.h"
#include "BuildBerserkerIcon.h"
#include "BuildBigbomberIcon.h"
#include "BuildBomberIcon.h"
#include "BuildCrossbowmanIcon.h"
#include "BuildDragonIcon.h"
#include "BuildEarth_elementIcon.h"
#include "BuildFire_elementIcon.h"
#include "BuildHeavyshieldbearerIcon.h"
#include "BuildHeavyspearmanIcon.h"
#include "BuildMachinegunIcon.h"
#include "BuildPaladinIcon.h"
#include "BuildShieldbearerIcon.h"
#include "BuildSpearmanIcon.h"
#include "BuildVampireIcon.h"
#include "BuildWarriorIcon.h"
#include "BuildWater_elementIcon.h"
#include <QMediaPlayer>
#include "Stop.h"
#include "Hero.h"
#include <QLabel>
#include <QMovie>

extern int factor;

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

    //create hero
    Hero *hero = new Hero();
    hero->setPos(300,650);
    scene->addItem(hero);
    hero->setFlag(QGraphicsItem::ItemIsFocusable);
    hero->setFocus();

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
    summon_autocannon = nullptr;
    summon_berserker = nullptr;
    summon_bomber = nullptr;
    summon_bigbomber = nullptr;
    summon_crossbowman = nullptr;
    summon_dragon = nullptr;
    summon_earth_element = nullptr;
    summon_fire_element = nullptr;
    summon_heavyshieldbearer = nullptr;
    summon_heavyspearman = nullptr;
    summon_machinegun = nullptr;
    summon_paladin = nullptr;
    summon_shieldbearer = nullptr;
    summon_spearman = nullptr;
    summon_vampire = nullptr;
    summon_warrior = nullptr;
    summon_water_element = nullptr;
    setMouseTracking(true);

    //set the window
    setFixedSize(1500,1000);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //spawn champions
      ChampionsSpawned = 0;
      maxNumberOfChampions = 0;
      createChampions(30);

    //play background music
    QMediaPlayer * music = new QMediaPlayer();
    music -> setMedia(QUrl("qrc:/image/bgm.mp3"));
    music->play();

    //set icon
    BuildKnightIcon * aa = new BuildKnightIcon();
    BuildArcherIcon * bb = new BuildArcherIcon();
    BuildRogueIcon * cc = new BuildRogueIcon();
    BuildSniperIcon * dd= new BuildSniperIcon();
    BuildBerserkerIcon * ee = new BuildBerserkerIcon();
    BuildBigbomberIcon * ff = new  BuildBigbomberIcon();
    BuildBomberIcon * gg = new BuildBomberIcon();
    BuildCrossbowmanIcon * hh= new BuildCrossbowmanIcon();
    BuildDragonIcon * ii = new  BuildDragonIcon();
    BuildEarth_elementIcon * jj = new BuildEarth_elementIcon();
    BuildFire_elementIcon * kk = new BuildFire_elementIcon();
    BuildHeavyshieldbearerIcon * ll = new BuildHeavyshieldbearerIcon();
    BuildHeavyspearmanIcon * mm = new BuildHeavyspearmanIcon();
    BuildPaladinIcon * nn = new BuildPaladinIcon();
    BuildShieldbearerIcon * oo = new BuildShieldbearerIcon();
    BuildSpearmanIcon * pp = new BuildSpearmanIcon();
    BuildVampireIcon * qq = new BuildVampireIcon();
    BuildWarriorIcon * rr = new BuildWarriorIcon();
    BuildWater_elementIcon * ss = new BuildWater_elementIcon();
    BuildAutocannonIcon * tt = new BuildAutocannonIcon();
    BuildMachinegunIcon * uu = new BuildMachinegunIcon();
    bb->setPos(x(),y());
    hh->setPos(x()+90,y());
    aa->setPos(x(),y()+85);
    nn->setPos(x()+90,y()+85);
    rr->setPos(x(),y()+170);
    ee->setPos(x()+90,y()+170);
    oo->setPos(x(),y()+255);
    ll->setPos(x()+90,y()+255);
    pp->setPos(x(),y()+340);
    mm->setPos(x()+90,y()+340);
    gg->setPos(x(),y()+425);
    ff->setPos(x()+90,y()+425);
    uu->setPos(x(),y()+510);
    tt->setPos(x()+90,y()+510);
    cc->setPos(x(),y()+595);
    dd->setPos(x()+90,y()+595);
    kk->setPos(x(),y()+680);
    jj->setPos(x()+90,y()+680);
    ss->setPos(x(),y()+765);
    qq->setPos(x()+90,y()+765);
    ii->setPos(x()+180,y()+765);
    scene->addItem(aa);
    scene->addItem(bb);
    scene->addItem(cc);
    scene->addItem(dd);
    scene->addItem(ee);
    scene->addItem(ff);
    scene->addItem(gg);
    scene->addItem(hh);
    scene->addItem(ii);
    scene->addItem(jj);
    scene->addItem(kk);
    scene->addItem(ll);
    scene->addItem(mm);
    scene->addItem(nn);
    scene->addItem(oo);
    scene->addItem(pp);
    scene->addItem(qq);
    scene->addItem(rr);
    scene->addItem(ss);
    scene->addItem(tt);
    scene->addItem(uu);

    //set upfirewall
    QLabel * label_a = new QLabel(this);
    QMovie *movie_a = new QMovie(":/image/fire.gif");
    label_a->move(800,150);
    label_a->setMovie(movie_a);
    movie_a->start();
    QLabel * label_b = new QLabel(this);
    QMovie *movie_b = new QMovie(":/image/fire.gif");
    label_b->move(800,200);
    label_b->setMovie(movie_b);
    movie_b->start();
    QLabel * label_c = new QLabel(this);
    QMovie *movie_c = new QMovie(":/image/fire.gif");
    label_c->move(800,250);
    label_c->setMovie(movie_c);
    movie_c->start();
    QLabel * label_d = new QLabel(this);
    QMovie *movie_d = new QMovie(":/image/fire.gif");
    label_d->move(800,300);
    label_d->setMovie(movie_d);
    movie_d->start();
    //set downfirewall
    QLabel * label_1 = new QLabel(this);
    QMovie *movie_1 = new QMovie(":/image/fire.gif");
    label_1->move(800,500);
    label_1->setMovie(movie_1);
    movie_1->start();
    QLabel * label_2 = new QLabel(this);
    QMovie *movie_2 = new QMovie(":/image/fire.gif");
    label_2->move(800,550);
    label_2->setMovie(movie_2);
    movie_2->start();
    QLabel * label_3 = new QLabel(this);
    QMovie *movie_3 = new QMovie(":/image/fire.gif");
    label_3->move(800,600);
    label_3->setMovie(movie_3);
    movie_3->start();
    QLabel * label_4 = new QLabel(this);
    QMovie *movie_4 = new QMovie(":/image/fire.gif");
    label_4->move(800,650);
    label_4->setMovie(movie_4);
    movie_4->start();
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
        else if(summon_autocannon)
        {
            scene->addItem(summon_autocannon);
            summon_autocannon->setPos(event->pos());
            summon_autocannon = nullptr;
            cursor = nullptr;
        }
        else if(summon_berserker)
        {
            scene->addItem(summon_berserker);
            summon_berserker->setPos(event->pos());
            summon_berserker = nullptr;
            cursor = nullptr;
        }
        else if(summon_bigbomber)
        {
            scene->addItem(summon_bigbomber);
            summon_bigbomber->setPos(event->pos());
           summon_bigbomber = nullptr;
            cursor = nullptr;
        }
        else if(summon_bomber)
        {
            scene->addItem(summon_bomber);
            summon_bomber->setPos(event->pos());
            summon_bomber = nullptr;
            cursor = nullptr;
        }
        else if(summon_crossbowman)
        {
            scene->addItem(summon_crossbowman);
            summon_crossbowman->setPos(event->pos());
            summon_crossbowman = nullptr;
            cursor = nullptr;
        }
        else if(summon_dragon)
        {
            scene->addItem(summon_dragon);
            summon_dragon->setPos(event->pos());
            summon_dragon = nullptr;
            cursor = nullptr;
        }
        else if(summon_earth_element)
        {
            scene->addItem(summon_earth_element);
            summon_earth_element->setPos(event->pos());
            summon_earth_element = nullptr;
            cursor = nullptr;
        }
        else if(summon_fire_element)
        {
            scene->addItem(summon_fire_element);
            summon_fire_element->setPos(event->pos());
            summon_fire_element = nullptr;
            cursor = nullptr;
        }
        else if(summon_heavyshieldbearer)
        {
            scene->addItem(summon_heavyshieldbearer);
            summon_heavyshieldbearer->setPos(event->pos());
            summon_heavyshieldbearer = nullptr;
            cursor = nullptr;
        }
        else if(summon_heavyspearman)
        {
            scene->addItem(summon_heavyspearman);
            summon_heavyspearman->setPos(event->pos());
            summon_heavyspearman = nullptr;
            cursor = nullptr;
        }
        else if(summon_machinegun)
        {
            scene->addItem(summon_machinegun);
            summon_machinegun->setPos(event->pos());
            summon_machinegun = nullptr;
            cursor = nullptr;
        }
        else if(summon_paladin)
        {
            scene->addItem(summon_paladin);
            summon_paladin->setPos(event->pos());
            summon_paladin = nullptr;
            cursor = nullptr;
        }
        else if(summon_shieldbearer)
        {
            scene->addItem(summon_shieldbearer);
            summon_shieldbearer->setPos(event->pos());
            summon_shieldbearer = nullptr;
            cursor = nullptr;
        }
        else if(summon_spearman)
        {
            scene->addItem(summon_spearman);
            summon_spearman->setPos(event->pos());
            summon_spearman = nullptr;
            cursor = nullptr;
        }
        else if(summon_vampire)
        {
            scene->addItem(summon_vampire);
            summon_vampire->setPos(event->pos());
            summon_vampire = nullptr;
            cursor = nullptr;
        }
        else if(summon_warrior)
        {
            scene->addItem(summon_warrior);
            summon_warrior->setPos(event->pos());
            summon_warrior = nullptr;
            cursor = nullptr;
        }
        else if(summon_water_element)
        {
            scene->addItem(summon_water_element);
            summon_water_element->setPos(event->pos());
            summon_water_element = nullptr;
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
    spawnTimer->start(2000);
}

void Game::spawn()
{
    // spawn an champion
    /*if(ChampionsSpawned>=0)
    {
        Com_Archer * a = new Com_Archer();
        a->setPos(1077,300);
        scene->addItem(a);
        ChampionsSpawned += 1;
    }
     if(ChampionsSpawned>=3)
     {
        Com_Sniper * s= new Com_Sniper();
        s->setPos(1057,500);
        scene->addItem(s);
        ChampionsSpawned += 1;
     }
    if(ChampionsSpawned>=5)
    {
        Com_Rogue * r = new Com_Rogue();
        r->setPos(1057,500);
        scene->addItem(r);
        ChampionsSpawned += 1;
    }
    if(ChampionsSpawned>=8)
    {
        Com_Knight * k = new Com_Knight();
        k->setPos(1057,250);
        scene->addItem(k);
    }*/
    Com_Archer * a = new Com_Archer();
    a->setPos(1077,300);
    scene->addItem(a);
    Com_Sniper * s= new Com_Sniper();
    s->setPos(1057,500);
    scene->addItem(s);
    Com_Rogue * r = new Com_Rogue();
    r->setPos(1057,600);
    scene->addItem(r);
    Com_Knight * k = new Com_Knight();
    k->setPos(1057,200);
    scene->addItem(k);

    if (ChampionsSpawned >= maxNumberOfChampions)
    {
        spawnTimer->disconnect();
    }
}

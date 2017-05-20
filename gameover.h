#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <iostream>
#include <QLabel>
using namespace std;

class Gameover: public QGraphicsPixmapItem
{
public:
    Gameover();
 private:
    QLabel *label;
};
#endif // GAMEOVER_H

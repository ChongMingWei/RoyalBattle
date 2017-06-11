#include <QApplication>
#include "Game.h"

Game * game;
int factor = 0;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();

    return a.exec();
}

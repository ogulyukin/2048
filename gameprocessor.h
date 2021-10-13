#ifndef GAMEPROCESSOR_H
#define GAMEPROCESSOR_H

#include <QRandomGenerator>
#include <QDebug>
#include "gamerect.h"
#include "rectcoordinates.h"

class GameProcessor
{
public:
    GameProcessor();
    static int newRectPosition(int max, QList<RectCoordinates*> *rectDim);
    static int twoOrFour();
    static void newGame(QList<GameRect*> *rectangles, QList<RectCoordinates*> *rectDim);
    static bool generateNewGameRect(QList<GameRect*> *rectangles, QList<RectCoordinates*> *rectDim);
private:
    static int getFreeCellcount(QList<RectCoordinates*> *rectDim);
};

#endif // GAMEPROCESSOR_H

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
    static bool turnLeft(QList<GameRect*> *rectangles, QList<RectCoordinates*> *rectDim);
    static bool turnRight(QList<GameRect*> *rectangles, QList<RectCoordinates*> *rectDim);
    static bool turnUp(QList<GameRect*> *rectangles, QList<RectCoordinates*> *rectDim);
    static bool turnDown(QList<GameRect*> *rectangles, QList<RectCoordinates*> *rectDim);
private:
    static int getFreeCellcount(QList<RectCoordinates*> *rectDim);
    static void processingRight(int index, GameRect* rect, QList<RectCoordinates *> *rectDim);
    static void processingLeft(int index, GameRect* rect, QList<RectCoordinates *> *rectDim);
    static void processingUp(int index, GameRect* rect, QList<RectCoordinates *> *rectDim);
    static void processingDown(int index, GameRect* rect, QList<RectCoordinates *> *rectDim);
};

#endif // GAMEPROCESSOR_H

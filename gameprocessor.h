#ifndef GAMEPROCESSOR_H
#define GAMEPROCESSOR_H

#include <QRandomGenerator>
#include <QDebug>
#include "gamerect.h"
#include "rectcoordinates.h"
#include "scorechecker.h"

class GameProcessor
{
public:
    static int newRectPosition(int max, QList<RectCoordinates*> *rectDim);
    static int twoOrFour();
    static void newGame(QList<GameRect*> *rectangles, QList<RectCoordinates*> *rectDim);
    static int generateNewGameRect(QList<GameRect*> *rectangles, QList<RectCoordinates*> *rectDim);
    static bool turnLeft(QList<GameRect*> *rectangles, QList<RectCoordinates*> *rectDim, ScoreChecker *score);
    static bool turnRight(QList<GameRect*> *rectangles, QList<RectCoordinates*> *rectDim, ScoreChecker *score);
    static bool turnUp(QList<GameRect*> *rectangles, QList<RectCoordinates*> *rectDim, ScoreChecker *score);
    static bool turnDown(QList<GameRect*> *rectangles, QList<RectCoordinates*> *rectDim, ScoreChecker *score);
    static void setColor(GameRect* rect);
private:
    static int getFreeCellcount(QList<RectCoordinates*> *rectDim);
    static void processingRight(int index, GameRect* rect, QList<GameRect*> *rectangles, QList<RectCoordinates *> *rectDim, ScoreChecker *score);
    static void processingLeft(int index, GameRect* rect, QList<GameRect*> *rectangles, QList<RectCoordinates *> *rectDim, ScoreChecker *score);
    static void processingUp(int index, GameRect* rect, QList<GameRect*> *rectangles, QList<RectCoordinates *> *rectDim, ScoreChecker *score);
    static void processingDown(int index, GameRect* rect, QList<GameRect*> *rectangles, QList<RectCoordinates *> *rectDim, ScoreChecker *score);
    static void setNewText(GameRect* rect, ScoreChecker *score);
};

#endif // GAMEPROCESSOR_H

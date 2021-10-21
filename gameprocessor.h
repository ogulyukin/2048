#ifndef GAMEPROCESSOR_H
#define GAMEPROCESSOR_H

#include <QObject>
#include <QRandomGenerator>
#include <QDebug>
#include "gamerect.h"
#include "rectcoordinates.h"
#include "scorechecker.h"
#include <QTimer>

class GameProcessor : public QObject
{
    Q_OBJECT
public:
    explicit GameProcessor(QList<GameRect*> *rectangles, QList<RectCoordinates*> *rectDim, ScoreChecker *score, QObject *parent = nullptr);

    int newRectPosition(int max);
    void newGame();
    int generateNewGameRect();
    void turnLeft();
    void turnRight();
    void turnUp();
    void turnDown();
    void setColor(GameRect* rect);
    Q_INVOKABLE void setInProcess(bool newInProcess);

signals:
    void movingXReady();
    void movingYReady();
    void endOfTurn();

public slots:

private slots:
    void timeOut();
private:
    void turnLeft2();
    void turnLeft3();
    void turnRight2();
    void turnRight3();
    void turnUp2();
    void turnUp3();
    void turnDown2();
    void turnDown3();
    int getFreeCellcount();
    void processingRight(int index, GameRect* rect);
    void processingLeft(int index, GameRect* rect);
    void processingUp(int index, GameRect* rect);
    void processingDown(int index, GameRect* rect);
    void setNewText(GameRect* rect);
    int twoOrFour();
    void waitForAnimation();
    int direction;
    int stage;
    bool inProcess;
    QTimer* timer;
    QList<GameRect*> *rectangles;
    QList<RectCoordinates*> *rectDim;
    ScoreChecker *score;
};

#endif // GAMEPROCESSOR_H

#ifndef VIEWCHANGER_H
#define VIEWCHANGER_H

#include <QObject>
#include <QKeyEvent>
#include "gamerect.h"
#include "gameprocessor.h"
#include "rectcoordinates.h"
#include "keyboardfilter.h"
#include "scorechecker.h"

class ViewChanger : public QObject
{
    Q_OBJECT
public:
    explicit ViewChanger(KeyboardFilter* filter, QObject *parent = nullptr);
    QList<GameRect*> rectangles;
    QList<RectCoordinates*> rectDim;
    ScoreChecker *score;
    GameProcessor *processor;

signals:
    void gameOVER();

public slots:
    Q_INVOKABLE void newGame();
    void makeTurn(int direction);

private:
    void clearGameRect();
    KeyboardFilter* filter;
    bool turnProcessing;
    void refreshView();
    double getRightcoordinateX(int count);
    double getRightcoordinateY(int count);
    void checkView();
    void reporter01();
    void reporter02(int count);
};

#endif // VIEWCHANGER_H

#include "viewchanger.h"

ViewChanger::ViewChanger(KeyboardFilter* filter, QObject *parent) : QObject(parent),
    filter(filter)
{
    for(int i = 0; i < 16; i++)
    {
        GameRect *rect = new GameRect(this);
        rectangles.append(rect);
        RectCoordinates *drect = new RectCoordinates(this);
        rectDim.append(drect);
    }
    connect(filter, &KeyboardFilter::nextTurn, this, &ViewChanger::makeTurn);
    turnProcessing = true;
}

void ViewChanger::newGame()
{
    qDebug() << "**********************New game**********************";
    clearGameRect();
    GameProcessor::newGame(&rectangles, &rectDim);
    turnProcessing = false;
}

void ViewChanger::makeTurn(int direction)
{
    if(turnProcessing)
        return;
    turnProcessing = true;
    qDebug() << "Pressed key: " << direction;
    switch (direction) {
    case 0:
        GameProcessor::turnLeft(&rectangles, &rectDim);
        break;
    case 1:
        GameProcessor::turnRight(&rectangles, &rectDim);
        break;
    case 2:
        GameProcessor::turnUp(&rectangles, &rectDim);
        break;
    case 3:
        GameProcessor::turnDown(&rectangles, &rectDim);
    }
    reporter01();
    refreshView();
    bool result = GameProcessor::generateNewGameRect(&rectangles, &rectDim);
    turnProcessing = false;
    if(!result)
    {
        qDebug() << "MakeTurn: Game Over!";
        emit gameOVER();
    }
}

void ViewChanger::clearGameRect()
{
    foreach(auto it, rectangles)
    {
        it->clear();
    }
    foreach(auto it, rectDim)
    {
        it->busy = -1;
    }
}

void ViewChanger::refreshView()
{
    int count = 0;
    foreach(auto it, rectangles)
    {
        if(it->visible())
        {
            double pointX = getRightcoordinateX(count);
            double pointY = getRightcoordinateY(count);
            if(it->x() != pointX)
            {
                it->setX(pointX);
            }
            if(it->y() != pointY)
            {
                it->setY(pointY);
            }
        }
        count++;
    }
}

double ViewChanger::getRightcoordinateX(int count)
{
    foreach(auto it, rectDim)
    {
        if(it->busy == count)
        {
            return it->dX();
        }
    }
    return 0;
}

double ViewChanger::getRightcoordinateY(int count)
{
    foreach(auto it, rectDim)
    {
        if(it->busy == count)
        {
            return it->dY();
        }
    }
    return 0;
}

void ViewChanger::reporter01()
{
    int count = 0;
    foreach(auto it, rectangles)
    {
        if(it->visible())
        {
            qDebug() << "Reporting: " << it << " x: " << it->x() << " to: " << it->to();
            reporter02(count);
//            it->setVisible(false);
//            it->setVisible(true);
        }
        count++;
    }
}


void ViewChanger::reporter02(int count)
{
    foreach(auto it, rectDim)
    {
        if(it->busy == count)
        {
            qDebug() << "id: " << it->busy << " x: " << it->dX();
        }
    }
}


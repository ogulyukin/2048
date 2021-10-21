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
    score = new ScoreChecker(this);
    processor = new GameProcessor(&rectangles, &rectDim, score, this);
    connect(filter, &KeyboardFilter::nextTurn, this, &ViewChanger::makeTurn);
    turnProcessing = true;
    connect(processor, &GameProcessor::endOfTurn, [=](){turnProcessing = false;});
}

void ViewChanger::newGame()
{
    qDebug() << "**********************New game**********************";
    clearGameRect();
    score->resetScore();
    processor->newGame();
    turnProcessing = false;
    score->newRectCount = -1;
}

void ViewChanger::makeTurn(int direction)
{
    if(turnProcessing)
        return;
//    if(score->newRectCount != -1)
//        GameProcessor::setColor(rectangles.at(score->newRectCount));
    turnProcessing = true;
    qDebug() << "Pressed key: " << direction;
    switch (direction) {
    case 0:
        processor->turnLeft();
        break;
    case 1:
        processor->turnRight();
        break;
    case 2:
        processor->turnUp();
        break;
    case 3:
        processor->turnDown();
    }
    //reporter01();
//    refreshView();
//    //int result = processor->generateNewGameRect();
//    checkView();
//    turnProcessing = false;
//    if(result == -1)
//    {
//        qDebug() << "MakeTurn: Game Over!";
//        score->endGame();
//    }else
//    {
//        //score->newRectCount = result;
//        //rectangles.at(result)->setColor("red");
//    }
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
    qDebug() << "Error get right X for GRect: " << count;
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
        qDebug() << "Error get right Y for GRect: " << count;
        return 0;
}

void ViewChanger::checkView()
{
    int count = 0;
    qDebug() << "*******************Report*************************";
    foreach(auto it, rectDim)
    {
        if(it->busy != -1)
        {
            if(!rectangles.at(it->busy)->visible())
            {
                qDebug() << "Error: find hiden GRect in rectDim at cell: " << count;
                it->busy = -1;
            }
        }
        qDebug() << "Cell: " << count << " busy status: " << it->busy;
        count++;
    }
    qDebug() << "*******************Report*************************";
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


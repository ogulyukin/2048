#include "viewchanger.h"

ViewChanger::ViewChanger(QObject *parent) : QObject(parent)
{
    for(int i = 0; i < 16; i++)
    {
       GameRect *rect = new GameRect(this);
       rectangles.append(rect);
       RectCoordinates *drect = new RectCoordinates(this);
       rectDim.append(drect);
    }
}

void ViewChanger::newGame()
{
    qDebug() << "New game";
    clearGameRect();
    GameProcessor::newGame(&rectangles, &rectDim);
}

void ViewChanger::clearGameRect()
{
    foreach(auto it, rectangles)
    {
       it->clear();
    }
    foreach(auto it, rectDim)
    {
        it->busy = false;
    }
}


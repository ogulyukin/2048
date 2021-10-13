#include "gameprocessor.h"

GameProcessor::GameProcessor()
{

}

int GameProcessor::newRectPosition(int max, QList<RectCoordinates*> *rectDim)
{
    int random = QRandomGenerator::global()->bounded(0, max);
    int count = 0;
    int absoluteCount = 0;
    foreach(RectCoordinates* it, *rectDim){
        if(!it->busy)
        {
            if(random == count)
            {
                return absoluteCount;
            }
             count++;
        }
        absoluteCount++;
    }
    return 0;
}

int GameProcessor::twoOrFour()
{
    int value = QRandomGenerator::global()->bounded(1, 100);
    qDebug() << "twoOrFour: " << value;
    return value < 90 ? true : false;
}

void GameProcessor::newGame(QList<GameRect*> *rectangles, QList<RectCoordinates*> *rectDim)
{
    generateNewGameRect(rectangles, rectDim);
    generateNewGameRect(rectangles, rectDim);
}

bool GameProcessor::generateNewGameRect(QList<GameRect*> *rectangles, QList<RectCoordinates*> *rectDim)
{
    int max = getFreeCellcount(rectDim);
    if(max == 0)
        return false;
    int random = newRectPosition(max, rectDim);

    foreach(auto it, *rectangles){
        if(it->visible() == false)
        {
            rectDim->at(random)->busy = true;
            it->setX(rectDim->at(random)->dX());
            it->setY(rectDim->at(random)->dY());
            it->setText(twoOrFour() ? "2" : "4");
            it->setColor(it->text() == "2" ? "beige" : "yellowgreen");
            it->setVisible(true);
            qDebug() << "Rect Text: " << it->text();
            return true;
        }
    }
    return false;
}

int GameProcessor::getFreeCellcount(QList<RectCoordinates*> *rectDim)
{
    int count = 0;
    foreach(RectCoordinates* it, *rectDim){
        if(!it->busy)
            count++;
    }
    return count;
}


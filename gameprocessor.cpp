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
        if(it->busy < 0 )
        {
            if(random == count)
            {
                qDebug() << "Absolute count: " << absoluteCount;
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
    int count = 0;
    foreach(auto it, *rectangles){
        if(it->visible() == false)
        {
            rectDim->at(random)->busy = count;
            it->setX(rectDim->at(random)->dX());
            it->setY(rectDim->at(random)->dY());
            it->setText(twoOrFour() ? "2" : "4");
            it->setColor(it->text() == "2" ? "beige" : "yellowgreen");
            it->setVisible(true);

            //qDebug() << "Rect Text: " << it << " " << it->text();
            max = getFreeCellcount(rectDim);

            return (max == 0 ? false : true);
        }
        count++;
    }
    return false;
}

bool GameProcessor::turnLeft(QList<GameRect *> *rectangles, QList<RectCoordinates *> *rectDim)
{
    for(int i = 1; i < 16; i += 4){
        qDebug() << "L i = " << i;
        if(rectDim->at(i)->busy != -1){
            processingLeft(i, rectangles->at(rectDim->at(i)->busy), rectDim);
        }
    }
    for(int i = 2; i < 15; i += 4)
    {
        qDebug() << " Second L i = " << i;
        if(rectDim->at(i)->busy != -1){
            processingLeft(i, rectangles->at(rectDim->at(i)->busy), rectDim);
        }
    }
    for(int i = 3; i < 16; i += 4)
    {
        qDebug() << " Third L i = " << i;
        if(rectDim->at(i)->busy != -1){
            processingLeft(i, rectangles->at(rectDim->at(i)->busy), rectDim);
        }
    }
    return true;
}

bool GameProcessor::turnRight(QList<GameRect *> *rectangles, QList<RectCoordinates *> *rectDim)
{
    for(int i = 2; i < 16; i += 4){
        qDebug() << "R i = " << i;
        if(rectDim->at(i)->busy != -1){
            processingRight(i, rectangles->at(rectDim->at(i)->busy), rectDim);
        }
    }
    for(int i = 1; i < 14; i += 4)
    {
        qDebug() << " Second R i = " << i;
        if(rectDim->at(i)->busy != -1){
            processingRight(i, rectangles->at(rectDim->at(i)->busy), rectDim);
        }
    }
    for(int i = 0; i < 14; i += 4)
    {
        qDebug() << " Third R i = " << i;
        if(rectDim->at(i)->busy != -1){
            processingRight(i, rectangles->at(rectDim->at(i)->busy), rectDim);
        }
    }
    return true;
}

bool GameProcessor::turnUp(QList<GameRect *> *rectangles, QList<RectCoordinates *> *rectDim)
{
    for(int i = 4; i < 8; i++){
        qDebug() << "Up i = " << i;
        if(rectDim->at(i)->busy != -1){
            processingUp(i, rectangles->at(rectDim->at(i)->busy), rectDim);
        }
    }
    for(int i = 8; i < 12; i++)
    {
        qDebug() << " Second Up i = " << i;
        if(rectDim->at(i)->busy != -1){
            processingUp(i, rectangles->at(rectDim->at(i)->busy), rectDim);
        }
    }
    for(int i = 12; i < 16; i++)
    {
        qDebug() << " Third Up i = " << i;
        if(rectDim->at(i)->busy != -1){
            processingUp(i, rectangles->at(rectDim->at(i)->busy), rectDim);
        }
    }
    return true;
}

bool GameProcessor::turnDown(QList<GameRect *> *rectangles, QList<RectCoordinates *> *rectDim)
{
    for(int i = 8; i < 12; i++){
        qDebug() << "D i = " << i;
        if(rectDim->at(i)->busy != -1){
            processingDown(i, rectangles->at(rectDim->at(i)->busy), rectDim);
        }
    }
    for(int i = 4; i < 8; i++)
    {
        qDebug() << " Second D i = " << i;
        if(rectDim->at(i)->busy != -1){
            processingDown(i, rectangles->at(rectDim->at(i)->busy), rectDim);
        }
    }
    for(int i = 0; i < 4; i++)
    {
        qDebug() << " Third D i = " << i;
        if(rectDim->at(i)->busy != -1){
            processingDown(i, rectangles->at(rectDim->at(i)->busy), rectDim);
        }
    }
    return true;
}

int GameProcessor::getFreeCellcount(QList<RectCoordinates*> *rectDim)
{
    int count = 0;
    foreach(RectCoordinates* it, *rectDim){
        if(it->busy == -1)
            count++;
    }
    qDebug() << "Free cels found: " << count;
    return count;
}

void GameProcessor::processingRight(int index, GameRect *rect, QList<RectCoordinates *> *rectDim)
{
    int target = rectDim->at(index)->busy;
    int cindex = index;
    do
    {
        if(rectDim->at(cindex + 1)->busy == -1){
            cindex++;
        }else
        {
            break;
        }
    }while(cindex != 3 && cindex != 7 && cindex != 11 && cindex != 15);
    if(cindex != index)
    {
        qDebug() << "Cell " << (cindex) << " free! Processing...";
        rectDim->at(cindex)->busy = target;
        rectDim->at(index)->busy = -1;
        rect->setTo(rectDim->at(cindex)->dX());
        qDebug() << "Processing target right: " << target << " x: " << rect->x() << " to: " << rect->to();
    }
}

void GameProcessor::processingLeft(int index, GameRect *rect, QList<RectCoordinates *> *rectDim)
{
    int target = rectDim->at(index)->busy;
    int cindex = index;
    do
    {
        if(rectDim->at(cindex - 1)->busy == -1){
            cindex--;
        }else
        {
            break;
        }
    }while(cindex != 0 && cindex != 4 && cindex != 8 && cindex != 12);
    if(cindex != index)
    {
        qDebug() << "Cell " << (cindex) << " free! Processing...";
        rectDim->at(cindex)->busy = target;
        rectDim->at(index)->busy = -1;
        rect->setTo(rectDim->at(cindex)->dX());
        qDebug() << "Processing target left: " << target << " x: " << rect->x() << " to: " << rect->to();
    }
}

void GameProcessor::processingUp(int index, GameRect *rect, QList<RectCoordinates *> *rectDim)
{
    int target = rectDim->at(index)->busy;
    int cindex = index;
    do
    {
        if(rectDim->at(cindex - 4)->busy == -1){
            cindex -= 4;
        }else
        {
            break;
        }
    }while(cindex > 3);
    if(cindex != index)
    {
        qDebug() << "Cell " << (cindex) << " free! Processing...";
        rectDim->at(cindex)->busy = target;
        rectDim->at(index)->busy = -1;
        rect->setToY(rectDim->at(cindex)->dY());
        qDebug() << "Processing target up: " << target << " y: " << rect->x() << " to: " << rect->to();
    }
}

void GameProcessor::processingDown(int index, GameRect *rect, QList<RectCoordinates *> *rectDim)
{
    int target = rectDim->at(index)->busy;
    int cindex = index;
    do
    {
        if(rectDim->at(cindex + 4)->busy == -1){
            cindex += 4;
        }else
        {
            break;
        }
    }while(cindex < 12);
    if(cindex != index)
    {
        qDebug() << "Cell " << (cindex) << " free! Processing...";
        rectDim->at(cindex)->busy = target;
        rectDim->at(index)->busy = -1;
        rect->setToY(rectDim->at(cindex)->dY());
        qDebug() << "Processing target Down: " << target << " y: " << rect->x() << " to: " << rect->to();
    }
}


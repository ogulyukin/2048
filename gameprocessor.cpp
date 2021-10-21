#include "gameprocessor.h"

GameProcessor::GameProcessor(QList<GameRect*> *rectangles, QList<RectCoordinates*> *rectDim, ScoreChecker *score, QObject *parent): QObject(parent),
    rectangles(rectangles), rectDim(rectDim), score(score)
{
    timer = new QTimer(this);
    timer->setInterval(300);
    connect(timer, &QTimer::timeout, this, &GameProcessor::timeOut);
}

int GameProcessor::newRectPosition(int max)
{ 
    int random = 1;
    if (max > 1)
        random = QRandomGenerator::global()->bounded(0, (max -1));
    int count = 0;
    int absoluteCount = 0;
    foreach(RectCoordinates* it, *rectDim){
        if(it->busy == -1 )
        {
            if(random == count)
            {
                qDebug() << "Free cell: " << absoluteCount;
                return absoluteCount;
            }
            if(max == 1)
                return absoluteCount;
            count++;
        }
        absoluteCount++;
    }
    qDebug() << "Error!!! no free cell found with max: " << max;
    return -1;
}

int GameProcessor::twoOrFour()
{
    int value = QRandomGenerator::global()->bounded(1, 100);
    //qDebug() << "twoOrFour: " << (value < 90 ? 2 : 4);
    return value < 90 ? true : false;
}

void GameProcessor::waitForAnimation()
{
    timer->start();
    qDebug() << "Start timer 500 ms";
    //inProcess = true;
}

void GameProcessor::setInProcess(bool newInProcess)
{
    inProcess = newInProcess;
}

void GameProcessor::timeOut()
{
    timer->stop();
    qDebug() << "Stop timer";
    if(stage == 3)
    {
        int result = generateNewGameRect();
        if(result != -1)
        {
            emit endOfTurn();
        }else
        {
            score->endGame();
        }

        return;
    }
    if(direction == 0)
    {
        if(stage == 1)
        {
            turnLeft2();
            return;
        }else
        {
            turnLeft3();
            return;
        }
    }
    if(direction == 1)
    {
        if(stage == 1)
        {
            turnRight2();
            return;
        }else
        {
            turnRight3();
            return;
        }
    }
    if(direction == 2)
    {
        if(stage == 1)
        {
            turnUp2();
            return;
        }else
        {
            turnUp3();
            return;
        }
    }
    if(direction == 3)
    {
        if(stage == 1)
        {
            turnDown2();
            return;
        }else
        {
            turnDown3();
            return;
        }
    }
}

void GameProcessor::newGame()
{
    generateNewGameRect();
    generateNewGameRect();
}

int GameProcessor::generateNewGameRect()
{
    int max = getFreeCellcount();
    if(max == 0)
        return -1;
    int random = newRectPosition(max);
    if(random == -1 || random > 15)
    {
        qDebug() << "Error new random position: " << random;
        return -1;
    }
    int count = 0;
    foreach(auto it, *rectangles){
        if(it->visible() == false)
        {
            rectDim->at(random)->busy = count;
            it->setX(rectDim->at(random)->dX());
            it->setY(rectDim->at(random)->dY());
            it->setText(twoOrFour() ? "2" : "4");
            it->setColor(it->text() == "2" ? "beige" : "bisque");
            it->setVisible(true);

            qDebug() << "New Rect " << count << " at: " << random << " Value: " << it->text();
            max = getFreeCellcount();

            return (max == 0 ? -1 : count);
        }
        count++;
    }
    return -1;
}

void GameProcessor::turnLeft()
{
    direction = 0;
    for(int i = 1; i < 16; i += 4){
        if(rectDim->at(i)->busy != -1)
        {
            qDebug() << "**********************L i = " << i;
            processingLeft(i, rectangles->at(rectDim->at(i)->busy));
        }
    }
    stage = 1;
    waitForAnimation();
}


void GameProcessor::turnLeft2()
{
    for(int i = 2; i < 15; i += 4)
    {
        if(rectDim->at(i)->busy != -1)
        {
            qDebug() << " ***********************Second L i = " << i;
            processingLeft(i, rectangles->at(rectDim->at(i)->busy));
        }
    }
    stage = 2;
    waitForAnimation();
}

void GameProcessor::turnLeft3()
{
    for(int i = 3; i < 16; i += 4)
    {
        if(rectDim->at(i)->busy != -1)
        {
            qDebug() << " ************************Third L i = " << i;
            processingLeft(i, rectangles->at(rectDim->at(i)->busy));
        }
    }
    stage = 3;
    waitForAnimation();
}

void GameProcessor::turnRight()
{
    direction = 1;
    for(int i = 2; i < 16; i += 4){
        if(rectDim->at(i)->busy != -1)
        {
            qDebug() << "**************************R i = " << i;
            processingRight(i, rectangles->at(rectDim->at(i)->busy));
        }
    }
    stage = 1;
    waitForAnimation();
}

void GameProcessor::turnRight2()
{
    for(int i = 1; i < 14; i += 4)
    {
        if(rectDim->at(i)->busy != -1)
        {
            qDebug() << "************************** Second R i = " << i;
            processingRight(i, rectangles->at(rectDim->at(i)->busy));
        }
    }
    stage = 2;
    waitForAnimation();
}

void GameProcessor::turnRight3()
{
    for(int i = 0; i < 14; i += 4)
    {
        if(rectDim->at(i)->busy != -1)
        {
            qDebug() << "**************************** Third R i = " << i;
            processingRight(i, rectangles->at(rectDim->at(i)->busy));
        }
    }
    stage = 3;
    waitForAnimation();
}

void GameProcessor::turnUp()
{
    direction = 2;
    for(int i = 4; i < 8; i++){
        if(rectDim->at(i)->busy != -1)
        {
            qDebug() << "***********************Up i = " << i;
            processingUp(i, rectangles->at(rectDim->at(i)->busy));
        }
    }
    stage = 1;
    waitForAnimation();    
}


void GameProcessor::turnUp2()
{
    for(int i = 8; i < 12; i++)
    {
        if(rectDim->at(i)->busy != -1)
        {
            qDebug() << "*********************** Second Up i = " << i;
            processingUp(i, rectangles->at(rectDim->at(i)->busy));
        }
    }
    stage = 2;
    waitForAnimation();
}

void GameProcessor::turnUp3()
{
    for(int i = 12; i < 16; i++)
    {
        if(rectDim->at(i)->busy != -1)
        {
            qDebug() << "*********************** Third Up i = " << i;
            processingUp(i, rectangles->at(rectDim->at(i)->busy));
        }
    }
    stage = 3;
    waitForAnimation();
}

void GameProcessor::turnDown()
{
    direction = 3;
    for(int i = 8; i < 12; i++)
    {
        if(rectDim->at(i)->busy != -1)
        {
            qDebug() << "*********************D i = " << i;
            processingDown(i, rectangles->at(rectDim->at(i)->busy));
        }
    }
    stage = 1;
    waitForAnimation();
}


void GameProcessor::turnDown2()
{
    for(int i = 4; i < 8; i++)
    {
        if(rectDim->at(i)->busy != -1)
        {
            qDebug() << "********************* Second D i = " << i;
            processingDown(i, rectangles->at(rectDim->at(i)->busy));
        }
    }
    stage = 2;
    waitForAnimation();
}

void GameProcessor::turnDown3()
{
    for(int i = 0; i < 4; i++)
    {
        if(rectDim->at(i)->busy != -1)
        {
            qDebug() << "********************** Third D i = " << i;
            processingDown(i, rectangles->at(rectDim->at(i)->busy));
        }
    }
    stage = 3;
    waitForAnimation();
}

int GameProcessor::getFreeCellcount()
{
    int count = 0;
    foreach(RectCoordinates* it, *rectDim){
        if(it->busy == -1)
            count++;
    }
    qDebug() << "Free cels found: " << count;
    return count;
}

void GameProcessor::processingRight(int index, GameRect *rect)
{
    int target = rectDim->at(index)->busy;
    qDebug() << "Working with cell: " << target;
    int cindex = index;
    do
    {
        if(rectDim->at(cindex + 1)->busy == -1){
            cindex++;
        }else
        {
            int checkIndex = rectDim->at(cindex + 1)->busy;
            if(rect->text() == rectangles->at(checkIndex)->text())
            {
                rectangles->at(checkIndex)->setVisible(false);
                setNewText(rect);
                qDebug() << "!!!Merging: delete " << checkIndex << " at " << cindex;
                cindex++;
            }
            break;
        }
    }while(cindex != 3 && cindex != 7 && cindex != 11 && cindex != 15);
    if(cindex != index)
    {
        //qDebug() << "Cell " << (cindex) << " Processing...";
        rectDim->at(cindex)->busy = target;
        rectDim->at(index)->busy = -1;
        rect->setTo(rectDim->at(cindex)->dX());
        qDebug() << "Processing target right: " << target << " from " << index << " to " << cindex;//" x: " << rect->x() << " to: " << rect->to();
    }
}

void GameProcessor::processingLeft(int index, GameRect *rect)
{
    int target = rectDim->at(index)->busy;
    qDebug() << "Working with cell: " << target;
    int cindex = index;
    do
    {
        if(rectDim->at(cindex - 1)->busy == -1){
            cindex--;
        }else
        {
            int checkIndex = rectDim->at(cindex - 1)->busy;
            if(rect->text() == rectangles->at(checkIndex)->text())
            {
                rectangles->at(checkIndex)->setVisible(false);
                setNewText(rect);
                cindex--;
                qDebug() << "!!!Merging: delete " << checkIndex << " at " << cindex;
            }
            break;
        }
    }while(cindex != 0 && cindex != 4 && cindex != 8 && cindex != 12);
    if(cindex != index)
    {
        //qDebug() << "Cell " << (cindex) << "Processing...";
        rectDim->at(cindex)->busy = target;
        rectDim->at(index)->busy = -1;
        rect->setTo(rectDim->at(cindex)->dX());
        //qDebug() << "Processing target left: " << target << " x: " << rect->x() << " to: " << rect->to();
        qDebug() << "Processing target right: " << target << " from " << index << " to " << cindex;
    }
}

void GameProcessor::processingUp(int index, GameRect *rect)
{
    int target = rectDim->at(index)->busy;
    qDebug() << "Working with cell: " << target;
    int cindex = index;
    do
    {
        if(rectDim->at(cindex - 4)->busy == -1){
            cindex -= 4;
        }else
        {
            int checkIndex = rectDim->at(cindex - 4)->busy;
            if(rect->text() == rectangles->at(checkIndex)->text())
            {
                rectangles->at(checkIndex)->setVisible(false);
                setNewText(rect);
                cindex -= 4;
                qDebug() << "Merging: delete " << checkIndex << " at " << cindex;
            }
            break;
        }
    }while(cindex > 3);
    if(cindex != index)
    {
        //qDebug() << "Cell " << (cindex) << " free! Processing...";
        rectDim->at(cindex)->busy = target;
        rectDim->at(index)->busy = -1;
        rect->setToY(rectDim->at(cindex)->dY());
        qDebug() << "Processing target right: " << target << " from " << index << " to " << cindex;
        //qDebug() << "Processing target up: " << target << " y: " << rect->x() << " to: " << rect->to();
    }
}

void GameProcessor::processingDown(int index, GameRect *rect)
{
    int target = rectDim->at(index)->busy;
    qDebug() << "Working with cell: " << target;
    int cindex = index;
    do
    {
        if(rectDim->at(cindex + 4)->busy == -1){
            cindex += 4;
        }else
        {
            int checkIndex = rectDim->at(cindex + 4)->busy;
            if(rect->text() == rectangles->at(checkIndex)->text())
            {
                rectangles->at(checkIndex)->setVisible(false);
                setNewText(rect);
                cindex += 4;
                qDebug() << "Merging: delete " << checkIndex << " at " << cindex;
            }
            break;
        }
    }while(cindex < 12);
    if(cindex != index)
    {
        //qDebug() << "Cell " << (cindex) << " free! Processing...";
        rectDim->at(cindex)->busy = target;
        rectDim->at(index)->busy = -1;
        rect->setToY(rectDim->at(cindex)->dY());
        qDebug() << "Processing target right: " << target << " from " << index << " to " << cindex;
        //qDebug() << "Processing target Down: " << target << " y: " << rect->x() << " to: " << rect->to();
    }
}

void GameProcessor::setNewText(GameRect *rect)
{
    rect->setText(QString::number(rect->text().toInt() * 2));
    score->setScore(rect->text().toInt());
    qDebug() << "Set for: " << rect->text();
    setColor(rect);
}

void GameProcessor::setColor(GameRect *rect)
{
    switch (rect->text().toInt()) {
    case 4:
        rect->setColor("bisque");
        break;
    case 8:
        rect->setColor("aquamarine");
        break;
    case 16:
        rect->setColor("burlywood");
        break;
    case 32:
        rect->setColor("yellowgreen");
        break;
    case 64:
        rect->setColor("dodgerblue");
        break;
    case 128:
        rect->setColor("coral");
        break;
    case 256:
        rect->setColor("orange");
        break;
    case 512:
        rect->setColor("olive");
        break;
    case 1024:
        rect->setColor("stateblue");
        break;
    case 2048:
        rect->setColor("gold");
    }
}


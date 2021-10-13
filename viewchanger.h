#ifndef VIEWCHANGER_H
#define VIEWCHANGER_H

#include <QObject>
#include "gamerect.h"
#include "gameprocessor.h"
#include "rectcoordinates.h"

class ViewChanger : public QObject
{
    Q_OBJECT
public:
    explicit ViewChanger(QObject *parent = nullptr);
    QList<GameRect*> rectangles;
    QList<RectCoordinates*> rectDim;

signals:


public slots:
    Q_INVOKABLE void newGame();

private:
    void clearGameRect();
};

#endif // VIEWCHANGER_H

#include "rectcoordinates.h"

RectCoordinates::RectCoordinates(QObject *parent) : QObject(parent)
{
    busy = -1;
}

double RectCoordinates::dX() const
{
    return m_dX;
}

void RectCoordinates::setDX(double newDX)
{
    m_dX = newDX;
    emit dXChanged();
}

double RectCoordinates::dY() const
{
    return m_dY;
}

void RectCoordinates::setDY(double newDY)
{
    m_dY = newDY;
    emit dYChanged();
}

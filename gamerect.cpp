#include "gamerect.h"

GameRect::GameRect(QObject *parent): QObject(parent)
{
    m_color = "beige";
    m_text = "2";
    m_visible = false;
    m_x = 0;
    m_y = 0;
    m_to = 0;
}

const QString &GameRect::color() const
{
    return m_color;
}

void GameRect::setColor(const QString &newColor)
{
    m_color = newColor;
    emit colorChanged();
}

const QString &GameRect::text() const
{
    return m_text;
}

void GameRect::setText(const QString &newText)
{
    m_text = newText;
    emit textChanged();
}

const double &GameRect::x() const
{
    return m_x;
}

void GameRect::setX(const double &newX)
{
    m_x = newX;
    emit xChanged();
}

const double &GameRect::y() const
{
    return m_y;
}

void GameRect::setY(const double &newY)
{
    m_y = newY;
    emit yChanged();
}

bool GameRect::visible() const
{
    return m_visible;
}

void GameRect::setVisible(bool newVisible)
{
    m_visible = newVisible;
    emit visibleChanged();
}

void GameRect::clear()
{
    m_color = "beige";
    m_text = "2";
    m_x = 0;
    m_y = 0;
    setVisible(false);
}

double GameRect::to() const
{
    return m_to;
}

void GameRect::setTo(double newTo)
{
    m_to = newTo;
    emit toChanged();
}

double GameRect::toY() const
{
    return m_toY;
}

void GameRect::setToY(double newToY)
{
    m_toY = newToY;
    emit toYChanged();
}

#ifndef RECTCOORDINATES_H
#define RECTCOORDINATES_H

#include <QObject>

class RectCoordinates : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double dX READ dX WRITE setDX NOTIFY dXChanged)
    Q_PROPERTY(double dY READ dY WRITE setDY NOTIFY dYChanged)

public:
    RectCoordinates(QObject *parent = nullptr);

    double dX() const;
    void setDX(double newDX);

    double dY() const;
    void setDY(double newDY);
    bool busy;

signals:
    void dXChanged();
    void dYChanged();

private:
    double m_dX;
    double m_dY;
};

#endif // RECTCOORDINATES_H

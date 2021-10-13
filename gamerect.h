#ifndef GAMERECT_H
#define GAMERECT_H
#include <QObject>


class GameRect : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(double x READ x WRITE setX NOTIFY xChanged)
    Q_PROPERTY(double y READ y WRITE setY NOTIFY yChanged)
    Q_PROPERTY(bool visible READ visible WRITE setVisible NOTIFY visibleChanged)

public:
    GameRect(QObject *parent = nullptr);

    const QString &color() const;
    void setColor(const QString &newColor);

    const QString &text() const;
    void setText(const QString &newText);

    const double &x() const;
    void setX(const double &newX);

    const double &y() const;
    void setY(const double &newY);

    bool visible() const;
    void setVisible(bool newVisible);
    void clear();

signals:
    void colorChanged();
    void textChanged();
    void xChanged();
    void yChanged();
    void visibleChanged();

public slots:

private:
    QString m_color;
    QString m_text;
    double m_x;
    double m_y;
    bool m_visible;
};

#endif // GAMERECT_H

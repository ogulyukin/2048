#ifndef SCORECHECKER_H
#define SCORECHECKER_H

#include <QObject>
#include <QSettings>

class ScoreChecker : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int score READ score WRITE setScore NOTIFY scoreChanged)
    Q_PROPERTY(QString endGameText READ endGameText WRITE setEndGameText NOTIFY endGameTextChanged)
    Q_PROPERTY(int bestScore READ bestScore WRITE setBestScore NOTIFY bestScoreChanged)

public:
    explicit ScoreChecker(QObject *parent = nullptr);


    int score() const;
    void setScore(int newScore);
    void resetScore();

    const QString &endGameText() const;
    void setEndGameText(const QString &newEndGameText);
    void endGame();

    int bestScore() const;
    void setBestScore(int newBestScore);
    int newRectCount;

signals:

    void scoreChanged();

    void endGameTextChanged();

    void bestScoreChanged();

private:
    int m_score;
    QString m_endGameText;
    void loadSettings();
    int m_bestScore;
};

#endif // SCORECHECKER_H

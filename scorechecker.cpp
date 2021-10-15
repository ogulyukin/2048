#include "scorechecker.h"

ScoreChecker::ScoreChecker(QObject *parent) : QObject(parent)
{
    m_score = 0;
    m_endGameText = "Вы проиграли! Попробуйте еще раз";
    newRectCount = -1;
    loadSettings();
}

int ScoreChecker::score() const
{
    return m_score;
}

void ScoreChecker::setScore(int newScore)
{
    m_score += newScore;
    emit scoreChanged();
    if (newScore == 2048)
    {
        setEndGameText("Этого не может быть! Вы выиграли!");
        emit endGameTextChanged();
    }
}

void ScoreChecker::resetScore()
{
    m_score = 0;
    emit scoreChanged();
}

const QString &ScoreChecker::endGameText() const
{
    return m_endGameText;
}

void ScoreChecker::setEndGameText(const QString &newEndGameText)
{
    m_endGameText = newEndGameText;
    emit endGameTextChanged();
}

void ScoreChecker::endGame()
{
    setEndGameText("Вы проиграли! Попробуйте еще раз");
    if(m_score > m_bestScore)
    {
        setBestScore(m_score);
        QSettings settings("Game2048", "Score");
        settings.beginGroup("MyScore");
        settings.setValue("BestScore", m_bestScore);
        settings.endGroup();
    }
}

void ScoreChecker::loadSettings()
{
    QSettings settings("Game2048", "Score");
    settings.beginGroup("MyScore");
    m_bestScore = settings.value("BestScore", QVariant(0)).toInt();
    settings.endGroup();
    emit bestScoreChanged();
}

int ScoreChecker::bestScore() const
{
    return m_bestScore;
}

void ScoreChecker::setBestScore(int newBestScore)
{
    if (m_bestScore == newBestScore)
        return;
    m_bestScore = newBestScore;
    emit bestScoreChanged();
}

#include "score.h"
#include<QFont>

Score::Score()
{
    //set score to 0
    score = 0;

    //draw the score
    setPlainText(QString("Score: ") + QString::number(score));

    //change colour
    setDefaultTextColor(Qt::black);
    setFont(QFont("default", 15));

}

void Score::increase_score()
{
    //increase the score
    score ++;
    //update the visual
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore()
{
    return score;
}

void Score::add_to_score()
{
    //increase the score
    score += 5000;
    //update the visual score
    setPlainText(QString("Score: ") + QString::number(score));
}

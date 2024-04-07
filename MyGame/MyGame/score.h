#ifndef SCORE_H
#define SCORE_H
#include<QGraphicsTextItem>
#include<QObject>


class Score: public QGraphicsTextItem
{
    Q_OBJECT

public:
    Score();
    int getScore();

private:
    int score;

public slots:
    void add_to_score();
    void increase_score();
};


#endif // SCORE_H

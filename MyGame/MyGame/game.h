#ifndef GAME_H
#define GAME_H
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QWidget>
#include<QObject>
#include<QMediaPlayer>
#include<QAudioOutput>
#include"player.h"
#include"score.h"
#include"health.h"
#include"rocketbar.h"

class Game: public QGraphicsView
{
    Q_OBJECT
public:
    Game();
    Health *health;
    Score *score;
    RocketBar *rocketbar;
private:
    QGraphicsScene *scene;
    Player *player;
    QAudioOutput *audio_output;
    QMediaPlayer *music;
public slots:
    void spawn_walls();
private slots:
    void game_over();
};

#endif // GAME_H

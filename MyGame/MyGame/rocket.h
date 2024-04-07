#ifndef ROCKET_H
#define ROCKET_H
#include<QGraphicsPixmapItem>
#include<QGraphicsScene>
#include<QObject>
#include<QWidget>
#include"game.h"

class Rocket: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Rocket();

public slots:
    void move_rocket();
private:
    QMediaPlayer *wall_destroy;
    QAudioOutput *wall_destroy_output;
};

#endif // ROCKET_H

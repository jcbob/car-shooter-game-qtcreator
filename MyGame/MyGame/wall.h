#ifndef WALL_H
#define WALL_H
#include<QGraphicsPixmapItem>
#include<QGraphicsScene>
#include<QObject>
#include<QWidget>
#include"game.h"


class Wall: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Wall(int pocz=0, int kon=750);
public slots:
    void move_wall();
private:
    QMediaPlayer *crash;
    QAudioOutput *crash_output;
};

#endif // WALL_H

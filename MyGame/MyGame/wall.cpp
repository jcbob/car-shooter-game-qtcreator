#include "wall.h"
#include<QTimer>
#include<QList>
#include<stdlib.h>
#include"player.h"

extern Game *game;

Wall::Wall(int pocz, int kon): QObject(), QGraphicsPixmapItem()
{
    //set random position
    int rand_number = pocz + (rand() % (kon - pocz));
    setPos(rand_number, -118);

    int rand_car = rand()%8;
    //draw the wall
    if(rand_car == 0)
        setPixmap(QPixmap(":/Graphics/yellow car.png"));
    else if(rand_car == 1)
        setPixmap(QPixmap(":/Graphics/purple car.png"));
    else if(rand_car == 2)
        setPixmap(QPixmap(":/Graphics/grey car.png"));
    else if(rand_car == 3)
        setPixmap(QPixmap(":/Graphics/black car.png"));
    else if(rand_car ==4)
        setPixmap(QPixmap(":/Graphics/blue white car.png"));
    else if(rand_car == 5)
        setPixmap(QPixmap(":/Graphics/khaki.png"));
    else if(rand_car == 6)
        setPixmap(QPixmap(":/Graphics/orange car.png"));
    else if(rand_car == 7)
        setPixmap(QPixmap(":/Graphics/green car.png"));

    //timer for moving
    QTimer *timer = new QTimer();
    timer->setInterval(7);
    connect(timer, SIGNAL(timeout()), this, SLOT(move_wall()));
    timer->start();

    //create a media player to have the ability to play a sound
    crash = new QMediaPlayer();
    crash_output = new QAudioOutput();
    crash_output->setVolume(30);
    crash->setAudioOutput(crash_output);
    crash->setSource(QUrl("qrc:/Sounds/crash_sound.mp3"));
}

void Wall::move_wall()
{
    //check if the wall collides with the player
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0;  i < colliding_items.size(); ++i)
    {
        //check if colliding items are player & wall
        if(typeid(*(colliding_items[i])) == typeid(Player))
        {
            //remove the colliding wall
            scene()->removeItem(this);
            // delete the colliding wall
            delete this;
            //play crash sound
            crash->play();
            //decrease player health
            game->health->decrease_health();
            return;
        }
    }


    //move the wall down
    setPos(x(),y()+2);
    if(pos().y() > scene()->height())
    {
        scene()->removeItem(this);
        delete this;
    }
}

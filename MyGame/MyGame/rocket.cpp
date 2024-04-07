#include "rocket.h"
#include<QTimer>
#include<QList>
#include"wall.h"

extern Game *game;

Rocket::Rocket(): QObject(), QGraphicsPixmapItem()
{
    //draw the rocket
    setPixmap(QPixmap(":/Graphics/rocket.png"));

    //set timer to move the rocket
    QTimer *timer = new QTimer();
    timer->setInterval(20);
    connect(timer, SIGNAL(timeout()), this, SLOT(move_rocket()));
    timer->start();

    //create a media player & output with random audio for each rocket
    wall_destroy = new QMediaPlayer();
    wall_destroy_output = new QAudioOutput();
    wall_destroy->setAudioOutput(wall_destroy_output);
    int random = rand() % 4;
    if(random==0)
        wall_destroy->setSource(QUrl("qrc:/Sounds/Wall destroy 1.wav"));
    else if(random==1)
        wall_destroy->setSource(QUrl("qrc:/Sounds/Wall destroy 2.wav"));
    else if(random==2)
        wall_destroy->setSource(QUrl("qrc:/Sounds/Wall destroy 3.wav"));
    else
        wall_destroy->setSource(QUrl("qrc:/Sounds/Wall destroy 4.wav"));
}

void Rocket::move_rocket()
{
    //first check if rocket collided with wall
    QList <QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0;  i < colliding_items.size(); ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Wall))
        {
            //play the Wall_destroy.wav
            wall_destroy->play();
            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them both
            delete colliding_items[i];
            delete this;
            //add to score
            game->score->add_to_score();
            return;

        }
    }

    //move the rocket
    setPos(x(),y()-20);
    if(pos().y() < -20)
    {
        scene()->removeItem(this);
        delete this;
    }
}

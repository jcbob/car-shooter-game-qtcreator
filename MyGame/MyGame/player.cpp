#include "player.h"
#include<QKeyEvent>
#include"rocket.h"
#include"wall.h"
#include"game.h"

extern Game *game;

Player::Player()
{
    setPixmap(QPixmap(":/Graphics/race_car.png"));

}

void Player::keyPressEvent(QKeyEvent *event)
{
    // move left
    if(event->key() == Qt::Key_A)
    {
        if(!(x()-35 < 0))        //check if player wont go out of bounds
            setPos(x()-35, y()); // move player
    }
    // move right
    else if(event->key() == Qt::Key_D)
    {
        if(!(x() + 51 + 35 > scene()->width()))
            setPos(x()+35, y());
    }
    // move up
    else if(event->key() == Qt::Key_W)
    {
        if(!(y()-35 < 0))
            setPos(x(), y()-35);    //-10 because the (0,0) origin is in the top left corner of the screen and positive y goes down
    }
    // move down
    else if(event->key() == Qt::Key_S)
    {
        if(!(y() + 112 + 35 > scene()->height()))
            setPos(x(), y()+35);
    }
    //shoot the rocket
    else if(event->key() == Qt::Key_Space)
    {
        //check if the rocket progress bar is full
        if(game->rocketbar->value() >= 20)
        {
            //create a rocket
            Rocket *rocket = new Rocket();
            rocket->setPos(this->x() + 25 - 5, this->y());
            //add rocket to scene
            scene()->addItem(rocket);

            //decrease the progress bar
            game->rocketbar->setValue(game->rocketbar->value()-20);

            //play the rocket shooting sound
            QMediaPlayer *new_rocket = new QMediaPlayer;
            QAudioOutput *new_rocket_output = new QAudioOutput();
            new_rocket->setAudioOutput(new_rocket_output);
            new_rocket->setSource(QUrl("qrc:/Sounds/Rocket.wav"));
            new_rocket->play();
        }
        //if it's not full do nothing
    }
}

void Player::spawn_wall()
{
    //create wall
    Wall *wall = new Wall();
    scene()->addItem(wall);

}

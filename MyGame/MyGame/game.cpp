#include "game.h"
#include<stdlib.h>
#include<QTimer>
#include<QGraphicsTextItem>
#include<QFont>
#include"wall.h"
#include<QMediaPlayer>
#include<QAudioOutput>
#include<QBrush>
#include<QImage>

Game::Game()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,700);
    setBackgroundBrush(QBrush(QImage(":/Graphics/road.png")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,700);

    //create player
    player = new Player();
    player->setPos((width()/2) - 25, height() - 112);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    //create the score
    score = new Score();
    scene->addItem(score);

    //create health
    health = new Health();
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);

    //create progress bar for rockets
    rocketbar = new RocketBar();
    rocketbar->setValue(0);
    rocketbar->setRange(0,60);
    rocketbar->resize(10,250);
    rocketbar->setOrientation(Qt::Vertical);
    rocketbar->move(scene->width()-rocketbar->width(),scene->height()-rocketbar->height());
    scene->addWidget(rocketbar);

    //increase the score over time
    QTimer *timer_for_score = new QTimer();
    timer_for_score->setInterval(1);
    QObject::connect(timer_for_score, SIGNAL(timeout()), score, SLOT(increase_score()));
    timer_for_score->start();

    //increase the rocket progress bar
    QTimer *timer_for_rockets = new QTimer();
    timer_for_rockets->setInterval(100);
    QObject::connect(timer_for_rockets, SIGNAL(timeout()), rocketbar, SLOT(increase_rocketbar()));
    timer_for_rockets->start();

    //create car
    QTimer *timer_for_wall = new QTimer();
    timer_for_wall->setInterval(int(250 + (rand() % 1500)));
    QObject::connect(timer_for_wall, SIGNAL(timeout()), this, SLOT(spawn_walls()));
    timer_for_wall->start();

    //play some stuff
    music = new QMediaPlayer();
    audio_output = new QAudioOutput();
    music->setAudioOutput(audio_output);
    music->setSource(QUrl("qrc:/Sounds/background music.mp3"));
    audio_output->setVolume(50);
    music->play();

    //check if it's game over
    QTimer *timer_game_over = new QTimer();
    timer_game_over->setInterval(100);
    connect(timer_game_over, SIGNAL(timeout()), this, SLOT(game_over()));
    timer_game_over->start();
}


void Game::spawn_walls()
{
    if(rand() % 7 == 1)
    {
        //7% chance to spawn 2 cars at the same time
        Wall *wall1 = new Wall(5,300);
        Wall *wall2 = new Wall(355,750);
        scene->addItem(wall1);
        scene->addItem(wall2);
    }
    else
    {
        //create  1 car
        Wall *wall = new Wall();
        scene->addItem(wall);
    }

}

void Game::game_over()
{
    if(health->getHealth() <= 0)
        delete this;
    else
        return;
}

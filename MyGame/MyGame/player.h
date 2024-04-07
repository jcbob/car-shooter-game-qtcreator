#ifndef PLAYER_H
#define PLAYER_H
#include<QGraphicsPixmapItem>
#include<QObject>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Player();
    void keyPressEvent(QKeyEvent *event);
public slots:
    void spawn_wall();
};

#endif // PLAYER_H

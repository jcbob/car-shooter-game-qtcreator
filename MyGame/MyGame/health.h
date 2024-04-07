#ifndef HEALTH_H
#define HEALTH_H
#include<QGraphicsTextItem>
#include<QObject>

class Health: public QGraphicsTextItem
{
    Q_OBJECT

public:
    Health();
    int getHealth();

private:
    int health;

public slots:
    void decrease_health();
};

#endif // HEALTH_H

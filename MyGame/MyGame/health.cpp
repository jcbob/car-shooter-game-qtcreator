#include "health.h"
#include<QFont>

Health::Health()
{
    //set score to 0
    health = 3;

    //draw the score
    setPlainText(QString("Health: ") + QString::number(health));

    //change colour
    setDefaultTextColor(Qt::red);
    setFont(QFont("default", 15));

}

void Health::decrease_health()
{
    health --;
    setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth()
{
    return health;
}

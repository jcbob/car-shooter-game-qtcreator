#ifndef ROCKETBAR_H
#define ROCKETBAR_H
#include<QProgressBar>

class RocketBar: public QProgressBar
{
    Q_OBJECT
public:
    RocketBar();
private slots:
    void increase_rocketbar();
};

#endif // ROCKETBAR_H

#include "rocketbar.h"

RocketBar::RocketBar()
{

}

void RocketBar::increase_rocketbar()
{
    //increase the progress bar
    setValue(value()+1);
}

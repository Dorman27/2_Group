#ifndef GAMBLINGGAME_H
#define GAMBLINGGAME_H

#include "Player.h"
#include <iostream>

class GamblingGame
{
    Player p[2];
public:
    void play();
    ~GamblingGame();
};

#endif 

#pragma once
#ifndef GAMBLINGGAME_H
#define GAMBLINGGAME_H

#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class GamblingGame {
    Player* player1;
    Player* player2;

public:
    GamblingGame(Player* p1, Player* p2) : player1(p1), player2(p2) {}

    void play();

private:
    bool takeTurn(Player* player);
};

#endif

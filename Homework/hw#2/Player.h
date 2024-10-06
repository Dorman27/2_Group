#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player {
    string name;
public:
    Player(string n) : name(n) {}
    string getName() { return name; } 
};

#endif

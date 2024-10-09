#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
    std::string name;
public:
    void setName(std::string name);
    std::string getName();
};

#endif

//
// Created by zacka on 7/10/2024.
//

#ifndef PLAYERS_H
#define PLAYERS_H

#include <vector>
#include "Player.h"

class Player;

class Players {
private:
public:
    Players();
    static std::vector<Player*> playerList;
};



#endif //PLAYERS_H

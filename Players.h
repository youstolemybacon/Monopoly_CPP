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
    ~Players(); // Needs implementation
    static std::vector<Player*> playerList;
    static void randomizePlayerOrder();
    static void displayPlayers();
    static void setPlayerNumber();
    static void setPlayerNames();
    static std::vector<Player*> getOtherPlayers(Player* player);
};



#endif //PLAYERS_H

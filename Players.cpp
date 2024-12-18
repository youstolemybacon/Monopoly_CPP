//
// Created by zacka on 7/10/2024.
//

#include "Players.h"
#include <algorithm>
#include "Board.h"

Board Player::playerBoard;

std::vector<Player*> Players::playerList;

Players::Players()
{
    setPlayerNumber();
    setPlayerNames();
    randomizePlayerOrder();
    displayPlayers();
}

Players::~Players()
{
}

void Players::setPlayerNumber()
{
    short numberOfPlayers;
    cout << "How many players will be playing: " << endl;
    cin >> numberOfPlayers;
    playerList.resize(numberOfPlayers);
}

void Players::setPlayerNames()
{
    string name;
    for(int i = 0; i < playerList.size(); i++)
    {
        playerList[i] = new Player;
        cout << "Player " << i + 1 << " enter your name: " << endl;
        cin >> name;
        playerList[i]->name = name;
    }
}

std::vector<Player*> Players::getOtherPlayers(Player* player)
{
    std::vector<Player*> otherPlayers;
    for (auto currentPlayer : playerList)
    {
        if (player != currentPlayer)
        {
            otherPlayers.push_back(currentPlayer);
        }
    }
    return otherPlayers;
}

void Players::randomizePlayerOrder()
{
    for(int i = 0; i < playerList.size(); i++)
    {
        short playerIndex = rand() % playerList.size();
        if(playerIndex != i)
        {
            swap(playerList[playerIndex], playerList[i]);
        }
    }
}

void Players::displayPlayers()
{
    short playerNumber = 1;
    for(const Player* player : playerList)
    {
        cout << playerNumber << ": " << player->name << endl;
        playerNumber++;
    }
}
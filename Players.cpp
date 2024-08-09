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
    short numberOfPlayers = 4;
    cout << "How many players will be playing: " << endl;
    //cin >> numberOfPlayers; // Removed for testing
    playerList.resize(numberOfPlayers);
}

void Players::setPlayerNames()
{
    string names[4] = {"Zack", "Ethan", "Chase", "Tori"}; // Added for testing
    for(int i = 0; i < playerList.size(); i++)
    {
        playerList[i] = new Player;
        cout << "Player " << i + 1 << " enter your name: " << endl;
        //cin >> name; Removed for testing
        playerList[i]->name = names[i];
    }
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
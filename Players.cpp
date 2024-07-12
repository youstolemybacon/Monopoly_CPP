//
// Created by zacka on 7/10/2024.
//

#include "Players.h"

Board Player::board;

Players::Players()
{
    short numberOfPlayers = 2;
    cout << "How many players will be playing: " << endl;
    //cin >> numberOfPlayers;
    playerList.resize(numberOfPlayers);

    for(int i = 0; i < numberOfPlayers; i++)
    {
        playerList[i] = new Player;
        string name = "Zack" + i;
        cout << "Player " << i + 1 << " enter your name: " << endl;
        //cin >> name;
        playerList[i]->name = name;
        playerList[i]->roll(); // The player rolls here to avoid all players having same seed
    }

    cout << "Welcome " << playerList[0]->name;
    for(int i = 1; i < playerList.size() - 1; i++)
    {
        cout << ", " << playerList[i]->name;
    }
    cout << " and " << playerList[playerList.size() - 1]->name << " we hope you enjoy the game! Let us begin by rolling for the order of play!" << endl;

    bool ordered = false;

    for(short i = 0; i < playerList.size(); i++)
    {
        short largestIndex = 0; // Store Player with highest roll
        short largestRoll = 0; // Store the largest roll
        for(short j = i; j < playerList.size(); j++)
        {
            if(playerList[j]->getDice() > largestRoll)
            {
                largestRoll = playerList[j]->getDice();
                largestIndex = j;
            }
        }
        if(largestIndex != i)
        {
            swap(playerList[i], playerList[largestIndex]);
        }
    }

    for(Player* player : playerList)
    {
        cout << player->name << " you rolled " << player->getDice() << endl;
    }
}

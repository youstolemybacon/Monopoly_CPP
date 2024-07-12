#include <iostream>
#include "Player.h"
#include <variant>
#include "Board.h"

using namespace std;

void playerSetup(vector<Player*> &players);

int main() {
    vector<Player*> players;
    playerSetup(players);
    Board board;

    players[0]->buy(dynamic_cast<Property*>(board.getSpace(1)));
    players[0]->buy(dynamic_cast<Property*>(board.getSpace(0)));
    players[0]->buy(dynamic_cast<Railroad*>(board.getSpace(2)));
    dynamic_cast<Property*>(board.getSpace(1))->displayInfo();
    board.getOwnedProperties(players[0]);
    players[0]->printMoney();

    return 0;
}

void playerSetup(vector<Player*> &players)
{
    short numberOfPlayers = 2;
    cout << "How many players will be playing: " << endl;
    //cin >> numberOfPlayers;
    players.resize(numberOfPlayers);

    for(int i = 0; i < numberOfPlayers; i++)
    {
        players[i] = new Player;
        string name = "Zack" + i;
        cout << "Player " << i + 1 << " enter your name: " << endl;
        //cin >> name;
        players[i]->name = name;
        players[i]->roll(); // The player rolls here to avoid all players having same seed
    }

    cout << "Welcome " << players[0]->name;
    for(int i = 1; i < players.size() - 1; i++)
    {
            cout << ", " << players[i]->name;
    }
    cout << " and " << players[players.size() - 1]->name << " we hope you enjoy the game! Let us begin by rolling for the order of play!" << endl;

    bool ordered = false;

    for(short i = 0; i < players.size(); i++)
    {
        short largestIndex = 0; // Store Player with highest roll
        short largestRoll = 0; // Store the largest roll
        for(short j = i; j < players.size(); j++)
        {
            if(players[j]->getDice() > largestRoll)
            {
                largestRoll = players[j]->getDice();
                largestIndex = j;
            }
        }
        if(largestIndex != i)
        {
            swap(players[i], players[largestIndex]);
        }
    }

    for(Player* player : players)
    {
        cout << player->name << " you rolled " << player->getDice() << endl;
    }
}

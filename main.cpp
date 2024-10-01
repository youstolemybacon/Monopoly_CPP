#include "Player.h"
#include "Board.h"
#include "Chance.h"
#include "Dice.h"
#include "Gameplay.h"
#include "Players.h"

using namespace std;

class Gameplay;

int main() {
    srand(time(nullptr));
    Players players;

    Chance chance(42);

    dynamic_cast<Railroad*>(Player::playerBoard.getSpace(15))->buy(Players::playerList[1]);
    dynamic_cast<Utility*>(Player::playerBoard.getSpace(12))->buy(Players::playerList[1]);


    //chance.DELETE(players.playerList[0], 2);
    //chance.DELETE(players.playerList[0], 3);
    //chance.DELETE(players.playerList[0], 4);
    chance.DELETE(players.playerList[0], 5);
    chance.DELETE(players.playerList[0], 6);
    chance.DELETE(players.playerList[0], 7);
    chance.DELETE(players.playerList[0], 8);
    chance.DELETE(players.playerList[0], 9);
    chance.DELETE(players.playerList[0], 10);
    chance.DELETE(players.playerList[0], 11);
    chance.DELETE(players.playerList[0], 12);
    chance.DELETE(players.playerList[0], 13);
    chance.DELETE(players.playerList[0], 14);
    chance.DELETE(players.playerList[0], 15);




    //Players::playerList[1]->income(3000);
    //dynamic_cast<Property*>(Player::playerBoard.getSpace(1))->buy(Players::playerList[1]);
    //dynamic_cast<Property*>(Player::playerBoard.getSpace(3))->buy(Players::playerList[1]);
    //dynamic_cast<Railroad*>(Player::playerBoard.getSpace(5))->buy(Players::playerList[1]);
    //dynamic_cast<Railroad*>(Player::playerBoard.getSpace(35))->buy(Players::playerList[1]);
    //dynamic_cast<Utility*>(Player::playerBoard.getSpace(12))->buy(Players::playerList[1]);
    //dynamic_cast<Property*>(Player::playerBoard.getSpace(39))->buy(Players::playerList[0]);
    //dynamic_cast<Property*>(Player::playerBoard.getSpace(37))->buy(Players::playerList[0]);
    //
    //cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";


    while(true)
    {
        for (auto player : Players::playerList)
        {
            Gameplay::turn(player);
        }
    }

    return 0;
}
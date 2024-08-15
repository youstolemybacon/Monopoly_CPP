#include "Player.h"
#include "Board.h"
#include "Dice.h"
#include "Gameplay.h"

#include "Players.h"

using namespace std;

class Gameplay;

int main() {
    srand(time(nullptr));
    Players players;
    Gameplay game;
    Property boardwalk(50, 200, 600, 1400, 1700, 2000, 400, 39, "Boardwalk", 400);
    Utility electric(12, "Electric Company");
    boardwalk.displayInfo();
    electric.displayInfo();

    Players::playerList[1]->pay(3000);
    dynamic_cast<Property*>(Player::playerBoard.getSpace(1))->buy(Players::playerList[1]);
    dynamic_cast<Property*>(Player::playerBoard.getSpace(1))->buy(Players::playerList[1]);
    dynamic_cast<Property*>(Player::playerBoard.getSpace(3))->buy(Players::playerList[1]);
    dynamic_cast<Property*>(Player::playerBoard.getSpace(6))->buy(Players::playerList[1]);
    dynamic_cast<Railroad*>(Player::playerBoard.getSpace(5))->buy(Players::playerList[1]);
    dynamic_cast<Railroad*>(Player::playerBoard.getSpace(15))->buy(Players::playerList[1]);
    dynamic_cast<Railroad*>(Player::playerBoard.getSpace(25))->buy(Players::playerList[1]);
    dynamic_cast<Railroad*>(Player::playerBoard.getSpace(35))->buy(Players::playerList[1]);
    dynamic_cast<Utility*>(Player::playerBoard.getSpace(12))->buy(Players::playerList[1]);
    dynamic_cast<Utility*>(Player::playerBoard.getSpace(28))->buy(Players::playerList[1]);


    Players::playerList[0]->printSpaces();

    while(true)
    {
        game.turn(Players::playerList[0]);
    }

    return 0;
}
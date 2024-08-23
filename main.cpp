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

    Players::playerList[1]->income(3000);
    dynamic_cast<Property*>(Player::playerBoard.getSpace(1))->buy(Players::playerList[1]);
    dynamic_cast<Property*>(Player::playerBoard.getSpace(3))->buy(Players::playerList[1]);
    dynamic_cast<Property*>(Player::playerBoard.getSpace(6))->buy(Players::playerList[1]);
    dynamic_cast<Railroad*>(Player::playerBoard.getSpace(5))->buy(Players::playerList[1]);
    dynamic_cast<Railroad*>(Player::playerBoard.getSpace(15))->buy(Players::playerList[1]);
    dynamic_cast<Railroad*>(Player::playerBoard.getSpace(25))->buy(Players::playerList[1]);
    dynamic_cast<Railroad*>(Player::playerBoard.getSpace(35))->buy(Players::playerList[1]);
    dynamic_cast<Utility*>(Player::playerBoard.getSpace(12))->buy(Players::playerList[1]);
    dynamic_cast<Utility*>(Player::playerBoard.getSpace(28))->buy(Players::playerList[1]);
    dynamic_cast<Property*>(Player::playerBoard.getSpace(39))->buy(Players::playerList[1]);

    cout << "Monopoly: " << Board::monopolyCheck(Players::playerList[1], Property::PropertyGroup::BROWN) << endl;
    cout << "Rent: " << dynamic_cast<Property*>(Player::playerBoard.getSpace(1))->getRent() << endl;
    cout << "Monopoly: " << Board::monopolyCheck(Players::playerList[1], Property::PropertyGroup::BLUE) << endl;
    cout << "Rent: " << dynamic_cast<Property*>(Player::playerBoard.getSpace(39))->getRent() << endl;

    OwnableSpaces::printSpaces(Board::getOwnedSpaces(Players::playerList[0]));

    while(true)
    {
        game.turn(Players::playerList[0]);
    }

    return 0;
}
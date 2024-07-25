#include "Player.h"
#include "Board.h"
#include "Chance.h"
#include "CommunityChest.h"
#include "Dice.h"
#include "Gameplay.h"
#include "Go.h"
#include "GoToJail.h"
#include "IncomeTax.h"
#include "Jail.h"
#include "LuxuryTax.h"
#include "Players.h"

using namespace std;

class Gameplay;

int main() {
    srand(time(nullptr));
    Players players;

    Gameplay::getSpaceMenu(players.playerList[0], Player::board.getSpace(1));
    //players.playerList[0]->buy(dynamic_cast<Railroad*>(Player::board.getSpace(5)));
    //players.playerList[0]->buy(dynamic_cast<Railroad*>(Player::board.getSpace(15)));
    //cout << Player::board.getOwnedRailroads(players.playerList[0])[1]->getRent() << endl;
    //cout << Player::board.getOwnedRailroads(players.playerList[0])[0]->getRent() << endl;
    //dynamic_cast<Property*>(Player::board.getSpace(1))->displayInfo();
    //Player::board.getOwnedProperties(players.playerList[0]);
    //players.playerList[0]->printMoney();

    return 0;
}
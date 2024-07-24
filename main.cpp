#include "Player.h"
#include "Board.h"
#include "Chance.h"
#include "CommunityChest.h"
#include "Dice.h"
#include "Go.h"
#include "GoToJail.h"
#include "IncomeTax.h"
#include "Jail.h"
#include "LuxuryTax.h"
#include "Players.h"

using namespace std;

void getSpaceMenu(Player* player, Space* space)
{
    Space::SpaceType type = Space::getType(space);

    switch(type)
    {
    case Space::SpaceType::PROPERTY:
        dynamic_cast<Property*>(space)->spaceMenu(player);
        break;
    case Space::SpaceType::RAILROAD:
        dynamic_cast<Railroad*>(space)->spaceMenu(player);
        break;
    case Space::SpaceType::UTILITY:
        dynamic_cast<Utility*>(space)->spaceMenu(player);
        break;
    case Space::SpaceType::CHANCE:
        dynamic_cast<Chance*>(space)->spaceMenu(player);
        break;
    case Space::SpaceType::COMMUNITY_CHEST:
        dynamic_cast<CommunityChest*>(space)->spaceMenu(player);
        break;
    case Space::SpaceType::GO:
        dynamic_cast<Go*>(space)->spaceMenu(player);
        break;
    case Space::SpaceType::GO_TO_JAIL:
        dynamic_cast<GoToJail*>(space)->spaceMenu(player);
        break;
    case Space::SpaceType::JAIL:
        dynamic_cast<Jail*>(space)->spaceMenu(player);
        break;
    case Space::SpaceType::INCOME_TAX:
        dynamic_cast<IncomeTax*>(space)->spaceMenu(player);
        break;
    case Space::SpaceType::LUXURY_TAX:
        dynamic_cast<LuxuryTax*>(space)->spaceMenu(player);
        break;
    }
}

int main() {
    srand(time(nullptr));
    Players players;
    Dice dice;
    dice.rollDice();
    cout << dice.getRoll();
    getSpaceMenu(players.playerList[0], Player::board.getSpace(1));
    cout << "Rent is: " << dynamic_cast<Utility*>(Player::board.getSpace(12))->getRent() << endl;
    players.playerList[0]->buy(dynamic_cast<Property*>(Player::board.getSpace(1)));
    players.playerList[0]->buy(dynamic_cast<Property*>(Player::board.getSpace(0)));
    players.playerList[0]->buy(dynamic_cast<Railroad*>(Player::board.getSpace(2)));
    players.playerList[0]->buy(dynamic_cast<Railroad*>(Player::board.getSpace(9)));
    cout << Player::board.getOwnedRailroads(players.playerList[0])[1]->getRent() << endl;
    cout << Player::board.getOwnedRailroads(players.playerList[0])[0]->getRent() << endl;
    dynamic_cast<Property*>(Player::board.getSpace(1))->displayInfo();
    Player::board.getOwnedProperties(players.playerList[0]);
    players.playerList[0]->printMoney();

    return 0;
}
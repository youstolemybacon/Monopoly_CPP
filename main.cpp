#include "Player.h"
#include "Board.h"
#include "Chance.h"
#include "CommunityChest.h"
#include "Dice.h"
#include "Gameplay.h"
#include "Players.h"

using namespace std;

class Gameplay;


int main() {
    srand(time(nullptr));
    Players players;

    //CommunityChest communityChest(42);
    //
    //dynamic_cast<Railroad*>(Player::playerBoard.getSpace(15))->buy(Players::playerList[1]);
    //dynamic_cast<Utility*>(Player::playerBoard.getSpace(12))->buy(Players::playerList[1]);
    //
    //dynamic_cast<Property*>(Player::playerBoard.getSpace(39))->buy(Players::playerList[0]);
    //dynamic_cast<Property*>(Player::playerBoard.getSpace(37))->buy(Players::playerList[0]);



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
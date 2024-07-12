#include "Player.h"
#include "Board.h"
#include "Players.h"

using namespace std;


int main() {
    Players players;
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
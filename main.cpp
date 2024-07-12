#include "Player.h"
#include "Board.h"
#include "Players.h"

using namespace std;


int main() {
    Players players;
    Board board;

    players.playerList[0]->buy(dynamic_cast<Property*>(board.getSpace(1)));
    players.playerList[0]->buy(dynamic_cast<Property*>(board.getSpace(0)));
    players.playerList[0]->buy(dynamic_cast<Railroad*>(board.getSpace(2)));
    dynamic_cast<Property*>(board.getSpace(1))->displayInfo();
    board.getOwnedProperties(players.playerList[0]);
    players.playerList[0]->printMoney();

    return 0;
}
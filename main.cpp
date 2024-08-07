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

    Gameplay::getSpaceMenu(Players::playerList[0], Player::playerBoard.getSpace(1));
    Gameplay::getSpaceMenu(Players::playerList[1], Player::playerBoard.getSpace(5));

    return 0;
}
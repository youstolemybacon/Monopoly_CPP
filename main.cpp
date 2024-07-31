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

    Gameplay::getSpaceMenu(Players::playerList[0], Player::board.getSpace(1));

    return 0;
}
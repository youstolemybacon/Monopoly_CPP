//
// Created by Victoria Hendren on 6/15/24.
//

#ifndef CHANCE_H
#define CHANCE_H

#include <vector>
#include "Deck.h"
#include "Space.h"

using namespace std;

class Chance : public Space {
private:
public:
    Chance(short spaceIndex);
    static Deck chanceDeck;
    void spaceMenu(Player* player) override;
    void getCardEffect(Player* player);
    bool passGoCheck(int currentSpace, int NewSpace);
    void payMenu(Player* player, short cost);
    void payMenu(Player* payer, Player* receiver, short cost);

    // Card effects
    void advanceToBoardwalk(Player* player);
    void advanceToGo(Player* player);
    void advanceToIllinoisAve(Player* player);
    void advnaceToStCharlesPlace(Player* player);
    void advanceToNearestRailroad(Player* player);
    void advanceToNearestUtility(Player* player);
    void bankPaysDividend(Player* player);
    void getOutOfJail(Player* player);
    void goBackThreeSpaces(Player* player);
    void goToJail(Player* player);
    void generalRepairs(Player* player);
    void speedingFine(Player* player);
    void tripToReadingRailroad(Player* player);
    void electedChairman(Player* player);
    void buildingLoanMatures(Player* player);


    void DELETE(Player* player, short card);
};

#endif //CHANCE_H

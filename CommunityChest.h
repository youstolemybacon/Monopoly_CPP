//
// Created by zacka on 7/15/2024.
//

#ifndef COMMUNITYCHEST_H
#define COMMUNITYCHEST_H
#include "Deck.h"
#include "Space.h"


class CommunityChest : public Space {
    private:
    public:
    CommunityChest(short spaceIndex);
    static Deck communityChestDeck;
    void spaceMenu(Player* player) override;
    void getCardEffect(Player* player);
    void payMenu(Player* player, short cost);
    void payMenu(Player* payer, Player* receiver, short cost);

    // Card effects
    void advanceToGo(Player* player);
    void bankError(Player* player);
    void doctorFee(Player* player);
    void sellStocks(Player* player);
    void getOutOfJailFree(Player* player);
    void goToJail(Player* player);
    void holidayFund(Player* player);
    void taxRefund(Player* player);
    void birthday(Player* player);
    void lifeInsurance(Player* player);
    void hospitalFee(Player* player);
    void schoolFee(Player* player);
    void consultancyFee(Player* player);
    void streetRepair(Player* player);
    void beautyConstest(Player* player);
    void inheritance(Player* player);
};



#endif //COMMUNITYCHEST_H

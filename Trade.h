//
// Created by zacka on 10/8/2024.
//

#ifndef TRADE_H
#define TRADE_H

#include <vector>

class Player;
class OwnableSpaces;

class Trade {
public:
    Trade(Player* tradeInitiator);

    void trade();
    Player* playerSelection();
    void ownedMenu();
    void previewTrade();
    void ownedPropertiesSelection();
    int moneySelection(Player* player = nullptr);

    Player* tradeInitiator = nullptr;
    std::vector<OwnableSpaces*> initiatorOwnedOffer{};
    int initiatorMoney = 0;

    Player* tradeReceiver = nullptr;
    std::vector<OwnableSpaces*> receiverOwnedOffer{};
    int receiverMoney = 0;


};



#endif //TRADE_H

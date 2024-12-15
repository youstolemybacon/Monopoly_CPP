//
// Created by zacka on 10/8/2024.
//

#ifndef TRADE_H
#define TRADE_H

#include <map>
#include <vector>

class Player;
class OwnableSpaces;

class Trade {
public:
    Trade(Player* tradeInitiator);

    // Player specific trade data
    struct TradeData
    {
        std::vector<OwnableSpaces*> assetOffer;
        int money = 0;
    };

    void trade();
    Player* playerSelection();
    void ownedPropertiesSelection();
    void moneySelection(Player* player = nullptr);
    bool previewTrade();
    bool signature(Player* player);
    void exchangeAssets();

private:
    Player* tradeInitiator = nullptr;
    Player* tradeReceiver = nullptr;
    std::map<Player*, TradeData> tradeData;
};

#endif //TRADE_H

//
// Created by zacka on 7/12/2024.
//

#ifndef OWNABLESPACES_H
#define OWNABLESPACES_H

#include "Space.h"
#include <vector>

class Players;
class Player;
class Space;


class OwnableSpaces : public Space {
private:
    short price;
    Player* owner = nullptr;
    enum class OwnedMenuOptions
    {
        DEFAULT = 0,
        PAY,
        MORTGAGE,
        END_TURN
    };
    enum class UnownedMenuOptions
    {
        DEFAULT = 0,
        BUY,
        AUCTION,
        MORTGAGE,
        INFO,
        END_TURN
    };
public:
    OwnableSpaces(short price, short spaceIndex, string spaceName);
    void auction(vector<Player*> players);
    short getPrice();
    bool isOwned();
    void changeOwner(Player* newOwner);
    Player* getOwner() const;
    virtual short getRent() = 0;
    virtual void displayInfo() = 0;
    virtual bool buy(Player* buyer, short price);
    virtual bool buy(Player* buyer);

    void spaceMenu(Player* currentPlayer) override;
    void unownedMenu(Player* currentPlayer);
    void ownedMenu(Player* currentPlayer, Player* owner);
};

#endif //OWNABLESPACES_H

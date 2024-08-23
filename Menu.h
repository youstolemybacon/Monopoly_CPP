//
// Created by zacka on 8/22/2024.
//

#ifndef MENU_H
#define MENU_H

class OwnableSpaces;
class Player;

class Menu {
private:
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
        OWNED,
        END_TURN
    };

public:
    void unownableSpaceMenu(Player* currentPlayer);
    void ownableSpaceMenu(Player* currentPlayer, OwnableSpaces* ownableSpace);

    void unownedMenu(Player* currentPlayer, OwnableSpaces* ownableSpace);
    void ownedMenu(Player* currentPlayer, Player* owner, OwnableSpaces* ownableSpace);

};



#endif //MENU_H

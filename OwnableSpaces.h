//
// Created by zacka on 7/12/2024.
//

#ifndef OWNABLESPACES_H
#define OWNABLESPACES_H

#include "Players.h"
#include "Space.h"


class OwnableSpaces : public Space {
private:
    short price;
    Player* owner = nullptr;
public:
    OwnableSpaces(short price, short spaceIndex, string spaceName);
    void auction(Players* players);
    short getPrice();
    bool isOwned();
    void changeOwner(Player* newOwner);
    Player* getOwner() const;
    virtual short getRent() = 0;
    virtual void displayInfo() = 0;
    virtual void buy(Player* buyer) = 0;
    void spaceMenu(Player* player) override;
};



#endif //OWNABLESPACES_H

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

};



#endif //COMMUNITYCHEST_H

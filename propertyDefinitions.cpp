//
// Created by Zack on 5/2/2024.
//

#include "Property.h"
#include "Deck.h"


short rent[6] = {50, 200, 600, 1400, 1700, 2000};
extern Property boardwalk{"Boardwalk", rent, 200};

short mediterraneanRent[6] = {2, 10, 30, 90, 160, 250};
extern Property mediterraneanAvenue{"Mediterranean Avenue", mediterraneanRent, 50};

extern Deck chanceDeck(Deck::DeckType::chance);

extern Deck communityChestDeck(Deck::DeckType::communityChest);
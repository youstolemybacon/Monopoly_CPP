//
// Created by Zack on 4/28/2024.
//

#include "Deck.h"

void Deck::shuffle() {
    int swapIndex;
    Cards temp;
    srand(time(nullptr)); // Generate random seed for rand() function

    while(!discardPile.empty()) {
        swapIndex = rand() % discardPile.size();
        temp = discardPile[swapIndex];
        discardPile.erase(discardPile.begin() + swapIndex);
        drawPile.push_back(temp);
    }
}

Deck::Cards Deck::draw() {
    // Check if deck is empty.
    if(drawPile.empty()) {
        shuffle();
    }
    srand(time(nullptr)); // Generate random seed for rand() function

    Cards cardDrawn = drawPile.back();
    drawPile.pop_back();

    return cardDrawn;
}
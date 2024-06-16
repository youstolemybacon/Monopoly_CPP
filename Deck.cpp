//
// Created by Zack on 4/28/2024.
//

#include "Deck.h"

void Deck::shuffle() {
    int swapIndex;
    int temp;
    srand(time(0)); // Generate random seed for rand() function

    while(drawPile.size() < 16) {
        swapIndex = rand() % discardPile.size();
        temp = discardPile[swapIndex];
        drawPile.push_back(temp);
        discardPile.erase(discardPile.begin() + swapIndex);
    }
}

int Deck::draw() {
    // Check if deck is empty.
    if(drawPile.empty()) {
        shuffle();
    }
    srand(time(0)); // Generate random seed for rand() function

    int cardDrawn = drawPile.back();
    discardPile.push_back(cardDrawn);
    drawPile.pop_back();

    return cardDrawn;
}
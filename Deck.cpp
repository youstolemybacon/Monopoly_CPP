//
// Created by Zack on 4/28/2024.
//

#include "Deck.h"

void Deck::shuffle() {
    switch(deckType) {
        case DeckType::communityChest:
            deck = communityChestDeck;
            break;
        case DeckType::chance:
            deck = chanceDeck;
            break;
        default:
        cerr << "deckType: Invalid value" << endl;
    }

    int swapIndex;
    cardList temp;
    srand(static_cast<unsigned int>(time(nullptr)));
    for(cardList & i : deck) {
        swapIndex = rand() % deck.size();
        temp = deck[swapIndex];
        deck[swapIndex] = i;
        i = temp;
    }
}

Deck::cardList Deck::draw() {
    // Check if deck is empty.
    if(deck.empty()) {
        shuffle();
    }

    // Get the current time point with high precision
    auto currentTime = std::chrono::high_resolution_clock::now();

    // Convert the time point to microseconds
    auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(currentTime.time_since_epoch()).count();

    // Seed the random number generator with the current time in microseconds
    std::mt19937 generator(static_cast<unsigned int>(microseconds));

    // Generate a random number
    std::uniform_int_distribution<int> distribution(0, deck.size() - 1); // Example distribution

    int cardIndex = distribution(generator);
    cardList card = deck[cardIndex];
    deck.erase(deck.begin() + cardIndex);

    displayCard(card, false);

    return card;
}

Deck::Deck(DeckType deckType) {
    this->deckType = deckType;
}

void Deck::displayCard(Deck::cardList card, bool info) {
    switch (card) {
        case cardList::AdvanceToGo:
            cout << "Advance to Go" << endl;
            break;
        case cardList::BankError:
            cout << "Bank Error" << endl;
            break;
        case cardList::DoctorsFee:
            cout << "Doctor's Fee" << endl;
            break;
        case cardList::SellStock:
            cout << "Sell Stock" << endl;
            break;
        case cardList::GetOutOfJail:
            cout << "Get Out of Jail" << endl;
            break;
        case cardList::GoToJail:
            cout << "Go to Jail" << endl;
            break;
        case cardList::HolidayFund:
            cout << "Holiday Fund" << endl;
            break;
        case cardList::IncomeTaxRefund:
            cout << "Income Tax Refund" << endl;
            break;
        case cardList::Birthday:
            cout << "Birthday" << endl;
            break;
        case cardList::LifeInsurance:
            cout << "Life Insurance" << endl;
            break;
        case cardList::HospitalFees:
            cout << "Hospital Fees" << endl;
            break;
        case cardList::SchoolFees:
            cout << "School Fees" << endl;
            break;
        case cardList::ReceiveConsultancyFee:
            cout << "Receive Consultancy Fee" << endl;
            break;
        case cardList::StreetRepair:
            cout << "Street Repair" << endl;
            break;
        case cardList::SecondPlaceBeautyContest:
            cout << "Second Place Beauty Contest" << endl;
            break;
        case cardList::Inherit:
            cout << "Inherit" << endl;
            break;
        case cardList::AdvanceToBoardwalk:
            cout << "Advance to Boardwalk" << endl;
            break;
        case cardList::AdvanceToIllinoisAve:
            cout << "Advance to Illinois Avenue" << endl;
            break;
        case cardList::AdvanceToStCharlesPlace:
            cout << "Advance to St. Charles Place" << endl;
            break;
        case cardList::AdvanceToRailroad:
            cout << "Advance to Railroad" << endl;
            break;
        case cardList::AdvanceToUtility:
            cout << "Advance to Utility" << endl;
            break;
        case cardList::BankPaysDividend:
            cout << "Bank Pays Dividend" << endl;
            break;
        case cardList::GoBackThree:
            cout << "Go Back Three" << endl;
            break;
        case cardList::GeneralRepairs:
            cout << "General Repairs" << endl;
            break;
        case cardList::SpeedingFine:
            cout << "Speeding Fine" << endl;
            break;
        case cardList::AdvanceToReadingRailroad:
            cout << "Advance to Reading Railroad" << endl;
            break;
        case cardList::ElectedChairman:
            cout << "Elected Chairman" << endl;
            break;
        case cardList::BuildingLoanMatures:
            cout << "Building Loan Matures" << endl;
            break;
        default:
            cout << "Unknown card" << endl;
            break;
    }
}
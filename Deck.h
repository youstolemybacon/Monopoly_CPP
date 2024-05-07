//
// Created by Zack on 4/28/2024.
//

#include <iostream>
#include <random>
#include <chrono>
#include <vector>

#ifndef MONOPOLY_SIM_COMMUNITYCHEST_H
#define MONOPOLY_SIM_COMMUNITYCHEST_H

using namespace std;

class Deck {
public:
    enum cardList {
        AdvanceToGo,
        BankError,
        DoctorsFee,
        SellStock,
        GetOutOfJail,
        GoToJail,
        HolidayFund,
        IncomeTaxRefund,
        Birthday,
        LifeInsurance,
        HospitalFees,
        SchoolFees,
        ReceiveConsultancyFee,
        StreetRepair,
        SecondPlaceBeautyContest,
        Inherit,
        AdvanceToBoardwalk,
        AdvanceToIllinoisAve,
        AdvanceToStCharlesPlace,
        AdvanceToRailroad,
        AdvanceToUtility,
        BankPaysDividend,
        GoBackThree,
        GeneralRepairs,
        SpeedingFine,
        AdvanceToReadingRailroad,
        ElectedChairman,
        BuildingLoanMatures
    };
private:

    vector<cardList> const chanceDeck = {
            AdvanceToBoardwalk,
            AdvanceToGo,
            AdvanceToIllinoisAve,
            AdvanceToStCharlesPlace,
            AdvanceToRailroad,
            AdvanceToRailroad,
            AdvanceToUtility,
            BankPaysDividend,
            GetOutOfJail,
            GoBackThree,
            GoToJail,
            GeneralRepairs,
            SpeedingFine,
            AdvanceToReadingRailroad,
            ElectedChairman,
            BuildingLoanMatures
    };

    vector<cardList> const communityChestDeck = {
            AdvanceToGo,
            BankError,
            DoctorsFee,
            SellStock,
            GetOutOfJail,
            GoToJail,
            HolidayFund,
            IncomeTaxRefund,
            Birthday,
            LifeInsurance,
            HospitalFees,
            SchoolFees,
            ReceiveConsultancyFee,
            StreetRepair,
            SecondPlaceBeautyContest,
            Inherit,
            };

    vector<cardList> deck;

public:
    enum class DeckType {communityChest, chance};
    Deck::DeckType deckType;

    Deck(DeckType type);
    void shuffle();
    cardList draw();
    void displayCard(cardList card, bool info);
};


#endif //MONOPOLY_SIM_COMMUNITYCHEST_H

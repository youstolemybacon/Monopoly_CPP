//
// Created by Victoria Hendren on 6/15/24.
//

#ifndef CHANCE_H
#define CHANCE_H

#include <vector>
#include "Deck.h"

using namespace std;

class Chance {
private:
    enum CardList {
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

    vector<CardList> ChadrawPile;
    vector<CardList> chanceDiscard {
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
public:

};



#endif //CHANCE_H

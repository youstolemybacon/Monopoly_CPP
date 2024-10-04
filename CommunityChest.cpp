//
// Created by zacka on 7/15/2024.
//

#include "CommunityChest.h"
#include "Board.h"
#include "Gameplay.h"
#include "Players.h"

Deck CommunityChest::communityChestDeck = Deck();

CommunityChest::CommunityChest(const short spaceIndex) : Space(spaceIndex, "Community Chest") {}

void CommunityChest::spaceMenu(Player* player)
{
    cout << "Community Chest" << endl;
    getCardEffect(player);
};

void CommunityChest::payMenu(Player* player, short cost)
{
    enum OwnedMenuOptions
    {
        DEFAULT = 0,
        PAY,
        OWNED,
        END_TURN
    };

    short userInput = 0;
    OwnedMenuOptions menuSelection = DEFAULT;

    while(menuSelection != END_TURN)
    {
        cout << "The following actions are available: \n"
                "   [1] Pay\n"
                "   [2] Owned\n";
        cin >> userInput;
        cin.clear();
        menuSelection = static_cast<OwnedMenuOptions>(userInput);

        switch(menuSelection)
        {
        case PAY:
            if (player(cost))
            {
                menuSelection = END_TURN;
            }
            break;
        case OWNED:
            Board::spaceInfoMenu(player);
            break;
        default:
            menuSelection = DEFAULT;
            cerr << "Invalid input!" << endl;
        }
    }
}

void CommunityChest::payMenu(Player* payer, Player* receiver, short cost)
{
    enum OwnedMenuOptions
    {
        DEFAULT = 0,
        PAY,
        OWNED,
        END_TURN
    };

    short userInput = 0;
    OwnedMenuOptions menuSelection = DEFAULT;

    while(menuSelection != END_TURN)
    {
        cout << "The following actions are available: \n"
                "   [1] Pay\n"
                "   [2] Owned\n";
        cin >> userInput;
        cin.clear();
        menuSelection = static_cast<OwnedMenuOptions>(userInput);

        switch(menuSelection)
        {
        case PAY:
            if (payer->pay(cost, receiver))
            {
                menuSelection = END_TURN;
            }
            break;
        case OWNED:
            Board::spaceInfoMenu(payer);
            break;
        default:
            menuSelection = DEFAULT;
            cerr << "Invalid input!" << endl;
        }
    }
}

void CommunityChest::getCardEffect(Player* player)
{
    int card = communityChestDeck.draw();

    switch (card)
    {
    case 0:
        advanceToGo(player);
        break;
    case 1:
        bankError(player);
        break;
    case 2:
        doctorFee(player);
        break;
    case 3:
        sellStocks(player);
        break;
    case 4:
        getOutOfJailFree(player);
        break;
    case 5:
        goToJail(player);
        break;
    case 6:
        holidayFund(player);
        break;
    case 7:
        taxRefund(player);
        break;
    case 8:
        birthday(player);
        break;
    case 9:
        lifeInsurance(player);
        break;
    case 10:
        hospitalFee(player);
        break;
    case 11:
        schoolFee(player);
        break;
    case 12:
        consultancyFee(player);
        break;
    case 13:
        streetRepair(player);
        break;
    case 14:
        beautyConstest(player);
        break;
    case 15:
        inheritance(player);
        break;
    default:
        cerr << "Invalid Chance card drawn. \n";
    }
}

void CommunityChest::advanceToGo(Player* player)
{
    cout << "Advance to Go (Collect $200). \n\n";
    player->setSpace(0);
    Gameplay::spaceMenu(player);
}

void CommunityChest::bankError(Player* player)
{
    cout << "Bank error in your favor (Collect $200). \n";
    player->income(200);
}

void CommunityChest::doctorFee(Player* player)
{
    cout << "Doctor's fee (Pay $50). \n";
    payMenu(player, 50);
}

void CommunityChest::sellStocks(Player* player)
{
    cout << "Sell stocks (Collect $50). \n";
    player->income(50);
}

void CommunityChest::getOutOfJailFree(Player* player)
{
    cout << "Get out of Jail Free. \n";

    short cards = player->getGetOutOfJailFree();
    cards++;
    player->setGetOutOfJailFree(cards);
}

void CommunityChest::goToJail(Player* player)
{
    cout << "Go to Jail. Go directly to jail, do not pass Go, do not collet $200. \n";

    // Set space to go to jail
    player->setSpace(30);

    Gameplay::spaceMenu(player);
}

void CommunityChest::holidayFund(Player* player)
{
    cout << "Holiday fund matures (Collect $100). \n";

    player->income(100);
}

void CommunityChest::taxRefund(Player* player)
{
    cout << "Income tax refund (Collect $20). \n";

    player->income(20);
}

void CommunityChest::birthday(Player* player)
{
    cout << "It is your birthday (Collect $10 from each player). \n\n";
    for (auto selectedPlayer : Players::playerList)
    {
        if (player != selectedPlayer)
        {
            selectedPlayer->printPlayerInfo();
            payMenu(selectedPlayer, player, 10);
        }
    }
}

void CommunityChest::lifeInsurance(Player* player)
{
    cout << "Life insurance matures (Collect $100). \n";

    player->income(100);
}

void CommunityChest::hospitalFee(Player* player)
{
    cout << "Pay hospital fees (Pay $100) \n";

    payMenu(player, 100);
}

void CommunityChest::schoolFee(Player* player)
{
    cout << "Pay school fees (Pay $50). \n";
    payMenu(player, 50);
}

void CommunityChest::consultancyFee(Player* player)
{
    cout << "Receive $25 consultancy fee";

    player->income(25);
}

void CommunityChest::streetRepair(Player* player)
{
    auto ownedProperties = Board::getOwnedProperties(player);
    short houses = 0;
    short hotels = 0;

    cout << "You are assessed for street repair. $40 per house. $115 per hotel. \n\n";

    for (auto property : ownedProperties)
    {
        // If it is a hotel set it equal to 4 houses since hotels are only $100 instead of $125
        if (property->getHouses() == 5)
        {
            hotels += 1;
        }
        else
        {
            houses += property->getHouses();
        }
    }

    // Set repair costs
    short houseRepairs = houses * 40;
    short hotelRepairs = hotels * 115;
    if (houses > 0)
    {
        cout << "HOUSES: " << houses << "\n "
                "   " << houses << " x 40 = $" << houseRepairs << "\n";
    }
    if (hotels > 0)
    {
        cout << "HOTELS: " << hotels << "\n"
                "   " << hotels << " x 115 = $" << hotelRepairs << "\n";
    }

    // Set total repair cost
    short totalRepairs = houseRepairs + hotelRepairs;
    if (houses > 0 && hotels > 0)
    {
        cout << "TOTAL: \n"
                "   $" << houseRepairs << " x $" << hotelRepairs << " = $" << totalRepairs << "\n";
    }
    else if (houses == 0 && hotels == 0)
    {
        cout << "You do not own any houses or hotels. You owe nothing for repairs. \n";
        return;
    }
    payMenu(player, totalRepairs);
}

void CommunityChest::beautyConstest(Player* player)
{
    cout << "You have won second prize in a beauty contest. Collect $10 \n";

    player->income(10);
}

void CommunityChest::inheritance(Player* player)
{
    cout << "You inherit $100 \n";

    player->income(100);
}
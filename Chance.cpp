//
// Created by Victoria Hendren on 6/15/24.
//

#include "Chance.h"
#include "Board.h"
#include "Gameplay.h"
#include "Players.h"

Deck Chance::chanceDeck = Deck();

Chance::Chance(const short spaceIndex) : Space(spaceIndex, "Chance") {}

void Chance::spaceMenu(Player* player)
{
    cout << "You landed on " << getSpaceName() << ". \n";
    getCardEffect(player);
}

void Chance::payMenu(Player* player, short cost)
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
            if (player->pay(cost))
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

void Chance::payMenu(Player* payer, Player* receiver, short cost)
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

void Chance::getCardEffect(Player* player)
{
    int card = chanceDeck.draw();

    switch (card)
    {
    case 0:
        advanceToBoardwalk(player);
        break;
    case 1:
        advanceToGo(player);
        break;
    case 2:
        advanceToIllinoisAve(player);
        break;
    case 3:
        advnaceToStCharlesPlace(player);
        break;
    case 4:
    case 5:
        advanceToNearestRailroad(player);
        break;
    case 6:
        advanceToNearestUtility(player);
        break;
    case 7:
        bankPaysDividend(player);
        break;
    case 8:
        getOutOfJail(player);
        break;
    case 9:
        goBackThreeSpaces(player);
        break;
    case 10:
        goToJail(player);
        break;
    case 11:
        generalRepairs(player);
        break;
    case 12:
        speedingFine(player);
        break;
    case 13:
        tripToReadingRailroad(player);
        break;
    case 14:
        electedChairman(player);
        break;
    case 15:
        buildingLoanMatures(player);
        break;
    default:
        cerr << "Invalid Chance card drawn. \n";
    }
}

void Chance::passGoCheck(Player* player, int newSpace)
{
    if (player->getSpaceIndex() > newSpace)
    {
        Board::getSpace(0)->spaceMenu(player); // Calling passing go menu
    }
}

void Chance::advanceToBoardwalk(Player* player)
{
    cout << "Advance to Boardwalk. \n\n";
    player->setSpace(39);
    Gameplay::spaceMenu(player);
}

void Chance::advanceToGo(Player* player)
{
    cout << "Advance to Go (Collect $200). \n\n";
    player->setSpace(0);
    Gameplay::spaceMenu(player);
}

void Chance::advanceToIllinoisAve(Player* player)
{
    cout << "Advance to Illinois Avenue. If you pass Go, collect $200. \n\n";

    passGoCheck(player, 24);

    player->setSpace(24);
    Gameplay::spaceMenu(player);
}

void Chance::advnaceToStCharlesPlace(Player* player)
{
    cout << "Advance to St. Charles Place. If you pass Go, collect $200. \n\n";
    passGoCheck(player, 11);
    player->setSpace(11);
    Gameplay::spaceMenu(player);
}

void Chance::advanceToNearestRailroad(Player* player)
{
    cout << "Advance to the nearest Railroad. If unowned, you may buy it from the Bank. If owned, pay ownerr twice the rental to which they are otherwise entitled. \n\n";
    int currentSpace = player->getSpaceIndex();
    int newSpace;

    // Set modifier so railroad is double
    player->setChanceModifier(true);

    // Reading Railroad
    if (currentSpace >= 35 || currentSpace < 5)
    {
        newSpace = 5;
    }
    // Short Line
    else if (currentSpace >= 25)
    {
        newSpace = 35;
    }
    // B. &. O. Railroad
    else if (currentSpace >= 15)
    {
        newSpace = 25;
    }
    // Pennsylvania Railroad
    else
    {
        newSpace = 15;
    }

    passGoCheck(player, newSpace);

    player->setSpace(newSpace);
    Gameplay::spaceMenu(player);

    player->setChanceModifier(false);
}

void Chance::advanceToNearestUtility(Player* player)
{
    cout << "Advance token to nearest Utility. If unowned, you may buy it from the Bank. \n"
            "If owned, throw dice and pay owner a total ten times amount thrown. \n\n";
    int currentSpace = player->getSpaceIndex();
    int newSpace;

    // Set modifier so utility is x10
    player->setChanceModifier(true);

    // Electric Company
    if (currentSpace >= 28 || currentSpace < 12)
    {
        newSpace = 12;
    }
    // Water Works
    else
    {
        player->setSpace(28);
        newSpace = 28;
    }

    passGoCheck(player, newSpace);

    Gameplay::spaceMenu(player);

    // Turn off modifier
    player->setChanceModifier(false);
}

void Chance::bankPaysDividend(Player* player)
{
    cout << "Bank pays you dividend of $50. \n\n";

    player->income(50);
}

void Chance::getOutOfJail(Player* player)
{
    cout << "Get Out of Jail Free. \n\n";

    short cards = player->getGetOutOfJailFree();
    cards++;
    player->setGetOutOfJailFree(cards);
}

void Chance::goBackThreeSpaces(Player* player)
{
    cout << "Go Back 3 Spaces. \n\n";

    int space = player->getSpaceIndex();
    space = space - 3;

    // Ensure it is not negative
    if (space < 0)
    {
        space += 40;
    }
    player->setSpace(space);

    // Get the new spaces menu
    Gameplay::spaceMenu(player);
}

void Chance::goToJail(Player* player)
{
    cout << "Go to Jail. Go directly to jail, do not pass Go, do not collet $200";

    // Set space to go to jail
    player->setSpace(30);

    Gameplay::spaceMenu(player);
}

void Chance::generalRepairs(Player* player)
{
    auto ownedProperties = Board::getOwnedProperties(player);
    short houses = 0;
    short hotels = 0;

    cout << "Make general repairs on all your property. For each house pay $25. For each hotel pay $100. \n\n";

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
    short houseRepairs = houses * 25;
    short hotelRepairs = hotels * 100;
    if (houses > 0)
    {
        cout << "HOUSES: " << houses << "\n "
                "   " << houses << " x $25 = $" << houseRepairs << "\n";
    }
    if (hotels > 0)
    {
        cout << "HOTELS: " << hotels << "\n"
                "   " << hotels << " x $100 = $" << hotelRepairs << "\n";
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

void Chance::speedingFine(Player* player)
{
    cout << "Speeding fine $15. \n";

    // Pay speeding fine
    payMenu(player, 15);
}

void Chance::tripToReadingRailroad(Player* player)
{
    cout << "Take a trip to Reading Railroad. If you pass Go, collect $200. \n\n";

    passGoCheck(player, 5);

    player->setSpace(5);
    Gameplay::spaceMenu(player);
}

void Chance::electedChairman(Player* player)
{
    cout << "You have been elected Chairman of the Board. Pay each player $50. \n\n";
    for (auto selectedPlayer : Players::getOtherPlayers(player))
    {
        payMenu(player, selectedPlayer, 50);
    }
}

void Chance::buildingLoanMatures(Player* player)
{
    cout << "Your building loan matures. Collect $150 \n\n";
    player->income(150);
}
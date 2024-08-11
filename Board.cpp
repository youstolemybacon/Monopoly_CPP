//
// Created by zacka on 7/4/2024.
//

#include "Board.h"
#include "Chance.h"
#include "CommunityChest.h"
#include "GoToJail.h"
#include "Jail.h"
#include "LuxuryTax.h"
#include "Go.h"

vector<Space*> Board::board;

Board::Board()
{
    board.push_back(new Go());
    board.push_back(new Property(2,10,30,90,160,250,50,1,"Mediterranean Avenue", 60));
    board.push_back(new CommunityChest(2));
    board.push_back(new Property(4, 20, 60, 180, 320, 450, 50, 3, "Baltic Avenue", 60));
    board.push_back(new LuxuryTax());
    board.push_back(new Railroad(5, "Reading Railroad"));
    board.push_back(new Property(6, 30, 90, 270, 400, 550, 50, 6, "Oriental Avenue", 100));
    board.push_back(new Chance(7));
    board.push_back(new Property(6, 30, 90, 270, 400, 550, 50, 8, "Vermont Avenue", 100));
    board.push_back(new Property(8, 40, 100, 300, 450, 600, 50, 9, "Connecticut Avenue", 120));
    board.push_back(new Jail());
    board.push_back(new Property(10, 50, 150, 450, 625, 750, 100, 11, "St. Charles Place", 70));
    board.push_back(new Utility(12, "Electric Company"));
    board.push_back(new Property(12, 60, 180, 500, 700, 900, 100, 13, "States Avenue", 70));
    board.push_back(new Property(14, 70, 200, 550, 750, 950, 100, 14, "Virginia Avenue", 80));
    board.push_back(new Railroad(15, "Pennsylvania Railroad"));
    board.push_back(new Property(14, 70, 200, 550, 750, 950, 100, 16, "St. James Place", 90));
    board.push_back(new CommunityChest(17));
    board.push_back(new Property(16, 80, 220, 600, 800, 1000, 100, 18, "Tennessee Avenue", 90));
    board.push_back(new Property(18, 90, 250, 700, 875, 1050, 100, 19, "New York Avenue", 100));
    board.push_back(new Space(20, "Free Parking"));
    board.push_back(new Property(18, 90, 250, 700, 875, 1050, 220, 21, "Kentucky Avenue", 110));
    board.push_back(new Chance(22));
    board.push_back(new Property(20, 100, 300, 750, 925, 1100, 220, 23, "Indiana Avenue", 110));
    board.push_back(new Property(22, 110, 330, 800, 975, 1150, 240, 24, "Illinois Avenue", 120));
    board.push_back(new Railroad(25, "B. & O. Railroad"));
    board.push_back(new Property(22, 110, 330, 800, 975, 1150, 260, 26, "Atlantic Avenue", 130));
    board.push_back(new Property(24, 120, 360, 850, 1025, 1200, 260, 27, "Ventnor Avenue", 130));
    board.push_back(new Utility(28, "Water Works"));
    board.push_back(new Property(24, 120, 360, 850, 1025, 1200, 280, 29, "Marvin Gardens", 140));
    board.push_back(new GoToJail());
    board.push_back(new Property(26, 130, 390, 900, 1100, 1275, 300, 31, "Pacific Avenue", 150));
    board.push_back(new Property(26, 130, 390, 900, 1100, 1275, 300, 32, "North Carolina Avenue", 150));
    board.push_back(new CommunityChest(33));
    board.push_back(new Property(28, 150, 450, 1000, 1200, 1400, 320, 34, "Pennsylvania Avenue", 160));
    board.push_back(new Railroad(35, "Short Line Railroad"));
    board.push_back(new Chance(36));
    board.push_back(new Property(35, 175, 500, 1100, 1300, 1500, 350, 37, "Park Place", 350));
    board.push_back(new LuxuryTax());
    board.push_back(new Property(50, 200, 600, 1400, 1700, 2000, 400, 39, "Boardwalk", 400));
}

Board::~Board()
{
    for(Space* space : board)
    {
        delete space;
    }
}

Space* Board::getSpace(const short spaceIndex) const
{
    return board[spaceIndex];
}

vector<Property*> Board::getOwnedProperties(const Player* player)
{
    vector<Property*> properties;
    for(Space* space : board)
    {
        auto* property = dynamic_cast<Property*>(space);
        // Check if it is of type property and is owned by the current player
        if(property && property->getOwner() == player)
        {
            properties.push_back(property);
        }
    }
    return properties;
}

vector<Railroad*> Board::getOwnedRailroads(const Player* player)
{
    vector<Railroad*> railroads;
    for(Space* space : board)
    {
        Railroad* railroad = dynamic_cast<Railroad*>(space);
        if(railroad && railroad->getOwner() == player)
        {
            railroads.push_back(railroad);
        }
    }
    return railroads;
}

vector<Utility*> Board::getOwnedUtilities(const Player* player)
{
    vector<Utility*> utilities;
    for(Space* space : board)
    {
        Utility* utility = dynamic_cast<Utility*>(space);
        if(utility && utility->getOwner() == player)
        {
            utilities.push_back(utility);
        }
    }
    return utilities;
}

vector<OwnableSpaces*> Board::getOwnedSpaces(const Player* player)
{
    vector<OwnableSpaces*> ownableSpaces;
    for(Space* space : board)
    {
        auto ownableSpace = dynamic_cast<OwnableSpaces*>(space);
        if(ownableSpace && ownableSpace->getOwner() == player)
        {
            ownableSpaces.push_back(ownableSpace);
        }
    }
    return ownableSpaces;
}

//
// Created by zacka on 7/4/2024.
//

#include "Board.h"

Board::Board()
{
    board.push_back(new Property(2,10,30,90,160,250,50,1,"Mediterranean Avenue", 60));
    board.push_back(new Property(4, 20, 60, 180, 320, 450, 50, 3, "Baltic Avenue", 60));
    board.push_back(new Railroad(5, "Reading Railroad"));
    board.push_back(new Property(6, 30, 90, 270, 400, 550, 50, 6, "Oriental Avenue", 100));
    board.push_back(new Property(6, 30, 90, 270, 400, 550, 50, 8, "Vermont Avenue", 100));
    board.push_back(new Property(8, 40, 100, 300, 450, 600, 50, 9, "Connecticut Avenue", 120));
    board.push_back(new Property(10, 50, 150, 450, 625, 750, 100, 11, "St. Charles Place", 70));
    board.push_back(new Property(12, 60, 180, 500, 700, 900, 100, 13, "States Avenue", 70));
    board.push_back(new Property(14, 70, 200, 550, 750, 950, 100, 14, "Virginia Avenue", 80));
    board.push_back(new Railroad(15, "Pennsylvania Railroad"));
    board.push_back(new Property(14, 70, 200, 550, 750, 950, 100, 16, "St. James Place", 90));
    board.push_back(new Property(16, 80, 220, 600, 800, 1000, 100, 18, "Tennessee Avenue", 90));
    board.push_back(new Property(18, 90, 250, 700, 875, 1050, 100, 19, "New York Avenue", 100));
    board.push_back(new Property(18, 90, 250, 700, 875, 1050, 220, 21, "Kentucky Avenue", 110));
    board.push_back(new Property(20, 100, 300, 750, 925, 1100, 220, 23, "Indiana Avenue", 110));
    board.push_back(new Property(22, 110, 330, 800, 975, 1150, 240, 24, "Illinois Avenue", 120));
    board.push_back(new Railroad(25, "B. & O. Railroad"));
    board.push_back(new Property(22, 110, 330, 800, 975, 1150, 260, 26, "Atlantic Avenue", 130));
    board.push_back(new Property(24, 120, 360, 850, 1025, 1200, 260, 27, "Ventnor Avenue", 130));
    board.push_back(new Property(24, 120, 360, 850, 1025, 1200, 280, 29, "Marvin Gardens", 140));
    board.push_back(new Property(26, 130, 390, 900, 1100, 1275, 300, 31, "Pacific Avenue", 150));
    board.push_back(new Property(26, 130, 390, 900, 1100, 1275, 300, 32, "North Carolina Avenue", 150));
    board.push_back(new Property(28, 150, 450, 1000, 1200, 1400, 320, 34, "Pennsylvania Avenue", 160));
    board.push_back(new Railroad(35, "Short Line Railroad"));
    board.push_back(new Property(35, 175, 500, 1100, 1300, 1500, 350, 37, "Park Place", 350));
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

void Board::getOwnedProperties(const Player* player)
{
    for(Space* space : board)
    {
        if(dynamic_cast<Property*>(space)->getOwner() == player)
        {
            cout << "You own: " << dynamic_cast<Property*>(space)->getSpaceName() << endl;
        }
    }
}

//
// Created by zacka on 7/4/2024.
//

#include "Board.h"

Board::Board()
{
    board.resize(40);
    Property mediterraneanAvenue(2,10,30,90,160,250,50,1,"Mediterranean Avenue", 60);
    board.push_back(&mediterraneanAvenue);
    Property balticAvenue(4, 20, 60, 180, 320, 450, 50, 3, "Baltic Avenue", 60);
    board.push_back(&balticAvenue);
    Railroad readingRailroad(5, "Reading Railroad");
    board.push_back(&readingRailroad);
    Property orientalAvenue(6, 30, 90, 270, 400, 550, 50, 6, "Oriental Avenue", 100);
    board.push_back(&orientalAvenue);
    Property vermontAvenue(6, 30, 90, 270, 400, 550, 50, 8, "Vermont Avenue", 100);
    board.push_back(&vermontAvenue);
    Property connecticutAvenue(8, 40, 100, 300, 450, 600, 50, 9, "Connecticut Avenue", 120);
    board.push_back(&connecticutAvenue);
    Property saintCharlesPlace(10, 50, 150, 450, 625, 750, 100, 11, "St. Charles Place", 70);
    board.push_back(&saintCharlesPlace);
    Property statesAvenue(12, 60, 180, 500, 700, 900, 100, 13, "States Avenue", 70);
    board.push_back(&statesAvenue);
    Property virginiaAvenue(14, 70, 200, 550, 750, 950, 100, 14, "Virginia Avenue", 80);
    board.push_back(&virginiaAvenue);
    Property saintJamesPlace(14, 70, 200, 550, 750, 950, 100, 16, "St. James Place", 90);
    board.push_back(&saintJamesPlace);
    Property tennesseeAvenue(16, 80, 220, 600, 800, 1000, 100, 18, "Tennessee Avenue", 90);
    board.push_back(&tennesseeAvenue);
    Property newYorkAvenue(18, 90, 250, 700, 875, 1050, 100, 19, "New York Avenue", 100);
    board.push_back(&newYorkAvenue);
    Property kentuckyAvenue(18, 90, 250, 700, 875, 1050, 220, 21, "Kentucky Avenue", 110);
    board.push_back(&kentuckyAvenue);
    Property indianaAvenue(20, 100, 300, 750, 925, 1100, 220, 23, "Indiana Avenue", 110);
    board.push_back(&indianaAvenue);
    Property illinoisAvenue(22, 110, 330, 800, 975, 1150, 240, 24, "Illinois Avenue", 120);
    board.push_back(&illinoisAvenue);
    Property atlanticAvenue(22, 110, 330, 800, 975, 1150, 260, 26, "Atlantic Avenue", 130);
    board.push_back(&atlanticAvenue);
    Property ventnorAvenue(24, 120, 360, 850, 1025, 1200, 260, 27, "Ventnor Avenue", 130);
    board.push_back(&ventnorAvenue);
    Property marvinGardens(24, 120, 360, 850, 1025, 1200, 280, 29, "Marvin Gardens", 140);
    board.push_back(&marvinGardens);
    Property pacificAvenue(26, 130, 390, 900, 1100, 1275, 300, 31, "Pacific Avenue", 150);
    board.push_back(&pacificAvenue);
    Property northCarolinaAvenue(26, 130, 390, 900, 1100, 1275, 300, 32, "North Carolina Avenue", 150);
    board.push_back(&northCarolinaAvenue);
    Property pennsylvanuaAvenue(28, 150, 450, 1000, 1200, 1400, 320, 34, "Pennsylvania Avenue", 160);
    board.push_back(&pennsylvanuaAvenue);
    Property parkPlace(35, 175, 500, 1100, 1300, 1500, 350, 37, "Park Place", 350);
    board.push_back(&parkPlace);
    Property boardwalk(50, 200, 600, 1400, 1700, 2000, 400, 39, "Boardwalk", 400);
    board.push_back(&boardwalk);
}

Space* Board::getSpace(const short spaceIndex) const
{
    return board[spaceIndex];
}
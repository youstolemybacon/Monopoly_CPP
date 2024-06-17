#include <iostream>

#include "Chance.h"
#include "Player.h"
#include "Property.h"
#include "Chance.h"

using namespace std;

// enum Deck{
//     Go = 0,
//     Mediterranean_Avenue = 1,
//     Community_Chest_1 = 2,
//     Baltic_Avenue = 3,
//     Income_Tax = 4,
//     Reading_Railroad = 5,
//     Oriental_Avenue = 6,
//     Chance_1 = 7,
//     Vermont_Avenue = 8,
//     Connecticut = 9,
//     Jail = 10,
//     St_Charles_Place = 11,
//     Electric_Company = 12,
//     States_Avenue = 13,
//     Virginia_Avenue = 14,
//     Pennsylvania_Railroad = 15,
//     St_James_Place = 16,
//     Community_Chest_2 = 17,
//     Tennessee_Avenue = 18,
//     New_York_Avenue = 19,
//     Free_Parking = 20,
//     Kentucky_Avenue = 21,
//     Chance_2 = 22,
//     Indiana_Avenue = 23,
//     Illinois_Avenue = 24,
//     BO_Railroad = 25,
//     Atlantic_Avenue = 26,
//     Ventnor_Avenue = 27,
//     Water_Works = 28,
//     Marvin_Gardens = 29,
//     Go_To_Jail = 30,
//     Pacific_Avenue = 31,
//     North_Carolina_Avenue = 32,
//     Community_Chest_3 = 33,
//     Pennsylvania_Avenue = 34,
//     Short_Line_Railroad = 35,
//     Chance_3 = 36,
//     Park_Place = 37,
//     Luxury_Tax = 38,
//     Boardwalk = 39
// };

// Defining Property Objects
short rentMediterraneanAve[6] = {2, 10, 30, 90, 160, 250};
Property mediterraneanAve(rentMediterraneanAve, 50, 1, "Mediterranean Avenue");

short rentBalticAve[6] = {4, 20, 60, 180, 320, 450};
Property balticAve(rentBalticAve, 50, 3, "Baltic Avenue");

short rentOrientalAve[6] = {6, 30, 90, 270, 400, 550};
Property orientalAve(rentOrientalAve, 50, 6, "Oriental Avenue");

short rentVermontAve[6] = {6, 30, 90, 270, 400, 550};
Property vermontAve(rentVermontAve, 50, 8, "Vermont Avenue");

short rentConnecticutAve[6] = {8, 40, 100, 300, 450, 600};
Property connecticutAve(rentConnecticutAve, 50, 9, "Connecticut Avenue");

short rentStCharlesPlace[6] = {10, 50, 150, 450, 625, 750};
Property stCharlesPlace(rentStCharlesPlace, 100, 11, "St. Charles Place");

short rentStatesAve[6] = {10, 50, 150, 450, 625, 750};
Property statesAve(rentStatesAve, 100, 13, "States Avenue");

short rentVirginiaAve[6] = {12, 60, 180, 500, 700, 900};
Property virginiaAve(rentVirginiaAve, 100, 14, "Virginia Avenue");

short rentStJamesPlace[6] = {14, 70, 200, 550, 750, 950};
Property stJamesPlace(rentStJamesPlace, 100, 16, "St. James Place");

short rentTennesseeAve[6] = {14, 70, 200, 550, 750, 950};
Property tennesseeAve(rentTennesseeAve, 100, 18, "Tennessee Avenue");

short rentNewYorkAve[6] = {16, 80, 220, 600, 800, 1000};
Property newYorkAve(rentNewYorkAve, 100, 19, "New York Avenue");

short rentKentuckyAve[6] = {18, 90, 250, 700, 875, 1050};
Property kentuckyAve(rentKentuckyAve, 150, 21, "Kentucky Avenue");

short rentIndianaAve[6] = {18, 90, 250, 700, 875, 1050};
Property indianaAve(rentIndianaAve, 150, 23, "Indiana Avenue");

short rentIllinoisAve[6] = {20, 100, 300, 750, 925, 1100};
Property illinoisAve(rentIllinoisAve, 150, 24, "Illinois Avenue");

short rentAtlanticAve[6] = {22, 110, 330, 800, 975, 1150};
Property atlanticAve(rentAtlanticAve, 150, 26, "Atlantic Avenue");

short rentVentnorAve[6] = {22, 110, 330, 800, 975, 1150};
Property ventnorAve(rentVentnorAve, 150, 27, "Ventnor Avenue");

short rentMarvinGardens[6] = {24, 120, 360, 850, 1025, 1200};
Property marvinGardens(rentMarvinGardens, 150, 29, "Marvin Gardens");

short rentPacificAve[6] = {26, 130, 390, 900, 1100, 1275};
Property pacificAve(rentPacificAve, 200, 31, "Pacific Avenue");

short rentNorthCarolinaAve[6] = {26, 130, 390, 900, 1100, 1275};
Property northCarolinaAve(rentNorthCarolinaAve, 200, 32, "North Carolina Avenue");

short rentPennsylvaniaAve[6] = {28, 150, 450, 1000, 1200, 1400};
Property pennsylvaniaAve(rentPennsylvaniaAve, 200, 34, "Pennsylvania Avenue");

short rentParkPlace[6] = {35, 175, 500, 1100, 1300, 1500};
Property parkPlace(rentParkPlace, 200, 37, "Park Place");

short rentBoardwalk[6] = {50, 200, 600, 1400, 1700, 2000};
Property boardwalk(rentBoardwalk, 200, 39, "Boardwalk");

int main() {

    cout << "Rent is: " << mediterraneanAve.chargeRent();
    return 0;
}
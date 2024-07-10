#include <iostream>
#include "Player.h"
#include <variant>
#include "Board.h"

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

void playerSetup(vector<Player>& players);

int main() {
    vector<Space*> board;
    Property property(2,10,30,90,160,250,50,1,"Mediterranean Avenue", 60);
    Railroad railroad(5, "Reading Railroad");




    vector<Player> players;
    playerSetup(players);

    players[0].printMoney();
    //players[0].buyProperty();
    players[0].printProperties();




    //mediterraneanAve.displayPropertyInfo();
    //cout << mediterraneanAve.getRent() << endl;
    //mediterraneanAve.build(5);
    //cout << mediterraneanAve.getRent() << endl;
    return 0;
}

void playerSetup(vector<Player>& players)
{
    short numberOfPlayers;
    cout << "How many players will be playing: " << endl;
    cin >> numberOfPlayers;
    players.resize(numberOfPlayers);

    for(int i = 0; i < numberOfPlayers; i++)
    {
        string name;
        cout << "Player " << i + 1 << " enter your name: " << endl;
        cin >> name;
        players[i].name = name;
        players[i].roll(); // The player rolls here to avoid all players having same seed
    }

    cout << "Welcome " << players[0].name;
    for(int i = 1; i < players.size() - 1; i++)
    {
            cout << ", " << players[i].name;
    }
    cout << " and " << players[players.size() - 1].name << " we hope you enjoy the game! Let us begin by rolling for the order of play!" << endl;

    bool ordered = false;

    for(short i = 0; i < players.size(); i++)
    {
        short largestIndex = 0; // Store Player with highest roll
        short largestRoll = 0; // Store the largest roll
        for(short j = i; j < players.size(); j++)
        {
            if(players[j].getDice() > largestRoll)
            {
                largestRoll = players[j].getDice();
                largestIndex = j;
            }
        }
        if(largestIndex != i)
        {
            swap(players[i], players[largestIndex]);
        }
    }

    for(Player& player : players)
    {
        cout << player.name << " you rolled " << player.getDice() << endl;
    }
}

//
// Created by Zack on 4/20/2024.
//

#ifndef MONOPOLY_SIM_PLAYER_H
#define MONOPOLY_SIM_PLAYER_H

#include <iostream>

class Board;
class Space;
class Property;
class Railroad;
class Utility;

using namespace std;

class Player {
public:
    Player(string name);
    Player() = default;

    int getSpaceIndex() const;
    void setSpace(int spaceIndex);

    Space* getSpace();

    short getJailSentence();
    void setJailSentence(short jailSentence);

    short getRailroadsOwned() const;
    void incrementRailroadsOwned();
    void decrementRailroadsOwned();

    void roll();
    bool move();

    bool passGoCheck();

    const int getDice() const;
    bool compareDice();

    const int *getSpaceHistory() const;
    void displaySpaceHistory() const;

    void printMoney() const;
    void printSpaces() const;

    bool pay(short cost, Player* beneficiary);
    bool pay(short cost);

    //bool buy(Property* property);
    //bool buy(Property* property, short price);
    //bool buy(Railroad* railroad);
    //bool buy(Railroad* railroad, short price);
    //bool buy(Utility* utility);
    //bool buy(Utility* utility, short price);

    int money = 1500;
    string name;
    static Board playerBoard;
private:
    short railroadsOwned = 0;
    short jailSentence{};
    int spaceIndex = 0;
    int dice[2] = {0};
    int spaceHistory[40] = {0};
    double moves = 0;
};
#endif //MONOPOLY_SIM_PLAYER_H

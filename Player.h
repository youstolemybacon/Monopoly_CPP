//
// Created by Zack on 4/20/2024.
//

#ifndef MONOPOLY_SIM_PLAYER_H
#define MONOPOLY_SIM_PLAYER_H

#include <iostream>
#include <vector>

class OwnableSpaces;
class Board;
class Space;
class Property;
class Railroad;
class Utility;

using namespace std;

class Player {
public:
    Player() = default;

    int getSpaceIndex() const;
    void setSpace(int spaceIndex);

    Space* getSpace();

    short getJailSentence() const;
    void setJailSentence(short jailSentence);
    bool isJailed() const ;

    short getRailroadsOwned() const;
    void incrementRailroadsOwned();
    void decrementRailroadsOwned();

    void roll();
    void move();

    const int getDice() const;
    bool compareDice();

    void printMoney() const;
    void printPlayerInfo() const;

    bool pay(short cost, Player* beneficiary);
    bool pay(short cost);

    void income(short income);

    void setDoubles(short doubles);
    short getDoubles() const;

    void setChanceModifier(bool chanceModifier);
    bool getChanceModifier();

    void setGetOutOfJailFree(short count);
    short getGetOutOfJailFree() const;

    void trade();
    std::vector<OwnableSpaces*> tradeOwnedMenu(Player* tradingPlayer);
    std::vector<OwnableSpaces*> tradeOwnedPropertiesSelection();

    bool operator==(const Player& player) const;

    int money = 1500;
    string name;
    static Board playerBoard;
private:
    bool chanceModifier = false; // Used when a chance card affects rent values
    short getOutOfJailFree = 0;
    short doubles = 0;
    short railroadsOwned = 0;
    short jailSentence{};
    int spaceIndex = 0;
    int dice[2] = {0};
    double moves = 0;
};


#endif //MONOPOLY_SIM_PLAYER_H

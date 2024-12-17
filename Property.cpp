//
// Created by Zack on 5/2/2024.
//

#include "Property.h"
#include "Board.h"
#include "Player.h"

Property::Property(short rent_1, short rent_2, short rent_3, short rent_4, short rent_5, short rent_6, short housePrice, short spaceIndex, string spaceName, short price, PropertyGroup propertyGroup) : rent{rent_1, rent_2, rent_3, rent_4, rent_5, rent_6}, housePrice(housePrice), OwnableSpaces(price, spaceIndex, spaceName), propertyGroup(propertyGroup) {}

void Property::build(short buildHouses) {

    auto propertyOwner = this->getOwner();
    short buildPrice = housePrice * buildHouses;

    if (buildHouseCheck(propertyGroup, buildHouses))
    {
        if(houses + buildHouses > 5)
        {
            cout << "This property cannot be developed further." << endl;
        }
        else if (propertyOwner->pay(buildPrice))
        {
            // Add the houses being built to the member variable
            houses += buildHouses;
        }
    }
}

void Property::demo(short demos)
{
    auto propertyOwner = this->getOwner();
    short houseCost = housePrice / 2;

    if (this->houses != 0 & demoHouseCheck(propertyGroup, -demos))
    {
        // Remove the houses being demoed to the member variable
        houses -= demos;
        propertyOwner->income(houseCost * demos);
    }
}

short Property::getHouses() const
{
    return houses;
}

bool Property::buildHouseCheck(PropertyGroup colorSet, short houses) const
{
    auto colorGroup = getPropertyGroup(colorSet);

    // Building a house
    if (this->houses + houses < 6)
    {
        for (auto property : colorGroup)
        {
            // Check if the current property will have a delta of more then 1 house when compared to other properties in the set
            if (this->houses - property->houses + houses > 1)
            {
                // Build criteria is not met
                cout << "This property is over developed compared to the other properties in the Color Set. \n";
                return false;
            }
        }
        // Building criteria met
        return true;
    }
    else
    {
        cout << "You are attempting to build past the limit. \n";
    }
    // Build criteria is not met
    return false;
}

bool Property::demoHouseCheck(PropertyGroup colorSet, short houses) const
{
    auto colorGroup = getPropertyGroup(colorSet);

    // Building a house
    if (this->houses + houses > -1)
    {
        for (const auto property : colorGroup)
        {
            // Check if the current property will have a delta of more then 1 house when compared to other properties in the set
            if (this->houses - property->houses + houses > 1)
            {
                // Build criteria is not met
                cout << "This property is over developed compared to the other properties in the Color Set. \n";
                return false;
            }
        }
        // Building criteria met
        return true;
    }
    // Build criteria is not met
    cout << "There are no houses to demo on this property. \n";
    return false;
}

short Property::getRent(Player* player)
{
    if (houses == 0 && monopolyCheck(getOwner(), propertyGroup))
    {
        return rent[0] * 2;
    }
    return rent[houses];
}

short Property::getHousePrice() const
{
    return housePrice;
}

void Property::displayInfo() {
    cout << endl << "_______________________________________" << endl;
    cout << endl << getSpaceName() << endl;
    cout << endl;
    cout << "  RENT $" << rent[0] << endl;
    cout << "  With 1 House... $" << rent[1] << endl;
    cout << "  With 2 House... $" << rent[2] << endl;
    cout << "  With 3 House... $" << rent[3] << endl;
    cout << "  With 4 House... $" << rent[4] << endl;
    cout << "  With HOTEL $" << rent[5] << endl;
    cout << endl;
    cout << "  Mortgage Value $" << getPrice() / 2 << endl;
    cout << "  Houses cost $" << getHousePrice() << " each" << endl;
    cout << "  Hotels, $" << getHousePrice() << " plus 4 houses" << endl;
    cout << endl << "_______________________________________" << endl << endl;
}

vector<Property*> Property::getPropertyGroup(PropertyGroup color)
{
    vector<Property*> groupProperties;
    for (Space* space : Board::board)
    {
        auto property = dynamic_cast<Property*>(space);
        if (property && property->propertyGroup == color)
        {
            groupProperties.push_back(property);
        }
    }
    return groupProperties;
}

vector<Property*> Property::getMonopolies(const Player* player)
{
    vector<Property*> monopolies{};
    constexpr PropertyGroup colors[8] =
        {
            PropertyGroup::BROWN, PropertyGroup::LIGHT_BLUE, PropertyGroup::PINK, PropertyGroup::ORANGE,
            PropertyGroup::RED, PropertyGroup::YELLOW, PropertyGroup::GREEN, PropertyGroup::BLUE
        };

    // Go through each color group
    for (const auto color : colors)
    {
        // Get the properties of the current color group
        auto colorGroup = getPropertyGroup(color);

        // Check if player has a monopoly on the color group. If it is a monopoly add properties to list of monopolies
        if (monopolyCheck(player, color))
        {
            // Loop through colorGroup to add each property to the monopolies vector
            for (auto property : colorGroup)
            {
                monopolies.push_back(property);
            }
        }
    }
    return monopolies;
}

bool Property::monopolyCheck(const Player* player, PropertyGroup color)
{
    auto propertyGroup = getPropertyGroup(color);

    for (Property* property : propertyGroup)
    {
        if (property->getOwner() != player)
        {
            return false; // Not a monopoloy
        }
    }
    return true; // Monopoly
}

void Property::displaySpace()
{
    OwnableSpaces::displaySpace();

    // Open parentheses for extra info
    cout << " (";

    // Print info on is there are houses or if it is a monopoly
    if (this->houses == 5)
    {
        cout << "HOTEL, ";
    }
    else if (this->houses > 0)
    {
        cout << "HOUSES: " << this->houses << ", ";
    }
    else if (monopolyCheck(getOwner(), propertyGroup))
    {
        cout << "MONOPOLY, ";
    }

    // Print property group
    switch (propertyGroup)
    {
    case PropertyGroup::BROWN:
        cout << "BROWN";
        break;
    case PropertyGroup::LIGHT_BLUE:
        cout << "LIGHT BLUE";
        break;
    case PropertyGroup::PINK:
        cout << "PINK";
        break;
    case PropertyGroup::ORANGE:
        cout << "ORANGE";
        break;
    case PropertyGroup::RED:
        cout << "RED";
        break;
    case PropertyGroup::YELLOW:
        cout << "YELLOW";
        break;
    case PropertyGroup::GREEN:
        cout << "GREEN";
        break;
    case PropertyGroup::BLUE:
        cout << "BLUE";
        break;
    }
    cout << ")";
}

void Property::spaceSelectedFromMenu()
{
    bool exitMenu = false;
    short menuSelection;
    enum menuOptions
    {
        BACK,
        INFO,
        MORTGAGE,
        BUILD,
        DEMO
    };
    while(!exitMenu)
    {
        // Print menu options
        cout << "The following actions are available:\n"
                "   [0] Back\n"
                "   [1] Info\n"
                "   [2] Mortgage\n"
                "   [3] Build\n"
                "   [4] Demo\n";

        // Get user input
        cin >> menuSelection;
        cin.clear();

        switch (static_cast<menuOptions>(menuSelection))
        {
        case BACK:
            exitMenu = true;
            break;
        case INFO:
            displayInfo();
            break;
        case MORTGAGE:
            if (getMortgage())
            {
                unmortgageSpace();
            }
            else
            {
                mortgageSpace();
            }
            break;
        case BUILD:
            if (monopolyCheck(getOwner(), propertyGroup))
            {
                build(1);
            }
            else
            {
                cout << "You do not have a monopoly of this color set.\n\"You Egg!\" - Ethan\n\n";
            }
            break;
        case DEMO:
            demo();
            break;
        default:
            cout << "Invalid input\n";
        }
    }
}

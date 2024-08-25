//
// Created by Zack on 5/2/2024.
//

#include "Property.h"
#include "Board.h"
#include "Player.h"

Property::Property(short rent_1, short rent_2, short rent_3, short rent_4, short rent_5, short rent_6, short housePrice, short spaceIndex, string spaceName, short price, PropertyGroup propertyGroup) : rent{rent_1, rent_2, rent_3, rent_4, rent_5, rent_6}, housePrice(housePrice), OwnableSpaces(price, spaceIndex, spaceName), propertyGroup(propertyGroup) {}

void Property::build(short buildHouses) {
    auto colorGroup = this->getPropertyGroup(propertyGroup);

    for (auto property : colorGroup)
    {
        if (property->houses < this->houses)
        {
            cout << "You are unable to build on this property. The other properties in the of the color set must be further developed. \n";
            return;
        }
    }

    if(houses + buildHouses > 5)
    {
        cout << "This property is cannot be developed further." << endl;
    }
    else
    {
        // Add the houses being built to the member variable
        houses += buildHouses;

        //// Print info for user
        //if(houses == 1)
        //{
        //    cout << "There is now " << houses << " house on " << this->getSpaceName() << endl;
        //}
        //else if(houses == 5)
        //{
        //    cout << "There is now 1 hotel on " << this->getSpaceName() << endl;
        //}
        //else
        //{
        //    cout << "There are now " << houses << " houses on " << this->getSpaceName() << endl;
        //}
    }


}

short Property::getRent()
{
    if (houses == 0 && monopolyCheck(getOwner(), propertyGroup))
    {
        return rent[0] * 2;
    }
    return rent[houses];
}

short Property::getHousePrice()
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

void Property::developPropertiesMenu(Player* player)
{
    auto monopoliesProperties = getMonopolies(player);
    vector<OwnableSpaces*> monopolies;

    for (auto property : monopoliesProperties)
    {
        monopolies.push_back(property);
    }

    if (monopolies.empty())
    {
        cout << "You currently do not have any monopolies." << endl;
    }
    else
    {
        bool exitMenu = false;
        short userInput;

        while (!exitMenu)
        {
            cout << "Your monopolies are printed below. Select the property to develop: \n"
                "   [0] Back \n";

            printSpaces(monopolies, 1);

            // Get user input
            cin >> userInput;
            cin.clear();

            // If user input is 0 no action is taken. If it is not zero use the input to reference the correspondings space info
            if(userInput == 0)
            {
                exitMenu = true;
            }
            else
            {
                // Check if the user input is within the range of the vector
                if (userInput > monopolies.size())
                {
                    cout << "The value entered is outside of the range." << endl;
                }
                // Display the space info and building menu
                else
                {
                    bool returnToPropertySelection = false;
                    while (!returnToPropertySelection)
                    {
                        auto propertySelected = dynamic_cast<Property*>(monopolies[userInput - 1]);
                        propertySelected->displayInfo();

                        cout << "The following actions are available: \n"
                                "   [0] Back \n"
                                "   [1] Build House \n";
                        // Get user input
                        cin >> userInput;
                        cin.clear();

                        switch (userInput)
                        {
                        case 1:
                            propertySelected->build(1);
                        case 0:
                            returnToPropertySelection = true;
                            break;
                        default:
                            cout << "Invalid input! \n";
                        }
                    }
                }
            }
        }
    }
}

void Property::displaySpace()
{
    OwnableSpaces::displaySpace();
    if (this->houses == 5)
    {
        cout << " (HOTEL)";
    }
    else if (this->houses > 0)
    {
        cout << " (HOUSES: " << this->houses << ")";
    }
    else if (monopolyCheck(getOwner(), propertyGroup))
    {
        cout << " (MONOPOLY)";
    }
}

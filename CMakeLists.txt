cmake_minimum_required(VERSION 3.28)
project(Monopoly_Sim)

set(CMAKE_CXX_STANDARD 23)

add_executable(Monopoly_Sim main.cpp
        Player.cpp
        Player.h
        Deck.cpp
        Deck.h
        Space.cpp
        Space.h
        Board.cpp
        Board.h
        Players.cpp
        Players.h
        OwnableSpaces.cpp
        OwnableSpaces.h
        Utility.cpp
        Utility.h
        Dice.cpp
        Dice.h
        Go.cpp
        Go.h
        CommunityChest.cpp
        CommunityChest.h
        Jail.cpp
        Jail.h
        GoToJail.cpp
        GoToJail.h
        LuxuryTax.cpp
        LuxuryTax.h
        IncomeTax.cpp
        IncomeTax.h
        Property.cpp
        Property.h
        Railroad.h
        Railroad.cpp
        Chance.cpp
        Chance.h
        Gameplay.cpp
        Gameplay.h
        FreeParking.cpp
        FreeParking.h
        Trade.cpp
        Trade.h
        #Menu.cpp
        #Menu.h
)
cmake_minimum_required(VERSION 3.28)
project(Monopoly_Sim)

set(CMAKE_CXX_STANDARD 23)

add_executable(Monopoly_Sim main.cpp
        Player.cpp
        Player.h
        Deck.cpp
        Deck.h
        Property.cpp
        Property.h
        Chance.cpp
        Chance.h
        Space.cpp
        Space.h
        Railroad.h
        Railroad.cpp
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
)
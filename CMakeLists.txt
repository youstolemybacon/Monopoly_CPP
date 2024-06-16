cmake_minimum_required(VERSION 3.27)
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
)

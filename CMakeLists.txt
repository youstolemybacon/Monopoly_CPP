cmake_minimum_required(VERSION 3.28)
project(Monopoly)

set(CMAKE_CXX_STANDARD 23)

add_executable(Monopoly main.cpp
        Deck.cpp
        Deck.h
        Player.cpp
        Player.h
        Property.cpp
        Property.h
        Space.cpp
        Space.h
        Railroad.cpp
        Railroad.h
)

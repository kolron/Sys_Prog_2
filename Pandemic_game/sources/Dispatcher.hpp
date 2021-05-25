#pragma once
#include "Player.hpp"

namespace pandemic
{
    class Dispatcher: public Player //like all other Player-inheriting classes..
    {
        public:
            Dispatcher(Board& board, City city); //new constructor isn't a must because it's practically the same, still, for good measure.


            Player &fly_direct(City); //if a method is here it's because we need to override it, or we need it in order to override

            static std::string role();
            void displayAbillity();
    };
};
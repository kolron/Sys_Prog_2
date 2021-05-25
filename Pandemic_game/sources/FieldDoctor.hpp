#pragma once
#include "Player.hpp"

namespace pandemic
{
    class FieldDoctor: public Player
    {
        public:
            FieldDoctor(Board& board, City city);
            Player &treat(City);

            static std::string role();
            void displayAbillity();
    };
};
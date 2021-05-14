#pragma once
#include "Player.hpp"

namespace pandemic
{
    class Virologist: public Player
    {
        public:
            Virologist(Board& board, City city);   

            Player &treat(City city);
            static std::string role();
            void displayAbillity() ;
    };
};
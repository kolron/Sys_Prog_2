#pragma once
#include "Player.hpp"

namespace pandemic
{
    class Scientist: public Player
    {
        public:
            unsigned int cure_num;

            Scientist(Board& board, City city, unsigned int cure_num ):Player(board,city)
            {
                this -> cure_num = cure_num;
            }
            Player &discover_cure(Color color);
            std::string role()
            {
                return "Dispatcher";
            }
    };
};
#pragma once
#include "Player.hpp"

namespace pandemic
{
    class Scientist: public Player
    {
        public:
            int cure_num;

            Scientist(Board& board, City city, int cure_num);
            
            Player &discover_cure(Color color);

            static std::string role();
           

             void displayAbillity();
            
    };
};
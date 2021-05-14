#pragma once
#include "Player.hpp"

namespace pandemic
{
    class Medic: public Player
    {
        public:
            Medic(Board& board, City city);
            
            Player &drive(City city);
            Player &fly_direct(City city);
            Player &fly_shuttle(City city);
            Player &fly_charter(City city);
            Player &treat(City city);
            Player &discover_cure(Color color);
            static std::string role();
            void displayAbillity();

        private:
            void medic_perk();
    };

};
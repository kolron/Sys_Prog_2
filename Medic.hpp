#pragma once
#include "Player.hpp"

namespace pandemic
{
    class Medic: public Player
    {
        public:
            Medic(Board& board, City city):Player(board,city)
            {

            }
            Player &drive(City city);
            Player &fly_direct(City city);
            Player &fly_shuttle(City city);
            Player &fly_charter(City city);
            Player &treat(City city);
            Player &discover_cure(Color color);
            std::string role()
            {
                return "Medic";
            }
        private:
            void medic_perk();
    };

};
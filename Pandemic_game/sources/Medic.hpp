#pragma once
#include "Player.hpp"

namespace pandemic
{
    class Medic: public Player
    {
        public:
        //overrides every movment action because of it's special rule applying each time the Medic moves.
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
        //called after each time a Medic moves to apply it's special rule.
            void medic_perk();
    };

};
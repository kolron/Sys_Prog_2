#pragma once
#include "City.hpp"
#include "Board.hpp"
#include "Color.hpp"
#include <string>
#include <unordered_set>

namespace pandemic
{
    class Player
    {

    protected:
        Board &board; 
        City location;
        std::unordered_set<City> cards; //important! Cards are just cities! no actual Card object/Class
        const int NUM_OF_CARDS_FOR_DISCOVER = 5;
        const int TOTAL_CARDS = 48;



    public:
     
        Player(Board & board, City city);
        virtual ~Player();
        virtual Player &drive(City city);
        virtual Player &fly_direct(City city);
        virtual Player &fly_shuttle(City city);
        virtual Player &fly_charter(City city);
        virtual Player &build();
        virtual Player &discover_cure(Color color);
        virtual Player &treat(City city);
        Player &take_card();
        Player &take_card(City city);

        City get_location() 
        {
            return location;
        }

        std::string role()
        {
            return "No special role have been chosen yet.";
        }

        void virtual displayAbillity()
        {
            std::cout << "No special abillites." << std::endl;
        }
       std::unordered_set<pandemic::City> get_cards();
 
    };
};
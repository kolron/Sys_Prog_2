#include "Medic.hpp"
using namespace std;
using namespace pandemic;


void Medic::medic_perk()
{
    if (board->have_cure(board->get_color(location)))
    {
        (*board)[location] = 0;
    }
}
Player &Medic::drive(City city)
{
   Player::drive(city);
   medic_perk();
    return *this;
}

Player &Medic::fly_direct(City city)
{

  Player::fly_direct(city);
  medic_perk();
   return *this;
}

Player &Medic::fly_charter(City city)
{
    Player::fly_charter(city);
    medic_perk();
     return *this;
}
Player &Medic::fly_shuttle(City city)
{
    Player::fly_shuttle(city);
    medic_perk();
     return *this;
}

Player &Medic::discover_cure(Color color)
{
    Player::discover_cure(color);
    medic_perk();
     return *this;
}

Player &Medic::treat(City city) 
{
    if(!(city == location && (*board)[city] > 0))
    {
        throw invalid_argument("You must be in the city you want to treat and the city must have an infection level of atleast 1.");
    }
    
    if(board ->have_cure(board->get_color(city)))
    {
        (*board)[city] = 0;
    }
    else
    {
        (*board)[city] -= 1;
    }
     return *this;
}

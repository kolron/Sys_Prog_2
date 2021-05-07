
#include "Virologist.hpp"
using namespace std;
using namespace pandemic;

Player &Virologist::treat(City city)
{
    if(location == city)
    {
         Player::treat(city);
    }
    else
    {
        auto card = cards.find(city);
        if(card == cards.end())
        {
            throw invalid_argument("You must have the city's card to treat as a Virologist!");
        }

        if(!((*board)[city] > 0))
        {
            throw invalid_argument("The city must have an infection level of atleast 1.");
        }

        if(board ->have_cure(board->get_color(city)))
        {
            (*board)[city] = 0;
        }
        else
        {
            (*board)[city] -= 1;
        }
        cards.erase(card);
    }
     return *this;
}
#include "Dispatcher.hpp"
using namespace pandemic;

Player &Dispatcher::fly_direct(City city)
{
    if (board ->have_research(location))
    {
        location = city;
    }
    else
    {
        Player::fly_direct(city);
    }
     return *this;
}

#include "FieldDoctor.hpp"
#include <exception>
using namespace pandemic;
using namespace std;

Player &FieldDoctor::treat(City city)
{
    if(!(city == location && (*board)[city] > 0) && board->is_connected(location,city))
    {
        throw invalid_argument("You must be in the city, or one that is connected to the city you want to treat and the city must have an infection level of atleast 1.");
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

#include "Dispatcher.hpp"
using namespace pandemic;
using namespace std;

Dispatcher::Dispatcher(Board& board, City city):Player(board,city)
{

}

Player &Dispatcher::fly_direct(City city)
{
    if (location == city)
    {
        throw std::invalid_argument("Source and destination city must be different.");
    }
    if (board .have_research(location))
    {
        location = city;
    }
    else
    {
        Player::fly_direct(city);
    }
     return *this;
}
string Dispatcher::role()
{
    return "Dispatcher";
}
void Dispatcher::displayAbillity() 
{
    cout<<"As a "<< role()<< " if you are at a city that has a Research Station, you can Fly Direct to any city you want without tossing the relavent card.\n" << endl;
}
    
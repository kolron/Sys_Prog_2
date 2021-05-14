#include "FieldDoctor.hpp"
#include <exception>
using namespace pandemic;
using namespace std;

FieldDoctor::FieldDoctor(Board& board, City city):Player(board,city)
{
    
}
Player &FieldDoctor::treat(City city)
{
    if(!(city == location && board[city] > 0) && !(Board::is_connected(location,city)))
    {
        throw invalid_argument("You must be in the city, or one that is connected to the city you want to treat and the city must have an infection level of atleast 1.");
    }
    
    if(board .have_cure(Board::get_color(city)))
    {
        board[city] = 0;
    }
    else
    {
        board[city] -= 1;
    }
     return *this;
}
string FieldDoctor::role()
{
    return "FieldDoctor";
}
void FieldDoctor::displayAbillity() 
{
    cout<<"As a "<< role()<< " you can Treat in any city that is connected to the one you're in.\n" << endl;
}

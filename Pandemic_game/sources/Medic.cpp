#include "Medic.hpp"
using namespace std;
using namespace pandemic;

Medic::Medic(Board& board, City city):Player(board,city)
        {

        }

void Medic::medic_perk() //called after each time a Medic moves to apply it's special rule.
{
    if (board.have_cure(Board::get_color(location)))
    {
        board[location] = 0;
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

Player &Medic::treat(City city) // applying rule..
{
    if(!(city == location && board[city] > 0))
    {
        throw invalid_argument("You must be in the city you want to treat and the city must have an infection level of atleast 1.");
    }

    board[city] = 0;
   
     return *this;
}
string Medic::role()
{
    return "Medic";
}

void Medic::displayAbillity() 
{
    cout<<"As a "<< role()<< " any time you Treat you immediately reduce the city's infection level to 0. \n In addition, once a cure has been discovered, each matching-colored city you visit has it's infection level reduced to 0." <<endl;
}

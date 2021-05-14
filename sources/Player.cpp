#include "Player.hpp"
#include <vector>
#include <exception>
using namespace pandemic;
using namespace std;

const int NUM_OF_CARDS_FOR_DISCOVER = 5;
const int TOTAL_CARDS = 48;
Player::Player(Board & board, City city):board(board)
{ 
            this -> location = city;
}
Player::~Player(){}

Player& Player::drive(City city)
{
    if(city == location)
    {
         throw invalid_argument("Can't drive from a city to itself.");
    }

    if (Board::is_connected(location, city))
    {
        location = city;
        cout << "Driving to " << Board::ctos(city) << endl;
    }

    else
    {
    throw invalid_argument("can only drive between connected cities.");
    }
     return *this;
}
std::unordered_set<pandemic::City> Player::get_cards()
{
    return cards;
}
Player &Player::fly_direct(City city)
{
 if(city == location)
    {
         throw invalid_argument("Can't fly from a city to itself.");
    }
    auto card = cards.find(city);
    if (card == cards.end())
    {
        throw invalid_argument("You must have the correct city card to fly direct to it.");
    }
    location = city;
    cout << "Flying Direct to " << Board::ctos(city)<<endl;
    cards.erase(card);
    return *this;
}

Player &Player::fly_charter(City city)
{
    if(city == location)
    {
         throw invalid_argument("Can't fly from a city to itself.");
    }
    auto card = cards.find(location);
    if (card == cards.end())
    {
        throw invalid_argument("You must have your current city card to fly charter");
    }
    
    location = city;
    cout << "Flying Charter to " << Board::ctos(city)<< endl;
    cards.erase(card);
    
     return *this;

}
Player &Player::fly_shuttle(City city)
{

    if(city == location)
    {
         throw invalid_argument("Can't fly from a city to itself.");
    }
    
    if (board.have_research(location) && board.have_research(city))
    {
        location = city;
        cout << "Flying Shuttle to " << Board::ctos(city)<< endl;
    }
   
    else
    {
        throw invalid_argument("Both cities must have a research station in order to fly shuttle.");
    }
     return *this;
}

Player &Player::build()
{
    cout << "Attempting to build a Research Station in "<< Board::ctos(location) << "..." << endl;
    auto card = cards.find(location);
    if (card == cards.end())
    {
        throw invalid_argument("Build failed. You must have the correct city card to build.");
    } 

    if(board.have_research(location))
    {
      cout << "Warning! A Research Station is already present in this city." <<endl ;
    }
    else
    {
        cout << "Build completed successfully" << endl;
        board.add_research(location);
        cards.erase(card);
    }
     return *this;
}

Player &Player::discover_cure(Color color)
{
    cout << "Attempeting to discover cure for color: "<< Board::clrtos(color)<<endl;;
    int count = 0;
    vector<City> cure_cards;
    bool card_flag = false;
    for(City card : cards)
    {
        if(Board::get_color(card) == color)
        {
            cure_cards.push_back(card);
            count +=1;
            if (count == NUM_OF_CARDS_FOR_DISCOVER)
            {
                card_flag = true;
                break;
            }
        }
    }

    if(!(board.have_research(location) && card_flag))
    {
        throw invalid_argument("This city must have a Research Station and you must have 5 cards of the disease's color");
    }
   
    board.add_cure(color);
    for(City card : cure_cards)
    {
        cout << "Discovery was a success!" << endl;
        cards.erase(card);
    }
    
     return *this;
}

Player &Player::treat(City city)
{
    cout<<"Attempting to treat "<< Board::ctos(city)<<endl;
    if(!(city == location && board[city] > 0))
    {
        throw invalid_argument("You must be in the city you want to treat and the city must have an infection level of atleast 1.");
    }

    if(board.have_cure(Board::get_color(city)))
    {
        board[city] = 0;

    }
    else
    {
        board[city] -= 1;
    }
     cout << "Treat was successfull in "<< Board::ctos(city)<<".Infection level is now at: "<< board[city]<<endl;
     return *this;
}

Player &Player::take_card()
{
    City card = City(rand()%TOTAL_CARDS);
    cout << '|' << Board::ctos(card) << '|' << endl;
    cards.insert(card);
     return *this;

}

Player &Player::take_card(City city) //mostly for tests.. actual game will be a random draw like above.
{
    cards.insert(city);
    return *this;

}


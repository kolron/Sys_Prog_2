#include "Player.hpp"
#include <vector>
#include <exception>
using namespace pandemic;
using namespace std;

const int NUM_OF_CARDS_FOR_DISCOVER = 5; //used in the discover cure method
const int TOTAL_CARDS = 48; //a card for each city, doesn't mention otherwise in the readme

//all methods that return *this (&player) do so in order to string/concat(idk if it's the right word) methods (player.foo().foo()..)

Player::Player(Board & board, City city):board(board),location(city) //constructor for player
{ 
           //this -> location = city;
}
Player::~Player(){} //destructor


//won't comment on every single momvement action.. it's all the same: checks for eligibility and moves if possible, if not- throws
//prints action using ctos for player experience, erasing card if needed
//chaning location by setting (this->)location = city
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
    auto card = cards.find(location); //attempts to find the matching City card in our hand ((this->)cards)
     
    //checks for eligibility
    //fails
    if (card == cards.end())
    {
        throw invalid_argument("Build failed. You must have the correct city card to build.");
    } 

    if(board.have_research(location)) //Doesn't do anything but prints out a warning - useful for not ending turns should I implement a 2 player main
    {
      cout << "Warning! A Research Station is already present in this city." <<endl ;
    }
    else //success
    {
        cout << "Build completed successfully" << endl;
        board.add_research(location); //add research station
        cards.erase(card); //erase card
    }
     return *this;
}

//most troublesome method for me
Player &Player::discover_cure(Color color) 
{
    cout << "Attempeting to discover cure for color: "<< Board::clrtos(color)<<endl;;

    int count = 0; //counts how many matching cards we found
    vector<City> cure_cards; //holds the matching cards
    bool card_flag = false; //represents if enough cards were found.
    for(City card : cards) //for each card in our hand
    {
        if(Board::get_color(card) == color) //if it's the right color (Each card is a City and each City has a color)
        {
            cure_cards.push_back(card); //add it to the vector which holds the cards.
            count +=1; 
            if (count == NUM_OF_CARDS_FOR_DISCOVER) // if we reached enough cards.
            {
                card_flag = true; // we have enough cards to discover cure.
                break;
            }
        }
    }

    if(!(board.have_research(location) && card_flag)) //If we have a research station and we found enough cards we can cure, if not throw.
    {
        throw invalid_argument("This city must have a Research Station and you must have 5 cards of the disease's color");
    }
   
    board.add_cure(color); //add the color of the found Cure to the Cures set
    cout << "Discovery was a success!" << endl;
    for(City card : cure_cards)
    {
        cards.erase(card); //erase (toss) all cards that were used. 
    }
     return *this;
     //not giving the Player the option to choose which cards to toss just yet
}

Player &Player::treat(City city)
{
    cout<<"Attempting to treat "<< Board::ctos(city)<<endl; 
    if(!(city == location && board[city] > 0)) //checks for eligibllity 
    {
        throw invalid_argument("You must be in the city you want to treat and the city must have an infection level of atleast 1.");
    }

    if(board.have_cure(Board::get_color(city))) //success
    {
        board[city] = 0; //reduces infection according to the rules.

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
    cout << '|' << Board::ctos(card) << '|' << endl; //for printing purposes only
    cards.insert(card);
     return *this;

}

Player &Player::take_card(City city) //mostly for tests.. actual game will be a random draw like above.
{
    cards.insert(city);
    return *this;

}

std::unordered_set<pandemic::City> Player::get_cards() //returns the cards the player holds
{
    return cards;
}


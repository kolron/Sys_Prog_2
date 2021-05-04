#include "Player.hpp"
#include <vector>
#include <exception>
using namespace pandemic;
using namespace std;

Player &Player::drive(City city)
{
    if (board->is_connected(location, city))
    {
        location = city;
    }
    else
    {
    throw invalid_argument("aren't connected. can only drive between connected cities.;");
    }
     return *this;
}

Player &Player::fly_direct(City city)
{

    auto card = cards.find(city);
    if (card == cards.end())
    {
        throw invalid_argument("You must have the correct city card to fly direct to it.");
    }

    location = city;
    cards.erase(card);
    
     return *this;
}

Player &Player::fly_charter(City city)
{
    auto card = cards.find(location);
    if (card == cards.end())
    {
        throw invalid_argument("You must have your current city card to fly charter");
    }
    
    location = city;
    cards.erase(card);
    
     return *this;

}
Player &Player::fly_shuttle(City city)
{
    if(board->have_research(location) && board->have_research(city))
    {
        location = city;
    }
    else
    {
        throw invalid_argument("Both cities must have a research station in order to fly shuttle.");
    }
     return *this;
}

Player &Player::build()
{
    auto card = cards.find(location);
    if (card == cards.end() || board ->have_research(location))
    {
      cout << "You either don't have the required city card, or a Research Station is already present in this city." << endl;
    }
    else
    {
        board ->add_research(location);
        cards.erase(card);
    }
     return *this;
}

Player &Player::discover_cure(Color color)
{
    int count = 0;
    vector<City> cure_cards;
    bool card_flag = false;
    for(City card : cards)
    {
        if(board->get_color(card) == color)
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

    if(!(board->have_research(location) && card_flag))
    {
        cout << "This city must have a Research Station and you must have 5 cards of the disease's color" << endl;
    }
    else
    {
        board->add_cure(color);
        for(City card : cure_cards)
        {
            cards.erase(card);
        }
    }
     return *this;
}

Player &Player::treat(City city)
{

    if(!(city == location && (*board)[city] > 0))
    {
        throw invalid_argument("You must be in the city you want to treat and the city must have an infection level of atleast 1.");
    }

    if(board->have_cure(board->get_color(city)))
    {
        (*board)[city] = 0;
    }
    else
    {
        (*board)[city] -= 1;
    }
     return *this;
}

Player &Player::take_card()
{
    City card = City(rand()%TOTAL_CARDS);
    cards.insert(card);
     return *this;

}

Player &Player::take_card(City city)
{
    cards.insert(city );
    return *this;

}

string Player::role()
{
    return "No special role have been chosen yet.";
}
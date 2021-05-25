
#include "Scientist.hpp"
#include <vector>
using namespace pandemic;
using namespace std;


Scientist::Scientist(Board& board, City city, int cure_num ):Player(board,city), cure_num(cure_num) //cure_num is used in discover_cure
{ //cure_num is the argument passed in the constrution of the Scientist that deteremines how many cards are needed for discover_cure.
}
Player &Scientist::discover_cure(Color color) //same as player but changes the amount of cards needed.. 
{ //in second thought I could've made a methods that checks for eligibility and override that instead of overriding the entire function.. will fix later
    if (cure_num == 0 && board.have_research(location))
    {
        board.add_cure(color);
        return *this;
    }
    int count = 0;
    vector<City> cure_cards;
    bool card_flag = false;
    
    for(City card : cards)
    {
        if(Board::get_color(card) == color)
        {
            cure_cards.push_back(card);
            count +=1;
            if (count == cure_num)
            {
                card_flag = true;
                break;
            }
        }
    }

    if(!(board.have_research(location) && card_flag))
    {
        throw invalid_argument("This city must have a Research Station and you must have enough cards of the disease's color");
    }
    
    
    board.add_cure(color);
    for(City card : cure_cards)
    {
        cards.erase(card);
    }

     return *this;
}

std::string Scientist::role()
{
    return "Scientist";
}
void Scientist::displayAbillity() 
{
    std::cout<<"As a " << role() << " you can Discover Cure with less than 5 cards, refer to instructions for how much (Default 4).\n" << std::endl;
}

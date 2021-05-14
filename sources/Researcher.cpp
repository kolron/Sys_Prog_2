#include "Researcher.hpp"
#include <vector>
using namespace std;
using namespace pandemic;

Researcher::Researcher(Board& board, City city):Player(board,city)
            {

            }
Player &Researcher::discover_cure(Color color)
{
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

    if(!(card_flag))
    {
       throw invalid_argument("You must have 5 cards of the disease's color");
    }
    
    
    board.add_cure(color);
    for(City card : cure_cards)
    {
            cards.erase(card);
    }
    
    return *this;
}
string Researcher::role()
{
    return "Researcher";
}

void Researcher::displayAbillity() 
{
    std::cout<<"As a "<< role()<< " you can Discover Cure in any city, not just those with a Research Station.\n" << std::endl;
}



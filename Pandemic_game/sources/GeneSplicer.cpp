
#include "GeneSplicer.hpp"
#include <exception>
#include<vector>
using namespace pandemic;
using namespace std;

GeneSplicer::GeneSplicer(Board& board, City city):Player(board,city)
{

}

Player &GeneSplicer::discover_cure(Color color) //applying rule..
{
    int count = 0;
    vector<City> cure_cards;
    bool card_flag = false;
    for(City card : cards)
    {
            cure_cards.push_back(card);
            count +=1;
            if (count == NUM_OF_CARDS_FOR_DISCOVER)
            {
                card_flag = true;
                break;
            }
    }
    if(!(board.have_research(location) && card_flag))
    {
        throw invalid_argument("This city must have a Research Station and you must have 5 cards" );
    }
    
    
    board.add_cure(color);
    for(City card : cure_cards)
    {
       cards.erase(card);
    }
    
     return *this;
}
string GeneSplicer::role()
{
    return "GeneSplicer";
}

void GeneSplicer::displayAbillity() 
{
    cout<<"As a "<< role()<< " you can Discover Cure with any 5 cards, not just those that match the disease's color.\n" << endl;
}
#include "Researcher.hpp"
#include <vector>
using namespace std;
using namespace pandemic;


Player &Researcher::discover_cure(Color color)
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

    if(!(card_flag))
    {
        cout << "You must have 5 cards of the disease's color" << endl;
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



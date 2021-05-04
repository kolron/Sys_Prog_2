
#include "Scientist.hpp"
#include <vector>
using namespace pandemic;
using namespace std;

Player &Scientist::discover_cure(Color color)
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
            if (count == cure_num)
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

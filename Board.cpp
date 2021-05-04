#include "Board.hpp"
#include "fstream"
#include <algorithm>
using namespace std;
using namespace pandemic;

namespace pandemic{
Board::Board()
{
    string filename = "cities_map.txt";
    ifstream file{filename};
    while(!file.eof())
    {
        string name;
        string color; 
        string nei;
        file>>name;
        City city = cities.find(name)->second;
        infection_lvl[city] = 0;
        file >> color;
        city_color[city] = color_tr.find(color) -> second;
        while (file.peek() != '\n' && !file.eof()) 
        {
        file >> nei;
        connections[city].insert(cities.find(nei)->second);
        }   
    }
}


ostream &operator<<(ostream &os, Board &board)
{
    for (auto city : board.infection_lvl)
    {
        string name =find_if(begin(board.cities), end(board.cities), [&](const auto &element)
                    { return element.second == city.first; } )->first;
        os << name << "... Infection level: " << city.second;
        if(board.have_research(city.first))
        { 
            os << " ... Has a Research Station";
        }
        else
        {
            os << " ... No Research Station";
        }
        os << endl;
    }
    for(auto cure:board.cures)
    {
          string name =find_if(begin(color_tr), end(color_tr), [&](const auto &element)
                    { return element.second == cure; } )->first;
        os << name << endl;
    }
    return os;
}

unsigned int & Board::operator[](City city)
{
    return infection_lvl[city];
}

bool Board::is_connected(City src, City dest)
{
    auto _src = connections.find(src) -> second;
    return _src.find(dest) != _src.end();
}

bool Board::is_clean()
{
    for (auto element : infection_lvl)
    {
        if (element.second != 0)
        {
            return false;
        }
    }
    return true;
}

void Board::add_research(City city)
{
    research_stations.insert(city);
}

bool Board::have_research(City city)
{
    auto station = research_stations.find(city);
    return station != research_stations.end();
    
}

Color Board::get_color(City city)
{
	return city_color.find(city) -> second;
}

void Board::add_cure(Color color)
{
    cures.insert(color);
}

bool Board::have_cure(Color color)
{
    auto cure = cures.find(color); 
    return cure != cures.end();
    
}

void Board::remove_cures()
{
    for(auto cure : cures)
    {
        cures.erase(cure);
    }
}
};
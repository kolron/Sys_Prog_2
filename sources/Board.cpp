#include "Board.hpp"
#include "fstream"
#include <algorithm>
#include <iostream>
using namespace std;
using namespace pandemic;

namespace pandemic{
    std::unordered_map<City, std::unordered_set<City>> Board::connections;
    std::unordered_map<City,Color> Board::city_color;
  
	std::unordered_map<std::string,City> Board::cities =
	{
    {"Algiers", City::Algiers},
    {"Atlanta", City::Atlanta},
    {"Baghdad", City::Baghdad},
    {"Bangkok", City::Bangkok},
    {"Beijing", City::Beijing},
    {"Bogota", City::Bogota},
    {"BuenosAires", City::BuenosAires},
    {"Cairo", City::Cairo},
    {"Chennai", City::Chennai},
    {"Chicago", City::Chicago},
    {"Delhi", City::Delhi},
    {"Essen", City::Essen},
    {"HoChiMinhCity", City::HoChiMinhCity},
    {"HongKong", City::HongKong},
    {"Istanbul", City::Istanbul},
    {"Jakarta", City::Jakarta},
    {"Johannesburg", City::Johannesburg},
    {"Karachi", City::Karachi},
    {"Khartoum", City::Khartoum},
    {"Kinshasa", City::Kinshasa},
    {"Kolkata", City::Kolkata},
    {"Lagos", City::Lagos},
    {"Lima", City::Lima},
    {"London", City::London},
    {"LosAngeles", City::LosAngeles},
    {"Madrid", City::Madrid},
    {"Manila", City::Manila},
    {"MexicoCity", City::MexicoCity},
    {"Miami", City::Miami},
    {"Milan", City::Milan},
    {"Montreal", City::Montreal},
    {"Moscow", City::Moscow},
    {"Mumbai", City::Mumbai},
    {"NewYork", City::NewYork},
    {"Osaka", City::Osaka},
    {"Paris", City::Paris},
    {"Riyadh", City::Riyadh},
    {"SanFrancisco", City::SanFrancisco},
    {"Santiago", City::Santiago},
    {"SaoPaulo", City::SaoPaulo},
    {"Seoul", City::Seoul},
    {"Shanghai", City::Shanghai},
    {"StPetersburg", City::StPetersburg},
    {"Sydney", City::Sydney},
    {"Taipei", City::Taipei},
    {"Tehran", City::Tehran},
    {"Tokyo", City::Tokyo},
    {"Washington", City::Washington},
    };

Board::Board()
{
   

    string filename = "cities_map.txt";
    ifstream file{"cities_map.txt"};
    while(!file.eof())
    {
        string name; 
        string color;  
        string nei; 
        file >> name; 
        if (name.empty())
        {break;}
        City city = cities[name]; 
        infection_lvl[city] = 0;
        file >> color;
        city_color[city] = color_tr.find(color) -> second;
        while (file.peek() != '\n' && !file.eof())
        {
        file >> nei;
        (connections[city]).insert(cities[nei]);
        }   
    }
    file.close();
   
}




ostream &operator<<(ostream &os, Board &board)
{
    for (auto city : board.infection_lvl)
    {
        string name = Board::ctos(city.first);

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
        string name = Board::clrtos(cure);
        os << name << endl;
    }
    return os;
}

 int & Board::operator[](City city)
{
    return infection_lvl[city];
}

bool Board::is_connected(City src, City dest) 
{

    auto _src = connections.find(src)->second; //find city SRC in board's conbnections. retrieve it's sub-hashmap of connections
    return _src.find(dest) != _src.end();  // now in the sub-hasmap look if you can't find the destination.
}
void Board::show_connections(City city)
{
    cout << Board::ctos(city);
    for (City dest : Board::connections[city])
    {
        cout << "----->" << Board::ctos(dest);
    }
    cout << endl;
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
   
    return research_stations.find(city) != research_stations.end(); //in the map of research stations look for the city.
    
}

Color Board::get_color(City city)
{
	return city_color.find(city) -> second;
}

void Board::add_cure(Color color)
{
    cures.insert(color);
}

bool Board::have_cure(Color color) const
{

    return cures.find(color) != cures.end();
    
}

void Board::remove_cures()
{
   
        cures.clear();
 }

string Board::ctos(City city)
 {
     return find_if(begin(Board::cities), end(Board::cities), [&](auto &element){ return element.second == city;}) -> first;
 }
string Board::clrtos(Color color)
{
     return find_if(begin(color_tr), end(color_tr), [&](auto &element){ return element.second == color;}) -> first;
}


};
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
    ifstream file{filename}; //TODO: add filename to constructor - not hardcoded but with default
    while(!file.eof())
    { //board constructor 
        string name; 
        string color;  
        string nei; 
        file >> name; 
        City city = cities[name]; //assign number from city's enum class where the strings match
        infection_lvl[city] = 0; //set infection to 0
        file >> color;
        city_color[city] = color_tr.find(color) -> second; //assign color like we did in city map. // can also do color_tr[city] // altough remember having an issue
        while (file.peek() != '\n' && !file.eof()) //according to the map, \n means we finished reading connections.
        {
        file >> nei;
        (connections[city]).insert(cities[nei]); //add neighbor
        }   
    }
    file.close();
   
}




ostream &operator<<(ostream &os, Board &board)
{
    for (auto city : board.infection_lvl) //first loop prints the city's name, infection level and research station status
    {
        string name = Board::ctos(city.first); //translate city name

        os << name << "... Infection level: " << city.second; //reminder: city is taken from infection level map .second is infection level
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
    for(auto cure:board.cures) // second for prints city's color
    {
        string name = Board::clrtos(cure); 
        os << name << endl;
    }
    return os;
}

 int & Board::operator[](City city) //according to readme.
{
    return infection_lvl[city];
}

bool Board::is_connected(City src, City dest) 
{

    auto _src = connections.find(src)->second; //find city SRC in board's conbnections. retrieve it's sub-hashmap of connections
    return _src.find(dest) != _src.end();  // now in the sub-hasmap look if you can't find the destination.
}
void Board::show_connections(City city) // used in demo
{
    cout << Board::ctos(city); // translate city's name.
    for (City dest : Board::connections[city]) // prints connected cities by translating names from connections map
    {
        cout << "----->" << Board::ctos(dest);
    }
    cout << endl;
}
bool Board::is_clean() //simply checks in infection_level map for != 0
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
    research_stations.insert(city); //insert the City to the research_stations map to represent we built a station there
}

bool Board::have_research(City city) 
{
   
    return research_stations.find(city) != research_stations.end(); //in the map of research stations look for the city, return true if it is found 
                                                                    //(!= end())
    
}

Color Board::get_color(City city)
{
	return city_color.find(city) -> second; //finds the color of the city from the city_color map
}

void Board::add_cure(Color color)
{
    cures.insert(color); //insert color to the cures map to represent we found a cure to the disease of that color.
}

bool Board::have_cure(Color color) const //checks if found we found a cure to Color
{

    return cures.find(color) != cures.end();
    
}

void Board::remove_cures() //for tests
{
   
        cures.clear();
 }



//most interseting functions below..

//using find_if to translate from the enum city class to string, using the cities map as a median. lambda function idea came from
// https://stackoverflow.com/questions/8054147/stdmap-find-if-condition-style-confusion from Unkle George's comment.

string Board::ctos(City city) //ctos = city to string
 { 
     return find_if(begin(Board::cities), end(Board::cities), [&](auto &element){ return element.second == city;}) -> first;
 }

 //exactly the same as above, but using the Color enum class and the color_tr as the median.

string Board::clrtos(Color color) //clrtos = color to string (not the most intuitive naming but both start with the letter c  :-/  )
{
     return find_if(begin(color_tr), end(color_tr), [&](auto &element){ return element.second == color;}) -> first;
}

};
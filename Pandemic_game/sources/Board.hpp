#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "Color.hpp"
#include "City.hpp"
namespace pandemic
{
	class Board
	{
		public:
				//all the methods the player and the demo may call
		Board();
		friend std::ostream &operator<<(std::ostream &os, Board &board); //prints board
		int &operator[](City city); //returns infection level

		bool have_cure(Color color)const; 
		void add_cure(Color color);
		bool is_clean(); //checks for diseases on the board

		void add_research(City city);
		bool have_research(City city) ;

		static bool is_connected(City src,City dest) ; //checks if src is a neightbor (is connected) to dest
		static Color get_color(City city); //returns the city's color
		void remove_cures(); // for tests
	   	static std::string ctos(City city); //translates from city to string
		static std::string clrtos(Color color); // ---- from color to string
	   	static void show_connections(City city); //returns all connections of a city
		
		private:
		// wouldn't want the players to cheat and have the option to change the maps unchecked.
		static std::unordered_map<City, std::unordered_set<City>> connections; //A map that holds a set for each city representing the connections
		static std::unordered_map<City,Color> city_color; // map that holds each city's color
		static std::unordered_map<std::string,City> cities; // map that helps read and construct board, and in translation from City enum to string.(and vice versa)
		std::unordered_set<City> research_stations; //set that holds cities that have a research station
		std::unordered_map<City, int> infection_lvl; //represents the city's infection level.. would've went for unsigned int but tests don't allow
	    std::unordered_set<Color> cures; //set that holds the each color we found a cure for.
			
	};

};

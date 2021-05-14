#pragma once
#include <iostream>
#include <array>
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

		Board();
		friend std::ostream &operator<<(std::ostream &os, Board &board);
		int &operator[](City city);
		bool have_cure(Color color)const;
		void add_cure(Color color);
		bool is_clean();
		void add_research(City city);
		bool have_research(City city) ;
		static bool is_connected(City src,City dest) ;
		static Color get_color(City city);
		void remove_cures();
	   	static std::string ctos(City city);
		static std::string clrtos(Color color);
	   	static void show_connections(City city);
		
    
		static std::unordered_map<City, std::unordered_set<City>> connections;
		static std::unordered_map<City,Color> city_color;
		static std::unordered_map<std::string,City> cities;
		std::unordered_set<City> research_stations;
		std::unordered_map<City, int> infection_lvl;
	    std::unordered_set<Color> cures;
			


	};

};

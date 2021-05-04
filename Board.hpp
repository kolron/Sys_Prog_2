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
		unsigned int &operator[](City);
		bool have_cure(Color color);
		void add_cure(Color color);
		bool is_clean();
		void add_research(City city);
		bool have_research(City city);
		bool is_connected(City src,City dest);
		Color get_color(City city);
		void remove_cures();
		
		




		private:

			
	 	    const std::unordered_map<std::string,City> cities =
			{
            	{"Algiers",City::Algiers},
            	{"Atlanta",City::Atlanta},
            	{"Baghdad",City::Baghdad},
            	{"Bangkok",City::Bangkok},
            	{"Beijing",City::Beijing},
            	{"Bogota",City::Bogota},
            	{"BuenosAires",City::BuenosAires},
            	{"Cairo",City::Cairo},
            	{"Chennai",City::Chennai},
            	{"Chicago",City::Chicago},
            	{"Delhi",City::Delhi},
            	{"Essen",City::Essen},
            	{"HoChiMinhCity",City::HoChiMinhCity},
            	{"HongKong",City::HongKong},
            	{"Istanbul",City::Istanbul},
            	{"Jakarta",City::Jakarta},
            	{"Johannesburg",City::Johannesburg},
            	{"Karachi",City::Karachi},
            	{"Khartoum",City::Khartoum},
            	{"Kinshasa",City::Kinshasa},
            	{"Kolkata",City::Kolkata},
            	{"Lagos",City::Lagos},
            	{"Lima",City::Lima},
            	{"London",City::London},
            	{"LosAngeles",City::LosAngeles},
            	{"Madrid",City::Madrid},
            	{"Manila",City::Manila},
            	{"MexicoCity",City::MexicoCity},
            	{"Miami",City::Miami},
            	{"Milan",City::Milan},
            	{"Montreal",City::Montreal},
            	{"Moscow",City::Moscow},
            	{"Mumbai",City::Mumbai},
            	{"NewYork",City::NewYork},
            	{"Osaka",City::Osaka},
            	{"Paris",City::Paris},
            	{"Riyadh",City::Riyadh},
            	{"SanFrancisco",City::SanFrancisco},
            	{"Santiago",City::Santiago},
            	{"SaoPaulo",City::SaoPaulo},
            	{"Seoul",City::Seoul},
            	{"Shanghai",City::Shanghai},
            	{"StPetersburg",City::StPetersburg},
            	{"Sydney",City::Sydney},
            	{"Taipei",City::Taipei},
            	{"Tehran",City::Tehran},
            	{"Tokyo",City::Tokyo},
            	{"Washington",City::Washington},
        	};
			std::unordered_set<City> research_stations;
        	std::unordered_set<Color> cures;
			std::unordered_map<City, std::unordered_set<City>> connections;
			std::unordered_map<City,Color> city_color;
			std::unordered_map<City, unsigned int> infection_lvl;
			


	};

};

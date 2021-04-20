#include <string>
#include <fstream>
#include <ostream>
#include <unordered_map>

#pragma once

namespace ariel
{
    class NumberWithUnits
    {
        private:
            std::string type; // km, miles, kg..                                                            
            double value;                                                                                           
            static std::unordered_map<std::string, std::unordered_map<std::string, double>> conversion_table; //FILLED VIA read_units()
           
            bool checkMatch(const NumberWithUnits &other) const;    //(X)                                                    
            double convertType(const std::string &newType) const;   //(X)
           

        public:
            static const std::unordered_map<std::string, std::unordered_map<std::string, double>> getTable();
            NumberWithUnits(double v, std::string t)
            {
            if(conversion_table.find(t) == conversion_table.end())
            {
                throw std::invalid_argument("No such type");
            }  
            this->type=t;
            this->value=v;} 
            //constructor //(X)
            static void read_units(std::ifstream &file); //instruction reader. //(X)
            double getValue(); //(X)
            std::string getType();//(X)


            //OPERATOR OVERLOAD
            //PLUS(+) OPERATORS
            NumberWithUnits operator+(const NumberWithUnits &other) const;//(X)
            NumberWithUnits &operator+=(const NumberWithUnits &other);//(X)
            NumberWithUnits operator+() const;//(X)
            NumberWithUnits &operator++();//(X)
            NumberWithUnits operator++(int);//(X)
            //MINUS(-) OPERATORS
            NumberWithUnits operator-(const NumberWithUnits &other) const;//(X)
            NumberWithUnits &operator-=(const NumberWithUnits &other);//(X)
            NumberWithUnits operator-();//(X)
            NumberWithUnits &operator--();//(X)
            NumberWithUnits operator--(int);//(X)

            //BOOL OPERATORS
            bool operator<(const NumberWithUnits &other) const;  //(X)
            bool operator<=(const NumberWithUnits &other) const; //(X)
            bool operator>(const NumberWithUnits &other) const;  //(X)
            bool operator>=(const NumberWithUnits &other) const; //(X)
            bool operator==(const NumberWithUnits &other) const; //(X)
            bool operator!=(const NumberWithUnits &other) const; //(X)
    
            
            //MULTIPLY(*)
            friend  NumberWithUnits operator*(const NumberWithUnits &other, double factor);//(X)
            friend  NumberWithUnits operator*(double factor, const NumberWithUnits &other);//(X)

            

            //OSTREAM AND ISTREAM
            friend std::ostream &operator<<(std::ostream &os, const NumberWithUnits &out);
          //  friend std::istream &operator>>(std::istream &is, const NumberWithUnits &in);

            
    };
};

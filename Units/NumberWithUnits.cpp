
#include "NumberWithUnits.hpp"
#include<iostream>
using namespace std;
using namespace ariel;  


namespace ariel{
std::unordered_map<std::string, std::unordered_map<std::string, double>> NumberWithUnits::conversion_table; //this nested map will hold conversion rates. will be filled via read_units



void NumberWithUnits::fillTable(const string&base, const string&rate)
{
    double weight;
  
    for(auto element : conversion_table[rate])
    {            
        if(element.first != base)
        {
            weight = conversion_table[base][rate] * element.second;
            conversion_table[base][element.first] = weight;
            conversion_table[element.first][base] = (double)(1/weight);
        }
    }
}

void NumberWithUnits::read_units(ifstream &file)
{  //EXAMPLE :: 1 km = 1000 m
    string base,rate,junk;
    double gate;
    int i = 0 ;
//file.txt-> '1'->  'km' -> '='  -> '1000' ->'m'
    while(!file.eof())
    {    
        file >> junk >> base >> junk >> gate >> rate;                 
        conversion_table[base][rate] = gate;
        conversion_table[rate][base] = (double)(1/gate);
        fillTable(base,rate);
        fillTable(rate,base);
    }
}

double NumberWithUnits::convertType(const string &target_type) const
{
    if (type != target_type)
    {
        return value * conversion_table[type][target_type];
    }
    return value;
}

bool NumberWithUnits::checkMatch(const NumberWithUnits &other) const
{
   return (type == other.type || (conversion_table[type].find(other.type) != conversion_table[type].end()));
}

string NumberWithUnits::getType()
{
    return type;
}
 
double NumberWithUnits::getValue()
{
    return value;
}

NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits &other) const
{
    if (!checkMatch(other))
    {
        throw invalid_argument("Incompatible unit type.");
    }
    return NumberWithUnits(value + other.convertType(type), type);

}

NumberWithUnits &NumberWithUnits::operator+=(const NumberWithUnits &other)
{
    if (!checkMatch(other))
    {
        throw invalid_argument("Incompatible unit type.");
    }
    value += other.convertType(type);
    return *this;
}

NumberWithUnits NumberWithUnits::operator+() const
{
    return NumberWithUnits(value,type);
}

NumberWithUnits &NumberWithUnits::operator++()
{
    value++;
    return *this;
}
NumberWithUnits NumberWithUnits::operator++(int)
{
    return NumberWithUnits(value++, type);
}

NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits &other) const
{
    if (!checkMatch(other))
    {
        throw invalid_argument("Incompatible unit type.");
    }
    return NumberWithUnits(value - other.convertType(type), type);

}

NumberWithUnits &NumberWithUnits::operator-=(const NumberWithUnits &other)
{
    if (!checkMatch(other))
    {
        throw invalid_argument("Incompatible unit type.");
    }
    value -= other.convertType(type);
    return *this;
}


NumberWithUnits NumberWithUnits::operator-()
{
    return NumberWithUnits(-value,type);
}

NumberWithUnits &NumberWithUnits::operator--()
{
    value--;
    return *this;
}

NumberWithUnits NumberWithUnits::operator--(int)
{
    return NumberWithUnits(value--, type);
}

NumberWithUnits operator*(const NumberWithUnits &other, double num)
{
    return NumberWithUnits(num * other.value, other.type);
}

NumberWithUnits operator*( double num ,const NumberWithUnits &other)
{
    return NumberWithUnits(num * other.value, other.type);
}


 bool NumberWithUnits::operator<(const NumberWithUnits &other) const
 {
     if (!checkMatch(other))
    {
        throw invalid_argument("Incompatible unit type.");
    }
    return (value < (other.convertType(type)));
 }

 bool NumberWithUnits::operator<=(const NumberWithUnits &other) const
 {
     if (!checkMatch(other))
    {
        throw invalid_argument("Incompatible unit type.");
    }
    return (value <= (other.convertType(type)));
 }

 bool NumberWithUnits::operator>(const NumberWithUnits &other) const
 {
     if (!checkMatch(other))
    {
        throw invalid_argument("Incompatible unit type.");
    }
    return (value > (other.convertType(type)));
 }

 bool NumberWithUnits::operator>=(const NumberWithUnits &other) const
 {
     if (!checkMatch(other))
    {
        throw invalid_argument("Incompatible unit type.");
    }
    return (value >= (other.convertType(type)));
 }

  bool NumberWithUnits::operator==(const NumberWithUnits &other) const
 {
     if (!checkMatch(other))
    {
        throw invalid_argument("Incompatible unit type.");
    }   
    return (value == (other.convertType(type)));
 }

bool NumberWithUnits::operator!=(const NumberWithUnits &other) const
 {
     if (!checkMatch(other))
    {
        throw invalid_argument("Incompatible unit type.");
    }
    return (value != (other.convertType(type)));
 }

ostream &operator<<(ostream &os, const NumberWithUnits &num)
{
  return (os << num.value << "[" << num.type << "]");

}
istream &operator>>(std::istream &is, NumberWithUnits &other)
{
    string unit_type;
    is >> other.value;
    if (is.fail())
    {
        throw invalid_argument("Not a valid input, please enter a double.");
    }
    
    getline(is, unit_type, ']');

    bool valid_format = unit_type[0] == '[';
    if (!valid_format)
    {
        throw invalid_argument("invalid input");
    }
    unit_type = unit_type.substr(1, unit_type.size() - 1);
    if (NumberWithUnits::conversion_table.find(unit_type) == NumberWithUnits::conversion_table.end())
    {
        throw invalid_argument(unit_type + " is an invalid type");
    }
    other.type = unit_type;

    return is;
}
const unordered_map<std::string, std::unordered_map<std::string, double>> NumberWithUnits::getTable()
{
    return conversion_table;
}

};

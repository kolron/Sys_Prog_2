
#include "NumberWithUnits.hpp"
using namespace std;
using namespace ariel;  


namespace ariel{
std::unordered_map<std::string, std::unordered_map<std::string, double>> NumberWithUnits::conversion_table; //this nested map will hold conversion rates. will be filled via read_units


void NumberWithUnits::read_units(std::ifstream &file)
{  //EXAMPLE :: 1 km = 1000 m
    string base,rate,junk;
    float gate;
//file.txt-> '1'->  'km' -> '='  -> '1000' ->'m'
    file >> junk >> base >> junk >> gate >> rate;

    while(!(file.eof()))
    {                     
        conversion_table[base][rate] = gate;
        conversion_table[rate][base] = (float)1/gate;
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
const unordered_map<std::string, std::unordered_map<std::string, double>> NumberWithUnits::getTable()
{
    return conversion_table;
}

};

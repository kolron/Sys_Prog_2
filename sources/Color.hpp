#pragma once
namespace pandemic
{
    enum class Color
    {
        Blue,
        Yellow,
        Black,
        Red,
    };

     const std::unordered_map<std::string,Color> color_tr = 
     {
            {"Blue",Color::Blue},
            {"Yellow",Color::Yellow},
            {"Black",Color::Black},
            {"Red",Color::Red},
            
        };
};
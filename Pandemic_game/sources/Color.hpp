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

     const std::unordered_map<std::string,Color> color_tr = //color tr = color translate
     {
            {"Blue",Color::Blue},
            {"Yellow",Color::Yellow},
            {"Black",Color::Black},
            {"Red",Color::Red},
            
        };
};
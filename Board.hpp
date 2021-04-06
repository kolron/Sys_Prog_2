#include<string>
#include<vector>
#include"Direction.hpp"
#pragma once
namespace ariel
{
    class Board
    {
        private:
            std::vector<std::vector<char>> board;
            void fitSize(unsigned int row, unsigned int col, unsigned int len, Direction direction);
            unsigned int firstRow;
            unsigned int rowEdge;
            unsigned int firstCol;
            unsigned int colEdge;
        
        public:
            Board();
            void show();
            void post(unsigned int row, unsigned int col, ariel::Direction direction, std::string msg);
            std::string read(unsigned int row, unsigned int col, Direction direction, unsigned int len);
             unsigned int  rec_row();
             unsigned int  rec_col();
            static char check_direction(char c);

    };
}

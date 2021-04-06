#include"Board.hpp"
#include<string>
#include<vector>
#include<stdexcept>
#include<iostream>
#include<bits/stdc++.h>


using namespace std;
namespace ariel
{   
    
    bool flag_written = false;
    const int required_2_spaces = 100;
    const int starting_size = 0;

    Board::Board()
    {
        flag_written = true;
        firstRow=firstCol = UINT_MAX;
        rowEdge = colEdge = starting_size;

        board=vector<vector<char>>(rowEdge, vector<char>(colEdge, '_'));
    }
  
    void Board::post(unsigned int row, unsigned int col, Direction direction, string msg)
    {
      
        unsigned int msglen = msg.length();
        bool flag_maxSize = false;
        //update first row for board.show only
        firstRow = min(firstRow, row);
        firstCol = min(firstCol, col);
        //make sure board size fits
        fitSize(row, col, msglen, direction);
       
        for( size_t i = 0; i<msglen; i++)
        {
            //handle a board that is past max size()
            if (direction == Direction::Horizontal)
            {
                if (col+1 > (UINT_MAX))
                {
                   flag_maxSize = true;
                }
            }
            else // if vertical
            {
                if (row+1> (UINT_MAX))
                {
                    flag_maxSize = true;
                }
            }

          
            board[row][col] = msg.at(i);
            
            
            if(flag_maxSize)
            {
                break;
            }
            
            if (direction == Direction::Horizontal)
            {  
                col++; 
            }
            else
            {
                row++;
            }
           
        }
    }


     unsigned int Board:: rec_row()
    {
        if (rowEdge < UINT_MAX)
        {   
          return rowEdge;
        }
         return 0; 
        
    }
      unsigned int Board::rec_col()
    {
        if (colEdge < UINT_MAX)
        {   
          return colEdge;
        }
         return 0; 
    }

    string Board::read(unsigned int row, unsigned int col, Direction direction, unsigned int len)
    {
        string text;
        for (size_t i = 0; i < len; i++)
        {
            //If user is trying to read from a place that doesnt exist print "_"
            if (row >= rowEdge || col >= colEdge) 
            {
                text += '_';
            }
            //else if the place does exist print that messege in it
            else
            {
                text += board[row][col];
            }

            if (direction == Direction::Horizontal)
            {
                col++;
            }
            else
            {
                row++;
            }
        }
    
    return text;
    }   


    void Board::show()
    {
        if(flag_written)
        {
            unsigned int actualHeight = rowEdge - firstRow+1;
            unsigned int actualWidth = colEdge - firstCol+1; 
            unsigned int rowNum = firstRow;
            for (unsigned int i = 0; i < actualHeight; i++)
            {
           
                cout <<"|"<<read(firstRow-(unsigned int)1+i, firstCol, Direction::Horizontal, actualWidth) << "|" << ":" << rowNum <<  endl;
                rowNum++;
         
            }
        }
        else
        {
            cout << "\n|__Nothing has been posted yet__|" << endl;
        } 
    }

    void Board::fitSize(unsigned int row, unsigned int col, unsigned int len, Direction direction)
    {
        if (direction == Direction::Horizontal)
        {
            colEdge = max(colEdge,col+len);
           rowEdge = max(rowEdge, row+1 ); //+1 IS NEEDED BECAUSE OTHERWISE RESIZE THROWS SEG FAULT
        }    
        else
        {
            rowEdge = max(rowEdge, row+len);
           colEdge = max(colEdge, col+1);
        }
        board.resize(rowEdge);
        for (size_t i = 0; i < rowEdge; i++)
        {
            board[i].resize(colEdge, '_');
        }
    }

     char Board::check_direction(char c)
    {
        if (c == 'v' || c == 'h' || c == 'V' || c == 'H' || c == 'e' || c == 'E')
        {
            return c;
        }
        return 0;
    }


}

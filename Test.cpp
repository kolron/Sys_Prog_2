#include "Board.hpp"
#include "Direction.hpp"
#include "doctest.h"
#include <algorithm>
using namespace std;
using ariel::Direction;

ariel::Board board;

//testing if posting doesn't fail the program
TEST_CASE("Posting all")
{
    unsigned int t =0 ;
    for(int i = 32; i < 254; i++)
    {
        
        
        board.post((unsigned int) (i/40)%10, (unsigned int)(i-32)%40, Direction::Horizontal,std::string(1,(char)i));
        CHECK(board.read((unsigned int)i/40,(unsigned int)(i-32)%40,Direction::Horizontal,1) == std::string(1,(char)i));
       
    } 
   
}

ariel::Board board2;
TEST_CASE("Posting & Reading Horizontal")
{
    board2.post(50,50,Direction::Horizontal, "abcd");
    
    CHECK(board2.read(50,50,Direction::Horizontal, 4) == "abcd"); //regular
    CHECK(board2.read(50,50,Direction::Horizontal, 5) == "abcd_");//reading 1 forward
    CHECK(board2.read(50,49,Direction::Horizontal, 5) == "_abcd"); //reading 1 backwards
    CHECK(board2.read(50,49,Direction::Horizontal, 6) == "_abcd_"); //both
    
    board2.post(0,0,Direction::Horizontal, "1");//posting and reading a digit
    CHECK(board2.read(0,0,Direction::Horizontal, 1) == "1");

    CHECK(board2.read(30,27, Direction::Horizontal, 4) == "____");//posting and reading from an empty space
    CHECK(board2.read(1,1,Direction::Horizontal, 1) == "_");
    CHECK(board2.read(102,100,Direction::Horizontal, 3) == "___");
}

 ariel::Board board3;

 TEST_CASE("Posting & Reading Vertical")
{
    board3.post(50,50,Direction::Horizontal, "abcd");
    CHECK(board3.read(50,50,Direction::Horizontal, 4) == "abcd"); //regular
    CHECK(board3.read(50,50,Direction::Horizontal, 5) == "abcd_");//reading 1 forward
    CHECK(board3.read(50,49,Direction::Horizontal, 5) == "_abcd"); //reading 1 backwards
    CHECK(board3.read(50,49,Direction::Horizontal, 6) == "_abcd_"); //both
    board3.post(0,0,Direction::Horizontal, "1");//posting and reading a digit
    CHECK(board3.read(0,0,Direction::Horizontal, 1) == "1");
    CHECK(board3.read(30,27, Direction::Horizontal, 4) == "____");//posting and reading from an empty space
    CHECK(board3.read(1,1,Direction::Horizontal, 1) == "_");
    CHECK(board3.read(102,100,Direction::Horizontal, 3) == "___");
}



ariel::Board board4;

TEST_CASE("Overwriting")
{
    board4.post(100,100,Direction::Horizontal, "abcd");
    board4.post(100,101,Direction::Horizontal,"abcd");
    CHECK(board4.read(100,100,Direction::Horizontal, 6) == "aabcd_");

    board4.post(99,100,Direction::Vertical,"abcd");
    CHECK(board4.read(100,100,Direction::Horizontal, 6) == "babcd_");

    board4.post(100,102,Direction::Horizontal,"cdba");
   
    CHECK(board4.read(100,100,Direction::Horizontal, 6) == "bacdba");
    board4.post(100,101,Direction::Vertical,"abcd");

   CHECK(board4.read(101,100,Direction::Horizontal, 4) == "cb__");
    
    board4.post(98,102,Direction::Vertical,"ABCD");
    CHECK(board4.read(98,102,Direction::Vertical, 6) == "ABCD__");
    
    board4.post(97,104,Direction::Vertical,"abcd");
  

 }

// ariel::Board board5;

// TEST_CASE("Bad posting")
// {
//      board5.post(50,50,Direction::Horizontal, "abcd");
//     CHECK(board5.read(50,50,Direction::Horizontal, 6) == "abcd__ ");
//     CHECK(board5.read(50,50,Direction::Horizontal, 6) == "abcd__");
//     CHECK(board5.read(50,50,Direction::Horizontal, 6) == "abcd__");
// }

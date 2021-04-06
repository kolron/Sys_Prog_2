/**
 * Demo program for message-board exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-03
 */

#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;




int main() {

	string msg;
	char flag_direct = '0';
	Direction D;
	unsigned int row;
	unsigned int col;
	ariel::Board board;
	ariel::Board board2;
	board.post(/*row=*/100, /*column=*/200, Direction::Horizontal, "abcd");
 	board.post(/*row=*/99, /*column=*/202,  Direction::Vertical, "xyz");
	board.post(/*row=*/103, /*column=*/204, Direction::Horizontal, "Vaccine is poison!");
 	board.post(/*row=*/102, /*column=*/207, Direction::Vertical, "Dont Go Vote!");
	board.post(/*row=*/102, /*column=*/205, Direction::Horizontal, "blalbablablabla!");
	board.post(/*row=*/100, /*column=*/180, Direction::Vertical, "I like Pizza!");
 	board.post(/*row=*/104, /*column=*/210, Direction::Horizontal, "This is board is full of nonsense! go post at a new, improved, CLEAN board at board2");

	board.show();
	
	while (msg != "exit" && flag_direct != 'e')
	{
		/*Entering a message*/
		cout<< "Enter your message: " << endl;
		getline(cin >>ws,  msg);
		if(msg == (string)"exit")
		{
			return 0;
		}
		
		/* Getting direction*/
		cout << "In what Direction do you want to post? H/V" << endl;
		cin >> flag_direct; //get direction
		flag_direct = board.check_direction(flag_direct); //checks if direction is valod
		while(!flag_direct) // if its not valid prompt again
		{
			cout << "Please enter a valid direction v/V (Vertical) or h/H (Horizontal)) E to exit" << endl;
			cin >> flag_direct;
			flag_direct = board.check_direction(flag_direct);
		}
		if(flag_direct == 'h'|| flag_direct == 'H')
		{
			D = Direction::Horizontal;
		} 

		else if(flag_direct == 'e' || flag_direct == 'E')
		{
			return 0;
		}
		else
		{
			D = Direction::Vertical;
		}

		/*Recommending and getting location*/
		cout << "Enter where on the board you want to post. Recommended location is: " << board2.rec_row() << "," << board2.rec_col() << endl;
		cin >> row >> col;


		/*Posting with passed arguments*/
		board2.post(row,col,D, msg);
		char y;

		/*Asking to show*/
		cout << "Do you want to see the board? Enter y/Y if you do, anything else to continue" << endl;
		cin >>y;
		
		if (y == 'Y' || y == 'y')
		{
			board2.show();
		}
		
	}

return 0;
}


#include "Board.hpp"
#include "Dispatcher.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "OperationsExpert.hpp"
#include "Virologist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "Medic.hpp"
#include <iostream>
#include <limits>
#include <algorithm>
#include <unordered_map>
using namespace std;
using namespace pandemic;


const int NUMBER_OF_CITIES = 48;
const int MAX_INFECTION_LEVEL = 20;
const int SCIENTIST_CARD_NUM = 4;



//********************************HELPER FUNCTIONS ***********************

City randomCity() //needed for placment
{
    return (City)(rand()%NUMBER_OF_CITIES);
}

City chooseCity() //allows player to pick a city from console
{
    bool flag = true;
    cout << "Choose a destination city.\n"<<endl;
    string choice;
    while (flag)
    {
        cin >> choice;
        if (Board::cities.find(choice)!= Board::cities.end())
        {
            flag = false;
        }
        else
        {  
            cout << "Please pick a valid city.\n" << endl; 
        }
    }
    return Board::cities.find(choice) -> second;
}

Color chooseColor() //same but for color
{
    bool flag = true;
    cout << "Choose the Disease's color."<<endl;
    string choice;
    while (flag)
    {
        cin >> choice;
        if (color_tr.find(choice)!= color_tr.end())
        {
            flag = false;
        }
        else
        {
            cout << "Please pick a valid color." << endl;
        }
    }
    return color_tr.find(choice) -> second;
}
 
void showHand(Player *player) //loops through the player's cards, uses City to string (Ctos) method to print them
{
    cout << "Your hand: ";
   for (City card:player->get_cards())
   {
       cout << '|' << Board::ctos(card) << '|';
   }
   cout << endl;
}

void showLocation(Player *player)
{
    cout << "Your location: " << Board::ctos(player->get_location());
    cout << endl;
}


string showColor_Rate(Board board) //shows the color and infection rate of the city passed as an argument
{                                
    City city = chooseCity();
    string rate = to_string(board[city]);
    return Board::ctos(city)+ ": Color: " + Board::clrtos(Board::get_color(city)) + ". Infection rate: " + rate;
}
//****************************************END HELPER FUNCTIONS **********************





//**************************************** GAMEPLAY FUNCTIONS*************************



Player *selectRole(Board &board) //2 - stage 2
{ //very simple, user enters a char from 1 to 8, everything else will require to prompt again, will always take the first digit from a multi digit input
    bool flag = true;
    char choice = '0';
    cout << "Welcome to the end of the world! It's your job to save it." << endl;
    cout << "Choose your profession:" << endl;
    cout << "1 --- Operations Expert\n2 --- Dispatcher\n3 --- Scientist\n4 --- Researcher" << endl;
    cout << "5 --- Medic\n6 --- Virologist\n7 --- Gene Splicer\n8 --- Field Doctor\n" << endl;
    
    Player *player;
    while (flag)
    {
        choice = '0';
        cin >> choice;
        if(choice < '1' || choice > '8')
        {
            cout << "please enter a valid role, between 1-8." << endl;
        }
        else
        {
            switch (choice)
            {
            case '1':
                player = new OperationsExpert(board, randomCity());
                flag = false;
                break;
            case '2':
                player = new Dispatcher(board, randomCity());
                 flag = false;
                break;
            case '3':
                player = new Scientist(board, randomCity(),SCIENTIST_CARD_NUM);
                 flag = false;
                break;
            case '4':
                player = new Researcher(board, randomCity());
                 flag = false;
                break;
            case '5':
                player = new Medic(board, randomCity());
                 flag = false;
                break;
            case '6':
                player = new Virologist(board, randomCity());
                flag = false;
                break;
            case '7':
                player = new GeneSplicer(board, randomCity());
                flag = false;
                break;
            case '8':
                player = new FieldDoctor(board, randomCity());
                flag = false;
                break;
            default:
                cout << "Please choose a valid role, between 1 -8." << endl;
                break;
            }
        }
    }
    return player;
}


bool promptAction(Player *player,Board board) //3 - stage 3
{ //Very simple.. Asks user for a char as the menu shows, prompts again until input is vaild or user quits..
    
    char choice = '0'; 
    while (1) //keeps prompting after every turn
    {
    cout << "-------------------------------------------"<<endl;
    cout << "Choose what you want to do. Remember your special abilites! If you forgot, press R.\n" << endl;
    cout << "1 --- Drive\n2 --- Fly Direct\n3 --- Fly Charter\n4 --- Fly Shuttle\n5 --- Build" << endl;
    cout << "6 --- Discover Cure\n7 --- Treat\n8 --- Draw card\nB --- Show Board\nC --- Display connected cities" <<endl;
    cout<<  "i --- Check a city's Color and Infection Level\nR --- Display Role\nH/L --- Show Hand and current location\nQ --- Quit" << endl;
    cout << "-------------------------------------------"<<endl;
    cin >> choice; //keep reading input
        try
        {
            switch (choice) //3.1 - stage 3.1
            {
            case '1':
                player->drive(chooseCity());
                return true; //if returns true (or false incase of quit )then the turn ended.
                break;
            case '2':
                player->fly_direct(chooseCity());
                return true;
                break;
            case '3':
                player->fly_charter(chooseCity());
                return true;
                break;
            case '4':
                player->fly_shuttle(chooseCity());
                return true;
                break;
            case '5':
                player->build();
                return true;
                break;
            case '6':
                player->discover_cure(chooseColor());
                return true;
                break;
            case '7':
                player->treat(chooseCity());
                return true;
                break;
            case '8':
                player->take_card();
                return true;
                break;

            case 'B':
            case 'b':
                cout << board << endl; //displaying things does not end turns, everything else does.
                break;

            case 'r': // R for role (abillity display()
            case 'R':
                player -> displayAbillity(); //3.1.1 -uphold rule 3.1.1
                break;

            case 'H':  //H for hand
            case 'h': 
            case 'L': // or L for Location
            case 'l':
                showHand(player); //3.1.1
                showLocation(player);//3.1.1
                break;

            case 'c': // C for connection
            case 'C':
                Board::show_connections(player->get_location()); //3.1.1
                break;

            case 'i':
            case 'I':
            cout << showColor_Rate(board) << endl;
            break;
            case 'Q': //Q for quit..
            case 'q': //3.1.2 - upholds rule 3.1.2
                cout << "Quitting game." << endl;
                return false;
                break;

            default:
                cout << "Please choose a valid action." << endl;
                break;
            }  
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }
    }
    return true;
}
/* GAME PROGRESS: */
/*  1- create board.
    2- Create player and choose role.
        2.1- Make sure user chooses a valid role.
    3- Prompt for user action
        3.1- For UX, Let the user do all possible actions at all time without terminating turn.
            3.1.1- Allow for Displaying Board Hand Role Location and Connections (All user stats) at all time.
            3.1.2 - Allow user to quit only by entering Q or q and not by some other missclick.
*/
int main()
{
    Board board;
    for (int i = 0; i < NUMBER_OF_CITIES; i++) //1
    {
        board[(City)i] = (int)(rand()%MAX_INFECTION_LEVEL);//1
    }
 
    bool notQuit = true;
    Player *player = selectRole(board);//2
    while (promptAction(player,board))//3
    {}
    delete player;
    return 0;
}
//TODO: ADD OPTION TO DISPLAY ALL SPOTS YOU CAN MOVE TO(HARDER) WILL MOST LIKELY GIVE UP ON THIS


//LAST TO DO :: AN OPTION THAT PRINTS OUT THE COLOR OF A SPECIFIED CITY FINISHED!!
// 
//      ADD OPTION THAT PRINTS WHAT YOU DID TO THE SCREEN(EASIER) FINISHED!!
//      ADD OPTION TO DISPLAY CONNECTIONS(EASIEST)      FINISHED!! OPTIONAL ADD COLOR TO SOURCE CITY //problomatic
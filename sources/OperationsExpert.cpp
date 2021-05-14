#include "OperationsExpert.hpp"
using namespace pandemic;
using namespace std;




 OperationsExpert::OperationsExpert(Board& board, City city):Player(board,city)
{

}

Player &OperationsExpert::build()
{
        board.add_research(location);
         return *this;
}
string OperationsExpert::role()
{
    return "OperationsExpert";
}
void OperationsExpert::displayAbillity() 
{
    cout<<"As an "<< role()<< " you can Build without tossing the relavent card.\n" <<endl;
}


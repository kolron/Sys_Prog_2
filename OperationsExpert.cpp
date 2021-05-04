#include "OperationsExpert.hpp"
using namespace pandemic;
using namespace std;


Player &OperationsExpert::build()
{
        board ->add_research(location);
         return *this;
}


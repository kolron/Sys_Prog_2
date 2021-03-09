#include "doctest.h"
#include "snowman.hpp"
#include <string>
#include <algorithm>
using namespace ariel;
using namespace std;

string nospace(string input)
{
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
    
}

TEST_CASE("Good snowman code")
 {
    //given CHECK, might as well
    CHECK(nospace(snowman(11114411)) == nospace(string("      \n _===_\n (.,.) \n ( : ) \n ( : )\n")));
    //Checking Arms 
    CHECK(nospace(snowman(44444444)) == nospace(string("  ___ \n (_*_)\n (- -) \n (   ) \n (   )\n")));//no arms 
    CHECK(nospace(snowman(32224432)) == nospace(string("   _  \n  /_\\ \n (o_o) \n (> <) \n (\" \")\n"))); // 2 leveled hat no arms
    CHECK(nospace(snowman(22114312)) == nospace(string("  ___ \n .....\n (._.) \n ( : )\\\n (\" \")\n"))); //no left arm 
    CHECK(nospace(snowman(43212432)) == nospace(string("  ___ \n (_*_)\n\\(o_.) \n (> <) \n (\" \")\n"))); //no right arm 
    CHECK(nospace(snowman(21342231)) == nospace(string("  ___ \n .....\n\\(O,-)/\n (> <) \n ( : )\n"))); //2 upwards arm
    CHECK(nospace(snowman(41322422)) == nospace(string("  ___ \n (_*_)\n\\(O,o) \n (] [) \n (\" \")\n"))); // left upwards
    CHECK(nospace(snowman(33144243)) == nospace(string("   _  \n  /_\\ \n (._-)/\n (   ) \n (___)\n"))); //right upwards
    //Checking Eyes 
    CHECK(nospace(snowman(43114411)) == nospace(string("  ___ \n (_*_)\n (._.) \n ( : ) \n ( : )\n")));
    CHECK(nospace(snowman(43224411)) == nospace(string("  ___ \n (_*_)\n (o_o) \n ( : ) \n ( : )\n")));
    CHECK(nospace(snowman(43334411)) == nospace(string("  ___ \n (_*_)\n (O_O) \n ( : ) \n ( : )\n")));
    CHECK(nospace(snowman(43444411)) == nospace(string("  ___ \n (_*_)\n (-_-) \n ( : ) \n ( : )\n")));
    //Checking Hat and Nose
    CHECK(nospace(snowman(41341242)) == nospace(string("  ___ \n (_*_)\n (O,-)/\n<(   ) \n (\" \")\n")));
    CHECK(nospace(snowman(32341242)) == nospace(string("   _  \n  /_\\ \n (O_-)/\n<(   ) \n (\" \")\n")));
    CHECK(nospace(snowman(23341242)) == nospace(string("  ___ \n .....\n (O_-)/\n<(   ) \n (\" \")\n")));
    CHECK(nospace(snowman(14341242)) == nospace(string("      \n _===_\n (O -)/\n<(   ) \n  (\" \")\n")));
    //Checking Torso and Base
    CHECK(nospace(snowman(31432241)) == nospace(string("   _  \n  /_\\ \n\\(-,O)/\n (   ) \n ( : )\n")));
    CHECK(nospace(snowman(31432232)) == nospace(string("   _  \n  /_\\ \n\\(-,O)/\n (> <) \n (\" \")\n")));
    CHECK(nospace(snowman(31432223)) == nospace(string("   _  \n  /_\\ \n\\(-,O)/\n (] [) \n (___)\n")));
    CHECK(nospace(snowman(31432214)) == nospace(string("   _  \n  /_\\ \n\\(-,O)/\n ( : ) \n (   )\n")));
    
    //Making sure each option has 1 2 3 4 to make sure they're all working.
    CHECK(nospace(snowman(12341234)) == nospace(string("      \n _===_\n (O_-)/\n<(> <) \n (   )\n")));
    CHECK(nospace(snowman(23412341)) == nospace(string("  ___ \n .....\n\\(-_.) \n (   )\\\n ( : )\n")));
    CHECK(nospace(snowman(34123412)) == nospace(string("   _  \n  /_\\ \n (. o) \n/( : ) \n (\" \")\n")));
    CHECK(nospace(snowman(41234123)) == nospace(string("  ___ \n (_*_)\n (o,O) \n (] [)>\n (___)\n")));
   
 }
TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(555)); // too little digits
    CHECK_THROWS(snowman(112232443)); //too many digits
    CHECK_THROWS(snowman(14444444+1)); //digits over 4
    CHECK_THROWS(snowman(13214259)); //digits over 4
    CHECK_THROWS(snowman(13214250)); //digits less than 1
    //same but negative
    CHECK_THROWS(snowman(-555)); // too little digits
    CHECK_THROWS(snowman(-112232443)); //too many digits
    CHECK_THROWS(snowman(-14444444+1)); //digits over 4
    CHECK_THROWS(snowman(-13214259)); //digits over 4
    CHECK_THROWS(snowman(-13214250)); //digits less than 1

}


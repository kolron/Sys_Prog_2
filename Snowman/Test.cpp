#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
using namespace std;



TEST_CASE("Good snowman code")
 {

    //given CHECK, might as well
    CHECK(snowman(11114411) == string("      \n _===_\n (.,.) \n ( : ) \n ( : )\n"));
    //Checking Arms 
    CHECK(snowman(44444444) == string("  ___ \n (_*_)\n (- -) \n (   ) \n (   )\n"));//no arms 
    CHECK(snowman(32224432) == string("   _  \n  /_\\ \n (o_o) \n (> <) \n (" ")\n")); // 2 leveled hat no arms
    CHECK(snowman(22114312) == string("  ___ \n .....\n (._.) \n ( : )\\\n (" ")\n")); //no left arm 
    CHECK(snowman(43212432) == string("  ___ \n (_*_)\n\\(o_.) \n (> <) \n (" ")\n")); //no right arm 
    CHECK(snowman(21342231) == string("  ___ \n .....\n\\(O,-)/\n (> <) \n ( : )\n")); //2 upwards arm
    CHECK(snowman(41322422) == string("  ___ \n (_*_)\n\\(O,o) \n (] [) \n (" ")\n")); // left upwards
    CHECK(snowman(33144243) == string("   _  \n  /_\\ \n (._-)/\n (   ) \n (___)\n")); //right upwards
    //Checking Eyes 
    CHECK(snowman(43114411) == string("  ___ \n (_*_)\n (._.) \n ( : ) \n ( : )\n"));
    CHECK(snowman(43224411) == string("  ___ \n (_*_)\n (o_o) \n ( : ) \n ( : )\n"));
    CHECK(snowman(43334411) == string("  ___ \n (_*_)\n (O_O) \n ( : ) \n ( : )\n"));
    CHECK(snowman(43444411) == string("  ___ \n (_*_)\n (-_-) \n ( : ) \n ( : )\n"));
    //Checking Hat and Nose
    CHECK(snowman(41341242) == string("  ___ \n (_*_)\n (O,-)/\n<(   ) \n (" ")\n"));
    CHECK(snowman(32341242) == string("   _  \n  /_\\ \n (O_-)/\n<(   ) \n (" ")\n"));
    CHECK(snowman(23341242) == string("  ___ \n .....\n (O_-)/\n<(   ) \n (" ")\n"));
    CHECK(snowman(14341242) == string("      \n _===_\n (O -)/\n<(   ) \n  (" ")\n"));
    //Checking Torso and Base
    CHECK(snowman(31432241) == string("   _  \n  /_\\ \n\\(-,O)/\n (   ) \n ( : )\n"));
    CHECK(snowman(31432232) == string("   _  \n  /_\\ \n\\(-,O)/\n (> <) \n (" ")\n"));
    CHECK(snowman(31432223) == string("   _  \n  /_\\ \n\\(-,O)/\n (] [) \n (___)\n"));
    CHECK(snowman(31432214) == string("   _  \n  /_\\ \n\\(-,O)/\n ( : ) \n (   )\n"));
    
    //Making sure each option has 1 2 3 4 to make sure they're all working.
    CHECK(snowman(12341234) == string("      \n _===_\n (O_-)/\n<(> <) \n (   )\n"));
    CHECK(snowman(23412341) == string("  ___ \n .....\n\\(-_.) \n (   )\\\n ( : )\n"));
    CHECK(snowman(34123412) == string("   _  \n  /_\\ \n (. o) \n/( : ) \n (" ")\n"));
    CHECK(snowman(41234123) == string("  ___ \n (_*_)\n (o,O) \n (] [)>\n (___)\n"));
   
 }
TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(555)); // too little digits
    CHECK_THROWS(snowman(112232443)); //too many digits
    CHECK_THROWS(snowman(14444444+1)); //digits over 4
    CHECK_THROWS(snowman(13214259)); //digits over 4
    CHECK_THROWS(snowman(13214250)); //digits less than 0
    CHECK_THROWS(snowman(13214251)); //letters
}


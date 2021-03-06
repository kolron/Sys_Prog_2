#include<iostream>
#include<string>
#include "snowman.hpp"
#include<stdexcept>
using namespace std;

namespace ariel{
string make_hat(char x)
{
   
    std::string hat;
    string hat_base ;

    ////////////////
    // HAT /////////
    ////////////////
    
    switch (x)
    {
    case '1':
        hat = "      \n";
        hat_base = " _===_\n";
        break;
    case '2':
        hat = "  ___ \n";
        hat_base = " .....";
        break;
    case '3':
        hat = "   _  \n";
        hat_base= "  /_\\ \n";
        break;
    case '4':
        hat="  ___ \n";
        hat_base = " (_*_)\n";
        break;
    default:
        exit(1);
    }
    string hat_final = hat + hat_base;
    
    return hat_final;
    
}

string make_eyes(string b, char l,char r)
{ 

    switch (l)
    {
    case '1':
        b[2] = '.';
        break;
    case '2':
        b[2] = 'o'; 
        break;
    case '3':
        b[2] = 'O'; 
        break;
    case '4':
        b[2] = '-';
        break;
    default:
        exit(1);
    }

   switch (r)
    {
    case '1':
        b[4] = '.';
        break;
    case '2':
        b[4] = 'o'; 
        break;
    case '3':
        b[4] = 'O'; 
        break;
    case '4':
        b[4] = '-';
        break;

    default:
        exit(1);
    }
    return b;

}


string make_body(string x)
{
     std::string u_body = " (   )  \n";
     std::string l_body = " (   )  \n";
   
    ////////////////
    // NOSE ////////
    ////////////////
    switch (x[0]) 
    {
    case '1':
        u_body[3] = ',';
        break;
    case '2':
        u_body[3] = '.';
     
    case '3':
        u_body[3] = '_' ;  
        break;

    case '4':
        u_body[3] = ' ' ;  
        break;

    default:
        exit(1);
    }


    ////////////////
    // TORSO ///////
    ////////////////
    switch(x[5]) 
    {
        case '1':
            l_body[3] = ':';
            break;
        case '2':
            l_body[2] = ']';
            l_body[4] = '[';
            break;
        case '3':
            l_body[2] = '>';
            l_body[4] = '<';
            break;
        case '4':
            l_body[3] = ' ';
            break;

        default:
            exit(1);
    }


    /*
    x[0] = Nose
    x[1] = Left eye
    x[2] = right eye
    x[3] = Left arm
    x[4] = Right arm
    x[5] = Torso
    */

    ////////////////
    // BOTH EYES ///
    ////////////////
    u_body = make_eyes(u_body, x[1], x[2]);
    

    ////////////////
    // LEFT ARM ////
    ////////////////
    switch(x[3])
    {
    case '1':
        l_body[0] = '<';
        break;
    case '2':
        u_body[0] = '\\';
        break;
    case '3':
        l_body[0] = '/';
        break;
    
    case '4':
         l_body[0] = ' ';
         break;
    default:
        exit(1);
    }
    
    ////////////////
    // RIGHT ARM ///
    ////////////////
    cout << "here" << endl;
    switch(x[4])
    {
    case '1':
        l_body[6] = '>';
        break;
    case '2':
        u_body[6] = '/';
        break;
    case '3':
        l_body[6] = '\\';
        break;
     case '4':
        l_body[6] = ' ';
        break;

    default:
        exit(1);
    }  
    cout << u_body << endl;
   string body = u_body + l_body;
  
   return body;
}

string  make_base(char x)
{
     std::string b_base = " (   )\n";

    ////////////////
    // BASE  ///////
    ////////////////

      switch (x)
    {
    case '1':
        b_base[3] = ':';
        
        break;
    case '2':
        b_base[2] = '"';
        b_base[4] = '"';
       break;
    case '3':
        b_base[2] = '_';
        b_base[3] = '_';
        b_base[4] = '_';
      break;
    case '4':

        break;
    
    default:
        exit(1);
    }

    return b_base;
}


string snowman(int x)
{
   
    string input = to_string(x);
    if (input.length() != 8) //if string is too short
    {
            string _err_msg = ("Invalid code '" + input + "'");
            throw std::invalid_argument(_err_msg);
    }

    for(int i = 0; i < 8; i++)
    {
        if(!(input[i] >= 49 && input[i] <= 52)) //if string has numbers(or characters for that matter) that are not 1,2,3,4
        {
            
            string _err_msg = ("Invalid code '" + input + "'");
            throw std::invalid_argument(_err_msg);
        }
    }
    

    string body_input = input.substr(1,6);//just for easier work in make_body

    string final_snowman = make_hat(input[0]) + make_body(body_input) + make_base(input[7]);
  
     cout << final_snowman << endl; //TODO: REMOVE IN THE END
    return final_snowman;
}
 };
// int main()
// {
//     ariel::snowman(41234123);
//     return 0;
// }

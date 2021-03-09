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

     /*
    x[0] = Nose
    x[1] = Left eye
    x[2] = right eye
    x[3] = Left arm
    x[4] = Right arm
    x[5] = Torso
    */
    const int nose_input = 0;
    const int nose_pos = 3;
    const int l_eye_input = 1;
    const int r_eye_input = 2;
    const int l_arm_input = 3 ;
    const int l_arm_pos = 0 ;
    const int r_arm_input = 4 ;
    const int r_arm_pos = 6;
    const int torso_input = 5;
    const int torso_mid_pos = 3;
    const int torso_l_pos = 2;
    const int torso_r_pos = 4;



   
    ////////////////
    // NOSE ////////
    ////////////////
    switch (x[nose_input]) 
    {
    case '1':
        u_body[nose_pos] = ',';
        break;
    case '2':
        u_body[nose_pos] = '.';
     
    case '3':
        u_body[nose_pos] = '_' ;  
        break;

    case '4':
        u_body[nose_pos] = ' ' ;  
        break;

    default:
        exit(1);
    }


    ////////////////
    // TORSO ///////
    ////////////////
    switch(x[torso_input]) 
    {
        case '1':
            l_body[torso_mid_pos] = ':';
            break;
        case '2':
            l_body[torso_l_pos] = ']';
            l_body[torso_r_pos] = '[';
            break;
        case '3':
            l_body[torso_l_pos] = '>';
            l_body[torso_r_pos] = '<';
            break;
        case '4':
            l_body[torso_mid_pos] = ' ';
            break;

        default:
            exit(1);
    }


    ////////////////
    // BOTH EYES ///
    ////////////////
    u_body = make_eyes(u_body, x[l_eye_input], x[r_eye_input]);
    

    ////////////////
    // LEFT ARM ////
    ////////////////
    switch(x[l_arm_input])
    {
    case '1':
        l_body[l_arm_pos] = '<';
        break;
    case '2':
        u_body[l_arm_pos] = '\\';
        break;
    case '3':
        l_body[l_arm_pos] = '/';
        break;
    
    case '4':
         l_body[l_arm_pos] = ' ';
         break;
    default:
        exit(1);
    }
    
    ////////////////
    // RIGHT ARM ///
    ////////////////
    
    switch(x[r_arm_input])
    {
    case '1':
        l_body[r_arm_pos] = '>';
        break;
    case '2':
        u_body[r_arm_pos] = '/';
        break;
    case '3':
        l_body[r_arm_pos] = '\\';
        break;
     case '4':
        l_body[r_arm_pos] = ' ';
        break;

    default:
        exit(1);
    }  
   string body = u_body + l_body;
  
   return body;
}

string make_base(char x)
{
     std::string b_base = " (   )\n";
     const int base_mid_pos = 3;
     const int base_l_pos = 2;
     const int base_r_pos = 4;


    ////////////////
    // BASE  ///////
    ////////////////

      switch (x)
    {
    case '1':
        b_base[base_mid_pos] = ':';
        
        break;
    case '2':
        b_base[base_l_pos] = '"';
        b_base[base_r_pos] = '"';
       break;
    case '3':
        b_base[base_l_pos] = '_';
        b_base[base_mid_pos] = '_';
        b_base[base_r_pos] = '_';
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
   const int length = 8;
    string input = to_string(x);
    if (input.length() != length) //if string is too short or too long
    {
            string _err_msg = ("Invalid code '" + input + "'");
            throw std::invalid_argument(_err_msg);
    }

    for(int i = 0; i < length; i++)
    {
        if(!(input[i] >= '1' && input[i] <= '4')) //if string has numbers(or characters for that matter) that are not 1,2,3,4
        {
            
            string _err_msg = ("Invalid code '" + input + "'");
            throw std::invalid_argument(_err_msg);
        }
    }
    
    const int start_body = 1;
    const int end_body = 6;
    const int hat_input = 0;
    const int base_input = 7;
    
    string body_input = input.substr(start_body,end_body);//just for easier work in make_body

    string final_snowman = make_hat(input[hat_input]) + make_body(body_input) + make_base(input[base_input]);
  
    //cout << final_snowman << endl; //TODO: REMOVE IN THE END
    return final_snowman;
}
 };
// int main()
// {
//     ariel::snowman(34123412);
//     return 0;
// }

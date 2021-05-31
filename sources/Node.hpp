#pragma once
namespace ariel
{
    template<typename T> struct Node
    {

        T data;
        Node* left;
        Node* right;

        Node( T& data):data(data)
        {
            this ->right = nullptr;
            this -> left = nullptr;
        }
        Node(Node* left = nullptr, Node* right = nullptr)
        {
            this ->right = right;
            this -> left = left;

        }
          
    };    
};

   
 
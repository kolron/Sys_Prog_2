#pragma once
namespace ariel
{
    template<typename T> struct Node
    {
        public:
            Node(Node* left = nullptr, Node* right = nullptr)
            {
                this ->right = right;
                this -> left = left;
                this ->data = data;
            }
            T data;
            Node* left;
            Node* right;
    };
};
#pragma once
#include "Node.hpp"
#include <stack>


namespace ariel
{
    
    template <typename T> class InIterator
    {
    public:
        InIterator(){};   

        InIterator(Node<T> *root) 
        {
            while(root != nullptr)
            {
                stack.push(root);
                root = root->left;
            }
        };

        InIterator<T> &operator++()
        {

            Node<T> *first = stack.top()->right;
            stack.pop();

            while(first != nullptr)
            {
                stack.push(first);
                first = first->left;
            }
            
            return *this;
        }
        T &operator*()
        {
            return stack.top()->data;
        }

        
        T *operator->()
        {
            //Node<T> *node = stack.top();
            return &(stack.top()->data);
        }



        bool operator!=(const InIterator &other) const
        {
            return other.stack.empty() != stack.empty() ||
                   (!stack.empty() && other.stack.top() != stack.top());
        }


        Node<T> *getNode() 
        {
            return stack.top();
        }

    private:
        std::stack<Node<T> *> stack;
    };
};
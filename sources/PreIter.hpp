#pragma once
#include "Node.hpp"
#include <stack>

namespace ariel
{
    
    template <typename T> class PreIterator
    {
    public:
        PreIterator(){};   

        PreIterator(Node<T> *root) 
        {
            if (root != nullptr)
            {
                stack.push(root);
            }
        };
        PreIterator<T> &operator++()
        {

            Node<T> *first = stack.top();
            stack.pop();
            if (first->right != nullptr)
            {
                stack.push(first->right);
            }
            if (first->left != nullptr)
            {
                stack.push(first->left);
            }
            return *this;
        }
        T& operator*()
        {
            return stack.top()->data;
        }


        T* operator->()
        {
            Node<T> *node = stack.top();
            return &(node->data);
        }



        bool operator!=(const PreIterator &other) const
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
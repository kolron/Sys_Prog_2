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
            if (root)
            {
                stack.push(root);
            }
        };
        PreIterator<T> &operator++()
        {
            Node<T> *curr = stack.top();
            stack.pop();
            if (curr->right)
            {
                stack.push(curr->right);
            }
            if (curr->left)
            {
                stack.push(curr->left);
            }
            return *this;
        }

        PreIterator<T> operator++(int)
        {
            PreIterator<T> temp = *this;
            Node<T> *curr = stack.top();
            stack.pop();
            if (curr->right)
            {
                stack.push(curr->right);
            }
            if (curr->left)
            {
                stack.push(curr->left);
            }
            return temp;
        }

        T &operator*()
        {
            return stack.top()->data;
        }
        T *operator->()
        {
            return &(stack.top()->data);
        }
        bool operator!=(const PreIterator &other) const
        {
            return other.stack.empty() != stack.empty() ||
                   (!stack.empty() && other.stack.top() != stack.top());
        }
        bool operator==(const PreIterator &other) const
        {
            return !(*this != other);
        }
        
        Node<T> *getNode() 
        {
            return stack.top();
        }


    private:
        std::stack<Node<T> *> stack;
    };
};
#pragma once
#include "Node.hpp"
#include <stack>


namespace ariel
{
    template <typename T> class InIterator
    {
    public:
    
        InIterator(){};           
        InIterator(Node<T> *node) 
        {
            while (node)
            {
                stack.push(node);
                node = node->left;
            }
        };
        InIterator<T> &operator++()
        {
            Node<T> *curr = stack.top()->right;
            stack.pop();
            while (curr)
            {
                stack.push(curr);
                curr = curr->left;
            }
            return *this;
        }
        InIterator<T> operator++(int)
        {
            InIterator<T> temp = *this;
            Node<T> *curr = stack.top()->right;
            stack.pop();
            while (curr)
            {
                stack.push(curr);
                curr = curr->left;
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
        bool operator!=(const InIterator &other) const
        {
            return other.stack.empty() != stack.empty() ||
                   (!stack.empty() && other.stack.top() != stack.top());
        }
        bool operator==(const InIterator &other) const
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
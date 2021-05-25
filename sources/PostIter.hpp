#pragma once
#include "Node.hpp"
#include <stack>

namespace ariel
{
    
    template <typename T> class PostIterator
    {
    public:
        PostIterator(){};   

        PostIterator(Node<T> *root) 
        {
            postorder(root);
        };

        PostIterator<T> &operator++()
        {
            stack.pop();
            return *this;
            
        }
        T &operator*()
        {
            return stack.top()->data;
        }


        T *operator->()
        {
            //Node<T> * node = stack.top();
            return &(stack.top()->data);
        }



        bool operator!=(const PostIterator &other) const
        {
            return other.stack.empty() != stack.empty() ||
                   (!stack.empty() && other.stack.top() != stack.top());
        }


        Node<T> *getNode() 
        {
            return stack.top();
        }

    private:
        std::stack<Node<T>*> stack;

        //Recursive function for constructor 
        //https://www.tutorialspoint.com/cplusplus-program-to-perform-postorder-recursive-traversal-of-a-given-binary-tree

        void postorder(Node<T> *root)
        {
            if (root)
            {
                if(root ->left)
                {
                    postorder(root->left);
                }
                if(root -> right)
                {
                    postorder(root->right);
                }
                stack.push(root);
            }
        }
    };
};
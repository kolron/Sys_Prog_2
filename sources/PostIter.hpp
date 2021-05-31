#pragma once
#include "Node.hpp"
#include <list>
namespace ariel
{
    template <typename T> class PostIterator
    {
    public:
        PostIterator(){};
        PostIterator(Node<T> *node)
        {
            postorder(node);
        };
        PostIterator<T> &operator++()
        {
            stack.pop_front();
            return *this;
        }
        PostIterator<T> operator++(int)
        {
            PostIterator<T> ret = *this;
            stack.pop_front();
            return ret;
        }
        T &operator*()
        {
            return stack.front()->data;
        }
        T *operator->()
        {
            return &(stack.front()->data);
        }
        bool operator==(const PostIterator &other) const
        {
            return !(other.stack.empty() != stack.empty() ||(!stack.empty() && other.stack.front() != stack.front()));
        }
        bool operator!=(const PostIterator &other) const
        {
            return !(*this == other);
        }
        
        Node<T> *getNode() 
        {
            return stack.top();
        }

    private:
        std::list<Node<T>*> stack;

        //Recursive function for constructor 
        //started with a 2 stack implementation before realizing we can just do push_back using a list

        //  while(!stackHelp.empty())
        //             {
        //                 Node<T>* node = stackHelp.top();
        //                 stackHelp.pop();
        //                 stackMain.push(node);  
        //             }
        
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
                stack.push_back(root);
            }
        }
    };
};
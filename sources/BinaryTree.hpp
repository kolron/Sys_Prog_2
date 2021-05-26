#pragma once
#include "Node.hpp"
#include "PostIter.hpp"
#include "PreIter.hpp"
#include "InIter.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

namespace ariel
{
    template<typename T> class BinaryTree
    {
        public:
            Node<T> *root;

            BinaryTree() 
            {
               root = nullptr;
            }

            BinaryTree(Node<T>* root)
            {
                this -> root = root;
            }

            BinaryTree &add_root(T data)
            {
                
                if (root == nullptr) // if root is NULL create it, then update it's data;
                {
                 root = new Node<T>{};
                }
                root->data = data;
                return *this;
            }

            BinaryTree &add_left(T parentData, T newData) // T aren't nodes, they are data inside nodes.
            {   

                Node<T> * parentNode = find(parentData); //find the matching node, add to the left of that.
                if(parentNode == nullptr)
                {
                    throw std::invalid_argument("Parent node (left argument) does't exist");
                }

                if (parentNode->left == nullptr) //same as add_root
                {
                   parentNode->left = new Node<T>{};
                }

                parentNode->left->data = newData;
                return *this;
                
            }

            BinaryTree &add_right(T parentData, T newData)
            {

                Node<T> * parentNode = find(parentData); //find the matching node, add to the left of that.
                if(parentNode == nullptr)
                {
                    throw std::invalid_argument("Parent node (left argument) does't exist");
                }

                if (parentNode->right == nullptr) //same as add_root
                {
                   parentNode->right = new Node<T>{};
                }

                parentNode->right->data = newData;
                return *this;
            }

        PreIterator<T> begin_preorder()
        {
            return PreIterator<T>{root};
        }
        PreIterator<T> end_preorder()
        {
            return PreIterator<T>{};
        }


        InIterator<T> begin_inorder()
        {
            return InIterator<T>{root};
        }
        InIterator<T> end_inorder()
        {
            return InIterator<T>{};
        }
         InIterator<T> begin()
        {
            return InIterator<T>{root};
        }
        InIterator<T> end()
        {
            return InIterator<T>{};
        }


        PostIterator<T> begin_postorder()
        {
            return PostIterator<T>{root};
        }
        PostIterator<T> end_postorder()
        {
            return PostIterator<T>{};
        }

        friend std::ostream &operator<<(std::ostream &os, const BinaryTree<T> &tree);
        
        private:

        Node<T> * find(T x)
        {
            
            for(auto it = begin_preorder(); it != end_preorder(); ++it)
            {
                if(*it == x)
                {
                    return it.getNode();
                }
            }
            return nullptr;
        }

    };
    template<typename T> std::ostream &operator<<(std::ostream &os, BinaryTree<T>& tree)
    {
         std::for_each(tree.begin(), tree.end(),   [](const auto element) { std::cout << " " << element;});
         os<<std::endl;
         return os;
     }
    
};

#pragma once
#include <iostream>
#include <vector>
#include "Node.hpp"
#include "InIter.hpp"
#include "PreIter.hpp"
#include "PostIter.hpp"

namespace ariel
{
    template <typename T> class BinaryTree
    {
    public:
        BinaryTree() //default constructor
         {
             root = nullptr;
         }

        BinaryTree(const BinaryTree &other) //deep copy constructor - create all new nodes.
        {
            if(other.root != nullptr)
            {
                root = new Node<T>{other.root -> data};
                copyTree(other.root, root);
            }
        }

        BinaryTree(BinaryTree &&other) noexcept  //shallow copy - just change the root of the new tree to be the same as the old tree. 
        {                              //We don't want 2 roots to the same tree (or another place to access the tree) so make the old root point null
            root = other.root;
            other.root = nullptr;
        }


        ~BinaryTree() //delete all nodes in the tree
        {
            for (auto it = begin_preorder(); it != end_preorder();)
            {
                Node<T> *node = it.getNode();
                ++it;
                delete node;
            }
        }
  
        BinaryTree &add_root(T data)
        {
            if (root == nullptr)
            {
                root = new Node<T>{data};
            }
            else
            {
                root->data = data;
            }
            return *this;
        }

        BinaryTree &operator=(const BinaryTree &other)
        {
            if(this != &other)
            {
                for (auto it = begin_preorder(); it != end_preorder();)
            {
                Node<T> *node = it.getNode();
                ++it;
                delete node;
            }
                if(other.root != nullptr)
                {
                    root = new Node<T>{other.root -> data};
                    copyTree(other.root, root);                   
                }
            }
            return *this;
        }

        BinaryTree &operator=(BinaryTree &&other) noexcept
        {
            root = other.root;
            other.root = nullptr;
            return *this;
        }


        BinaryTree &add_left(T parentData, T newData) // T aren't nodes, they are data inside nodes.
        {   
            Node<T> * parentNode = findNode(parentData); //find the matching node, add to the left of that.
            if(parentNode == nullptr)
            {
                throw std::invalid_argument("Parent node (left argument) does't exist");
            }
            if(parentNode->left == nullptr) //same as add_root
            {
                parentNode->left = new Node<T>{newData};
            }
            parentNode->left->data = newData;
            return *this;   
            }

        BinaryTree &add_right(T parentData, T newData)
            {
                Node<T> * parentNode = findNode(parentData); //find the matching node, add to the right of that.
                if(parentNode == nullptr)
                {
                    throw std::invalid_argument("Parent node (left argument) does't exist");
                }
                if (parentNode->right == nullptr) //same as add_root
                {
                   parentNode->right = new Node<T>{newData};
                }
                parentNode->right->data = newData;
                return *this;
            }

        /***Iterators***/
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

        /////////////

        friend std::ostream &operator<<(std::ostream &os, const BinaryTree<T> &tree);
        

    private:
        Node<T> *root;
        Node<T>* findNode(T data)
        {
            for(auto it = begin(); it != end(); ++it)
            {
                if(*it == data)
                {
                    return it.getNode();
                }
            }
            return nullptr;
        }
    
        void copyTree(Node<T>* srcNode,Node<T>* newNode)
        {
            if(srcNode->left != nullptr)
            {                    
                newNode->left = new Node<T>{srcNode->left->data};
                copyTree(srcNode->left,newNode->left);
            }

            if(srcNode->right!=nullptr)
            {
                newNode->right = new Node<T>{srcNode->right->data};                    
                copyTree(srcNode->right,newNode->right);
            }
        }
    };
    
       template<typename T> std::ostream &operator<<(std::ostream &os, BinaryTree<T>& tree)
    {
        std::for_each(tree.begin(), tree.end(),   [](const auto element) { std::cout << " " << element;});
        os<<std::endl;
        return os;
    }

};

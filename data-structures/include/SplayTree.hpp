#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include "TreeNode.hpp"

#include <iostream>

template <typename T, typename Comparator = std::less<T>>

//Classe que vai implementar uma SplayTree
class SplayTree {
    private:
        //Store how many nodes exist in the tree
        std::size_t m_NodeCount;

        //Pointer to the root 
        TreeNode<T>* m_Root;

    public:
        /**
         * @brief Default contrutor. Initializa with 0 nodes and null root
        */
        SplayTree() : m_NodeCount(0), m_Root(nullptr) { };

        /**
         * @brief Constructor to initialize with root
         * @param root root of the tree
        */
       SplayTree(const TreeNode<T>* root) : m_Root(root) { };
};

#endif // !SPLAYTREE_H
#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include "TreeNode.hpp"

#include <iostream>


// Class that will represent a splay tree
template <typename T, typename Comparator = std::less<T>>
class SplayTree {
    public:
        /**
         * @brief Default contrutor. Initialize with 0 nodes and null root with default less comparator
         */
        SplayTree() : m_NodeCount(0), m_Root(nullptr), m_Comparator(Comparator()) { };

        /**
         * @brief Constructor to initialize with root and default less comparator
         * @param root root of the tree
         */
        SplayTree(TreeNode<T>* root) : m_Root(root), m_NodeCount(1), m_Comparator(Comparator()) { };

        /**
         * @brief Constructor to initialize with 0 nodes and custom comparator
         * @param comparator custom comparator
         */
        SplayTree(const Comparator& comparator) : m_NodeCount(0), m_Root(nullptr), m_Comparator(comparator) { };

        /**
         * @brief Constructor to initialize with root and custom comparator
         * @param root root of the tree
         * @param comparator custom comparator
         */
        SplayTree(TreeNode<T> *root, const Comparator& comparator) : m_NodeCount(1), m_Root(root), m_Comparator(comparator) { };

        /**
         * @brief Insertion operation in the tree
         * @details A Splay tree will always make the new node the root
         * @param node node that will be inserted into the tree
        */

        void Insert(const TreeNode<T>& node) {
            Zig(node);
        }

    private:

        // //Do a Zig operation (left rotation)
        // void Zig(TreeNode<T>* node) {
        //     //Saves the right child of 'node' in 'x'
        //     TreeNode<T>* x = node->m_Right;

        //     // If x exists (is not null), adjust the pointers.
        //     if (x != nullptr) {
        //         // Update the right child of node to be the left child of x
        //         node->m_Right = x->m_Left;

        //         //If the left child of x exists, update the parent to be x
        //         if (x->m_Left != nullptr) {
        //             x->m_Left->m_Parent = node;
        //         }

        //         //Update x's parent to be node's parent
        //         x->m_Parent = node->m_Parent;
        //     }

        //     //If node is the root, update the root for x
        //     if (node->m_Parent == nullptr) {
        //         this->m_Root = x;
        //     }

        //     //If node is the left child, update the left pointer of his parent to x
        //     else if (node == node->m_Parent->m_Left) { 
        //         node->m_Parent->m_Left = x;
        //     }

        //     //If node is the right child, update the parent's right pointer to x
        //     else {
        //         node->m_Parent->m_Right = x;
        //     }

        //     //If x exists, update the left child of x to be node
        //     if (x != nullptr) {
        //         x->m_Left = node;
        //     }
        //     node->m_Parent = x;
        // }

        // //Do a Zag Operation (right rotation)
        // // See Zig function for comments, it's the same thinking but for the opposite side
        // void Zag(TreeNode<T>* node) {
        //     TreeNode<T>* x = node->m_Left;
            
        //     if (x != nullptr) {
        //         node->m_Left = x->m_Right;
        //         if (x->m_Right != nullptr) {
        //             x->m_Right->m_Parent = node;
        //         }
        //         x->m_Parent = node->m_Parent;
        //     }

        //     if (node->m_Parent == nullptr) {
        //         this->m_Root = x;
        //     }
        //     else if (node == node->m_Parent->m_Left) {
        //         node->m_Parent->m_Left = x;
        //     }
        //     else {
        //         node->m_Parent->m_Right = x;
        //     }
        //     if (x != nullptr) {
        //         x->m_Right = node;
        //     }
        //     node->m_Parent = x;
        // }

        // Store how many nodes exist in the tree
        std::size_t m_NodeCount;

        // Pointer to the root
        TreeNode<T> *m_Root;

        //Comparator instance for comparisons
        Comparator m_Comparator;
};

#endif // !SPLAYTREE_H
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
         * @brief Constructor to initialize with 0 nodes and custom comparator
         * @param comparator custom comparator
         */
        SplayTree(const Comparator& comparator) : m_NodeCount(0), m_Root(nullptr), m_Comparator(comparator) { };

        /**
         * @brief Insertion operation in the tree
         * @details A Splay tree will always make the new node the root
         * @param value new value that will be inserted into the tree
        */
        void Insert(const T& value);

    private:

        //Do a Zag operation (left rotation)
        void Zag(TreeNode<T>* node);

        //Do a Zig Operation (right rotation)
        //See Zag function for comments, it's the same thinking but for the right side.
        void Zig(TreeNode<T>* node);

        //Splay operation. Move the node to the root with zig and zag rotations
        void Splay(TreeNode<T>* node);

        /**
         * @brief Find the position in the tree for the new value
         * @details the new node will be moved to the root after this function
         * @param value new value to be inserted
        */
        void RecursiveInsertion(const T& value, TreeNode<T>* root, TreeNode<T>* parent);

        // Store how many nodes exist in the tree
        std::size_t m_NodeCount;

        // Pointer to the root
        TreeNode<T> *m_Root;

        //Comparator instance for comparisons
        Comparator m_Comparator;
};

/*Implements template functions*/

template<typename T, typename Comparator>
void SplayTree<T, Comparator>::Zag(TreeNode<T>* node) {
    
    //Saves the right child of 'node' in 'x'
    TreeNode<T>* x = node->GetRight();

    // If x exists (is not null), adjust the pointers.
    if (x != nullptr) {
        // Update the right child of node to be the left child of x
        node->SetRight(x->GetLeft());

        //If the left child of x exists, update the parent to be x
        if (x->GetLeft() != nullptr) {
            x->GetLeft()->SetParent(node);
        }

        //Update x's parent to be node's parent
        x->SetParent(node->GetParent());
    }

    //If node is the root, update the root for x
    if (node->GetParent() == nullptr) {
        this->m_Root = x;
    }

    //If node is the left child, update the left pointer of his parent to x
    else if (node == node->GetParent()->GetLeft()) { 
        node->GetParent()->SetLeft(x);
    }

    //If node is the right child, update the parent's right pointer to x
    else {
        node->GetParent()->SetRight(x);
    }

    //If x exists, update the left child of x to be node
    if (x != nullptr) {
        x->SetLeft(node);
    }
    node->SetParent(x);
}

//See Zag function for comments, it's the same thinking but for the  right side
template<typename T, typename Comparator>
void SplayTree<T, Comparator>::Zig(TreeNode<T>* node) {
    
    TreeNode<T>* x = node->GetLeft();
    
    if (x != nullptr) {
        node->SetLeft(x->GetRight());

        if (x->GetRight() != nullptr) {
            x->GetRight()->SetParent(node);
        }
        x->SetParent(node->GetParent());
    }

    if (node->GetParent() == nullptr) {
        this->m_Root = x;
    }
    else if (node == node->GetParent()->GetLeft()) {
        node->GetParent()->SetLeft(x);
    }
    else {
        node->GetParent()->SetRight(x);
    }
    if (x != nullptr) {
        x->SetRight(node);
    }
    node->SetParent(x);
}

template<typename T, typename Comparator>
void SplayTree<T, Comparator>::Splay(TreeNode<T>* node) {
    while (node != this->m_Root) {  
        //if node does not have a grandparent
        if(node->GetParent()->GetParent() == nullptr) {
            //if node is the left child do a right rotation
            if (node->GetParent()->GetLeft() == node) Zig(node->GetParent());
            //else do a left rotation
            else Zag(node->GetParent());
        }

        //This just means that the node has a grandparent and, him and his parent are to the left side
        else if ((node->GetParent()->GetLeft() == node) && (node->GetParent()->GetParent()->GetLeft() == node->GetParent())) {
            //Perform the right rotations on his grandparent and his parent
            Zig(node->GetParent()->GetParent());
            Zig(node->GetParent());
        }

        //Zag-Zag situation
        /*             
          (A)                  (B)                (C)
            \                 /   \               /
            (B)       -->   (A)   (C)   -->     (B)
              \                                 /
              (C)                             (A)
        */
        //This just means that the node has a grandparent and, him and his parent are to the right side
        else if ((node->GetParent()->GetRight() == node) && (node->GetParent()->GetParent()->GetRight() == node->GetParent())) {
            //Perform the right rotations on his grandparent and his parent
            Zag(node->GetParent()->GetParent());
            Zag(node->GetParent());
        }

        //This means that the node has a grandparent and him and his parent are in a zig zag situation
        else if ((node->GetParent()->GetLeft() == node) && (node->GetParent()->GetParent()->GetRight() == node->GetParent())) {
            Zig(node->GetParent());
            Zag(node->GetParent());
        }

        else {                                             
            Zag(node->GetParent()); 
            Zig(node->GetParent());
        }   
    }
}

template<typename T, typename Comparator>
void SplayTree<T, Comparator>::RecursiveInsertion(const T& value, TreeNode<T>* current, TreeNode<T>* parent) {
    //base case: reached a leaf node or tree is empty
    if (current == nullptr) {
        TreeNode<T>* new_node = new TreeNode<T>(value, parent);

        //if new node is the root
        if (parent == nullptr) this->m_Root = new_node;

        //If value is in the right subtree
        else if (m_Comparator(parent->GetData(), value)) {
            parent->SetRight(new_node);
        }

        //if value is in the left subtree
        else {
            parent->SetLeft(new_node);
        }

        //Splay operation in the new node
        Splay(new_node);
        this->m_NodeCount++;
    }

    //go to the right subtree
    else if (this->m_Comparator(current->GetData(), value)) {
        parent = current;
        RecursiveInsertion(value, current->GetRight(), parent);
    }
    
    //go to left subtree
    else {
        parent = current;
        RecursiveInsertion(value, current->GetLeft(), parent);
    }

} 

template<typename T, typename Comparator>
void SplayTree<T, Comparator>::Insert(const T& value) {
    //Aux. variables    
    TreeNode<T>* current = this->m_Root;
    TreeNode<T>* parent = nullptr;

    //Call recursive insertion to insert and splay the new node
    RecursiveInsertion(value, current, parent);
}

#endif // !SPLAYTREE_H
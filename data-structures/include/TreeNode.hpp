#ifndef TREENODE_H
#define TREENODE_H

template <typename T>
/**
 * @brief Class that represents a node in a tree
*/
class TreeNode {
    
    public:
        /**
         * @brief Constructor of TreeNode with left, right and parent initialized with nullptr
         * @param data data of the type that the node will store
        */
        TreeNode(const T& data) : m_Data(data), m_Left(nullptr), m_Right(nullptr), m_Parent(nullptr) { };

        /**
         * @brief Constructor of Node with data and left child. Both parent and right are nullptr
         * @param data data of the type that the node will store
         * @param left pointer to the left child of the node
        */
        TreeNode(const TreeNode<T>* left, const T& data) : m_Data(data), m_Left(left), m_Right(nullptr), m_Parent(nullptr) { };

        /**
         * @brief Constructor of Node with data and right child. Both parent and left are nullptr
         * @param data data of the type that the node will store
         * @param right pointer to the right child of the node
        */
        TreeNode(const T& data, const TreeNode<T>* right) : m_Data(data), m_Left(nullptr), m_Right(right), m_Parent(nullptr) { };

        /**
         * @brief Constructor of Node with data, left, right and parent
         * @param data data of the type that the node will store
         * @param left pointer to the left child of the node
         * @param right pointer to the right child of the node
         * @param parent parent of node
        */
        TreeNode(const T& data, const TreeNode<T>* left, const TreeNode<T>* right, const TreeNode<T>* parent) : 
        m_Data(data), m_Left(left), m_Right(right), m_Parent(parent) { };

        friend class SplayTree;
    
    private:
        //Stored Data
        T m_Data;

        //Pointer to Left Child
        TreeNode<T>* m_Left;

        //Pointer to Right Child
        TreeNode<T>* m_Right;

        //Pointer to Parent Node
        TreeNode<T>* m_Parent;
};


#endif // !TREENODE_H
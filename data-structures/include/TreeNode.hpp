#ifndef TREENODE_H
#define TREENODE_H

template <typename T>
/**
 * @brief Class that represents a node in a tree
*/
class TreeNode {
    private:
        //Stored Data
        T m_Data;

        //Pointer to Left Child
        TreeNode<T>* m_Left;

        //Pointer to Right Child
        TreeNode<T>* m_Right;
    
    public:
        /**
         * @brief Constructor of TreeNode with both left and right initialized with nullptr
         * @param object object of the type that the node will store
        */
        TreeNode(const T &object) : m_Data(object), m_Left(nullptr), m_Right(nullptr){ };

        /**
         * @brief Constructor of Node with data and left child
         * @param object object of the type that the node will store
         * @param left pointer to the left child of the node
        */
        TreeNode(const T& object, const TreeNode<T>* left) : m_Data(object), m_Left(left), m_Right(nullptr) { };

        /**
         * @brief Constructor of Node with data and right child
         * @param object object of the type that the node will store
         * @param right pointer to the right child of the node
        */
        TreeNode(const TreeNode<T>* right, const T& object) : m_Data(object), m_Left(nullptr), m_Right(right) { };

        /**
         * @brief Constructor of Node with data, left and right child.
         * @param object object of the type that the node will store
         * @param left pointer to the left child of the node
         * @param right pointer to the right child of the node
        */
        TreeNode(const T& object, const TreeNode<T>* left, const TreeNode<T>* right) : m_Data(object), m_Left(left), m_Right(right) { };
};


#endif // !TREENODE_H
#ifndef TREENODE_H
#define TREENODE_H

//foward declaration to use the 'friend' keyword with template classes.
template <typename T, typename Comparator>
class SplayTree;

/**
 * @brief Class that represents a node in a tree
*/
template <typename T>
class TreeNode {
    private:
        //Declare splay tree as a friend
        template <typename U, typename Comparator>
        friend class SplayTree;

        /**
         * @brief Constructor of TreeNode with left, right and parent initialized with nullptr
         * @param data data of the type that the node will store
        */
        TreeNode(const T& data) : m_Data(data), m_Left(nullptr), m_Right(nullptr), m_Parent(nullptr) { };

        /**
         * @brief Constructor of Node with data and right child. Both parent and left are nullptr
         * @param data data of the type that the node will store
         * @param parent pointer to the parent of the node
        */
        TreeNode(const T& data, TreeNode<T>* parent) : m_Data(data), m_Left(nullptr), m_Right(nullptr), m_Parent(parent) { };


        //Return left child of a node
        TreeNode<T>* GetLeft();

        //Return right child of a node
        TreeNode<T>* GetRight();

        //Return parent of a node
        TreeNode<T>* GetParent();

        //Return data of a node
        T GetData();

        //Set left child of a node
        void SetLeft(TreeNode<T>* left_child);

        //Set right child of a node
        void SetRight(TreeNode<T>* right_child);

        //Set parent of a node
        void SetParent(TreeNode<T>* parent);
    
        //Stored Data
        T m_Data;

        //Pointer to Left Child
        TreeNode<T>* m_Left;

        //Pointer to Right Child
        TreeNode<T>* m_Right;

        //Pointer to Parent Node
        TreeNode<T>* m_Parent;
};

template<typename T>
TreeNode<T>* TreeNode<T>::GetLeft() {
    return this->m_Left;
}

template<typename T>
TreeNode<T>* TreeNode<T>::GetRight() {
    return this->m_Right;
}

template<typename T>
TreeNode<T>* TreeNode<T>::GetParent() {
    return this->m_Parent;
}

template<typename T>
T TreeNode<T>::GetData() {
    return this->m_Data;
}


template<typename T>
void TreeNode<T>::SetLeft(TreeNode<T>* left_child) {
    this->m_Left = left_child;
}

template<typename T>
void TreeNode<T>::SetRight(TreeNode<T>* right_child) {
    this->m_Right = right_child;
}

template<typename T>
void TreeNode<T>::SetParent(TreeNode<T>* parent) {
    this->m_Parent = parent;
}


#endif // !TREENODE_H
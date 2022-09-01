/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * @file Tree.hpp
 * @author Grupo 1 y 20
 * @brief Tree class
 * Github: https://github.com/ChristopherIza/Arboles_AVL.git
 * @version 0.1
 * @date 2022-07-12
 * Date last modification: 2022-07-14
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef TREE_HPP
#define TREE_HPP

class Node;

class Tree {
    private:
        Node *root{};

        /**
         * @brief add a new int value to tree
         * 
         * @param value value to insert
         * @param root node root of tree object
         */
        void addRecursive(const int &value, Node *&root, Node *&father);

        /**
         * @brief Search a value in this tree
         * 
         * @param value to search
         * @return true if exist
         * @return false if don't exist
         */
        bool searchRecursive(const int &value, Node *&root);

        /**
         * @brief calculates the height of a node
         * 
         * @param node 
         * @return int 
         */
        int calculateHeightOfNode(Node *&node);

        /**
         * @brief Get the Balance Factor of a node
         * 
         * @param node 
         * @return int 
         */
        int calculateBalancingFactory(Node *&node);

        /**
         * @brief 
         * 
         * @param node 
         * @return Node*& 
         */
        Node *&findMaxNode(Node *&node);

        /**
         * @brief 
         * 
         * @param node 
         * @return Node*& 
         */
        Node *&findMinNode(Node *&node);

        /**
         * @brief Find a node that match with value parameter
         * 
         * @param root 
         * @param value 
         */
        void findNodeToRemove(const int &value, Node *&root);

        /**
         * @brief Remove a node of this tree
         * 
         * @param nodeToRomove 
         */
        void removeNode(Node *&nodeToRomove);

        /**
         * @brief Replace original node with new node
         * 
         * @param originalNode 
         * @param newNode 
         */
        void replaceNode(Node *&originalNode, Node *&newNode);
        /**
         * @brief Rotates when there is a unbalanced subtree
         * 
         * @param nodeToRotate 
         */
        void leftRotation(Node *&nodeToRotate);

        /**
         * @brief Rotates when there is a unbalanced subtree
         * 
         * @param node 
         */
        void rightRotation(Node *&nodeToRotate);

        /**
         * @brief Rotates when there is a unbalanced subtree
         * 
         * @param nodeToRotate 
         */
        void doubleRightRotation(Node *&nodeToRotate);

        /**
         * @brief Rotates when there is a unbalanced subtree
         * 
         * @param nodeToRotate 
         */
        void doubleLeftRotation(Node *&nodeToRotate);

        /**
         * @brief Verify balancing factor and apply algorithms of rotation
         * 
         * @param nodeToBalance 
         */
        void balance(Node *&nodeToBalance);

    public:
        /**
         * @brief Get the root node object
         * 
         * @return Node*& 
         */
        Node *&getRoot();

        /**
         * @brief insert a value in this tree
         * 
         * @param value 
         */
        void add(const int &value);

        /**
         * @brief seach a value in this tree
         * 
         * @param value 
         * @return true 
         * @return false 
         */
        bool search(const int &value);

        /**
         * @brief erase a value of this tree
         * 
         * @param value 
         * @return true if value exist
         * @return false if don't exist
         */
        void remove(const int &value);
};

#endif
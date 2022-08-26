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
        Node *root{nullptr};

        /**
         * @brief Verify if node is equal to root attribute or his father is null
         * 
         * @param node 
         * @return true 
         * @return false 
         */
        bool isRoot(Node *&node);

        /**
         * @brief Verify if node haven't left and right node
         * 
         * @param node 
         * @return true 
         * @return false 
         */
        bool isLeafNode(Node *&node);

        /**
         * @brief Verify if node have left node
         * 
         * @param node 
         * @return true 
         * @return false 
         */
        bool hasLeftSon(Node *&node);

        /**
         * @brief Verify if node have right node
         * 
         * @param node 
         * @return true 
         * @return false 
         */
        bool hasRightSon(Node *&node);

        /**
         * @brief Return level of a specified node = 1 + level of node father
         * 
         * @param node 
         * @return int 
         */
        int levelOfNodeRecursive(Node *&node);

        /**
         * @brief Return hight of a specified node = 1 + max hight between left node or right node
         * 
         * @param node 
         * @return int 
         */
        int hightOfNodeRecursive(Node *&node);

        /**
         * @brief Return the node with maximum value of the tree, rightmost node
         * 
         * @param root 
         * @return Node*& 
         */
        Node *&maxNodeRecursive(Node *&root);

        /**
         * @brief Return the node with maximum value of the tree, leftmost node
         * 
         * @param root 
         * @return Node*& 
         */
        Node *&minNodeRecursive(Node *&root);

        /**
         * @brief Return bancing factor of a specified node = hight(right node) - hight(left node)
         * 
         * @param node 
         * @return int 
         */
        int balancingFactor(Node *&node);

        /**
         * @brief Realize a left rotation when balnancing factor is greather or equal than 2
         * 
         * @param node 
         */
        void leftRotation(Node *&node);

        /**
         * @brief Realize a left rotation when balnancing factor is less or equal than -2
         * 
         * @param node 
         */
        void rightRotation(Node *&node);

        /**
         * @brief Realize a right rotation and then a left rotation
         * 
         * @param node 
         */
        void doubleLeftRotation(Node *&node);

        /**
         * @brief Realize a left rotation and then a right rotation
         * 
         * @param node 
         */
        void doubleRightRotation(Node *&node);

        /**
         * @brief Verify balance factor of a specified node and then realize the respective rotation
         * 
         * @param node 
         */
        void balance(Node *&node);

        /**
         * @brief Insert a value recursively, little values going to left and big values going to right of tree
         * 
         * @param value 
         * @param root 
         * @param father 
         */
        void addRecursive(const int &value, Node *&root, Node *father);

        /**
         * @brief Search the first instance of a value in this tree
         * 
         * @param value 
         * @param root 
         * @return true if exits
         * @return false if don't exist
         */
        bool searchValueRecursive(const int &value, Node *&root);

        /**
         * @brief Search a node with a specifed value, and return the first instance
         * 
         * @param value 
         * @param root 
         * @return Node*& 
         */
        Node *&searchNodeRecursive(const int &value, Node *&root);

        /**
         * @brief Remove a leaf node assign nullptr at father of node at his left or right
         * 
         * @param nodeToRemove 
         */
        void removeLeafNode(Node *nodeToRemove);

        /**
         * @brief Remove a node that has both sons replace the successor value and delete the node with successor value
         * 
         * @param nodeToRemove 
         */
        void removeNodeThatHasBothSons(Node *nodeToRemove);

        /**
         * @brief Replace the left node with actual node
         * 
         * @param nodeToRemove 
         */
        void removeNodeThatHasLeftSon(Node *nodeToRemove);

        /**
         * @brief Replace the right node with actual node
         * 
         * @param nodeToRemove 
         */
        void removeNodeThatHasRightSon(Node *nodeToRemove);

        /**
         * @brief Determinate if node to remove is leaf, have one or two sons and realize the respective operations
         * 
         * @param nodeToRemove 
         * @return true 
         * @return false 
         */
        bool removeRecursive(Node *nodeToRemove);

    public:
        /**
         * @brief Get the Root object
         * 
         * @return Node*& 
         */
        Node *&getRoot();

        /**
         * @brief Insert a value in this tree
         * 
         * @param value 
         */
        void add(const int &value);

        /**
         * @brief Search a value in this tree
         * 
         * @param value 
         * @return true 
         * @return false 
         */
        bool search(const int &value);

        /**
         * @brief Delete a value of this tree, if exist
         * 
         * @param value 
         * @return true 
         * @return false 
         */
        bool remove(const int &value);

        /**
         * @brief Return the maximum value of this tree, throw empty tree exception
         * 
         * @return int 
         */
        int maxValue();

        /**
         * @brief Return the minimum value of this tree, throw empty tree exception
         * 
         * @return int 
         */
        int minValue();
};

#endif
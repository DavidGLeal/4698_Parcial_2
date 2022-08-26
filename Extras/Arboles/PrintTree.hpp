/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * @file PrintTree.hpp
 * @author Grupo 1 y 20
 * @brief Class in charge of printing the data of the tree class in console
 * Github: https://github.com/ChristopherIza/Arboles_AVL.git
 * @version 0.1
 * @date 2022-07-12
 * Date last modification: 2022-07-14
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef PRINT_TREE_HPP
#define PRINT_TREE_HPP

#include <string>

class Node;
class Tree;

class PrintTree {
    private:
        /**
         * @brief print pre order recursively
         * 
         * @param root 
         */
        static void printPreOrderRecursive(Node *&root);

        /**
         * @brief print in order recursively
         * 
         * @param root 
         */
        static void printInOrderRecursive(Node *&root);

        /**
         * @brief print post order recursively
         * 
         * @param root 
         */
        static void printPostOrderRecursive(Node *&root);

        /**
         * @brief print tree on graphic format using recursive
         * 
         * @param tree 
         */
        static void printGraphicRecursive(Node *&root, std::string &information);

    public:

        /**
         * @brief print pre order
         * 
         * @param root 
         */
        static void printPreOrder(Tree &tree);

        /**
         * @brief print in order
         * 
         * @param root 
         */
        static void printInOrder(Tree &tree);

        /**
         * @brief print post order
         * 
         * @param root 
         */
        static void printPostOrder(Tree &tree);

        /**
         * @brief print tree on graphic format
         * 
         * @param tree 
         */
        static void printGraphic(Tree &tree);
};

#endif
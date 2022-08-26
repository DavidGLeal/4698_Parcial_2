/**
 * @file PDFManager.hpp
 * @author Grupo 1 y 20
 * @brief Class that manage files PDF and save information of Tree class
 * @brief Github: https://github.com/ChristopherIza/Arboles_AVL.git
 * @version 0.1
 * @date 2022-07-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef PDF_MANAGER_HPP
#define PDF_MANAGER_HPP
#include <string>
#include "pdf.hpp"
#include "Tree.hpp"

class Tree;
class Node;

class PDFManager
{
private:

    /**
     * @brief get in Order recursively
     * 
     * @param root 
     */
    void Recursive_getInOrder(Node *&root);

    /**
     * @brief get in Pre Order recursively
     * 
     * @param root 
     */
    void Recursive_getPreOrder(Node *&root);

    /**
     * @brief get Post Order recursively
     * 
     * @param root 
     */
    void Recursive_getPostOrder(Node *&root);


public:
    /**
     * @brief generate PDF with the Orders
     * 
     */
    static void generatePDF(Tree);

    /**
     * @brief Get the In Order tree
     * 
     * @param tree 
     */
    void getInORder(Tree &tree);

    /**
     * @brief Get the Pre Order tree
     * 
     * @param tree 
     */
    void getPreOrder(Tree &tree);

    /**
     * @brief Get the Post Order tree
     * 
     * @param tree 
     */
    void getPostOrder(Tree &tree);

    /**
     * @brief Convertion vector <int> to string 
     * 
     * @return std::string 
     */
    std::string convert_(std::vector<int>);
};
#endif
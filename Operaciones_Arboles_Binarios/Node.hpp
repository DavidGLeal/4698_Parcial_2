/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * @file Node.hpp
 * @author Grupo 1 y 20
 * @brief Node class
 * Github: https://github.com/ChristopherIza/Arboles_AVL.git
 * @version 0.1
 * @date 2022-07-10
 * Date last modification: 2022-07-14
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef NODE_HPP
#define NODE_HPP

class Node {
    private:
        int value{};
        Node *father{nullptr};
        Node *left{nullptr};
        Node *right{nullptr};

    public:
        /**
         * @brief Construct a new Node object
         * 
         * @param value 
         */
        Node(const int &initialValue, Node *&father);

        /**
         * @brief Get the Father object
         * 
         * @return Node*& 
         */
        Node *&getFather();

        /**
         * @brief Set the Father object
         * 
         * @param newFather 
         */
        void setFather(Node *&newFather);

        /**
         * @brief Get the Value object
         * 
         * @return int& 
         */
        int &getValue();

        /**
         * @brief Set a new value in this Node
         * 
         * @param newValue 
         */
        void setValue(const int &newValue);

        /**
         * @brief Get the Left Node object
         * 
         * @return Node*& 
         */
        Node *&getLeftNode();

        /**
         * @brief Set the Left Node object
         * 
         * @param newLeftNode 
         */
        void setLeftNode(Node *&newLeftNode);

        /**
         * @brief Get the Right Node object
         * 
         * @return Node*& 
         */
        Node *&getRightNode();

        /**
         * @brief Set the Right Node object
         * 
         * @param newRightNode 
         */
        void setRightNode(Node *&newRightNode);

        /**
         * @brief Destroy the Node object
         * 
         */
        ~Node();
};

#endif
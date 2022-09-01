#include "Tree.hpp"
#include "Node.hpp"
#include <iostream>

void Tree::addRecursive(const int &value, Node *&root, Node *&father) {
    if (root == nullptr) {
        Node *newNode = new Node(value, father);
        root = newNode;
        balance(root);

    } else if (value < root->getValue()) {
        addRecursive(value, root->getLeftNode(), root);

    } else {
        addRecursive(value, root->getRightNode(), root);
    }
}

bool Tree::searchRecursive(const int &value, Node *&root) {
    if (root == nullptr)
        return false;

    else if (value == root->getValue())
        return true;

    else if (value < root->getValue())
        return searchRecursive(value, root->getLeftNode());

    else
        return searchRecursive(value, root->getRightNode());
}

int Tree::calculateHeightOfNode(Node *&node){
    if(node == nullptr)
        return 0;

    int heightLeftNode = calculateHeightOfNode(node->getLeftNode());
    int heightRightNode = calculateHeightOfNode(node->getRightNode());

    if (heightLeftNode > heightRightNode)
        return 1 + heightLeftNode;
    
    else
        return 1 + heightRightNode;
}

int Tree::calculateBalancingFactory(Node *&node){ return calculateHeightOfNode(node->getRightNode()) - calculateHeightOfNode(node->getLeftNode()); }

Node *&Tree::findMaxNode(Node *&node){
    if(node == nullptr)
        return node;
    else if(node->getRightNode() == nullptr)
        return node;
    else 
        return findMaxNode(node->getRightNode());
}

Node *&Tree::findMinNode(Node *&node){
    if(node == nullptr)
        return node;
    else if(node->getLeftNode() == nullptr)
        return node;
    else 
        return findMinNode(node->getLeftNode());
}

void Tree::findNodeToRemove(const int &value, Node *&root) {
    if (root == nullptr)
        return;

    else if (value < root->getValue())
        findNodeToRemove(value, root->getLeftNode());

    else if (value > root->getValue())
        findNodeToRemove(value, root->getRightNode());

    else {
        Node *fatherOfNodeToRemove{root->getFather()};
        removeNode(root);
        balance(fatherOfNodeToRemove);
    }
}

void Tree::removeNode(Node *&nodeToRomove) {
    if (nodeToRomove->getLeftNode() != nullptr && nodeToRomove->getRightNode() != nullptr) {

        Node *&minimumNode = findMinNode(nodeToRomove->getRightNode());
        nodeToRomove->setValue(minimumNode->getValue());
        removeNode(minimumNode);

    } else if (nodeToRomove->getLeftNode() != nullptr) {
        replaceNode(nodeToRomove, nodeToRomove->getLeftNode());
        delete nodeToRomove;

    } else if (nodeToRomove->getRightNode() != nullptr) {
        replaceNode(nodeToRomove, nodeToRomove->getRightNode());
        delete nodeToRomove;

    } else {
        Node *nullNode{};
        replaceNode(nodeToRomove, nullNode);
        delete nodeToRomove;
    }
}

void Tree::replaceNode(Node *&originalNode, Node *&newNode) {
    if (originalNode->getFather() != nullptr) {

        if (originalNode->getValue() == originalNode->getFather()->getLeftNode()->getValue())
            originalNode->getFather()->setLeftNode(newNode);

        else if (originalNode->getValue() == originalNode->getFather()->getRightNode()->getValue())
            originalNode->getFather()->setRightNode(newNode);
    }

    if (newNode != nullptr)
        newNode->getFather() = originalNode->getFather();
}

void Tree::leftRotation(Node *&nodeToRotate) {
    Node *father{nodeToRotate->getFather()};
    Node *aux{nodeToRotate->getRightNode()};
    Node *grandson{aux->getLeftNode()};

    nodeToRotate->setRightNode(grandson);
    aux->setLeftNode(nodeToRotate);

    if (grandson != nullptr)
        grandson->setFather(nodeToRotate);

    nodeToRotate->setFather(aux);

    if (father == nullptr) {
        this->root = aux;

    } else {

        aux->setFather(father);

        if (aux->getValue() >= father->getValue())
            father->setRightNode(aux);
        else
            father->setLeftNode(aux);
    }

    aux->setBalancingFactory(calculateBalancingFactory(aux));
    nodeToRotate->setBalancingFactory(calculateBalancingFactory(nodeToRotate));
}

void Tree::rightRotation(Node *&nodeToRotate) {
    Node *father{nodeToRotate->getFather()};
    Node *aux{nodeToRotate->getLeftNode()};
    Node *grandson{aux->getRightNode()};

    nodeToRotate->setLeftNode(grandson);
    aux->setRightNode(nodeToRotate);

    if (grandson != nullptr)
        grandson->setFather(nodeToRotate);

    nodeToRotate->setFather(aux);

    if (father == nullptr) {
        this->root = aux;

    } else {

        aux->setFather(father);

        if (aux->getValue() >= father->getValue())
            father->setRightNode(aux);
        else
            father->setLeftNode(aux);
    }

    aux->setBalancingFactory(aux->getBalancingFactory());
    nodeToRotate->setBalancingFactory(nodeToRotate->getBalancingFactory());
}

void Tree::doubleRightRotation(Node *&nodeToRotate) {
    leftRotation(nodeToRotate->getLeftNode());
    rightRotation(nodeToRotate);
}

void Tree::doubleLeftRotation(Node *&nodeToRotate) {
    rightRotation(nodeToRotate->getRightNode());
    leftRotation(nodeToRotate);
}

void Tree::balance(Node *&nodeToBalance) {
    if (nodeToBalance != nullptr) {
        Node *fatherOfNodeToBalance{nodeToBalance->getFather()};
        nodeToBalance->setBalancingFactory(calculateBalancingFactory(nodeToBalance));

        if (nodeToBalance->getBalancingFactory() > 1) {

            if (calculateBalancingFactory(nodeToBalance->getRightNode()) < 0) {
                doubleLeftRotation(nodeToBalance);
            } else {
                leftRotation(nodeToBalance);
            }

        } else if (nodeToBalance->getBalancingFactory() < -1) {

            if (calculateBalancingFactory(nodeToBalance->getLeftNode()) > 0) {
                doubleRightRotation(nodeToBalance);
            } else {
                rightRotation(nodeToBalance);
            }

        }

        balance(fatherOfNodeToBalance);
    }
}

Node *&Tree::getRoot() { return this->root; }

void Tree::add(const int &value) {
    Node *nullNode{};
    addRecursive(value, this->root, nullNode);
}

bool Tree::search(const int &value) { return searchRecursive(value, this->root); }

void Tree::remove(const int &value) { findNodeToRemove(value, this->root); }
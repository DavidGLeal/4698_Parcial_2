#include "Tree.hpp"
#include "Node.hpp"
#include <iostream>

bool Tree::isRoot(Node *&node) { return node == this->root || node->getFather() == nullptr; }

bool Tree::isLeafNode(Node *&node) { return node->getLeftNode() == nullptr && node->getRightNode() == nullptr; }

bool Tree::hasLeftSon(Node *&node) { return node->getLeftNode() != nullptr; }

bool Tree::hasRightSon(Node *&node) { return node->getRightNode() != nullptr; }

int Tree::levelOfNodeRecursive(Node *&node) {
    if (isRoot(node))
        return 0;
    else
        return 1 + levelOfNodeRecursive(node->getFather());
}

int Tree::hightOfNodeRecursive(Node *&node) {
    if (node == nullptr)
        return -1;

    int hightLeft{hightOfNodeRecursive(node->getLeftNode())};
    int hightRight{hightOfNodeRecursive(node->getRightNode())};

    if (hightLeft > hightRight)
        return 1 + hightLeft;
    else
        return 1 + hightRight;
}

Node *&Tree::maxNodeRecursive(Node *&root) {
    if (!hasRightSon(root))
        return root;
    else
        return maxNodeRecursive(root->getRightNode());
}

Node *&Tree::minNodeRecursive(Node *&root) {
    if (!hasLeftSon(root))
        return root;
    else
        return minNodeRecursive(root->getLeftNode());
}

int Tree::balancingFactor(Node *&node) {
    return hightOfNodeRecursive(node->getRightNode()) - hightOfNodeRecursive(node->getLeftNode());;
}

void Tree::leftRotation(Node *&node) {
    Node *nodeFather{node->getFather()};
    Node *nodeP{node};
    Node *nodeQ{node->getRightNode()};
    Node *nodeAux{nodeQ->getLeftNode()};

    nodeP->setRightNode(nodeAux);
    nodeQ->setLeftNode(nodeP);

    if (nodeAux != nullptr)
        nodeAux->setFather(nodeP);

    nodeP->setFather(nodeQ);

    if (nodeFather == nullptr) {
        nodeQ->setFather(nodeFather);
        this->root = nodeQ;
    } else {
        if (nodeQ->getValue() < nodeFather->getValue())
            nodeFather->setLeftNode(nodeQ);
        else
            nodeFather->setRightNode(nodeQ);

        nodeQ->setFather(nodeFather);
    }
}

void Tree::rightRotation(Node *&node) {
    Node *nodeFather{node->getFather()};
    Node *nodeP{node};
    Node *nodeQ{node->getLeftNode()};
    Node *nodeAux{nodeQ->getRightNode()};

    nodeP->setLeftNode(nodeAux);
    nodeQ->setRightNode(nodeP);

    if (nodeAux != nullptr)
        nodeAux->setFather(nodeP);

    nodeP->setFather(nodeQ);

    if (nodeFather == nullptr) {
        nodeQ->setFather(nodeFather);
        this->root = nodeQ;
    } else {
        if (nodeQ->getValue() < nodeFather->getValue())
            nodeFather->setLeftNode(nodeQ);
        else
            nodeFather->setRightNode(nodeQ);

        nodeQ->setFather(nodeFather);
    }
}

void Tree::doubleLeftRotation(Node *&node) {
    rightRotation(node->getRightNode());
    leftRotation(node);
}

void Tree::doubleRightRotation(Node *&node) {
    leftRotation(node->getLeftNode());
    rightRotation(node);
}

void Tree::balance(Node *&node) {
    
    if (node == nullptr)
        return;

    Node *fatherOfNodeBalanced{node->getFather()};

    if (balancingFactor(node) >= 2) {

        if (balancingFactor(node->getRightNode()) <= -1)
            doubleLeftRotation(node);
        else
            leftRotation(node);
        
    } else if (balancingFactor(node) <= -2) {
        
        if (balancingFactor(node->getLeftNode()) >= 1)
            doubleRightRotation(node);
        else
            rightRotation(node);
    }

    balance(fatherOfNodeBalanced);
}

void Tree::addRecursive(const int &value, Node *&root, Node *father) {
    if (root == nullptr) {
        Node *newNode = new Node(value, father);
        root = newNode;
        balance(root->getFather());
    } else if (value < root->getValue()) {
        addRecursive(value, root->getLeftNode(), root);

    } else {
        addRecursive(value, root->getRightNode(), root);
    }
}

bool Tree::searchValueRecursive(const int &value, Node *&root) {
    if (root == nullptr)
        return false;

    else if (value == root->getValue())
        return true;

    else if (value < root->getValue())
        return searchValueRecursive(value, root->getLeftNode());

    else
        return searchValueRecursive(value, root->getRightNode());
}

Node *&Tree::searchNodeRecursive(const int &value, Node *&root) {
    if (root == nullptr)
        return root;

    if (value < root->getValue())
        return searchNodeRecursive(value, root->getLeftNode());

    else if (value > root->getValue())
        return searchNodeRecursive(value, root->getRightNode());

    else
        return root;
}

void Tree::removeLeafNode(Node *nodeToRemove) {
    Node *father{nodeToRemove->getFather()};

    if (isRoot(nodeToRemove))
        this->root = nullptr;

    else if (nodeToRemove == nodeToRemove->getFather()->getLeftNode())
        nodeToRemove->getFather()->getLeftNode() = nullptr;

    else
        nodeToRemove->getFather()->getRightNode() = nullptr;

    delete nodeToRemove;
    nodeToRemove = nullptr;

    balance(father);
}

void Tree::removeNodeThatHasBothSons(Node *nodeToRemove) {
    Node *successor{minNodeRecursive(nodeToRemove->getRightNode())};

    nodeToRemove->setValue(successor->getValue());

    removeRecursive(successor);
}

void Tree::removeNodeThatHasLeftSon(Node *nodeToRemove) {
    Node *father{nodeToRemove->getFather()};

    if (!isRoot(nodeToRemove)) {
            
        if (nodeToRemove->getValue() < nodeToRemove->getFather()->getValue())
            nodeToRemove->getFather()->setLeftNode(nodeToRemove->getLeftNode());
        else
            nodeToRemove->getFather()->setRightNode(nodeToRemove->getLeftNode());

        nodeToRemove->getLeftNode()->setFather(nodeToRemove->getFather());

    } else {
        this->root = nodeToRemove->getLeftNode();
        this->root->getFather() = nullptr;
    }

    delete nodeToRemove;
    nodeToRemove = nullptr;

    balance(father);
}

void Tree::removeNodeThatHasRightSon(Node *nodeToRemove) {
    Node *father{nodeToRemove->getFather()};

    if (!isRoot(nodeToRemove)) {

        if (nodeToRemove->getValue() < nodeToRemove->getFather()->getValue())
            nodeToRemove->getFather()->setLeftNode(nodeToRemove->getRightNode());
        else
            nodeToRemove->getFather()->setRightNode(nodeToRemove->getRightNode());

        nodeToRemove->getRightNode()->setFather(nodeToRemove->getFather());

    } else {
        this->root = nodeToRemove->getRightNode();   
        this->root->getFather() = nullptr;
    }

    delete nodeToRemove;
    nodeToRemove = nullptr;

    balance(father);
}

bool Tree::removeRecursive(Node *nodeToRemove) {
    if (nodeToRemove == nullptr)
        return false;

    if (isLeafNode(nodeToRemove))
        removeLeafNode(nodeToRemove);
        
    else if (hasLeftSon(nodeToRemove) && hasRightSon(nodeToRemove))
        removeNodeThatHasBothSons(nodeToRemove);
        
    else if (hasLeftSon(nodeToRemove))
        removeNodeThatHasLeftSon(nodeToRemove);

    else if (hasRightSon(nodeToRemove))
        removeNodeThatHasRightSon(nodeToRemove);

    return true;
}

Node *&Tree::getRoot() { return this->root; }

void Tree::add(const int &value) { addRecursive(value, this->root, nullptr); }

bool Tree::search(const int &value) { return searchValueRecursive(value, this->root); }

bool Tree::remove(const int &value) {
    Node *nodeToRemove{searchNodeRecursive(value, this->root)};
    return removeRecursive(nodeToRemove);
}

int Tree::maxValue() {
    if (this->root == nullptr)
        throw "Empty tree exception";

    return maxNodeRecursive(this->root)->getValue();
}

int Tree::minValue() {
    if (this->root == nullptr)
        throw "Empty tree exception";

    return minNodeRecursive(this->root)->getValue();
}
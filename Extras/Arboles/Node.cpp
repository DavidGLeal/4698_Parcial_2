#include "Node.hpp"

Node::Node(const int &initialValue, Node *&initialFather) {
    this->value = initialValue;
    this->father = initialFather;
}

Node *&Node::getFather() { return this->father; }

void Node::setFather(Node *&newFather) { this->father = newFather; }

int &Node::getValue() { return this->value; }

void Node::setValue(const int &newValue) { this->value = newValue; }

Node *&Node::getLeftNode() { return this->left; }

void Node::setLeftNode(Node *&newLeftNode) { this->left = newLeftNode; }

Node *&Node::getRightNode() { return this->right; }

void Node::setRightNode(Node *&newRightNode) { this->right = newRightNode; }

Node::~Node() {
    this->father = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}
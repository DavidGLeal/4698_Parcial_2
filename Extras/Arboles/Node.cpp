#include "Node.hpp"

Node::Node(const int &initialValue, Node *&initialFather) :
    value(initialValue),
    father(initialFather)
{}

Node *&Node::getFather() { return this->father; }

void Node::setFather(Node *&newFather) { this->father = newFather; }

int &Node::getValue() { return this->value; }

void Node::setValue(const int &newValue) { this->value = newValue; }

Node *&Node::getLeftNode() { return this->left; }

void Node::setLeftNode(Node *&newLeftNode) { this->left = newLeftNode; }

Node *&Node::getRightNode() { return this->right; }

void Node::setRightNode(Node *&newRightNode) { this->right = newRightNode; }

int &Node::getHeight() { return this->height; }

void Node::setHeight(const int &newHeight) { this->height = newHeight; }

int &Node::getBalancingFactory() { return this->balancingFactory; }

void Node::setBalancingFactory(const int &newBalancingFactory) { this->balancingFactory = newBalancingFactory; }

Node::~Node() {
    this->father = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}
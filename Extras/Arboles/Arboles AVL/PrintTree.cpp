#include "PrintTree.hpp"
#include "Tree.hpp"
#include "Node.hpp"
#include <iostream>

void PrintTree::printPreOrderRecursive(Node *&root) {
    if (root != nullptr) {
        std::cout << root->getValue() << ' ';
        printPreOrderRecursive(root->getLeftNode());
        printPreOrderRecursive(root->getRightNode());
    }
}

void PrintTree::printInOrderRecursive(Node *&root) {
    if (root != nullptr) {
        printInOrderRecursive(root->getLeftNode());
        std::cout << root->getValue() << ' ';
        printInOrderRecursive(root->getRightNode());
    }
}

void PrintTree::printPostOrderRecursive(Node *&root) {
    if (root != nullptr) {
        printPostOrderRecursive(root->getLeftNode());
        printPostOrderRecursive(root->getRightNode());
        std::cout << root->getValue() << ' ';
    }
}

const char VERTICAL_LINE = 179;
const std::string VERTICAL_LINE_STR{VERTICAL_LINE};
const char FINAL_LINK = 192;
const char INTERMEDIUM_LINK = 195;
const char HORIZONTAL_LINE = 196;
void PrintTree::printGraphicRecursive(Node *&root, std::string &graphic) {
    if (root != nullptr)
        std::cout << root->getValue() << '\n';

    if (root->getLeftNode() != nullptr) {
        std::string graphicLeftNode{graphic};

        if (root->getRightNode() != nullptr) {
            std::cout << graphic << INTERMEDIUM_LINK;

            for (int i{}; i < 4; i++) {
                printf("%c", HORIZONTAL_LINE);
            }
            
            graphicLeftNode += VERTICAL_LINE_STR + "     ";
            printGraphicRecursive(root->getLeftNode(), graphicLeftNode);

        } else {

            std::cout << graphic << FINAL_LINK;

            for (int i{}; i < 4; i++) {
                printf("%c", HORIZONTAL_LINE);
            }

            graphicLeftNode += "     ";
            printGraphicRecursive(root->getLeftNode(), graphicLeftNode);
        }
    }

    if (root->getRightNode() != nullptr) {
        std::string graphicRightNode{graphic};

        std::cout << graphic << FINAL_LINK;

        for (int i{}; i < 4; i++) {
            printf("%c", HORIZONTAL_LINE);
        }

        graphicRightNode += "     ";
        printGraphicRecursive(root->getRightNode(), graphicRightNode);
    }
}

void PrintTree::printPreOrder(Tree &tree) { printPreOrderRecursive(tree.getRoot()); }

void PrintTree::printInOrder(Tree &tree) { printInOrderRecursive(tree.getRoot()); }

void PrintTree::printPostOrder(Tree &tree) { printPostOrderRecursive(tree.getRoot()); }

void PrintTree::printGraphic(Tree &tree) {
    if (tree.getRoot() != nullptr) {
        std::string graphic{};
        printGraphicRecursive(tree.getRoot(), graphic);
    }
}
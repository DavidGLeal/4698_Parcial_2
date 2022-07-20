#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector;

struct ListNode {
    struct ListNode *siguiente = nullptr;
    struct ListNode *previo = nullptr;
    string dato;
} typedef ListNode;

class CircularList {
public:
    explicit CircularList(string dato) {
        cabeza = new ListNode;
        cabeza->siguiente = cabeza;
        cabeza->previo = cabeza;
        cabeza->dato = std::move(dato);
        final = cabeza;
    };

    ListNode *insertNodoFinal(string dato);
    ListNode *insertarNodopoCabeza(string dato);
    void printNodes();

    ~CircularList();
private:
    ListNode *cabeza = nullptr;
    ListNode *final = nullptr;
};

ListNode *CircularList::insertNodoFinal(string dato) {
    auto new_node = new ListNode;
    new_node->siguiente = cabeza;
    new_node->previo = final;
    new_node->dato = std::move(dato);

    cabeza->previo = new_node;
    final->siguiente = new_node;
    final = final->siguiente;
    return final;
}

ListNode *CircularList::insertarNodopoCabeza(string dato) {
    auto new_node = new ListNode;
    new_node->siguiente = cabeza;
    new_node->previo = final;
    new_node->dato = std::move(dato);

    cabeza->previo = new_node;
    final->siguiente = new_node;
    cabeza = new_node;
    return cabeza;
}

CircularList::~CircularList() {
    while (cabeza != final) {
        auto tmp = cabeza;
        cabeza = cabeza->siguiente;
        delete tmp;
    }
    delete cabeza;
}

void CircularList::printNodes() {
    auto count = 0;
    auto tmp = cabeza;
    while (tmp != final){
        cout << "nodo " << count << " - dato: " << tmp->dato << endl;
        tmp = tmp->siguiente;
        count++;
    }
    cout << "nodo " << count << " - dato: " << tmp->dato << endl;
}

int main() {
    CircularList clist("Hola");

    clist.insertarNodopoCabeza("Hi");
    clist.insertNodoFinal("Konichiwa");

    clist.printNodes();
    cout << " ----------------------------------- " << endl;

    clist.insertarNodopoCabeza("Salut");
    clist.printNodes();

    return EXIT_SUCCESS;
}
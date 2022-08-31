#include <iostream>
#include "Exhaustivo.h"

using namespace std;

int main()
{
    Exhaustivo obj;
    int pollo, conejo, cabeza, pie;
    int re;
    cout << " El método exhaustivo se utiliza para resolver el problema:" << endl;
    cout << " Introduzca el número de cabezas: ";
    cin >> cabeza;
    cout << " Introduzca el número de pies: ";
    cin >> pie;
    re = obj.metodoexhaustivo(cabeza, pie, &pollo, &conejo);
    if (re == 1)
    {
        cout << " El pollo tiene " << pollo << " Es el único, conejo " << conejo << " Solamente. " << endl;
    }
    else
    {
        cout << " Error no se puede resolver! " << endl;
    }
    return 0;
}
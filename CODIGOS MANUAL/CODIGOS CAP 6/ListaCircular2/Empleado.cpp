#include "Empleado.h"

Empleado::Empleado(/* args */)
{
}

Empleado::~Empleado()
{
}

Empleado *Empleado::insertar_nodo_inicial()
{
    Empleado *crear;
    crear = new Empleado;
    cout << "IDENTIFICACION: ";
    cin >> crear->ident;
    cout << "APELLIDO: ";
    cin >> crear->ap;
    cout << "NOMBRE: ";
    cin >> crear->nom;
    cout << "CARGO: ";
    cin >> crear->cargo;
    cout << "SUELDO: ";
    cin >> crear->sueldo;
    crear->avanc = crear;
    return crear;
}

// insertar nodo

void Empleado::insertar_nodos_circular(Empleado *&cab, int c)

{
    Empleado *aux;
    Empleado *r;
    if (cab != NULL)
    {
        r = cab;
        aux = new Empleado;
        while (r->ident != c && r->avanc != cab)
            r = r->avanc;
        if (r == cab)
        {
            aux->ident = c;
            cout << "APELLIDO: ";
            cin >> aux->ap;
            cout << "NOMBRE: ";
            cin >> aux->nom;
            cout << "CARGO: ";
            cin >> aux->cargo;
            cout << "SUELDO: ";
            cin >> aux->sueldo;
            aux->avanc = r->avanc;
            r->avanc = aux;
            r = aux;
        }
        else
        {
            aux->avanc = r->avanc;
            r->avanc = aux;
            aux->ident = c;
            cout << "APELLIDO: ";
            cin >> aux->ap;
            cout << "NOMBRE: ";
            cin >> aux->nom;
            cout << "CARGO: ";
            cin >> aux->cargo;
            cout << "SUELDO: ";
            cin >> aux->sueldo;
        }
    }

    else

        cout << "no hay nodo inicial de lista por favor digite 1";
}

// prog en c++

int Empleado::progenc(Empleado *cab)

{
    Empleado *q;
    int cant = 0;
    q = cab;
    if (cab)
    {
        while (q->avanc != cab)
        {
            if (strcmp(q->cargo, "programador") == 0)
            {
                cout << "\n";
                cant = cant + 1;
                q = q->avanc;
            }
            else
            {
                cout << "No hay ningun empleado con el cargo de progrmador";
            }
        }
    }
    else
        cout << "no existe lista";
    return cant;
    getch();
}

// SUELDO

void Empleado::empleadosmayora(Empleado *cab)
{
    Empleado *p;
    p = cab;
    if (cab)
    {
        if (cab->sueldo > 500)
        {
            cout << "IDENTIFICACION: " << cab->ident;
            cout << "\n";
            cout << "APELLIDO: " << cab->ap;
            cout << "\n";
            cout << "NOMBRE: " << cab->nom;
            cout << "\n";
            cout << "CARGO: " << cab->cargo;
            cout << "\n";
            cout << "SUELDO: " << cab->sueldo;
            cout << "\n";
        }

        p = cab->avanc;
        while (p != cab)
        {
            if (p->sueldo > 500 && p != cab)
            {
                cout << "\n";
                cout << "IDENTIFICACION: " << p->ident;
                cout << "\n";
                cout << "APELLIDO: " << p->ap;
                cout << "\n";
                cout << "NOMBRE: " << p->nom;
                cout << "\n";
                cout << "CARGO: " << p->cargo;
                cout << "\n";
                cout << "SUELDO: " << p->sueldo;
                cout << "\n";
            }
            else
            {
                cout << "No hay empleados registrados";
            }
            p = p->avanc;
        }
    }
    else
        cout << "no existe lista";
    getch();
}

// SUMANOMINA

void Empleado::sumanomina(Empleado *cab)
{
    Empleado *q;
    double sumnomina = 0;
    q = cab->avanc;
    if (cab)
    {
        sumnomina = cab->sueldo + sumnomina;
    }
    while (q != cab)
    {
        sumnomina = cab->sueldo + sumnomina;
        q = q->avanc;
    }
    cout << "El total de la nomina es " << sumnomina;
    getch();
}

void Empleado::imprime_lista_circ(Empleado *cab)

{
    Empleado *q;
    if (cab == NULL)
        cout << "No hay lista";
    else if (cab->avanc == cab)
    {
        cout << "\n";
        cout << "Cedula:" << cab->ident;
        cout << "\n";
        cout << "Apellido:" << cab->ap;
        cout << "\n";
        cout << "Nombre:" << cab->nom;
        cout << "\n";
        cout << "Cargo:" << cab->cargo;
        cout << "\n";
        cout << "Sueldo:" << cab->sueldo;
        cout << "\n";
    }
    else
    {
        q = cab;
        cout << "\n";
        cout << "Cedula:" << cab->ident;
        cout << "\n";
        cout << "Apellido:" << cab->ap;
        cout << "\n";
        cout << "Nombre:" << cab->nom;
        cout << "\n";
        cout << "Cargo:" << cab->cargo;
        cout << "\n";
        cout << "Sueldo:" << cab->sueldo;
        cout << "\n";
        q = cab->avanc;
        do
        {
            cout << "\n";
            cout << "Cedula:" << q->ident;
            cout << "\n";
            cout << "Apellido:" << q->ap;
            cout << "\n";
            cout << "Nombre:" << q->nom;
            cout << "\n";
            cout << "Cargo:" << q->cargo;
            cout << "\n";
            cout << "Sueldo:" << q->sueldo;
            cout << "\n";
            q = q->avanc;
        } while (q != cab);
    }
    getch();
}

// ELIMINAR NODO

void Empleado::eliminar_nodo_circ(Empleado *&cab, int i)
{
    Empleado *q, *r;
    q = r = cab;
    if (cab == NULL)
        cout << "no hay cabeza";
    else if (cab->avanc == cab && cab->ident == i)
    {
        delete (q);
    }
    else
        while ((q->ident != i) && (q->avanc != cab))
        {
            q = q->avanc;
        }
    if (cab->avanc == q)
    {
        cab->avanc = q->avanc;
        delete (q);
    }
    else
    {
        while (r->avanc != q)
        {
            r = r->avanc;
        }
        r->avanc = q->avanc;
        delete (q);
    }
}
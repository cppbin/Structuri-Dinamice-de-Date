/** simularea functionarii unei stive
prin algerea unor optiuni dintr-un meniu **/

#include <iostream>
using namespace std;

struct nod
{
    int info;
    nod *urm;
}*prim;

void adauga_la_inceput()
{
    nod *p;
    p = new nod;

    cout << "info = "; cin >> p->info;
    p->urm = prim;

    prim = p;
    cout << "s-a adaugat";
}

void sterge_la_inceput()
{
    nod *p;
    if(prim == NULL)
        cout << "Nu exista noduri de sters";
    else
    {
        p = prim;
        prim = prim->urm;
        delete p;
    }
}

void parcurgere()
{
    nod *p;
    p = prim;
    if(prim == NULL)
       cout << "Stiva este vida!";
    else
    {
        while(p != NULL)
        {
            cout << p->info << " ";
            p = p->urm;
        }
    }
}

int main()
{
    int opt;
    do
    {
        cout << endl << "1. Adaugare";
        cout << endl << "2. Stergere";
        cout << endl << "3. Parcurgere";
        cout << endl << "4. IESIRE";
        cout << endl << "Optiune = "; cin >> opt;
        switch(opt)
        {
            case 1: adauga_la_inceput();
                    break;
            case 2: sterge_la_inceput();
                    break;
            case 3: parcurgere();
                    break;
        }
    }while(opt!=4);
    return 0;
}

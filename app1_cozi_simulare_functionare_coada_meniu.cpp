/** Simulati functionarea unei cozi pe baza unui meniu **/

#include <iostream>
using namespace std;

struct nod
{
    int info;
    nod *urm;
}*prim, *ultim;

void adauga()
{
    nod *p = new nod;

    cout << "info = "; cin >> p->info;
    p->urm = NULL;

    if(ultim != NULL)
        ultim->urm = p;
    else
        prim = p;
    ultim = p;
}

void sterge()
{
    nod *p = prim;
    if(prim == NULL)
        cout << "Eroare-stergere imposibila-nu exista noduri";
    else
    {
        prim = prim->urm;
        delete p;
        if(prim == NULL)
            ultim = NULL;
    }
}

void parcurgere()
{
    nod *p = prim;
    if(prim == NULL)
        cout << endl << "Coada este vida!";
    else
        while(p!=NULL)
        {
            cout << p->info << "  ";
            p = p->urm;
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
        cout << endl << "4. Iesire";
        cout << endl << "Optiune = "; cin >> opt;
        switch(opt)
       {
           case 1: adauga();
                   break;
           case 2: sterge();
                   break;
           case 3 : parcurgere();
                    break;
       }
    }while(opt != 4);
    return 0;
}



/**
Scrieți un program care implementează următoarele funcții:

a) Creează o coadă, cu valori citite dintr-un fișier
b) Afișează conținutul  unei cozi, elementele
   fiind separate prin caracterul |, precum în exemplul
   următor:  | 7 | 213 | -9 | 4 | 7 | -4 |
c) Copiază coada C1 la sfârșitul lui C2
d) Verifică dacă această coada este ordonată;
e) Creează o nouă coadă care conține
   toate elementele din prima coadă
   care ocupau poziții pare.
**/

#include <iostream>
#include <fstream>
using namespace std;

struct nod
{
    int info;
    nod *urm;
}*prim, *ultim, *prim2, *ultim2;

ifstream f("date.txt");

void adauga(int x)
{
    nod *p = new nod;
    p->info = x;
    p->urm = NULL;
    if(ultim != NULL)
        ultim -> urm = p;
    else
        prim = p;
    ultim = p;
}

void parcurgere(nod *pr)
{
    nod *p = pr;
    while(p != NULL)
    {
        cout << " | " << p->info;
        p = p->urm;
    }
    cout << " |";
}

void adauga2()
{
    nod *p = new nod;
    cout << "info= "; cin >> p->info;
    p->urm = NULL;
    if(ultim2 != NULL)
        ultim2->urm = p;
    else
        prim2 = p;
    ultim2 = p;
}

int main()
{
    int x;
    while(!f.eof())
    {
        f >> x;
        adauga(x);
    }
    parcurgere(prim);

    cout << endl << ".. se creeaza coada C2";
    int n, i;
    cout << "cate noduri ? "; cin >> n;
    for(i = 0; i < n; i++)
        adauga2();
    cout << endl << "coada 2: ";
    parcurgere(prim2);
    return 0;
}

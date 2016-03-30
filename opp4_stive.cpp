/** Se creeaza o stiva cu camp informational de tip int.
sa se afiseze cel mai mare numar care exista in stiva. **/

#include <iostream>
using namespace std;

struct nod
{
  int info;
  nod *urm;
}*prim;

void adauga()
{
    nod *p = new nod;

    cout << "info = "; cin >> p->info;
    p->urm = prim;

    prim = p;
}

int maxim()
{
    int m = prim->info;
    nod *p = prim->urm;
    while(p != NULL)
    {
        if(p->info > m)
            m = p->info;
        p = p->urm;
    }
    return m;
}

int main()
{
    int n, i;
    cout << "n = "; cin >> n;
    for(i = 0; i < n; i++)
        adauga();
    cout << "maxim = " << maxim();
    return 0;
}

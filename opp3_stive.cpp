/** construiti o stiva ale carei noduri contin
    ca si informatie divizorii unui numar dat

    De ex:  x = 48 se construieste stiva:
    48   24  16   12  8  6  4  3  2  1
    **/

#include <iostream>
using namespace std;

struct nod
{
     int info;
     nod *urm;
}*prim;

void adauga(int k)
{
    nod *p = new nod;

    p->info = k;
    p->urm = prim;

    prim = p;
}

void parcurgere()
{
    nod *p = prim;
    while(p != NULL)
    {
        cout << p->info << " ";
        p = p->urm;
    }
}

int main()
{
    int x, i;
    cout << "x = "; cin >> x;
    for(i = 1; i <= x; i++)
        if(x % i == 0)
           adauga(i);
    cout << endl << "Stiva divizorilor: ";
    parcurgere();
    return 0;
}








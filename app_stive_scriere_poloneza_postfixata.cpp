/** evaluarea unei expresii in forma poloneza
    postfixata **/

#include <iostream>
#include <string.h>
using namespace std;

struct nod
{
    int info;
    nod *urm;
}*prim;

void adauga(int x)
{
    nod *p = new nod;

    p->info = x;
    p->urm = prim;

    prim = p;
}

int sterge()
{
    nod *p = prim;
    int x = prim->info;
    prim = prim->urm;
    delete p;
    return x;
}

void citire(char v[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        cin >> v[i];
}

int main()
{
    char v[50];
    int n, i, op1, op2;
    cout << "n = "; cin >> n;
    citire(v, n);
    for(i = 0; i < n; i++)
    {
        if(isdigit(v[i]))
            adauga(int(v[i])-'0');
        else
        {
            op1 = sterge();
            op2 = sterge();
            if(v[i] == '+')
                adauga(op1+op2);
            else if(v[i] == '-')
                adauga(op2-op1);
            else if(v[i] == '*')
                adauga(op2*op1);
            else adauga(op2/op1);
        }
    }
    cout << prim->info;
    return 0;
}

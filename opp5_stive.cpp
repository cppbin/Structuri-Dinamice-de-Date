/** se adauga noduri intr-o stiva de numere intregi pana cand
    se introduce 100. Sa se numere cate noduri au fost introduse. **/


#include<iostream>
using namespace std;

struct nod
{
    int info;
    nod *urm;
}*prim;

void adauga(int x)
{
  nod *p = new nod;
  p->info=x;
  p->urm=prim;
  prim = p;
}

int numara()
{
    int k=0;
    nod *p = prim;
    while(p != NULL)
    {
        k++;
        p=p->urm;
    }
     return k;
}

int main()
{
    int x;
    do{
       cout << "x = "; cin >> x;
       adauga(x);
    }while(x != 100);
    cout << numara();
}

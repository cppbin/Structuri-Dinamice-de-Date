/** Date fiind intr-un fisier text informatii despre persoane
    si numere de telefon, sa se organizeze sub forma unei stive
    si apoi sa se numere de cate ori apare un nume dat printre
    persoanele date **/

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct nod
{
    char nume[10];
    char telefon[10];
    nod *urm;
}*prim;

ifstream f("opp6.txt");

void adauga()
{
    nod *p = new nod;

    f >> p->nume;
    f >> p->telefon;
    p->urm = prim;

    prim = p;
}

void parcurgere()
{
    nod *p = prim;
    while(p != NULL)
    {
        cout << endl << p->nume << ", " << p->telefon;
        p = p->urm;
    }
}

int numara(char x[])
{
    int k = 0;
    nod *p = prim;
    while(p != NULL)
    {
        if(strcmp(p->nume, x)==0)
            k++;
        p = p->urm;
    }
    return k;
}

int main()
{
    char x[10];
    while(!f.eof())
        adauga();
    parcurgere();
    cout << endl << "nume = "; cin >> x;
    cout << "contor = " << numara(x);
    return 0;
}


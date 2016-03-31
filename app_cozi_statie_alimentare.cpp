/** simularea unei cozi pentru alimentarea cu carburant **/

#include <iostream>
using namespace std;

float c = 0;

struct nod
{
    char nr_inmatriculare[11];
    char model[16];
    char culoare[11];
    float litri;
    nod *urm;
}*prim, *ultim;

void qstore()
{
    nod *p = new nod;

    cout << "Nr. inmatriculare = "; cin >> p->nr_inmatriculare;
    cout << "Model = "; cin >> p->model;
    cout << "Culoare = "; cin >> p->culoare;

    p->urm = NULL;
    if(ultim != NULL)
      ultim->urm = p;
    else
        prim = p;
    ultim = p;
}

void qretrieve()
{
    nod *p = prim;
    if(prim == NULL)
        cout << "Coada goala!";
    else
    {
        cout << "litri = "; cin >> prim->litri;
        c += prim->litri;
        prim = prim->urm;
        delete p;
        if(prim==NULL)
            ultim = NULL;
    }
}

void parcurgere()
{
    nod *p = prim;
    if(prim == NULL)
        cout << "Coada este goala!";
    else
        while(p != NULL)
        {
            cout << endl << p->nr_inmatriculare;
            cout << ", " << p->model;
            cout << ", " << p->culoare;
            p = p->urm;
        }
}

int main()
{
    char opt;
    do{
        cout << endl << "a. adaugare";
        cout << endl << "e. eliminare";
        cout << endl << "l. listare";
        cout << endl << "c. afisare istoric";
        cout << endl << "s. stop";
        cout << endl << "optiune ="; cin >>opt;
        switch(opt)
        {
            case 'a': qstore();
                      break;
            case 'e': qretrieve();
                      break;
            case 'l': parcurgere();
                      break;
            case 'c': cout << "total litri= " << c;
                      break;
        }
    }while(opt!='s');
}



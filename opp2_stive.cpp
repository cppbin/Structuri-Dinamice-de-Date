/** Se citesc de la tastatura informaţii despre
elevii unei clase. Un elev se caracterizează prin numele
şi media sa anuală. Să se construiască o listă liniară
simplu înlănţuită cu elevii unei clase şi să se
calculeze media generala a clasei. Crearea listei
liniare se face prin adăugare la început. **/

#include <iostream>
using namespace std;

struct nod
{
    char nume[15];
    float media;
    nod *urm;
}*prim;

void adauga()
{
    nod *p = new nod;
    cin.get();
    cout << "nume = "; cin.get(p->nume, 15);
    cout << "media = "; cin >> p->media;
    p->urm = prim;

    prim = p;
}

void parcurgere()
{
    nod *p = prim;
    while(p != NULL)
    {
        cout << p->nume << ", " << p->media << endl;
        p = p->urm;
    }
}

float media()
{
    float m, s = 0;
    int k = 0;
    nod *p = prim;
    while(p != NULL)
    {
        s += p->media;
        k++;
        p = p->urm;
    }
    m = s/ k;
    return m;
}

int main()
{
    int n, i;
    cout << "n = "; cin >> n;
    for(i = 0; i < n; i++)
        adauga();
    parcurgere();
    cout << endl << "media clasei: " << media();
    return 0;
}

#include <iostream>
using namespace std;

typedef struct masini 
{
    char marca[50];
    int an;
    char combustibil[50];
    int putere;
}masini;

void citire_masini(masini* ps)
{
    cin.ignore();
    cin.sync();
    cout << "Marca: ";
    cin.getline(ps->marca, 50);
    cout << "An: ";
    cin >> ps->an;
    cin.ignore();
    cin.sync();
    cout << "Combustibil: ";
    cin.getline(ps->combustibil, 50);
    cout << "Putere: ";
    cin >> ps->putere;

}

void afisare_masini(masini s)
{
    cout << "marca: " << s.marca << endl;
    cout << "an: " << s.an << endl;
    cout << "combustibil: " << s.combustibil << endl;
    cout << "putere: " << s.putere << endl;
}

void citire_masini(int n, masini t[])
{
    for (int i = 0; i < n; i++)
    {
        citire_masini(&t[i]);
    }
}

void afisare_masini(int n, masini t[])
{
    for(int i = 0; i < n; i++)
    {
        afisare_masini(t[i]);
    }
}

int main()
{
    masini t[100];
    int n;
    cout << "n = ";
    cin >> n;
    citire_masini(n, t);
    afisare_masini(n, t);

    return 0;

}

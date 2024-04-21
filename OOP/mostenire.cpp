#include <iostream>
#include <string.h>

using namespace std;

class Persoana
{
    protected:
        char* nume;
        int varsta;
    
    public:
        Persoana(char* nume, int varsta = 0); //constructor cu parametri
        Persoana(const Persoana& p); // constructor de copiere
        ~Persoana();
        void afisare();
        char* getNume();
        int getVarsta();
        Persoana& operator = (Persoana& p);

};

Persoana::Persoana(char* nume, int varsta)
{
    this -> nume = new char[strlen(nume) + 1];
    strcpy(this -> nume, nume);
    this -> varsta = varsta;
    cout << "Apel constr. Persoana\n";
}

Persoana::Persoana(const Persoana& p )
{
    nume = new char[strlen(nume) + 1];
    strcpy(nume, p.nume);
    varsta = p.varsta;
    cout << "apel constr. copiere Persoana\n";
}

Persoana::~Persoana()
{
    delete []nume;
    cout << "Apel destructor Persoana\n";
}

void Persoana::afisare()
{
    cout << "Nume: " << nume << '\n';
    cout << "Varsta: " << varsta << '\n';
}

char* Persoana::getNume()
{
    return nume;
}

int Persoana::getVarsta()
{
    return varsta;
}


Persoana& Persoana::operator = (Persoana& p)
{
    cout << "apel atribuire Persoana\n";
    if(this != &p)
    {
        delete []nume;
        nume = new char[strlen(p.nume) + 1];
        strcpy(nume, p.nume);
        varsta = p.varsta;
    }
    return *this;
}

class Profesor: public Persoana
{
    protected:
        char* specializare;
    public:
        Profesor(char* nume, int varsta, char* specializare);
        Profesor(const Profesor& s);
        ~Profesor();
        void afisare();
        char* getSpecializare();
        Profesor& operator = (Profesor &p);
};

Profesor::Profesor(char* nume, int varsta, char* specializare): Persoana(nume, varsta)
{
    this -> specializare = new char[strlen(specializare) + 1];
    strcpy(this -> specializare, specializare);
    cout << "apel constr. profesor\n";
}

Profesor::Profesor(const Profesor& s) : Persoana(s.nume, s.varsta)
{
    specializare = new char[strlen(s.specializare) + 1];
    strcpy(specializare, s.specializare);
    cout << "apel constr de copiere Profesor\n";
}

Profesor::~Profesor()
{
    delete []specializare;
    cout << "apel destructor Profesor\n";
}

void Profesor::afisare()
{
    Persoana::afisare();
    cout << "Specializare: " << specializare << '\n';
}

char* Profesor::getSpecializare()
{
    return specializare;
}

Profesor& Profesor::operator = (Profesor& p)
{
    cout << "apel atribuire Profesor\n";
    if(this != &p)
    {
        Persoana::operator=(p);
        delete []specializare;
        specializare = new char[strlen(p.specializare) + 1];
        strcpy(specializare, p.specializare);
    }
    return *this;
}

class Diriginte : public Profesor
{
    protected:
        int clasa;
    public:
        Diriginte(char* nume, int varsta, char* specializare, int clasa);
        int getClasa();
        void afisare();

};

Diriginte::Diriginte(char* nume, int varsta, char* specializare, int clasa) : Profesor(nume, varsta, specializare)
{
    this -> clasa = clasa;
    cout << "apel constr. Diriginte\n";
}

int Diriginte::getClasa()
{
    return clasa;
}

void Diriginte::afisare()
{
    Profesor::afisare();
    cout <<"Clasa: " << clasa << '\n';
}

int main()
{
    Diriginte d("Mihai", 40, "Informatica", 10);
    d.afisare();
    cout << "-------------------" << '\n';
    cout << "Varsta: " << d.getVarsta() << '\n';
    Profesor p = d;
    p.afisare();
    Diriginte d3("Maria", 21, "Romana", 9);
    d = d3;
    d.afisare();
}

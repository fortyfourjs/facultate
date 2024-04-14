#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Pacient
{
    private:
        char* nume;
        char* prenume;
        int varsta;
        char* diagnostic;

    public:
        Pacient(const char* nume, const char* prenume, int varsta, const char* diagnostic);
        ~Pacient();
        

    char* getNume();
    void setNume(const char* nume);

    char* getPrenume();
    void setPrenume(const char* prenume);

    int getVarsta() const;
    void setVarsta(int varsta);

    char* getDiagnostic();
    void setDiagnostic(const char* diagnostic);

    void afiseazaDetalii() const;
};

Pacient::Pacient(const char* nume, const char* prenume, int varsta, const char* diagnostic)
{   
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);

    this->prenume = new char[strlen(prenume) + 1];
    strcpy(this->prenume, prenume);

    this->varsta = varsta;

    this->diagnostic = new char[strlen(diagnostic) + 1];
    strcpy(this->diagnostic, diagnostic);

}

char* Pacient::getNume()
{
    return nume;
}

void Pacient::setNume(const char* nume)
{
    delete[] this->nume;
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
}

char* Pacient::getPrenume()
{
    return prenume;
}

void Pacient::setPrenume(const char* prenume)
{
    delete[] this->prenume;
    this->prenume = new char[strlen(prenume) + 1];
    strcpy(this->prenume, prenume);
}

int Pacient::getVarsta() const
{
    return varsta;
}

void Pacient::setVarsta(int varsta)
{
    this->varsta = varsta;
}

char* Pacient::getDiagnostic()
{
    return diagnostic;
}

void Pacient::setDiagnostic(const char* diagnostic)
{
    delete[] this->diagnostic;
    this->diagnostic = new char[strlen(diagnostic) + 1];
    strcpy(this->diagnostic, diagnostic);
}
/*
Pacient::Pacient(const Pacient& other)
{
    nume = new char[strlen(other.nume) + 1];
    strcpy(nume, other.nume);

    prenume = new char[strlen(other.prenume) + 1];
    strcpy(prenume, other.prenume);

    varsta = other.varsta;

    diagnostic = new char[strlen(other.diagnostic) + 1];
    strcpy(diagnostic, other.diagnostic);
}

Pacient& Pacient::operator=(const Pacient& other)
{
    if (this == &other)
        return *this;
    
    delete[] nume;
    delete[] prenume;
    delete[] diagnostic;
    
    nume = new char[strlen(other.nume) + 1];
    strcpy(nume, other.nume);

    prenume = new char[strlen(other.prenume) + 1];
    strcpy(prenume, other.prenume);

    diagnostic = new char[strlen(other.diagnostic) + 1];
    strcpy(diagnostic, other.diagnostic);

    return *this;
}
*/
void Pacient::afiseazaDetalii() const
{
    cout << "nume: " << nume << '\n';
    cout << "prenume: " << prenume << '\n';
    cout << "varsta:  " << varsta << '\n';
    cout << "diagnostic:  " << diagnostic << '\n';
    cout << "--------------------\n";
}

bool sorteazaVarsta(const Pacient& p1, const Pacient& p2)
{
    return p1.getVarsta() < p2.getVarsta();
}

Pacient::~Pacient()
{
    if(nume != nullptr)
    {
        delete[] nume;
        nume = nullptr;
    }
    
    if(prenume != nullptr)
    {
        delete[] prenume;
        prenume = nullptr;
    }
    
    if(diagnostic != nullptr)
    {
        delete[] diagnostic;
        diagnostic = nullptr;
    }

}



int main()
{
    Pacient pacienti[] =
    {
        Pacient("Ion", "Groparu", 26, "Raceala"),
        Pacient("Alice", "Williams", 21, "Febra"),
        Pacient("Emma", "Watson", 29, "Durere de cap"),
        Pacient("Mihaela", "I.", 24, "Depresie")
    };
    
    const int numPacienti = sizeof(pacienti) / sizeof(pacienti[0]);

    sort(pacienti, pacienti + numPacienti, sorteazaVarsta);

    for(int i = 0; i < numPacienti; i++)
    {
        pacienti[i].afiseazaDetalii();
    }


    return 0;
}

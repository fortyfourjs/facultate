#include <iostream>
#include <cstring>

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

    int getVarsta();
    void setVarsta(int varsta);

    char* getDiagnostic();
    void setDiagnostic(const char* diagnostic);
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

Pacient::~Pacient()
{
    delete[] nume;
    delete[] prenume;
    delete[] diagnostic;

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

int Pacient::getVarsta()
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

int main()
{
    Pacient pacient1("Alex", "Groparu", 29, "H1N1");
    cout << "Nume: " << pacient1.getNume() << '\n';
    cout << "Prenume: " << pacient1.getPrenume() << '\n';
    cout << "Varsta: " << pacient1.getVarsta() << '\n';
    cout << "Diagnostic: " << pacient1.getDiagnostic() << '\n';

    return 0;
}

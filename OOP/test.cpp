#include <iostream>
#include <cstring>
using namespace std;

class Angajat
{
    private:
        char* nume;
        char* calificare;
        double salariu;
    
    public:
        Angajat(const char* nume, const char* calificare, double salariu)
        {
            this->nume = new char[strlen(nume) + 1];
            strcpy(this->nume, nume);

            this->calificare = new char[strlen(calificare) + 1];
            strcpy(this->calificare, calificare);

            this->salariu = salariu;
        }
        ~Angajat()
        {
            delete[] calificare;
            delete[] nume;
        }

        void afiseaza()
        {
            cout << "Nume: " << nume << '\n';
            cout << "Calificare: " << calificare <<'\n';
            cout << "Salariu: " << salariu << '\n';
        }
};

class sefSectie : public Angajat
{
    private:
        char* sectie;
    public:
        sefSectie(const char* nume, const char* calificare, double salariu, const char* sectie) : Angajat(nume, calificare, salariu)
        {
            this->sectie = new char[strlen(sectie) + 1];
            strcpy(this->sectie, sectie);
        }
    
    ~sefSectie()
    {
        delete[] sectie;
    }
    void afiseaza()
    {
        Angajat::afiseaza();
        cout << "sectie: " << sectie << '\n';
    }
};

class Director : public Angajat
{
    private:  
        double indemnizatie;
    public:
        Director(const char* nume, const char* calificare, double salariu, double indemnizatie) : Angajat(nume, calificare, salariu)
        {
            this->indemnizatie = indemnizatie;
        }

    ~Director(){}

    void afiseaza()
    {
        Angajat::afiseaza();
        cout << "indemnizatie: " << indemnizatie << '\n';
    }
};


int main()
{
    Angajat unu("Ion", "dulgher", 6500);
    unu.afiseaza();
}

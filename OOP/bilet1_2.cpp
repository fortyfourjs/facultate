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
            this->nume = new char[strlen(nume)+1];
            strcpy(this->nume, nume);

            this->calificare = new char[strlen(calificare) + 1];
            strcpy(this->calificare, calificare);

            this->salariu = salariu;
        }

    ~Angajat()
    {
        delete[] nume;
        delete[] calificare;
    }

    void afiseaza()
    {
        cout << "Nume: " << nume << "\nCalificare: " << calificare << "\nSalariu: " << salariu << '\n';
    }
};

class SefSectie : public Angajat
{
    private:
        char* numeSectie;

    public:
        SefSectie(const char* nume, const char* calificare, double salariu, const char* numeSectie) : Angajat(nume, calificare, salariu)
        {
            this->numeSectie = new char[strlen(numeSectie)+1];
            strcpy(this->numeSectie, numeSectie);
        }
    
    ~SefSectie()
    {
        delete[] numeSectie;
    }

    void afiseaza()
    {
        Angajat::afiseaza();
        cout<<"Sectia: " << numeSectie << '\n';
    }

};

class Director : public Angajat
{
    private:
        int indemnizatie;
    public:
        Director(const char* nume, const char* calificare, double salariu, int indemnziatie) : Angajat(nume, calificare, salariu)
        {
            this->indemnizatie = indemnizatie;
        }
    
    ~Director()
    {
    }
};

int main()
{
    Angajat unu("George", "dulgher", 8600);
    unu.afiseaza();
    SefSectie doi("Alex", "inginer", 10500, "productie");
    doi.afiseaza();

    Director trei("Gica","Masinist",9000,350);
    trei.afiseaza();
   
    
}



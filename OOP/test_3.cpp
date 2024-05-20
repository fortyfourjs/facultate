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

            this->calificare = new char[strlen(calificare)+1];
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
            cout << "nume: " << nume << "\ncalificare: " << calificare << "\nsalariu: " << salariu << '\n';
        }

        char* getNume() const  //daca vrei setter/getter
        {
            return nume;
        }
        void setNume(char* newNume)
        {
            delete[] nume;
            nume = new char[strlen(newNume) + 1];
            strcpy(nume, newNume);
        }
};

int main()
{
    Angajat unu("Ionel", "zugrav", 5500);
    unu.afiseaza();
    unu.setNume("Alin");
    unu.afiseaza();
    
}

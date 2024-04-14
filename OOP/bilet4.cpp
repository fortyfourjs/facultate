#include <iostream>
#include <cstring>

using namespace std;


class Coada
{
    private:
        char* nume;
        Coada* next;
    
    public:
        Coada(const char* nume = "");
        Coada(const Coada& other);
        ~Coada();
        Coada& operator=(const Coada& other);

        char* getNume() const;
        void setNume(const char* nume);
        void printNume() const;

        void adaugaPersoana(const char* nume);
        void eliminaPersoana();
        bool esteVida() const;
};

Coada::Coada(const char* nume)
{
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
    this->next = nullptr;
}

Coada::Coada(const Coada& other)
{
    this->nume = new char[strlen(other.nume) + 1];
    strcpy(this->nume, other.nume);
    this->next = nullptr;
}

Coada::~Coada()
{
    delete[] nume;
}

Coada& Coada::operator=(const Coada& other)
{
    if(this != &other)
    {
        delete[] nume;
        this->nume = new char[strlen(other.nume) + 1];
        strcpy(this->nume, other.nume);
        this->next = nullptr;
    }
    return *this;
}

char* Coada::getNume() const
{
    return nume;
}

void Coada::setNume(const char* nume)
{
    delete[] this -> nume;
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
}

void Coada::printNume() const
{
    cout << "elevul este: " << nume << '\n';
}

void Coada::adaugaPersoana(const char* nume)
{
    Coada* newNode = new Coada(nume);
    Coada* current = this;
    while(current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newNode;
}

void Coada::eliminaPersoana()
{
    if(this->next != nullptr)
    {
        Coada* temp = this->next;
        this->next = this->next->next;
        delete temp;
    }
}

bool Coada::esteVida() const
{
    return(this->next == nullptr);
}



int main()
{
    Coada student("Ioana");
    student.printNume();
    student.adaugaPersoana("Alex");
    student.adaugaPersoana("Ion");
    student.printNume();
    student.eliminaPersoana();
    student.printNume();
    student.eliminaPersoana();
    student.eliminaPersoana();

    cout << "coada este vida: " << (student.esteVida() ? "Da" : "Nu") << '\n';


    return 0;
}

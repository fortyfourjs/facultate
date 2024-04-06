#include <string.h>
#include <limits>
#include <iostream>

using namespace std;

#define MAX 40
class Student;
class Profesor
{
    private:
        char nume[MAX];
    public:
        Profesor(const char *nume = "");
        void afisare();
        void setNume(char *nume);
        char* getNume();
        void setMedie(Student &s, float medie);
};

class Student
{
    private:
        char nume[MAX];
        char facultate[MAX];
        float medie;
    public:
        Student(const char *nume = "", const char *facultate = "", float medie = 0);
        void afisare();
        char* getNume();
        char* getFacultate();
        float getMedie();

        friend void Profesor::setMedie(Student &s, float medie);
        friend class Secretara;
};

Profesor::Profesor(const char* nume)
{
    strncpy(this -> nume, nume, MAX);
}

void Profesor::afisare()
{
    cout << "---Profesor---" << '\n';
    cout << "Nume: " << nume << '\n';
    cout << "------" << '\n';
}

void Profesor::setMedie(Student &s, float medie)
{
    if (medie >= 0 && medie <= 10)
    {
        s.medie = medie;
    }
    else
    {
        cout << "medie invalida " << medie;
    }
}

Student::Student(const char* nume, const char* facultate, float medie)
{
    strncpy(this -> nume, nume, MAX);
    strncpy(this -> facultate, facultate, MAX);
    this -> medie = medie;
}

void Student::afisare()
{
    cout <<"---Student---" << '\n';
    cout << "Nume: " << nume << '\n';
    cout << "Facultate: " << facultate << '\n';
    cout << "Medie: " << medie << '\n';
    cout << "------" << '\n';
}

char* Student::getNume()
{
    return nume;
}
char* Student::getFacultate()
{
    return facultate;
}
float Student::getMedie()
{
    return medie;
}

class Student;
class Secretara
{
    public:
        void setFacultate(Student &s, const char* facultate);
        void setNume(Student &s, const char* nume);
};

void Secretara::setFacultate(Student &s, const char* facultate)
{
    strncpy(s.facultate, facultate, MAX);
}
void Secretara::setNume(Student &s, const char* nume)
{
    strncpy(s.nume, nume, MAX);
}


int main()
{
    Student s1("Maria Popescu", "Informatica");
    s1.afisare();
    Profesor p1("Mihai Gabroveanu");
    p1.afisare();
    p1.setMedie(s1, 10);
    s1.afisare();
    Secretara sec;
    sec.setFacultate(s1, "automatica");
    sec.setNume(s1, "Ionut Dinca");
    s1.afisare();
    
    return 0;
}

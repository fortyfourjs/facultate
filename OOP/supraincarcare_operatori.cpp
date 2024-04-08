#include <iostream>
using namespace std;

class Fractie
{
    private:
        int numarator;
        int numitor;
        static int cmmdc(int a, int b);
    
    public:
        Fractie(int numarator = 0, int numitor = 1);

        void citire();
        void afisare();

        void setNumarator(int numarator);
        void setNumitor(int numitor);

        int getNumarator() const;
        int getNumitor() const;

        void reducere();

        Fractie operator+ (Fractie g);
        friend Fractie operator* (Fractie f, Fractie g);

        operator float() const;
        friend bool operator == (Fractie f, Fractie g);

            Fractie& operator= (const Fractie& r);
            friend ostream& operator << (ostream& os, const Fractie& r);
            friend istream& operator >> (istream& is, Fractie& r);

};

ostream& operator << (ostream& os, const Fractie& r)
{
    os << r.numarator << "/" << r.numitor << '\n';
    return os;
}

istream& operator >> (istream& is, Fractie& r)
{
    cout << "Numarator: ";
    is >> r.numarator;
    cout << "Numitor: ";
    is >> r.numitor;
    return is;
}

Fractie& Fractie::operator = (const Fractie& r)
{
    if(this != &r)
    {
        numitor = r.numitor;//setNumitor(r.numitor)
        numarator = r.numarator;
        reducere();
    }
    return *this;
}

Fractie::Fractie(int numarator, int numitor)
{
    setNumarator(numarator);
    setNumitor(numitor);
}

void Fractie::citire()
{
    int temp;
    cout << "Dati numaratorul: ";
    cin >> temp;
    setNumarator(temp);
    cout << "Dati numitorul: ";
    cin >> temp;
    setNumitor(temp);
}

void Fractie::afisare()
{
    cout << numarator << "/" << numitor << '\n';
}

void Fractie::setNumarator(int numarator)
{
    this->numarator=numarator;
}

void Fractie::setNumitor(int numitor)
{
    if(numitor != 0)
    {
        this->numitor=numitor;
    }
    else
    {
        cout << "numitorul nu poate fi nul" << '\n';
        exit(1);
    }
}

int Fractie::getNumarator() const
{
    return this->numarator;
}

int Fractie::getNumitor() const
{
    return this->numitor;
}

int Fractie::cmmdc(int a, int b)
{
    int c;
    while(b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

void Fractie::reducere()
{
    if(numarator != 0)
    {
        int c = cmmdc(numarator, numitor);
        if(c != 1)
        {
            numarator = numarator / c;
            numitor = numitor / c;
        }
    }
}

Fractie Fractie::operator + (Fractie g)
{
    int numaratorNou = this->numarator*g.numitor + g.numarator*this->numitor;
    int numitorNou = this->numitor * g.numitor;
        Fractie s(numaratorNou, numitorNou);
        s.reducere();
        return s;
}

Fractie operator * (Fractie f, Fractie g)
{
    Fractie p(f.numarator *g.numarator, f.numitor *g.numitor);
    p.reducere();
    return p;
}

Fractie::operator float() const
{
    return float(numarator) / float(numitor);
}

bool operator == (Fractie f, Fractie g)
{
    return f.numarator * g.numitor == g.numarator * f.numitor;
}

int main()
{
    Fractie f,g,h;
    f.citire();
    f.afisare();
    f.reducere();
    cout << "dupa simplificare"<<'\n';
    f.afisare();
    cout << "numarul real corespunzator: " << (float) f << '\n';
    g.citire();
    g.afisare();

    cout << "---Test egalitate---\n";
    if(f == g)
    {
        cout << "Fractii egale" << '\n';
    }
    else
    {
        cout << "Fractii diferite" << '\n';
    }

    cout << "---Suma---\n";
    h = f + g;
    h.afisare();
    cout << "---Produsul---\n";
    h = f * g;
    h.afisare();
    return 0;
}


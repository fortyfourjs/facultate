#include <iostream>
#include <cstring>

using namespace std;

class Cantar
{
    private:
        double capacitateMaxima;

    public:
        Cantar(double capacitateMaxima) : capacitateMaxima(capacitateMaxima){}

    void cantareste(double greutate)
    {
        if(greutate > capacitateMaxima * 1.1)
        {
            cout << "Eroare: greutatea depaseste limita admisa" << '\n';
        }
        else if(greutate > capacitateMaxima)
        {
            cout << "avertisment: greutatea depaseste capacitatea maxima admisa" << '\n';
        }
        else
        {
            cout << "greutatea este in limitele admise" << greutate << " kg\n";
        }
    }
};

int main()
{
    Cantar cantar(100);

    double greutati[] = {90, 105, 115};

    for(double greutate : greutati)
    {
        cout << "incerc sa cantaresc: " << greutate << " kg\n";
        cantar.cantareste(greutate);

    }
}

#include <iostream>
#include <vector>
using namespace std;

class Matrice
{
private:
    int randuri;
    int coloane;
    std::vector<int> matrice;

public:
    Matrice(int randuri, int coloane) : randuri(randuri), coloane(coloane)
    {
        matrice.resize(randuri * coloane, 0);
    }

    int get(int rand, int coloana) const
    {
        if (rand >= 0 && rand < randuri && coloana >= 0 && coloana < coloane)
        {
            return matrice[rand * coloane + coloana];
        }
        else
        {
            throw std::out_of_range("Index out of range");
        }
    }

    void set(int rand, int coloana, int valoare)
    {
        if (rand >= 0 && rand < randuri && coloana >= 0 && coloana < coloane)
        {
            matrice[rand * coloane + coloana] = valoare;
        }
        else
        {
            throw std::out_of_range("Index out of range");
        }
    }

    void display() const
    {
        for (int i = 0; i < randuri; i++)
        {
            for (int j = 0; j < coloane; j++)
            {
                std::cout << get(i, j) << " ";
            }
            std::cout << '\n';
        }
    }
};

int main()
{
    int coloane = 3;
    int randuri = 3;
    Matrice matrix(coloane, randuri);

    for (int i = 0; i < randuri; i++)
    {
        for (int j = 0; j < coloane; j++)
        {
            matrix.set(i, j, i * coloane + j);
        }
    }

    matrix.display();

    return 0;
}

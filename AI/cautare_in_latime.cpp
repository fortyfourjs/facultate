#include <iostream>

const char* nume[] = 
{
    "Arad", "Bucuresti", "Craiova", "Drobeta", "Eforie", 
    "Fagaras", "Giurgiu" , "Harsova", "Iasi", "Lugoj", 
    "Mehadia", "Neamt", "Oradea", "Pitesti", "Ram Valcea",
    "Sibiu", "Timisoara", "Urziceni", "Vlahi", "Zerind"
};

int n = 20;
int a[20][20];
int oras_start = 0;
int vizitat[20], noduri[20], parinte[20], solutie[20];
int oras_destinatie = 1, nod, nr_noduri = 0, nr_solutie = 0;
int gasit = 0;

int main()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            a[i][j] = 0;

    {
        a[0][15] = 1;
        a[0][16] = 1;
        a[0][19] = 1;
        a[1][6] = 1;
        a[1][5] = 1;
        a[1][13] = 1;
        a[1][17] = 1;
        a[2][3] = 1;
        a[2][13] = 1;
        a[2][14] = 1;
        a[3][10] = 1;
        a[4][7] = 1;
        a[5][15] = 1;
        a[7][17] = 1;
        a[8][18] = 1;
        a[8][11] = 1;
        a[9][10] = 1;
        a[9][16] = 1;
        a[12][15] = 1;
        a[12][19] = 1;
        a[13][14] = 1;
        a[13][1] = 1;
        a[13][2] = 1;
        a[14][15] = 1;

    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j] == 1)
                a[i][j] = 1;

    std::cout << "orasele conectate de orasul " << nume[oras_start] << " sunt: ";

    for(int i = 0; i < n; i++)
        if(a[oras_start][i] == 1)
            std::cout << nume[i] << ",";

    
    //algoritm cautare in latime

    std::cout << '\n';

    for(int i = 0; i < n; i++)
        vizitat[i] = 0;

    noduri[0] = oras_start;
    nr_noduri++;

    vizitat[oras_start] = 1;

    while(gasit == 0 && nr_noduri != 0)
        nod = noduri[0];

        for(int i = 0; i < nr_noduri; i++)
            noduri[i] = noduri[i + 1];
        nr_noduri--;

        if(nod == oras_destinatie)
            gasit = 1;

        else
        {
            for(int i = 0; i < n; i++)
            {
                if(a[nod][i] == 1 && vizitat[i] == 0)
                    noduri[nr_noduri++] = i;
                    vizitat[i] = 1;
                    parinte[i] = nod;
            }
        }

if(gasit == 1)
{

    while(oras_destinatie != oras_start)
    {
        solutie[nr_solutie++] = oras_destinatie;
        oras_destinatie = parinte[oras_destinatie];
    }
    solutie[nr_solutie] = oras_start;

    for(int i = nr_solutie; i >= 0; i--)
        std::cout << nume[solutie[i]] << " ";
}
    else
        std::cout << " nicio solutie" << '\n';

    return 0;
}

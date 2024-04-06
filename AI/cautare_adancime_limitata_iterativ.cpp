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
int oras_start = 12;
int vizitat[20], noduri[20], parinte[20], solutie[20], adancime[20], limita = 2;
int oras_destinatie = 1;
int nr_noduri = 0;
int nr_solutie = 0;
int gasit = 0;
int nod;

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

 //Algoritmul de cautare in adancime limitata ITERATIV
limita = 0;
while ((gasit == 0) && (limita < n))
{
    limita++;
    for (int i = 0; i < n; i++)
        vizitat[i] = 0; // Toate orasele sunt nevizitate.
    noduri[0] = oras_start;//Adaugam in lista noduri orasul de plecare. (in lista de noduri pe prima pozitie adaug orasul de start
    nr_noduri++;
    vizitat[oras_start] = 1;//Marcam orasul de plecare ca vizitat.
    adancime[oras_start] = 0;
    while ((gasit == 0) && (nr_noduri != 0)) // Cat timp solutie negasita si noduri ≠ vida executa
    {
        nod = noduri[0];//nod = scoate_din_fata(noduri) //stocam primul element din noduri in variabila nod
        for (int i = 0; i < nr_noduri - 1; i++) //Eliminam primul element din noduri
            noduri[i] = noduri[i + 1];
        nr_noduri--;
        if (adancime[nod] <= limita)
        {
            if (nod == oras_destinatie) //Daca testare_tinta[problema] se aplica la stare(nod) atunci
                gasit = 1;//Solutia este gasita //facem variabila booleana gasit adevarata
           
            else
            {
                for (int i = 0; i < n; i++) // Adaugam la final in noduri orasele nevizitate care sunt conectate de nod
                    if ((a[nod][i] == 1) && ((vizitat[i] == 0) || (vizitat[i] == 1 && adancime[i] > adancime[nod] + 1))) {
                        for (i = nr_noduri; i > 0; i--)// Adaugam la inceput in noduri orasele conectate si nevizitate SAU care au fost vizitate dar adancimea veche e mai mare decat adancimea veche
                            noduri[i] = noduri[i - 1];
                        noduri[0] = i;
                        nr_noduri++;
                        vizitat[i] = 1;//Orasele adaugate sunt marcate ca vizitate
                        parinte[i] = nod;//Se retine pentru oricare din orasele adaugate nodul parinte ca fiind nod
                        adancime[i] = adancime[nod] + 1;
                    }

            }
        }
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
    std::cout << '\n' << "solutia s-a gasit la limita " << limita;

}
    else
        std::cout << "nicio solutie" << '\n';


return 0;


}

#include <iostream>
// #include <conio.h>  es no mi problema

using namespace std;

int n = 20, i, j, k;
int a[20][20];
const char* nume[20] = { "Arad", "Bucuresti", "Craiova", "Drobeta", "Eforie", "Fagaras", "Giurgiu", "Hirsova", "Iasi", "Lugoj","Mehadia", "Neamt", "Oradea", "Pitesti", "Rimnicu Valcea", "Sibiu", "Timisoara", "Urziceni", "Vaslui", "Zerind" };
//                        0          1          2           3        4            5           6        7         8        9        10        11      12        13            14              15        16            17        18         19
//int oras_start = 0;
int vizitat[20], noduri[20], parinte[20], oras_start = 0, oras_dest = 1, nod, nr_noduri;// nr_noduri este nr de elemente din noduri[]
int gasit = 0;//variabila care ne spune daca solutia este gasita
int solutie[20], nr_solutie = 0;
int adancime[20], limita = 5,km=0;
int cost[20];//costul unui oras este nr de km de la orasul de start pana la el
int h[20] = {366, 0, 160, 242, 161, 176, 77, 151, 226, 244, 241, 234, 380, 10, 193, 253, 329, 80, 199, 374};
int main() {
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }

    //matricea de adiacenta
    a[0][15] = 140;
    a[0][16] = 118;
    a[0][19] = 75;
    a[1][5] = 211;
    a[1][6] = 90;
    a[1][13] = 101;
    a[1][17] = 85;
    a[2][3] = 120;
    a[2][13] = 138;
    a[2][14] = 145;
    a[3][10] = 75;
    a[4][7] = 85;
    a[5][15] = 99;
    a[7][17] = 98;
    a[8][11] = 87;
    a[8][18] = 92;
    a[9][10] = 70;
    a[9][16] = 111;
    a[12][15] = 151;
    a[12][19] = 71;
    a[13][14] = 97;
    a[14][15] = 80;
    a[17][18] = 142;

    for (i = 0; i < n; i++)

        for(j = 0; j < n; j++)

            if (a[i][j] != 0)
                a[j][i] = a[i][j];

    std::cout << "Orasele conectate de orasul " << nume[oras_start] << " sunt ";
    for (i = 0; i < n; i++) {
        if (a[oras_start][i] == 1) {
            std::cout << nume[i] << ", ";
        }
    }
    std::cout << endl;

    /*
    //Algoritmul de cautare in latime

    for (i = 0; i < n; i++)
        vizitat[i] = 0; // Toate orasele sunt nevizitate.
    noduri[0] = oras_start;//Adaugam in lista noduri orasul de plecare. (in lista de noduri pe prima pozitie adaug orasul de start
    nr_noduri++;
    vizitat[oras_start] = 1;//Marcam orasul de plecare ca vizitat.

    while ((gasit == 0) && (nr_noduri != 0)) // Cat timp solutie negasita si noduri ≠ vida executa
    {
        nod = noduri[0];//nod = scoate_din_fata(noduri) //stocam primul element din noduri in variabila nod

        for (i = 0; i < nr_noduri - 1; i++) //Eliminam primul element din noduri
            noduri[i] = noduri[i + 1];
        nr_noduri--;

        if (nod == oras_dest) //Daca testare_tinta[problema] se aplica la stare(nod) atunci
            gasit = 1;//Solutia este gasita //facem variabila booleana gasit adevarata
        else
        {
            for (i = 0; i < n; i++) // Adaugam la final in noduri orasele nevizitate care sunt conectate de nod
                if ((a[nod][i] !=0) && (vizitat[i] == 0)) {
                    noduri[nr_noduri] = i;
                    nr_noduri++;
                    vizitat[i] = 1;//Orasele adaugate sunt marcate ca vizitate
                    parinte[i] = nod;//Se retine pentru oricare din orasele adaugate nodul parinte ca fiind nod

                }

        }
    } 
    */

    /*
    //Algoritmul de cautare in adancime

    for (i = 0; i < n; i++)
        vizitat[i] = 0; // Toate orasele sunt nevizitate.
    noduri[0] = oras_start;//Adaugam in lista noduri orasul de plecare. (in lista de noduri pe prima pozitie adaug orasul de start
    nr_noduri++;
    vizitat[oras_start] = 1;//Marcam orasul de plecare ca vizitat.

    while ((gasit == 0) && (nr_noduri != 0)) // Cat timp solutie negasita si noduri ≠ vida executa
    {
        nod = noduri[0];//nod = scoate_din_fata(noduri) //stocam primul element din noduri in variabila nod

        for (i = 0; i < nr_noduri - 1; i++) //Eliminam primul element din noduri
            noduri[i] = noduri[i + 1];
        nr_noduri--;

        if (nod == oras_dest) //Daca testare_tinta[problema] se aplica la stare(nod) atunci
            gasit = 1;//Solutia este gasita //facem variabila booleana gasit adevarata
        else
        {
            for (i = 0; i < n; i++) // Adaugam la final in noduri orasele nevizitate care sunt conectate de nod
                if ((a[nod][i]!=0) && (vizitat[i] == 0)) {
                    for (j = nr_noduri; j > 0; j--)
                    noduri[j] = noduri[j - 1];//deplasam elem din vect nod spre dreapta cu o pozitie
                    noduri[0] = i;
                    nr_noduri++;//adaugam la inceput in lista de noduri orasul i conectat de nod si nevizitat
                    vizitat[i] = 1;//Orasele adaugate sunt marcate ca vizitate
                    parinte[i] = nod;//Se retine pentru oricare din orasele adaugate nodul parinte ca fiind nod

                }

        }
    }
    */
    

    /*

    //Algoritmul de cautare in adancime LIMITATA

    for (i = 0; i < n; i++)
        vizitat[i] = 0; // Toate orasele sunt nevizitate.
    noduri[0] = oras_start;//Adaugam in lista noduri orasul de plecare. (in lista de noduri pe prima pozitie adaug orasul de start
    nr_noduri++;
    vizitat[oras_start] = 1;//Marcam orasul de plecare ca vizitat.
    adancime[oras_start] = 0;

    while ((gasit == 0) && (nr_noduri != 0)) // Cat timp solutie negasita si noduri ≠ vida executa
    {
        nod = noduri[0];  //nod = scoate_din_fata(noduri) //stocam primul element din noduri in variabila nod

        for (i = 0; i < nr_noduri - 1; i++) //Eliminam primul element din noduri
            noduri[i] = noduri[i + 1];
        nr_noduri--;

        if (adancime[nod] < limita)
        {

            if (nod == oras_dest) //Daca testare_tinta[problema] se aplica la stare(nod) atunci
                gasit = 1;//Solutia este gasita //facem variabila booleana gasit adevarata
            else
            {
                for (i = 0; i < n; i++)   // Adaugam la final in noduri orasele nevizitate care sunt conectate de nod
                    if ((a[nod][i] !=0) && ((vizitat[i] == 0) || ((vizitat[i]=1) && (adancime[i]>adancime[nod]+1) ))) {
                        for (j = nr_noduri; j > 0; j--)
                            noduri[j] = noduri[j - 1];  //deplasam elem din vect nod spre dreapta cu o pozitie
                        noduri[0] = i;
                        nr_noduri++;  //adaugam la inceput in lista de noduri orasul i conectat de nod si nevizitat
                        vizitat[i] = 1;  //Orasele adaugate sunt marcate ca vizitate
                        parinte[i] = nod;  //Se retine pentru oricare din orasele adaugate nodul parinte ca fiind nod
                        adancime[i] = adancime[nod] + 1;


                    }

            }
        }
    }
    */

/*

   //Algoritmul de cautare in adancime limitata ITERATIV

      limita = 0;
      while ((gasit == 0) && (limita < n))
      {
          limita++;

          for (i = 0; i < n; i++)
              vizitat[i] = 0; // Toate orasele sunt nevizitate.
          noduri[0] = oras_start;//Adaugam in lista noduri orasul de plecare. (in lista de noduri pe prima pozitie adaug orasul de start
          nr_noduri++;
          vizitat[oras_start] = 1;//Marcam orasul de plecare ca vizitat.
          adancime[oras_start] = 0;

          while ((gasit == 0) && (nr_noduri != 0)) // Cat timp solutie negasita si noduri ≠ vida executa
          {
              nod = noduri[0];  //nod = scoate_din_fata(noduri) //stocam primul element din noduri in variabila nod

              for (i = 0; i < nr_noduri - 1; i++) //Eliminam primul element din noduri
                  noduri[i] = noduri[i + 1];
              nr_noduri--;

              if (adancime[nod] < limita)
              {

                  if (nod == oras_dest) //Daca testare_tinta[problema] se aplica la stare(nod) atunci
                      gasit = 1;//Solutia este gasita //facem variabila booleana gasit adevarata
                  else
                  {
                      for (i = 0; i < n; i++)   // Adaugam la final in noduri orasele nevizitate care sunt conectate de nod
                          if ((a[nod][i] !=0 ) && ((vizitat[i] == 0) || ((vizitat[i] = 1) && (adancime[i] > adancime[nod] + 1)))) {
                              for (j = nr_noduri; j > 0; j--)
                                  noduri[j] = noduri[j - 1];  //deplasam elem din vect nod spre dreapta cu o pozitie
                              noduri[0] = i;
                              nr_noduri++;  //adaugam la inceput in lista de noduri orasul i conectat de nod si nevizitat
                              vizitat[i] = 1;  //Orasele adaugate sunt marcate ca vizitate
                              parinte[i] = nod;  //Se retine pentru oricare din orasele adaugate nodul parinte ca fiind nod
                              adancime[i] = adancime[nod] + 1;


                          }

                  }
              }
          }
      }
      */

      /*
      //Algoritmul de cautare cu cost uniform

     for (i = 0; i < n; i++)
        vizitat[i] = 0; // Toate orasele sunt nevizitate.
    noduri[0] = oras_start;//Adaugam in lista noduri orasul de plecare. (in lista de noduri pe prima pozitie adaug orasul de start
    nr_noduri++;
    vizitat[oras_start] = 1;//Marcam orasul de plecare ca vizitat.
    cost[oras_start] = 0;

    while ((gasit == 0) && (nr_noduri != 0)) // Cat timp solutie negasita si noduri ≠ vida executa
    {
        nod = noduri[0];  //nod = scoate_din_fata(noduri) //stocam primul element din noduri in variabila nod

        for (i = 0; i < nr_noduri - 1; i++) //Eliminam primul element din noduri
            noduri[i] = noduri[i + 1];
        nr_noduri--;


            if (nod == oras_dest) //Daca testare_tinta[problema] se aplica la stare(nod) atunci
                gasit = 1;//Solutia este gasita //facem variabila booleana gasit adevarata
            else
            {
                for (i = 0; i < n; i++)   // Adaugam la final in noduri orasele nevizitate care sunt conectate de nod
                    if ((a[nod][i] != 0) && ((vizitat[i] == 0) || ((vizitat[i] = 1) && (cost[i] > cost[nod] + a[nod][i]))))
                        //cautam orasele i conesctate de orasul nod si fie sunt nevizitate, fie au fost vizitate la un cost vechi mai mare decat noul cost
                    {
                        cost[i] = cost[nod] + a[nod][i];
                        int k = 0;
                        while ((k < nr_noduri) && (cost[i] > cost[noduri[k]]))
                            k++;

                        for (j = nr_noduri; j > k; j--)
                            noduri[j] = noduri[j - 1];  //deplasam elem din vect nod spre dreapta cu o pozitie
                        noduri[k] = i;
                        nr_noduri++;  //adaugam la inceput in lista de noduri orasul i conectat de nod si nevizitat
                        vizitat[i] = 1;  //Orasele adaugate sunt marcate ca vizitate
                        parinte[i] = nod;  //Se retine pentru oricare din orasele adaugate nodul parinte ca fiind nod


                    }

            }
    
    }
    */
/*
    //Algoritmul de cautare greedy(adaugarea in vectorul noduri se face astfel incat acesta sa fie ordonat crescator dupa h(euristica)

    for (i = 0; i < n; i++)
        vizitat[i] = 0; // Toate orasele sunt nevizitate.
    noduri[0] = oras_start;//Adaugam in lista noduri orasul de plecare. (in lista de noduri pe prima pozitie adaug orasul de start
    nr_noduri++;
    vizitat[oras_start] = 1;//Marcam orasul de plecare ca vizitat.
    cost[oras_start] = 0;

    while ((gasit == 0) && (nr_noduri != 0)) // Cat timp solutie negasita si noduri ≠ vida executa
    {
        nod = noduri[0];  //nod = scoate_din_fata(noduri) //stocam primul element din noduri in variabila nod

        for (i = 0; i < nr_noduri - 1; i++) //Eliminam primul element din noduri
            noduri[i] = noduri[i + 1];
        nr_noduri--;


        if (nod == oras_dest) //Daca testare_tinta[problema] se aplica la stare(nod) atunci
            gasit = 1;//Solutia este gasita //facem variabila booleana gasit adevarata
        else
        {
            for (i = 0; i < n; i++)   // Adaugam la final in noduri orasele nevizitate care sunt conectate de nod
                if ((a[nod][i] != 0) && ((vizitat[i] == 0) || ((vizitat[i] = 1) && (cost[i] > cost[nod] + a[nod][i]))))
                    //cautam orasele i conesctate de orasul nod si fie sunt nevizitate, fie au fost vizitate la un cost vechi mai mare decat noul cost
                {
                    cost[i] = cost[nod] + a[nod][i];
                    int k = 0;
                    while ((k < nr_noduri) && (h[i] > h[noduri[k]]))
                        k++;

                    for (j = nr_noduri; j > k; j--)
                        noduri[j] = noduri[j - 1];  //deplasam elem din vect nod spre dreapta cu o pozitie
                    noduri[k] = i;
                    nr_noduri++;  //adaugam la inceput in lista de noduri orasul i conectat de nod si nevizitat
                    vizitat[i] = 1;  //Orasele adaugate sunt marcate ca vizitate
                    parinte[i] = nod;  //Se retine pentru oricare din orasele adaugate nodul parinte ca fiind nod


                }

        }
}
    */

    //Algoritmul de cautare A*(adaugarea in vectorul noduri se face astfel incat acesta sa fie ordonat crescator dupa cost + h(euristica)

    for (i = 0; i < n; i++)
        vizitat[i] = 0; // Toate orasele sunt nevizitate.
    noduri[0] = oras_start;//Adaugam in lista noduri orasul de plecare. (in lista de noduri pe prima pozitie adaug orasul de start
    nr_noduri++;
    vizitat[oras_start] = 1;//Marcam orasul de plecare ca vizitat.
    cost[oras_start] = 0;

    while ((gasit == 0) && (nr_noduri != 0)) // Cat timp solutie negasita si noduri ≠ vida executa
    {
        nod = noduri[0];  //nod = scoate_din_fata(noduri) //stocam primul element din noduri in variabila nod

        for (i = 0; i < nr_noduri - 1; i++) //Eliminam primul element din noduri
            noduri[i] = noduri[i + 1];
        nr_noduri--;


        if (nod == oras_dest) //Daca testare_tinta[problema] se aplica la stare(nod) atunci
            gasit = 1;//Solutia este gasita //facem variabila booleana gasit adevarata
        else
        {
            for (i = 0; i < n; i++)   // Adaugam la final in noduri orasele nevizitate care sunt conectate de nod
                if ((a[nod][i] != 0) && ((vizitat[i] == 0) || ((vizitat[i] = 1) && (cost[i] > cost[nod] + a[nod][i]))))
                    //cautam orasele i conesctate de orasul nod si fie sunt nevizitate, fie au fost vizitate la un cost vechi mai mare decat noul cost
                {
                    cost[i] = cost[nod] + a[nod][i];
                    int k = 0;
                    while ((k < nr_noduri) && (cost[i]+h[i] > cost[noduri[k]]+h[noduri[k]]))
                        k++;

                    for (j = nr_noduri; j > k; j--)
                        noduri[j] = noduri[j - 1];  //deplasam elem din vect nod spre dreapta cu o pozitie
                    noduri[k] = i;
                    nr_noduri++;  //adaugam la inceput in lista de noduri orasul i conectat de nod si nevizitat
                    vizitat[i] = 1;  //Orasele adaugate sunt marcate ca vizitate
                    parinte[i] = nod;  //Se retine pentru oricare din orasele adaugate nodul parinte ca fiind nod


                }

        }

    }


    int lungime_drum = cost[oras_dest];
    // construirea si afisarea solutiei
    if (gasit == 1) {
        while (oras_dest != oras_start) {
            solutie[nr_solutie] = oras_dest;
            oras_dest = parinte[oras_dest];
            nr_solutie++;
        }
        solutie[nr_solutie] = oras_start;
        for (i = nr_solutie; i >= 0; i--)
            std::cout << nume[solutie[i]] << "   " << endl;

    std::cout << "Solutia s-a gasit la numarul de km " << lungime_drum << '\n';
    }
    else
        std::cout << "Nu s-a gasit solutia";


    for (i = 0; i < nr_solutie; i++)
        km = km + a[solutie[i]][solutie[i + 1]];
    std::cout << "Drumul are " << km << " km si se parcurge in " << km / 80 << " ore si " << ((km % 80) * 60)/80<<" minute.";

    return 0;
}

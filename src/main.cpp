#include<iostream>
using namespace std;


int nrNoduri, nrMuchii, i, j;
int adiacente[20][20];
bool vizitat[20];
int tata[20], distanta[20];
int prim, ultim, coada[20];


/* Initializeaza vectorii "vizitat", "tata" si "distanta" */
void intilializare()
{
	for (int i = 1; i <= nrNoduri; ++i)
	{
		vizitat[i] = 0; // un vector boolean care ne arata daca nodul 'i' a fost parcurs/vizitat pana acum
		tata[i] = 0; // vectorul tata 
		distanta[i] = INT_MAX; // distanta de la nodul 'i' la radacina
	}
}


/* Breadth first */
void bf(int start)
{
	int prim, ultim; // in principal folosim doua variabile "prim" si "ultim" deoarece dorim sa ne oprim atunci cand nu mai exista vecini ai nodului curent, cand nu mai avem ce parcurge pe scurt

	prim = ultim = 1;  coada[1] = start; // pozitia primului si a ultimului element la inceput este '1' si se adauga in coada primul element, "start"
	vizitat[start] = 1;  distanta[start] = 0; // se trece primul element, start, ca vizitat si distanta de la radacina la el este '0', deoarece "start" este chiar radacina

	while (prim <= ultim) 
	{
		int i = coada[prim];  prim = prim + 1; // se memoreaza valoarea actuala din coada in 'i' si se afiseaza, dupa aceea "prim" isi modifica pozitia+1 pt a memora urmatorul element adaugat
		cout << i << " ";

		for (j = 1; j <= nrNoduri; ++j)
			if (adiacente[i][j] == 1) // daca nodul 'i' are vecini atunci
				if (vizitat[j] == 0) // daca vecinii nu au fost vizitati atunci
				{
					ultim = ultim + 1;  coada[ultim] = j; // pozitia "ultim" creste cu o pozitie si se adauga nodul 'j' in coada, ca urmator element
					vizitat[j] = 1; // 'j' a fost vizitat
					tata[j] = i; // tatal nodului 'j' este 'i' <-> se creaza vectorul de tati automat
					distanta[j] = distanta[i] + 1; // distanta de la nodul 'j' la radacina <-> se creaza tot automat
				}
	}
}


int main()
{

	intilializare(); 

	cout << " Nr. de noduri este: ";
	cin >> nrNoduri;
	cout << " Nr. de muchii este: ";
	cin >> nrMuchii;

	int x, y;
	cout << " Se citeste matricea de adiacenta: " << endl;
	for (i = 1; i <= nrNoduri; i++)
		for (j = 1; j <= nrNoduri; j++)
			adiacente[i][j] = 0;
	for (i = 1; i <= nrMuchii; i++)
	{
		cout << " Dati extremitatile muchiei " << i << ": ";
		cin >> x >> y;
		adiacente[x][y] = 1;
		adiacente[y][x] = 1;
	}
	cout << " BF: ";
	bf(1);
	cout << endl;


	int nrCompConex = 0;
	for (i = 1; i <= nrNoduri; ++i)
		if (vizitat[i] == 0) 
		{
			cout << " Cealalta componenta conexa este: " << endl;
			nrCompConex++;
			bf(i);
			cout << endl;
		}


	cout << endl;
	system("pause");
	return 0;
}

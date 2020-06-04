#include <iostream>
using namespace std;

void kreska(int k, int s)
{
	for (int i = 0; i < k*s + 2 + k-1; i++)
		cout << "*";
	cout << endl;
}

void wnetrzeParzyste(int k, int s)
{
	for (int i = 0; i < s; i++)
	{
		//gwiazdka bezwzgledna
		cout << "*";
		for (int j = 0; j < k; j++)
		{
			//kropki przesuniecia
			for (int l = 0; l < i; l++) cout << ".";
			//klamra otwierajaca
			cout << "\\";
			j++;
			//kropki przesuniecia
			for (int l = s-1-i; l > 0; l--) cout << ".";
			//seperator *
			cout << "*";
			if (j >= k) break;
			//kropki przesuniecia
			for (int l = s - 1 - i; l > 0; l--) cout << ".";
			//klamra zamkniecia
			cout << "/";
			//kropki zamkniecia
			for (int l = 0; l < i; l++) cout << ".";
			//gwiazdka zamkniecia
			cout << "*";
		}
		cout << endl;
	}
}

void wnetrzeNieparzyste(int k, int s)
{
	for (int i = 0; i < s; i++)
	{
		//gwiazdka bezwzgledna
		cout << "*";
		for (int j = 0; j < k; j++)
		{
			//kropki przesuniecia
			for (int l = s - 1 - i; l > 0; l--) cout << ".";
			//klamra otwierajaca
			cout << "/";
			j++;
			//kropki przesuniecia
			for (int l = 0; l < i; l++) cout << ".";
			//seperator *
			cout << "*";
			if (j >= k) break;
			//kropki przesuniecia
			for (int l = 0; l < i; l++) cout << ".";
			//klamra zamkniecia
			cout << "\\";
			//kropki zamkniecia
			for (int l = s - 1 - i; l > 0; l--) cout << ".";
			//gwiazdka zamkniecia
			cout << "*";
		}
		cout << endl;
	}
}

void rysuj(int w, int k, int s)
{
	//rysowanie pierwszej kreski
	kreska(k, s);

	for (int i = 0; i < w; i++)
	{
		if (i % 2 == 0) wnetrzeParzyste(k, s);
		else wnetrzeNieparzyste(k, s);
		kreska(k, s);
	}
}


int main()
{
	int t; //liczba testow
	int w; //liczba wierszy
	int k; //liczba kolumn
	int s; //wysokoœæ kolumienki (szerokoœæ dywanu)
	int tab[100][3];

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> tab[i][j];
	}

	for (int i = 0; i < t; i++)
	{
		w = tab[i][0];
		k = tab[i][1];
		s = tab[i][2];
		rysuj(w, k, s);
		cout << endl << endl;
	}

	return 0;
}

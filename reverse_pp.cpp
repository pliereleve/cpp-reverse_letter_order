#include<string>
#include<iostream>

using namespace std;

int main()
{
	char tab[1000];
	int i = 0;
	do
	{
		tab[i] = getchar();
		i++;
	} while (tab[i - 1] != '\x0A');		//odpowiednik line feed (enter) w ascii (szesnastkowo); inny sposob: '\n'
	
	char wynik[1000];
	for (int k = 0; k < i; k++)			//i - liczba znakow calego tekstu
	{
		int licznik = 0;

		while (tab[k] != ' ' && tab[k] != '\n')
		{
			licznik++;					//zlicza dlugosc slowa
			k++;
		}
		
		for (int s = k - licznik, j = 0; s < k; s++, j++)		//s ma startowac od poczatku odwracanego slowa (k-licznik)
		{														//j to zmienna pomocnicza do poruszania sie po tab
			wynik[s] = tab[k - j - 1];							//k-j przechodzi po odwracanym slowie od konca; 
		}														//-1 poniewaz k poczatkowo pokazuje na spacje (wyzsza petla while konczy obieg, gdy k wejdzie na spacje)
		wynik[k] = ' ';
	}

	for (int p = 0; p < i; p++)
	{
		cout << wynik[p];
	}

	system("pause");
	return 0;
}
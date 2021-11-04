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
	} while (tab[i - 1] != '\x0A');		//odpowiednik line feed (enter) w ascii (szesnastkowo); inny spos�b: '\n'
	
	char wynik[1000];
	for (int k = 0; k < i; k++)			//i - liczba znak�w ca�ego tekstu
	{
		int licznik = 0;

		while (tab[k] != ' ' && tab[k] != '\n')
		{
			licznik++;
			k++;
		}
		
		for (int s = k - licznik, j = 0; s < k; s++, j++)		//s ma startowa� od pocz�tku odwracanego s�owa (k-licznik)
		{														//j to zmienna pomocnicza do poruszania si� po tab
			wynik[s] = tab[k - j - 1];							//k-j przechodzi po odwracanym s�owie od ko�ca; 
		}														//-1 poniewa� k pocz�tkowo pokazuje na spacj� (wy�sza p�tla while ko�czy obieg, gdy k wejdzie na spacj�)
		wynik[k] = ' ';
	}

	for (int p = 0; p < i; p++)
	{
		cout << wynik[p];
	}

	system("pause");
	return 0;
}
#include"Tablica2DFragmentarycznie.h"
int** AlokujTablice2DFragment(int wiersz, int kolumna)
{
	int** tablica = new int* [wiersz+1];
	tablica[0] = new int[1];
	tablica[0][0] = (wiersz << 16) | (kolumna&0xFFFF);
	for (int i = 1; i <=wiersz; i++)
		tablica[i] = new int[kolumna] {0};
	return tablica+1;
}

void DealokujTablice2DFragment(int** tablica)
{
	int SumaRozmiarow = tablica[-1][0];
	int wiersz = SumaRozmiarow >> 16;
	int kolumna = SumaRozmiarow & 0xFFFF;
	for (int i = 0; i < wiersz; i++)
	{
		delete[]tablica[i];
	}
	delete[]tablica[-1];
	delete[](tablica-1);
}

void ZapiszDoPlikuTablice2DFragment(const char* NazwaPliku,int** tablica)
{
	int SumaRozmiarow = tablica[-1][0];
	int wiersz = SumaRozmiarow>>16;
	int kolumna = SumaRozmiarow & 0xFFFF;
	FILE* plik = fopen(NazwaPliku, "wb");
	fwrite(&wiersz, sizeof(int), 1, plik);
	fwrite(&kolumna, sizeof(int), 1, plik);
	for (int i = 0; i < wiersz; i++)
	{
		fwrite(tablica[i], sizeof(int), kolumna, plik);
	}
	fclose(plik);
}

int** OdczytZPliku(const char* NazwaPliku)
{
	int wiersz = 0;
	int kolumna = 0;
	FILE* plik = fopen(NazwaPliku, "rb");
	fread(&wiersz, sizeof(int), 1, plik);
	fread(&kolumna, sizeof(int), 1, plik);
	int**tab = AlokujTablice2DFragment(wiersz, kolumna);
	for (int i = 0; i < wiersz; i++)
	{
		fread(tab[i], sizeof(int), kolumna, plik);
	}
	fclose(plik);
	return tab;
}
void WypiszTablice(int** tablica)
{
	int SumarycznyRozmiar = tablica[-1][0];
	int wiersz = SumarycznyRozmiar >> 16;
	int kolumna = SumarycznyRozmiar & 0xFFFF;
	for (int i = 0; i < wiersz; i++)
	{
		for (int j = 0; j < kolumna; j++)
		{
			cout << tablica[i][j] << " ";
		}
		cout << endl;
	}
}
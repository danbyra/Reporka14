#include"Tablica1D.h"
short* AlokujTablice1D(int rozmiar)
{
	short* tablica = new short[rozmiar + 1];
	tablica[0] = (rozmiar<<8) | (LicznikTablic&0xFF);
	for (int i = 1; i <=rozmiar; i++)
	{
		tablica[i] = 0;
	}
	LicznikTablic++;
	return tablica+1;
}
void DealokujTablice1D(short* tablica)
{
	delete[](tablica-1);
	LicznikTablic--;
	
}
void ZapiszDoPliku(const char* Nazwa, short* Tablica)
{
	char NazwaPliku[256];
	sprintf(NazwaPliku, "%s%d", Nazwa, Tablica[-1]&0xFF);

	int rozmiar = Tablica[-1]>>8;
	FILE* plik = fopen(NazwaPliku, "wb");
	fwrite(&rozmiar, sizeof(int), 1, plik);

	fwrite(Tablica, sizeof(short), rozmiar, plik);
	fclose(plik);
}
short* OdczytZPliku(const char* Nazwa, int licznik)
{
	char NazwaPliku[256];
	sprintf(NazwaPliku, "%s%d", Nazwa, licznik);
	FILE* plik = fopen(NazwaPliku, "rb");
	int rozmiar = 0;
	fread(&rozmiar, sizeof(int), 1, plik);
	short* dane = AlokujTablice1D(rozmiar);
	fread(dane, sizeof(short), rozmiar, plik);
	fclose(plik);
	return dane;
}

void Wypisz(short* tab)
{
	for (int i = 0; i < tab[-1]>>8; i++)
	{
		cout << tab[i] << endl;
	}
}
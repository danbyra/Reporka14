#include"Tablica2DCiagla.h"
int* AlokujTablice2DCiagla(int wiersz, int kolumny)
{
	int* tab = new int[wiersz * kolumny + 1];
	tab[0] = (wiersz << 16) | (kolumny&0xFFFF);
	for (int i = 1; i <=wiersz * kolumny; i++)tab[i] = 0;
	return tab + 1;
}
int PobierzWiersze(int* tab)
{
	return tab[-1] >> 16;
}
int PobierzKolumny(int* tab)
{
	return tab[-1] & 0xFFFF;
}
void DealokujTablice2Dciagla(int* tablica)
{
	delete[](tablica - 1);
}
void ZapiszDoPlikuTablica2DCiagla(const char* NazwaPliku, int* tablica)
{
	int meta = tablica[-1];
	int wiersz = PobierzWiersze(tablica);
	int kolumny = PobierzKolumny(tablica);
	FILE* plik = fopen(NazwaPliku, "wb");	
	fwrite(&meta, sizeof(int), 1, plik);
	fwrite(tablica, sizeof(int), wiersz * kolumny, plik);
	fclose(plik);
}
int* OdczytZPlikuTablica2DCiagla(const char* NazwaPliku)
{
	int meta = 0;
	FILE* plik = fopen(NazwaPliku, "rb");
	fread(&meta, sizeof(int), 1, plik);
	int wiersz = meta >> 16;
	int kolumny = meta & 0xFFFF;
	int* tab = AlokujTablice2DCiagla(wiersz, kolumny);
	fread(tab, sizeof(int), wiersz * kolumny, plik);
	fclose(plik);
	return tab;
}
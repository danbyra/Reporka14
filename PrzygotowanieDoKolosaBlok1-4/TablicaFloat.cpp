#include"Tablica.h"
TablicaFloat* AlokujTabliceFloat(int rozmiar)
{
	TablicaFloat* tablica = new TablicaFloat;
	tablica->rozmiar = rozmiar;
	tablica->id = IdentyfikatorFloat++;
	tablica->dane = new float[rozmiar] {0};
	return tablica;
}
void DealokujTabliceFloat(TablicaFloat* tablica)
{
	delete[]tablica->dane;
	delete tablica;
}
void ZapiszDoPliku(const char* nazwa, TablicaFloat* tablica)
{
	char NazwaPliku[30];
	double SumaKontrolna = 0;
	for (int i = 0; i < tablica->rozmiar; i++)
	SumaKontrolna += tablica->dane[i];
	sprintf(NazwaPliku, "%s%d%s", nazwa, tablica->id, ".bin");
	FILE* plik = fopen(NazwaPliku, "wb");
	fwrite(&tablica->rozmiar, sizeof(int), 1, plik);
	fwrite(tablica->dane, sizeof(float), tablica->rozmiar, plik);
	fwrite(&SumaKontrolna, sizeof(double), 1, plik);
	fclose(plik);
}
TablicaFloat* OdczytZpliku(const char* nazwa,int ID)
{
	char NazwaPliku[30];
	int rozmiar = 0;
	double SumaKontrolnaOdczyt = 0;
	double SumaKontrolna = 0;
	sprintf(NazwaPliku, "%s%d%s", nazwa, ID, ".bin");
	FILE* plik = fopen(NazwaPliku, "rb");
	fread(&rozmiar, sizeof(int), 1, plik);
	TablicaFloat* TabOdczyt = AlokujTabliceFloat(rozmiar);
	fread(TabOdczyt->dane, sizeof(float), rozmiar, plik);
	fread(&SumaKontrolnaOdczyt, sizeof(double), 1, plik);
	fclose(plik);
	for (int i = 0; i < rozmiar; i++)
		SumaKontrolna += TabOdczyt->dane[i];
	if (SumaKontrolna != SumaKontrolnaOdczyt)
	{
		throw domain_error("Blad sumy kontrolnej");
		return nullptr;
	}
	return TabOdczyt;
}

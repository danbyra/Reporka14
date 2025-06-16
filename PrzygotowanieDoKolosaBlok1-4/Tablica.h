#pragma once
#include"Biblioteki.h"

static int IdentyfikatorFloat=0;
struct TablicaFloat
{
	float* dane;
	int rozmiar;
	int id;
};

TablicaFloat* AlokujTabliceFloat(int rozmiar);
void DealokujTabliceFloat(TablicaFloat* tablica);
void ZapiszDoPliku(const char* nazwa, TablicaFloat* tablica);
TablicaFloat* OdczytZpliku(const char* nazwa,int ID);
#pragma once
#include"Biblioteki.h"
int* AlokujTablice2DCiagla(int wiersz, int kolumny);
int PobierzWiersze(int* tab);
int PobierzKolumny(int* tab);
void DealokujTablice2Dciagla(int* tablica);
void ZapiszDoPlikuTablica2DCiagla(const char* NazwaPliku, int* tablica);
int* OdczytZPlikuTablica2DCiagla(const char* NazwaPliku);
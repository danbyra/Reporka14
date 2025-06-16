#pragma once
#include"Biblioteki.h"
int** AlokujTablice2DFragment(int wiersz,int kolumna);
void DealokujTablice2DFragment(int** tablica);
void ZapiszDoPlikuTablice2DFragment(const char* NazwaPliku, int**tablica);
int** OdczytZPliku(const char* NazwaPliku);
void WypiszTablice(int** tablica);
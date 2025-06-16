#pragma once
#include"Biblioteki.h"
static int LicznikTablic = 0;

short* AlokujTablice1D(int rozmiar);
void DealokujTablice1D(short* tablica);
void ZapiszDoPliku(const char* Nazwa,short*Tablica);
short* OdczytZPliku(const char* Nazwa,int numer);
void Wypisz(short* tab);

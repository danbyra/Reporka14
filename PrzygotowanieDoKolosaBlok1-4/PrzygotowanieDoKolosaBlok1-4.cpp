// PrzygotowanieDoKolosaBlok1-4.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include"Biblioteki.h"
#include"Tablica1D.h"
#include"Tablica2DFragmentarycznie.h"
int main()
{
	int wiersz = 4;
	int kolumna = 6;
	char nazwa[20] = "test2D.txt";
	int** tab1 = AlokujTablice2DFragment(wiersz, kolumna);

	ZapiszDoPlikuTablice2DFragment(nazwa, tab1);
	int** TabOdczyt = OdczytZPliku(nazwa);
	WypiszTablice(TabOdczyt);

	DealokujTablice2DFragment(tab1);
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln

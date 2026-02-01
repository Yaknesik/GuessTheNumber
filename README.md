# GuessTheNumber
Gra w C++ "Zgadnij liczbę!" - sprawdź swoje zdolności liczenia i intuicji!

## Spis treści
- [Opis gry](#opis-gry)
- [Wymagania systemowe](#wymagania-systemowe)
- [Instalacja i uruchomienie](#instalacja-i-uruchomienie)
- [Instrukcja gry](#instrukcja-gry)
- [Poziomy trudności](#poziomy-trudności)
- [Funkcjonalności](#funkcjonalności)
- [Źródła](#źródła)

## Opis gry
"Guess The Number" to interaktywna gra konsolowa, w której zadaniem gracza jest odgadnięcie sekretnej liczby. Gra oferuje cztery różne poziomy trudności i rejestruje wyniki w rankingu TOP 5.

## Wymagania systemowe
- Kompilator C++ (np. g++, clang lub MSVC)
- Podstawowa wiedza na temat pracy z terminalem/wierszem poleceń
- Minimum 1 MB wolnego miejsca na dysku

## Instalacja i uruchomienie

### Kompilacja:
```bash
g++ main.cpp game.cpp top.cpp -o GuessTheNumber
```

### Uruchomienie:
```bash
./GuessTheNumber
```

## Instrukcja gry

1. **Menu główne** - Po uruchomieniu gry pojawi się menu główne z opcjami:
   - Rozpocznij grę
   - Instrukcja
   - TOP 5 (dostępne po rozegraniu co najmniej jednej gry)
   - Wyjście

2. **Wybranie poziomu trudności** - Wybierz odpowiadający ci poziom

3. **Gra** - Wpisuj liczby z podanego zakresu
   - Gra poda ci wskazówkę czy szukana liczba jest większa czy mniejsza
   - Licznik prób pokazuje, ile już spróbowałeś
   - Ciśnij Enter po każdym wpisaniu liczby

4. **Koniec gry** - Po odgadnięciu liczby wpisujesz swoje imię, które zostaje zapisane w rankingu

## Poziomy trudności

| Poziom | Zakres | Opis |
|--------|--------|------|
| **1. Łatwy** | 1-50 | Idealny dla początkujących |
| **2. Średni** | 1-125 | Dla osób z podstawową praktyką |
| **3. Trudny** | 1-250 | Wyzwanie dla doświadczonych graczy |
| **4. Ekstremalny** | 1-250 + reset | Liczba zmienia się co 5 nietrafionych prób! |

## Funkcjonalności

- **Cztery poziomy trudności** - Różne zakresy liczb dla każdego poziomu
- **Tryb Ekstremalny** - Dodatkowe wyzwanie z dynamiczną zmianą liczby
- **Losowe wskazówki** - Różne komunikaty zachęcające do dalszej gry
- **Ranking TOP 5** - Zapisywanie i wyświetlanie najlepszych wyników
- **Walidacja danych** - Gra chroni przed błędnym wpisaniem danych
- **Intuicyjny interfejs** - Łatwa do nauki i grania dla każdego

## Struktura projektu

- `main.cpp` - Plik główny z menu i logią aplikacji
- `game.cpp / game.h` - Moduł obsługujący grę
- `top.cpp / top.h` - Moduł obsługujący ranking TOP 5
- `wyniki.txt` - Plik z zapisanymi wynikami (tworzony automatycznie)

## Porady

- W trybie ekstremalnym każda pomyłka liczy się jako próba, nawet jeśli wpiszesz coś nieprawidłowego!
- Spróbuj odgadnąć liczbę w jak najmniej próbach
- Każdy poziom trudności zapisuje wyniki osobno

## Źródła
Gra powstała w oparciu o materiały z:
- https://www.w3schools.com/cpp/
- https://www.codecademy.com/

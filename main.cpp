#include <iostream>
#include "game.h"
using namespace std;

int main() {
    int select;
    do {
        cout << "============================================\nWitamy w grze liczbowej \"Guess The Number!\"\n============================================\n";
        cout << "Wybierz jedną z poniższych opcji, wpisując cyfrę!\n";
        cout << "1. Rozpocznij grę\n";
        cout << "2. Instrukcja\n";
        cout << "3. Wyjście\n";
        cin >> select;

        switch (select) {
            case 1:
                int difficulty;
                cout << "Wybierz poziom trudności!";
                cout << "1. Łatwy (1-50)";
                cout << "2. Średni (1-125)";
                cout << "3. Trudny (1-250)";
                cout << "4. Ekstremalny (1-250 + reset zgadywanej liczby co 5 prób)\n";

                cin >> difficulty;

                startGame(difficulty);
                
                break;

            case 2:
                cout << "INSTRUKCJA GRY:\n";
                cout << "Aby rozpocząć grę, należy wejść w \"Rozpocznij grę\"\n";
                cout << "Po czym wybrać poziom trudność i zgadnąć liczbę !\n";
                cout << "TRYB EKSTREMALNY - W tym trybie, gracz zgaduje liczbę w zakresie od 1 do 300,\nprzy 5 nietrafionych liczba zgadywana ulega zmianie!\n";
                cout << "1. Wyjście\n";

                cin >> select;

                break;
            
            case 3:
                cout << "Wyjście z gry.";
                return 0;

            default:
                cout << "Nieprawidłowa opcja! Wybierz ponownie.";
        };
    } while (select != 3);
};
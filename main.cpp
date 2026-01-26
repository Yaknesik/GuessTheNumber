#include <iostream>
#include <fstream>
#include "game.h"
#include "top.h"
using namespace std;

bool AnyScores() {
    ifstream file("wyniki.txt");
    if(!file.is_open()) return false;
    
    return file.peek() != ifstream::traits_type::eof();
}

int main() {
    int select;
    do {
        cout << "============================================\nWitamy w grze liczbowej \"Guess The Number!\"\n============================================\n";
        cout << "Wybierz jedną z poniższych opcji, wpisując cyfrę!\n";
        cout << "1. Rozpocznij grę\n";
        cout << "2. Instrukcja\n";
        
        bool scoresExist = AnyScores();
        if(scoresExist) cout << "3. TOP 5\n";
        
        cout << "4. Wyjście\n";
        cin >> select;
        
        if(!cin) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Nieprawidłowa opcja! Spróbuj ponownie.\n";
            continue;
        }

        switch (select) {
            case 1:
                cout << string(100, '\n');

                int difficulty;
                cout << "Wybierz poziom trudności!\n";
                cout << "1. Łatwy (1-50)\n";
                cout << "2. Średni (1-125)\n";
                cout << "3. Trudny (1-250)\n";
                cout << "4. Ekstremalny (1-250 + reset zgadywanej liczby co 5 prób)\n";
                cout << "5. Wyjście do menu!\n";

                cin >> difficulty;

                if(!cin) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Nieprawidłowa opcja! Spróbuj ponownie.\n";
                    continue;
                }

                if(difficulty == 5) {
                    cout << string(100, '\n');
                    break;
                } else if (difficulty >= 1 && difficulty <= 4) {
                        startGame(difficulty);
                } else {
                    break;
                }
            case 2:
                cout << string(100, '\n');
                
                int select;
            
                cout << "INSTRUKCJA GRY:\n";
                cout << "Aby rozpocząć grę, należy wejść w \"Rozpocznij grę\"\n";
                cout << "Po czym wybrać poziom trudność i zgadnąć liczbę !\n";
                cout << "TRYB EKSTREMALNY - W tym trybie, gracz zgaduje liczbę w zakresie od 1 do 250,\nprzy 5 nietrafionych liczba zgadywana ulega zmianie!\n";
                cout << "1. Wyjście do menu!\n";

                cin >> select;

                if(!cin || select != 1) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Nieprawidłowa opcja! Spróbuj ponownie.\n";
                    continue;
                } else if (select == 1) {
                    cout << string(100, '\n');
                    break;
                }
            
            case 3:
                cout << string(100, '\n');
                showTopMenu();
                break;

            case 4:
                cout << "Wyjście z gry.";
                return 0;

            default:
                cout << "Nieprawidłowa opcja! Wybierz ponownie.";
                break;
        };
    } while (select != 4);
};
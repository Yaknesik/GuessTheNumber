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
        cout << "Wybierz jedna z ponizszych opcji, wpisujac cyfre!\n";
        cout << "1. Rozpocznij gre\n";
        cout << "2. Instrukcja\n";
        
        bool scoresExist = AnyScores();
        if(scoresExist) cout << "3. TOP 5\n";
        
        cout << "4. Wyjscie\n";
        cin >> select;
        
        if(!cin) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Nieprawidlowa opcja! Sprobuj ponownie.\n";
            continue;
        }

        switch (select) {
            case 1:
                cout << string(100, '\n');

                int difficulty;
                cout << "Wybierz poziom trudnosci!\n";
                cout << "1. Latwy (1-50)\n";
                cout << "2. Sredni (1-125)\n";
                cout << "3. Trudny (1-250)\n";
                cout << "4. Ekstremalny (1-250 + reset zgadywanej liczby co 5 prob)\n";
                cout << "5. Wyjscie do menu!\n";

                cin >> difficulty;

                if(!cin) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Nieprawidlowa opcja! Sprobuj ponownie.\n";
                    continue;
                }

                if(difficulty == 5) {
                    cout << string(100, '\n');
                    break;
                } else if (difficulty >= 1 && difficulty <= 4) {
                        startGame(difficulty);
                };

                break; 
            case 2:
                cout << string(100, '\n');
                
                int instructionSelect;

                cout << "INSTRUKCJA GRY:\n";
                cout << "Aby rozpoczac gre, nalezy wejsc w \"Rozpocznij gre\"\n";
                cout << "Po czym wybrac poziom trudnosc i zgadnac liczbe !\n";
                cout << "TRYB EKSTREMALNY - W tym trybie, gracz zgaduje liczbe w zakresie od 1 do 250,\nprzy 5 nietrafionych liczba zgadywana ulega zmianie!\n";
                cout << "1. Wyjscie do menu!\n";
            
                do {
                    cin >> instructionSelect;

                    if(!cin || instructionSelect != 1) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Nieprawidlowa opcja! Sprobuj ponownie.\n";
                    };
                } while (instructionSelect != 1);
                cout << string(100, '\n');
                break;
            
            case 3:
                cout << string(100, '\n');
                showTopMenu();
                break;

            case 4:
                cout << "Wyjscie z gry.";
                return 0;

            default:
                cout << "Nieprawidlowa opcja! Wybierz ponownie.";
                break;
        };
    } while (select != 4);
};
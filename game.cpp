#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;


void startGame(int difficulty) {
    srand(time(0));


    vector<string> tooLow {
        "Za mało!",
        "Spróbuj większą liczbę!",
        "Nie, to za niska liczba!",
        "Więcej!",
        "Podnieś wartość!",
        "Nie trafione, jest za mało!",
        "Jeszcze trochę większa!",
        "Za mało, próbuj dalej!",
        "Nie, liczba jest większa!",
        "Nie zgadłeś, spróbuj większą!"
    };

    vector<string> tooHigh {
        "Za dużo!",
        "Spróbuj mniejszą liczbę!",
        "Nie, to zbyt wysoka liczba!",
        "Mniej!",
        "Obniż wartość!",
        "Nie trafione, jest za dużo!",
        "Jeszcze trochę mniejsza!",
        "Za dużo, próbuj dalej!",
        "Nie, liczba jest niższa!",
        "Nie zgadłeś, spróbuj mniejszą!"
    };

    int maxNumber;
    string difficultyName;
    bool extremeMode = false;

    switch (difficulty) {
        case 1: maxNumber = 50; difficultyName = "LATWY"; break;
        case 2: maxNumber = 125; difficultyName = "SREDNI"; break;
        case 3: maxNumber = 250; difficultyName = "TRUDNY"; break;
        case 4: maxNumber = 250; extremeMode = true; difficultyName = "EXTREME"; break;
        default:
            cout << "Nieprawidłowo wybrany poziom trudności! Spróbuj ponownie!\n";
            return;
    }

    int randomNumber =  rand() % maxNumber + 1;

    int guess;

    int tries = 1;

    cout << "\n\n\n\n\n\n\n\n\nZgadnij liczbę w zakresie od 1 do " << maxNumber << "!\n";

    do {
        cout << "Próba nr " << tries << " Twój strzał: ";
        cin >> guess;

        if(!cin || guess <= 0 || guess > maxNumber) {
            cout << "BŁĄD! Proszę wpisać tylko liczbę (nie używamy liter!), która jest w zakresie od 1 do" << maxNumber << "!\n";
            cin.clear();
            cin.ignore(1000, '\n');
            if(extremeMode) {
                tries++;
                cout << "W trybie ekstremalnym, nawet pomyłki liczą się jako próby ;)!\n";
            };
            continue;
        }

        tries++;

        if(guess < randomNumber) {
            int randomLow = rand() % tooLow.size();
            cout << tooLow[randomLow] << endl;
        } else if (guess > randomNumber) {
            int randomHigh = rand() % tooHigh.size();
            cout << tooHigh[randomHigh] << endl;
        } else {
            cout << "Brawo! Odgadnięto liczbę \"" << randomNumber << "\" w " << tries << " próbach!\n";
            
            cout << "\nPodaj swoje imię: ";
            string name;
            cin >> name;

            ofstream outFile("wyniki.txt", ios::app);
            if(outFile.is_open()) {
                outFile << difficulty << "," << tries << "," << name << endl;
                outFile.close();
                cout << "Wynik został zapisany!\n";
            }
        }

        if(extremeMode && tries % 5 == 0 && guess != randomNumber) {
            randomNumber = rand() % maxNumber + 1;
            cout << "LICZBA ZOSTAŁA ZMIENIONA!!!\n";
        }

    } while (guess != randomNumber);

};

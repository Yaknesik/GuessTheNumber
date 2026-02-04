#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;


void startGame(int difficulty) {
    srand(time(0));


    vector<string> tooLow {
        "Za malo!",
        "Sprobuj wieksza liczbe!",
        "Nie, to za niska liczba!",
        "Wiecej!",
        "Podnies wartosc!",
        "Nie trafione, jest za malo!",
        "Jeszcze troche wieksza!",
        "Za malo, probuj dalej!",
        "Nie, liczba jest wieksza!",
        "Nie zgadles, sprobuj wieksza!"
    };

    vector<string> tooHigh {
        "Za duzo!",
        "Sprobuj mniejsza liczbe!",
        "Nie, to zbyt wysoka liczba!",
        "Mniej!",
        "Obniz wartosc!",
        "Nie trafione, jest za duzo!",
        "Jeszcze troche mniejsza!",
        "Za duzo, probuj dalej!",
        "Nie, liczba jest nizsza!",
        "Nie zgadles, sprobuj mniejsza!"
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
            cout << "Nieprawidlowo wybrany poziom trudnosci! Sprobuj ponownie!\n";
            return;
    }

    int randomNumber =  rand() % maxNumber + 1;

    int guess;

    int tries = 1;

    cout << "\n\n\n\n\n\n\n\n\nZgadnij liczbe w zakresie od 1 do " << maxNumber << "!\n";

    do {
        cout << "Proba nr " << tries << " Twoj strzal: ";
        cin >> guess;

        if(!cin || guess <= 0 || guess > maxNumber) {
            cout << "BLAD! Prosze wpisac tylko liczbe (nie uzywamy liter!), ktora jest w zakresie od 1 do" << maxNumber << "!\n";
            cin.clear();
            cin.ignore(1000, '\n');
            if(extremeMode) {
                tries++;
                cout << "W trybie ekstremalnym, nawet pomylki licza sie jako proby ;)!\n";
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
            cout << "Brawo! Odgadnieto liczbe \"" << randomNumber << "\" w " << tries << " probach!\n";
            
            cout << "\nPodaj swoje imie: ";
            string name;
            cin >> name;

            ofstream outFile("wyniki.txt", ios::app);
            if(outFile.is_open()) {
                outFile << difficulty << "," << tries << "," << name << endl;
                outFile.close();
                cout << "Wynik zostal zapisany!\n";
            }
        }

        if(extremeMode && tries % 5 == 0 && guess != randomNumber) {
            randomNumber = rand() % maxNumber + 1;
            cout << "LICZBA ZOSTALA ZMIENIONA!!!\n";
        }

    } while (guess != randomNumber);

};

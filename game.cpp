#include <iostream>
#include <ctime>
using namespace std;


void startGame(int difficulty) {
    srand(time(0));

    int maxNumber;
    bool extremeMode = false;

    switch (difficulty) {
        case 1: maxNumber = 50; break;
        case 2: maxNumber = 125; break;
        case 3: maxNumber = 250; break;
        case 4: maxNumber = 250; extremeMode = true; break;
        default:
            cout << "Nieprawidłowo wybrany poziom trudności! Spróbuj ponownie!\n";
            return;
    }

}
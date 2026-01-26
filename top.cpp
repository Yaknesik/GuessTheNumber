#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Score {
    int difficulty;
    int tries;
    string name;
};

string difficultyName(int difficulty) {
    switch(difficulty) {
        case 1: return "LATWY";
        case 2: return "SREDNI";
        case 3: return "TRUDNY";
        case 4: return "EXTREME";
        default: return "NIEZNANY";
    }
}

void showTopForDifficulty(vector<Score> scores, int difficulty) {
    vector<Score> filtered;

    for(int i = 0; i < scores.size(); i++) {
        if(scores[i].difficulty == difficulty) filtered.push_back(scores[i]);
    }
    
    int back;

    if(filtered.empty()) {
        cout << "Brak wyników dla tego poziomu!\n\n";
        do {
            cout << "Wciśnij 1 aby wrócić do menu: ";
            cin >> back;
    
            if(!cin) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Nieprawidłowa opcja!\n";
            }
    
        } while(back != 1);
        return;
    }

    sort(filtered.begin(), filtered.end(), [](Score a, Score b){
        return a.tries < b.tries;
    });

    cout << "===== TOP 5 | " << difficultyName(difficulty) << " =====\n";

    int limit = min(5, (int)filtered.size());

    for(int i = 0; i < limit; i++) {
        cout << i+1 << ". " << filtered[i].name << " | Próby: " << filtered[i].tries << endl;
    }
    cout << endl;

    do {
        cout << "Wciśnij 1 aby wrócić do menu: ";
        cin >> back;

        if(!cin) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Nieprawidłowa opcja!\n";
        }

    } while(back != 1);

    cout << string(100, '\n');
}

void showTopMenu() {
    ifstream file("wyniki.txt");
    if(!file.is_open()) {
        cout << "Nie można otworzyć pliku wyników!\n";
        return;
    }

    vector<Score> scores;
    Score temp;
    char comma;

    while(file >> temp.difficulty >> comma >> temp.tries >> comma >> temp.name) {
        scores.push_back(temp);
    }
    file.close();

    if(scores.empty()) {
        cout << "Brak zapisanych wyników!\n";
        return;
    }

    int choice;
    do {
        cout << "\n===== MENU TOP 5 =====\n";
        cout << "1. Łatwy\n";
        cout << "2. Średni\n";
        cout << "3. Trudny\n";
        cout << "4. Extreme\n";
        cout << "5. Powrót do menu głównego\n";
        cin >> choice;

        if(!cin) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Nieprawidłowa opcja!\n";
            continue;
        }

        if(choice >= 1 && choice <= 4) {
            cout << string(100, '\n');
            showTopForDifficulty(scores, choice);
        } else if(choice == 5) {
            cout << string(100, '\n');
            break;
        } else {
            cout << "Nieprawidłowa opcja!\n";
        }

    } while(true);
}

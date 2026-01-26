#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Wynik {
    string difficulty;
    int tries;
    string name;
};

void pokazTop5() {
    ifstream file("wyniki.txt");
    vector<Wynik> wyniki;

    if (!file.is_open()) {
        cout << "Nie mozna otworzyc pliku\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        int p1 = line.find(',');
        int p2 = line.find(',', p1 + 1);

        Wynik w;
        w.difficulty = line.substr(0, p1);
        w.tries = stoi(line.substr(p1 + 1, p2 - p1 - 1));
        w.name = line.substr(p2 + 1);

        wyniki.push_back(w);
    }
    file.close();

    string difficulties[] = {"LATWY", "SREDNI", "TRUDNY", "EXTREME"};

    for (string diff : difficulties) {
        cout << "\n=== TOP 5 | " << diff << " ===\n";

        vector<Wynik> filtered;

        for (Wynik w : wyniki) {
            if (w.difficulty == diff) {
                filtered.push_back(w);
            }
        }

        // sort ręczny
        for (int i = 0; i < filtered.size(); i++) {
            for (int j = i + 1; j < filtered.size(); j++) {
                if (filtered[j].tries < filtered[i].tries) {
                    Wynik temp = filtered[i];
                    filtered[i] = filtered[j];
                    filtered[j] = temp;
                }
            }
        }

        for (int i = 0; i < filtered.size() && i < 5; i++) {
            cout << i + 1 << ". "
                 << filtered[i].name
                 << " | tries: " << filtered[i].tries
                 << endl;
        }

        if (filtered.empty()) {
            cout << "Brak wynikow\n";
        }
    }
}
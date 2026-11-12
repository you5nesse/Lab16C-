
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class StrategieTri {
public:
    virtual void trier(vector<string>& v) = 0;
    virtual ~StrategieTri() = default;
};

class TriCroissant : public StrategieTri {
public:
    void trier(vector<string>& v) override {
        sort(v.begin(), v.end());
    }
};

class TriDecroissant : public StrategieTri {
public:
    void trier(vector<string>& v) override {
        sort(v.begin(), v.end(), greater<string>());
    }
};

class TriParLongueur : public StrategieTri {
public:
    void trier(vector<string>& v) override {
        sort(v.begin(), v.end(),
            [](const string& a, const string& b) {
                return a.length() < b.length();
            }
        );
    }
};

class GestionnaireTri {
private:
    StrategieTri* strategie;

public:
    GestionnaireTri(StrategieTri* s) {
        strategie = s;
    }

    void changerStrategie(StrategieTri* s) {
        strategie = s;
    }

    void executerTri(vector<string>& v) {
        strategie->trier(v);
    }
};

void afficher(const vector<string>& v) {
    for (const string& mot : v) {
        cout << mot << " ";
    }
    cout << endl;
}

int main() {

    vector<string> mots = {
        "Banane", "Pomme", "Kiwi", "Orange", "Abricot"
    };

    TriCroissant croissant;
    TriDecroissant decroissant;
    TriParLongueur longueur;

    GestionnaireTri gestionnaire(&croissant);

    cout << "Tri croissant :" << endl;
    gestionnaire.executerTri(mots);
    afficher(mots);

    cout << "\nTri decroissant :" << endl;
    gestionnaire.changerStrategie(&decroissant);
    gestionnaire.executerTri(mots);
    afficher(mots);

    cout << "\nTri par longueur :" << endl;
    gestionnaire.changerStrategie(&longueur);
    gestionnaire.executerTri(mots);
    afficher(mots);

    return 0;
}

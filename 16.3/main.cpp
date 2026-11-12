
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Observateur {
public:
    virtual void mettreAJour(
        float temperature,
        float humidite,
        float pression
    ) = 0;

    virtual ~Observateur() = default;
};

class StationMeteo {
private:
    float temperature;
    float humidite;
    float pression;

    vector<Observateur*> observateurs;

public:
    void ajouterObservateur(Observateur* o) {
        observateurs.push_back(o);
    }

    void supprimerObservateur(Observateur* o) {
        observateurs.erase(
            remove(observateurs.begin(),
                   observateurs.end(), o),
            observateurs.end()
        );
    }

    void notifierObservateurs() {
        for (Observateur* o : observateurs) {
            o->mettreAJour(
                temperature,
                humidite,
                pression
            );
        }
    }

    void setMesures(float t, float h, float p) {
        temperature = t;
        humidite = h;
        pression = p;

        notifierObservateurs();
    }
};

class AffichageTemperature : public Observateur {
public:
    void mettreAJour(
        float t, float h, float p
    ) override {
        cout << "Temperature : " << t << " C" << endl;
    }
};

class AffichageHumidite : public Observateur {
public:
    void mettreAJour(
        float t, float h, float p
    ) override {
        cout << "Humidite : " << h << " %" << endl;
    }
};

class AffichagePression : public Observateur {
public:
    void mettreAJour(
        float t, float h, float p
    ) override {
        cout << "Pression : " << p << " hPa" << endl;
    }
};

int main() {

    StationMeteo station;

    AffichageTemperature affichageT;
    AffichageHumidite affichageH;
    AffichagePression affichageP;


    station.ajouterObservateur(&affichageT);
    station.ajouterObservateur(&affichageH);
    station.ajouterObservateur(&affichageP);

    cout << "=== Premiere mise a jour ===" << endl;

    station.setMesures(25.5, 60, 1013);

    cout << "\n=== Deuxieme mise a jour ===" << endl;

    station.setMesures(30, 45, 1010);

    return 0;
}

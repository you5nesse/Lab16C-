
#include <iostream>
#include <string>
using namespace std;

class Configuration {
private:
    string cheminFichier;
    string utilisateur;
    string motDePasse;

    static Configuration* instance;

    Configuration() {
        cheminFichier = "config.txt";
        utilisateur = "admin";
        motDePasse = "123456";
    }

public:
    Configuration(const Configuration&) = delete;
    Configuration& operator=(const Configuration&) = delete;

    static Configuration& getInstance() {
        if (instance == nullptr) {
            instance = new Configuration();
        }
        return *instance;
    }

    void afficherParametres() {
        cout << "Chemin du fichier : " << cheminFichier << endl;
        cout << "Utilisateur : " << utilisateur << endl;
        cout << "Mot de passe : " << motDePasse << endl;
    }
};

Configuration* Configuration::instance = nullptr;

int main() {

    Configuration& config1 = Configuration::getInstance();
    Configuration& config2 = Configuration::getInstance();

    config1.afficherParametres();

    if (&config1 == &config2) {
        cout << "\nLes deux references utilisent la meme instance."
             << endl;
    }

    return 0;
}

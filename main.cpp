#include <iostream>
#include <limits>
#include <functional>
#include <vector>
#include <random>

using namespace std;

// Fonction qui accepte un nombre variable de paramètres
void fonction_avec_parametres(int n, function<void(const vector<int>&)> operation) {
  vector<int> parametres(n); // Créer un vecteur pour stocker les paramètres

  //random number
  random_device rd;  
  mt19937 gen(rd()); 
  uniform_int_distribution<> distrib(1, 10000); 

  for (int i = 0; i < n; ++i) {
    parametres[i] = distrib(gen); // we are using random number to making sure that the varaibabel has some allocated memoire
  }

  operation(parametres);
}

// Fonction pour afficher tous les paramètres
void afficher_parametres(const vector<int>& parametres) {
  cout << "Paramètres: ";
  for (int valeur : parametres) {
    cout << valeur << " ";
  }
  cout << endl;
}

int main() {
  // While Loop To try max number of parameters
  int index = 1;

  while (true) {
    cout << "Nombre de paramètres: " << index << endl;

    try {
      fonction_avec_parametres(index, afficher_parametres);
    } 
    catch (const std::exception& e) {
      cout << "Erreur: " << e.what() << endl;
      break; 
      // here we reach max paramters
    }

    // Augmenter le nombre de paramètres
    index++;
  }

  return 0;
}
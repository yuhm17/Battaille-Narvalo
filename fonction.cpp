#include <cstdlib>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <time.h>
using namespace std;

// fonction switch touché ou couller

string Résultat_Shoot(int C) {

  string R;
  switch (C) {
  case 1: //"touché":
    cout << "\nBien joué , continue de jouer !\n";
    break;
  case 2: //"à l'eau":
    cout <<"\nRaté , tu l'auras une prochaine fois !\n";
    break;
  case 3: // plus de batteau":
    cout <<"\nBienjoué il n'y a plus de bateau, tu as gagné!\n";
    break;
  }
  return R;
}
// test position de position bateau
string test_posbat(int C) {
  if (C == 0) {
  }
  string R;
  switch (C) {
  case 1: //"out of bounds":
    cout << "Votre bateau dépasse les limitte du plateau de jeu (10 x 10) !\n";
    break;
  case 2: //"superposition":
    cout << "Votre bateau ne peut être superposé sur un autre bateau !\n";
    break;
  }
  return R;
}
// affiche un tableau
void affichertab(int table_de_jeu[12][12]) {
  system("clear");
  for (int j = 1; j <= 11; j++) {
    for (int i = 1; i <= 11; i++) {
      cout << " " << table_de_jeu[j][i];
    }
    cout << "\n";
  }
}
// sauvegarde de tableau
void sauvegardertab(int table_de_jeu[12][12], int table_temp[12][12]) {
  for (int j = 1; j <= 11; j++) {
    for (int i = 1; i <= 11; i++) {
      table_temp[j][i] = table_de_jeu[j][i];
    }
  }
}
// sauvegarde de reponse
void sauvegarderrep(int table_rep[12][12], int table_de_jeu[12][12]) {
  for (int j = 1; j <= 11; j++) {
    for (int i = 1; i <= 11; i++) {
      if (table_rep[j][i] == 0) {
        table_rep[j][i] = table_de_jeu[j][i];
      }
    }
  }
}
// reset de tableau si erreur utilisateur
void resettab(int table_rep[12][12], int table_temp[12][12]) {
  for (int j = 1; j <= 11; j++) {
    for (int i = 1; i <= 11; i++) {
      table_rep[j][i] = table_temp[j][i];
    }
  }
}

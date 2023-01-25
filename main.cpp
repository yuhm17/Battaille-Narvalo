// V2  pose aléatoire ou non des bateaux

#include <cstdlib>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <time.h>
using namespace std;

// fonction switch touché ou couler
string Résultat_Shoot(int C);
// test position de position bateau
string test_posbat(int C);
// affiche un tableau
void affichertab(int table_de_jeu[12][12]);
// sauvegarde un tableau
void sauvegardertab(int table_de_jeu[12][12], int table_temp[12][12]);
// reset de tableau si erreur utilisateur
void resettab(int table_rep[12][12], int table_temp[12][12]);
// sauvegarde de reponse
void sauvegarderrep(int table_rep[12][12], int table_de_jeu[12][12]);

// Structuration de l'emplacement bateau nom PV et emplacement.
struct Bateau {
  string name;
  int PV;
  int Id;
};
// Creation tableau + variable
int table_de_jeu[12][12]; // Grille du jeu
int table_temp[12][12];   // Grille de sauvgarde
int table_rep[12][12];    // Grille reponse
int PVT = 0;              // Pts de vie

int main() {
  system("clear");
  // Création de 5 bateaux
  // Anti Torpilleur
  Bateau At1;
  At1.name = "AntiTorpileur";
  At1.PV = 3;
  At1.Id = 1;
  // Anti Torpilleur
  Bateau At2;
  At2.name = "AntiTorpileur";
  At2.PV = 3;
  At2.Id = 2;
  // Porte-avion
  Bateau Pa;
  Pa.name = "Porte-avion";
  Pa.PV = 5;
  Pa.Id = 3;
  // Croiseur
  Bateau C;
  C.name = "Croiseur";
  C.PV = 4;
  C.Id = 4;
  // Torpilleur
  Bateau T;
  T.name = "Torpilleur";
  T.PV = 2;
  T.Id = 5;

  // Création de la grille de jeu
  for (int j = 1; j <= 11; j++) {
    for (int i = 1; i <= 11; i++) {
      table_rep[j][i] = 0;
      table_de_jeu[j][i] = 0;
    }
  }
  // Echelle de positionement de la grille
  for (int j = 0; j <= 10; j++) {
    table_rep[j][1] = j - 1;
    table_de_jeu[j][1] = j - 1;
  }
  for (int j = 0; j <= 10; j++) {
    table_rep[1][j] = j - 1;
    table_de_jeu[1][j] = j - 1;
  }

  // Positionnement des bateaux + direction des bateaux
  time_t nTime;                  // Initialisation rand
  srand((unsigned)time(&nTime)); // Initialisation rand
  int X, Y;                      // Axe positionnement du bateau si rand
  int direction;                 // 1234 de ou pointe le bateau
  int PV;                        // Longueur de bateau
  int c;                         // Choix pose bateaux
  string Name;                   // Nom bateau struc

  // Choix pose aléatoire ou non des bateaux
  while (true) {
    cout << "\nBienvenue dans Bataille Narvalo a vos bateaux!\n(1) Voulez vous "
            "poser vos bateaux\n(2) Pose aléatoire des bateaux\nQuelle seras "
            "votre ultime bafouille :";
    cin >> c;
    if (c == 1 || c == 2) {
      break;
    }
    system("clear");
    
  }
  for (int i = 1; i <= 5; i++) {
    affichertab(table_rep);
    sauvegardertab(table_rep, table_temp);
    // Recuperation de chiffre entre 1 et 10.
    X = (rand() % (10 - 1 + 1)) + 1;
    Y = (rand() % (10 - 1 + 1)) + 1;
    // Utilisation des strucs bouclé la position des bateaux.
    if (At1.Id == i) {
      PV = At1.PV;
      Name = At1.name;
    }
    if (At2.Id == i) {
      PV = At2.PV;
      Name = At2.name;
    }
    if (Pa.Id == i) {
      PV = Pa.PV;
      Name = Pa.name;
    }
    if (C.Id == i) {
      PV = C.PV;
      Name = C.name;
    }
    if (T.Id == i) {
      PV = T.PV;
      Name = T.name;
    }

    // Test de position placement des bateaux.
    while (true) {

    replacer: //(pour replacer le point de départ des bateaux)

      if (c == 1) {
        cout << "\nVotre bateau fait " << PV << " cases de longs.\n";
        cout << "Choisisser le point de départ de votre " << Name
             << " sur l'axe Y :";
        cin >> Y;
        cout << "Choisisser le point de départ de votre " << Name
             << " sur l'axe X :";
        cin >> X;
      }

      if (c == 2) {
        X = (rand() % (10 - 1 + 1)) + 1;
        Y = (rand() % (10 - 1 + 1)) + 1;
      }
      if (Y > 10 || Y <= 0) {
        affichertab(table_rep);
        cout << test_posbat(1);
      } else if (X > 10 || X <= 0) {
        affichertab(table_rep);
        cout << test_posbat(1);
      } else if (table_rep[Y + 1][X + 1] == 1) {
        affichertab(table_rep);
        cout << test_posbat(2);
      } else if (table_rep[Y + 1][X + 1] == 0) {
        Y = Y + 1; // mise a niveau a l'echelle du tableau
        X = X + 1; // mise a niveau a l'echelle du tableau
        break;
      }
    }
    // création sur le graphique du bateau

    table_rep[Y][X] = 1; // affiche le point principale du bateau

    // test dumb user
    if (c == 1) {
      while (true) {
        affichertab(table_rep);
        if (direction != 1 || direction != 2 || direction != 3 ||
            direction != 4 || direction != 5) {
          cout << "\nVous ne pouvez pas mettre plus de 5 ou moin de 1";
        }
        cout << "\n(1) Positionnez votre bateaux vers le haut ";
        cout << "\n(2) Positionnez votre bateaux vers la gauche ";
        cout << "\n(3) Positionnez votre bateaux vers le bas ";
        cout << "\n(4) Positionnez votre bateaux vers la droite ";
        cout << "\n(5) Repositionnez votre bateaux ";
        cout << "\nvotre choix :";
        cin >> direction;

        if (direction == 1 || direction == 2 || direction == 3 ||
            direction == 4 || direction == 5) {
          break;
        }
      }
    }
    if (c == 2) {
      direction = (rand() % (4 - 1 + 1)) + 1;
    }
    // haut
    if (direction == 1) {
      for (int i = 1; i <= PV - 1; i++) {
        if (table_rep[Y - i][X] == 1 || Y - i == 1) {

          table_de_jeu[Y][X] = 0;
          resettab(table_rep, table_temp);
          sauvegarderrep(table_rep, table_temp);
          affichertab(table_rep);
          cout << "\nCette direction ne fonctione pas veuillez replacer votre "
                  "bateau.";
          goto replacer;
        }
        table_rep[Y - i][X] = 1;
      }
    }
    // droite
    if (direction == 4) {
      for (int i = 1; i <= PV - 1; i++) {
        if (table_rep[Y][X + i] == 1 || X + i == 11) {
          table_rep[Y][X] = 0;
          resettab(table_rep, table_temp);
          affichertab(table_rep);
          cout << "\nCette direction ne fonctione pas veuillez replacer votre "
                  "bateau.";
          goto replacer;
        }
        table_rep[Y][X + i] = 1;
      }
    }

    // bas
    if (direction == 3) {
      for (int i = 1; i <= PV - 1; i++) {
        if (table_rep[Y + i][X] == 1 || Y + i == 11) {
          table_rep[Y][X] = 0;
          resettab(table_rep, table_temp);
          affichertab(table_rep);
          cout << "\nCette direction ne fonctione pas veuillez replacer votre "
                  "bateau.";
          goto replacer;
        }
        table_rep[Y + i][X] = 1;
      }
    }

    // gauche
    if (direction == 2) {
      for (int i = 1; i <= PV - 1; i++) {
        if (table_rep[Y][X - i] == 1 || X - i == 1) {
          table_rep[Y][X] = 0;
          resettab(table_rep, table_temp);
          affichertab(table_rep);
          cout << "\nCette direction ne fonctione pas veuillez replacer votre "
                  "bateau.";
          goto replacer;
        }
        table_rep[Y][X - i] = 1;
      }
    }

    // replacer le point de départ du bateau
    if (direction == 5) {
      table_rep[Y][X] = 0;
      affichertab(table_rep);
      goto replacer;
    }
    PVT += PV;
  }

  // affichage des bateaux
  system("clear");
  affichertab(table_de_jeu);

  // test de notre position bateau + - pv
  int R1 = 0, R2 = 0;
  while (PVT != 0) {
  antidumb:
    // positionnement du tire
    cout << "\n(Tapez 0 pour avoir les réponses, 11 pour reprendre)\nTrouvez le bateau 1, 10 (Y):";
    cin >> R1;
    cout << "\n(Tapez 0 pour avoir les réponses, 11 pour reprendre)\nTrouvez le bateau 1,10 (X):";
    cin >> R2;
    // test  tire
    // reussite tire
    if (R1 == 0 && R2 == 0) {
      affichertab(table_rep);
      goto antidumb;
    }
    if (R1 < 11 && R2 < 11) {
      affichertab(table_de_jeu);
    }
    if ((R1 == 0 || R2 == 0) || (R1 > 11 || R2 > 11)) {
      affichertab(table_de_jeu);
      cout << "Le tableau fait 10 x 10 vous ne pouvez mettre 0 ou plus de 10\n";
      goto antidumb;
    }
    // Test toucher
    if (table_rep[R1 + 1][R2 + 1] == 1) {
      table_de_jeu[R1 + 1][R2 + 1] = 1;
      PVT = PVT - 1;
      affichertab(table_de_jeu);
      cout << Résultat_Shoot(1);
    } // Sinon tire louper
    else {
      table_de_jeu[R1 + 1][R2 + 1] = 8;
      affichertab(table_de_jeu);
      cout << Résultat_Shoot(2);
    }
  }
  // Fin du jeu
  cout << Résultat_Shoot(3);

  return 0;
}

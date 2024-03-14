#pragma once


#include "joueur.h"
#include <array>


using grille = std::array<int, MAX_HAUTEUR*MAX_LARGEUR>; //0 vide // 1 E // 2 U

class Joueur_AlphaBeta_ : public Joueur
{
public:
  Joueur_AlphaBeta_(std::string nom, bool joueur);
  char nom_abbrege() const override;

  void recherche_coup(Jeu, int & coup) override;

  int min(Jeu &jeu, int, int, int , grille grille);
  int max(Jeu &jeu, int, int, int , grille grille);

  int estimateur(Jeu &jeu, int profondeur, grille grille) const;

  grille initialise();

  bool adversaire_a_3_verticale (grille) const;
  bool adversaire_a_2_horizontal (grille) const;

  void joue_grille(grille &grille, int i);
};

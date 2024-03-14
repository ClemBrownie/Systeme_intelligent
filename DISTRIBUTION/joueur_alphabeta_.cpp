#include "joueur_alphabeta_.h"


Joueur_AlphaBeta_::Joueur_AlphaBeta_(std::string nom, bool joueur)
    :Joueur(nom,joueur)
{}



char Joueur_AlphaBeta_::nom_abbrege() const
{
    return 'A';
}

void Joueur_AlphaBeta_::recherche_coup(Jeu jeu, int &coup)
{
    std::cout<<"rc"<<std::endl;

    int alpha = std::numeric_limits<int>::min();
    int beta = std::numeric_limits<int>::max();
    int profondeur = 3; // Profondeur de recherche
    int meilleur_coup = -1;
    int meilleure_valeur = std::numeric_limits<int>::min();
    grille grille = initialise();

    for (int i = 0; i < jeu.nb_coups(); i++) // 1 -> 7
    {
        if (jeu.coup_licite(i))
        {
            Jeu copie_jeu = jeu;


            copie_jeu.joue(i);
            joue_grille(grille, i);


            //copie_jeu.plateau()->afficher(std::cout);

            int valeur = min(copie_jeu, alpha, beta, profondeur - 1, grille);

            if (valeur > meilleure_valeur)
            {
                meilleur_coup = i;
                meilleure_valeur = valeur;
            }
        }
        else {
            std::cout<<i<<"coup_illicite"<<std::endl;
        }
    }
    coup = meilleur_coup;
}

int Joueur_AlphaBeta_::min(Jeu &jeu, int alpha, int beta, int profondeur, grille grille)
{
    //std::cout<<"min"<<std::endl;
    if (jeu.fini() || profondeur == 0)
    {
        return estimateur(jeu,profondeur, grille);
    }

    int valeur_min = std::numeric_limits<int>::max();
    for (int i = 0; i < jeu.nb_coups(); i++)
    {
        Jeu copie_jeu = jeu;
        if (copie_jeu.coup_licite(i))
        {
            copie_jeu.joue(i);
            joue_grille(grille, i);

            int valeur = max(copie_jeu, alpha, beta, profondeur - 1, grille);

            valeur_min = std::min(valeur_min, valeur);
            alpha = std::max(alpha, valeur);
            if (beta <= alpha)
            {
                break;
            }
        }
    }
    return valeur_min;
}

int Joueur_AlphaBeta_::max(Jeu &jeu, int alpha, int beta, int profondeur, grille grille)
{
    //std::cout<<"max"<<std::endl;

    if (jeu.fini() || profondeur == 0)
    {
        return estimateur(jeu,profondeur, grille);
    }

    int valeur_max = std::numeric_limits<int>::min();
    for (int i = 0; i < jeu.nb_coups(); i++)
    {
        Jeu copie_jeu = jeu;
        if (copie_jeu.coup_licite(i))
        {
            copie_jeu.joue(i);
            joue_grille(grille, i);

            int valeur = min(copie_jeu, alpha, beta, profondeur - 1, grille);

            valeur_max = std::max(valeur_max, valeur);
            beta = std::min(beta, valeur);
            if (beta <= alpha)
            {
                break;
            }
        }
    }
    return valeur_max;
}



int Joueur_AlphaBeta_::estimateur(Jeu &jeu, int profondeur, grille grille) const
{
//    std::srand(std::time(nullptr)); // use current time as seed for random generator
    int random_value = std::rand();

    //std::cout<<random_value<<std::endl;

    int eval = 0;

    if ( adversaire_a_3_verticale(grille) ){
        std::cout<<"adversaire à trois verticale"<<std::endl;
    }

    if ( adversaire_a_2_horizontal(grille) ){
        std::cout<<"adversaire à 2 horizontale"<<std::endl;
    }

    return random_value;

}




bool Joueur_AlphaBeta_::adversaire_a_3_verticale (grille) const{
   return false;
}


bool Joueur_AlphaBeta_::adversaire_a_2_horizontal (grille) const{
   return false;
}


void Joueur_AlphaBeta_::joue_grille(grille &grille, int i, int joueur){

   while(grille[i] != 0){
       i += 7;
   }

   grille[i]


}

grille Joueur_AlphaBeta_::initialise(){
    grille tempo;

    for(int xy = 0; xy<MAX_LARGEUR*MAX_HAUTEUR; ++xy){
        tempo[xy] = 0;
    }

}
